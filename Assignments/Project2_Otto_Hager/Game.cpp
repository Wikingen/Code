#include "Game.hpp"
#include "Functions.hpp"
#include "Items.hpp"
#include "utils.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

Game::Game()
{
    _num_players = 0;
    _num_enemies = 0;
}

// Parameterized constructor
Game::Game(Entity players[], Entity enemies[], int num_players, int num_enemies)
{

    // cout << "We pass num_players with the value " << num_players <<endl;

    // Makes sure there is max 2 enemies, and sets it to zero if negative number is given
    if (num_players > 2)
    {
        _num_players = 2;
    }
    else if (num_players < 0)
    {
        _num_players = 0;
    }
    else
    {
        _num_players = num_players;
    }

    for (int i = 0; i < _num_players; i++)
    {
        _players[i] = players[i];
    }

    if (num_enemies > 2)
    {
        _num_enemies = 2;
    }
    else if (num_enemies < 0)
    {
        _num_enemies = 0;
    }
    else
    {
        _num_enemies = num_enemies;
    }

    for (int i = 0; i < _num_enemies; i++)
    {
        _enemies[i] = enemies[i];
    }
}

// Loads characters and enemies into the _all_players and _all_enemies arrays
bool Game::loadEnteties(string filename, bool are_players)
{
    ifstream in_file(filename);
    if (in_file.fail())
    {
        return false;
    }

    string name;
    char type; //'p' - playeable character, 'I' - Island enemy, 'E' - Epic enemy
    double hp;
    double stamina;
    double defense;
    char condition; // H,D,P
    bool advantage; // Deciding weather you have an advanteage to start first
    // char el_weak; //Elemental weakness
    int gold;
    Potion new_potion;       // Will work as temporary potion to add to new entity
    Equipment new_equipment; // Will work as temporary equipment to add to new entities

    string splitted_line2[2]; // will contain the names of equiped items
    string potion_name;
    string equipment_name;

    int items[2];

    string line2;             // Here we take in the whole line of elements 9
    string splitted_line[15]; // array with all elements from one input line. Size should be 12, but we overshoot with 15
    int num_elements;         // number of elements in splitted string
    int curr_index = 0;       // Keeps track of where in the character array we are
    Entity new_player;        // Temporary entity object to fill entity lists wirth

    string line;            // Input lines from textfile
    getline(in_file, line); // Get rid of first line since it is a title-line

    while (getline(in_file, line) && curr_index < _MAX_PLAYERS)
    {
        num_elements = split(line, '|', splitted_line, 15);

        if (num_elements != 12) // skip invalid rows
        {
            //cout << "DEBUG line " << curr_index << " Has " << num_elements << " and not 12" << endl;
            continue;
        }

        // NOTE THE FOLLOWING VALIDATION IS REPETETIVE SINCE IT IS ALREADY CHECKED IN SETTERS

        name = splitted_line[0]; // If its a valid double we add it otherwise it is set to 0
        // cout << "DEBUG Gave the name: " << name << " on iteration " << curr_index  << endl;

        type = splitted_line[1][0];

        if (isDouble(splitted_line[2]))
        {
            hp = stod(splitted_line[2]);
        }
        else
        {
            hp = 0;
        }

        // cout << "DEBUG Gave the hp: " << hp << " on iteration " << curr_index << endl;

        if (isDouble(splitted_line[3]))
        {
            stamina = stod(splitted_line[3]);
        }
        else
        {
            stamina = 0;
        }

        // cout << "DEBUG Gave the stamina: " << stamina << " on iteration " << curr_index << endl;

        if (isDouble(splitted_line[4]))
        {
            defense = stod(splitted_line[4]);
        }
        else
        {
            defense = 0;
        }

        // cout << "DEBUG Gave the defense: " << defense << " on iteration " << curr_index << endl;

        if (splitted_line[5][0] == 'H' || splitted_line[5][0] == 'D' || splitted_line[5][0] == 'P') // if its a valid condition it is set, else it is 'H'
        {
            condition = splitted_line[5][0]; // add index 0 to make it a char
        }
        else
        {
            condition = 'H';
        }

        // cout << "DEBUG Gave the condition: '" << condition << "' on iteration " << curr_index << endl;

        if (splitted_line[6] == "True")
        {
            advantage = true;
        }
        else
        {
            advantage = false;
        }

        // cout << "DEBUG Set the advantage to: " << advantage << " on iteration " << curr_index << endl;

        // sets elemtal weaknesses, default is fire
        /*    if (splitted_line[7][0] == 'W' || splitted_line[7][0] == 'F' || splitted_line[7][0] == 'A' || splitted_line[7][0] == 'A') // if its a valid element it updates
           {
               el_weak = splitted_line[7][0]; // add index 0 to make it a char
           }
           else
           {
               el_weak = 'F';
           } */

        // Sets gold
        if (isInteger(splitted_line[8])) // if it is a valid int it will be added otherwise it is set to 0
        {
            gold = stoi(splitted_line[8]);
        }
        else
        {
            gold = 0;
        }

        line2 = splitted_line[9];

        split(line2, ',', splitted_line2, 2);
        // cout << "Line2:  " << line2 << endl;
        // cout << "Splitted line:  " << splitted_line2[0] << ",   " << splitted_line2[1] << endl;
        potion_name = splitted_line2[0];
        // cout << "Potion name " << potion_name << endl;
        new_potion = getPotion(potion_name);
        // cout << "Name of new potion  " << new_potion.name << endl;
        new_potion.quantity = 1; // Set initial quatnity to 1

        equipment_name = splitted_line2[1];
        // cout << "SPlitted line[1]" << splitted_line2[1] << endl;
        new_equipment = getEquipment(equipment_name);

        // cout << "DEBUG Set the gold value to: " << gold << " on iteration " << curr_index << endl;

        // cout << "DEBUG Is_player is set to: " << are_players << " on iteration " << curr_index << endl;

        if (are_players)
        {
            _all_players[curr_index].setName(name);
            _all_players[curr_index].setHP(hp);
            _all_players[curr_index].setGold(gold);
            _all_players[curr_index].setStamina(stamina);
            _all_players[curr_index].setDefense(defense);
            _all_players[curr_index].setCondition(condition);
            _all_players[curr_index].setAdvantage(advantage);
            _all_players[curr_index].setItems(items);
            _all_players[curr_index].setPotion(0, new_potion); // saves the loaded potion in spot 1
            _all_players[curr_index].setNumPotion(1);
            // cout << "DEBUG Name before setting: " << new_equipment.name << " in load entities"<<endl;
            _all_players[curr_index].setEquipment(0, new_equipment);
            _all_players[curr_index].setNumEquipment(1);

            /*          _players[curr_index].setPotions(potions);
                        _players[curr_index].setEquipped(equipped);
                        _players[curr_index].setInventory(inventory); */
            // cout << name  << " was successfully initiated" << endl;

            _num_players = curr_index; // Will update every iteration until last player is loaded
        }
        else
        {
            // cout << "DEBUG Index is now " << curr_index <<endl;

            _all_enemies[curr_index].setName(name);
            _all_enemies[curr_index].setHP(hp);
            _all_enemies[curr_index].setType(type);
            _all_enemies[curr_index].setGold(gold);
            _all_enemies[curr_index].setStamina(stamina);
            _all_enemies[curr_index].setDefense(defense);
            _all_enemies[curr_index].setCondition(condition);
            _all_enemies[curr_index].setAdvantage(advantage);
            _all_enemies[curr_index].setItems(items);
            _all_enemies[curr_index].setPotion(0, new_potion);
            _all_enemies[curr_index].setNumPotion(1);
            _all_enemies[curr_index].setEquipment(0, new_equipment);
            _all_enemies[curr_index].setNumEquipment(1);

            _num_enemies = curr_index; // Will uodate every iteration until last enemy is loaded
        }

        /* string second_line;
        Potion potions_array[3];
        split(second_line, ',', )





        _characters[curr_index].setName(name);
        _characters[curr_index].setHP(hp);
        _characters[curr_index].setGold(gold);
        _characters[curr_index].setCondition(condition);
        _characters[curr_index].setIsEnemy(is_enemy);*/
        curr_index++;
    }

    // cout << "We have " << _num_players +1 << " Characters and " << _num_enemies +1 << " Enemies" << endl;

    return true;
}

bool Game::loadItems(string filename)
{
    ifstream in_file(filename);
    if (in_file.fail())
    {
        return false;
    }

    string name;
    string desc;         // Description variable
    char type = 'X';     // D~Weapon S~Sword P~Potion
    char element = 'X';  // W F A E
    double effect_value; // Weapons have damage here and shield have defense here
    double price;

    int num_elements;
    string splitted_line[6];
    int curr_index = 0;
    int equ_index = 0;
    int pot_index = 0;

    string line;            // Input lines from textfile
    getline(in_file, line); // Get rid of first line since it is a title-line

    while (getline(in_file, line))
    {
        num_elements = split(line, '|', splitted_line, 15);

        if (num_elements != 6) // skip invalid rows
        {
            // cout << "DEBUG line " << curr_index << " Has " << num_elements << " and not 6" << endl;
            continue;
        }

        name = splitted_line[0];
        // cout << "DEBUG Gave the name: " << name << " on iteration " << curr_index  << endl;

        desc = splitted_line[1];

        type = splitted_line[2][0];

        if (isDouble(splitted_line[3]))
        {
            effect_value = stod(splitted_line[3]);
        }
        else
        {
            effect_value = 0;
            cout << "effect vlaue set 0 zero since it was not a double" << endl;
        }

        element = splitted_line[4][0];

        if (isDouble(splitted_line[5]))
        {
            price = stod(splitted_line[5]);
        }
        else
        {
            price = 0;
        }

        if (type == 'D') // if weapon
        {

            _all_equipment[equ_index].name = name;
            _all_equipment[equ_index].desc = desc;
            _all_equipment[equ_index].type = type;
            _all_equipment[equ_index].damage = effect_value;
            _all_equipment[equ_index].defense = 0;
            _all_equipment[equ_index].element = element;
            _all_equipment[equ_index].price = price;
            // cout << _all_equipment[equ_index].name << "was successfully iniated" << endl;
            equ_index++;
        }
        else if (type == 'S') // if shield
        {
            _all_equipment[equ_index].name = name;
            _all_equipment[equ_index].desc = desc;
            _all_equipment[equ_index].type = type;
            _all_equipment[equ_index].damage = 0;
            _all_equipment[equ_index].defense = effect_value;
            _all_equipment[equ_index].element = element;
            _all_equipment[equ_index].price = price;
            // cout << _all_equipment[equ_index].name << "was successfully iniated" << endl;
            equ_index++;
        }
        else if (type == 'P') // if potion
        {
            _all_potions[pot_index].name = name;
            _all_potions[pot_index].desc = desc;
            _all_potions[pot_index].type = type;
            _all_potions[pot_index].effect_value = effect_value;
            _all_potions[pot_index].quantity = 1; // default quantity when loading potions
            _all_potions[pot_index].price = price;
            pot_index++;

            // cout << _all_potions[curr_index].name << " was successfully initiated" << endl;
            _num_enemies = curr_index; // Will uodate every iteration until last enemy is loaded
        }
        else
        {
            cout << "Non valid type of weapon. Type: " << type << endl;
        }

        curr_index++;
    }

    return true;
}

bool Game::loadRiddles(string filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        int index = 0;
        while (getline(file, line))
        {
            string parts[2];
            int numParts = split(line, '|', parts, 2);
            if (numParts == 2)
            {
                _riddles[index] = parts[0];
                _riddles_answers[index] = parts[1];
                index++;
                if (index >= _MAX_RIDDLES)
                {
                    break; // Prevent exceeding array bounds
                }
            }
        }
        file.close();
        return true;
    }
    else
    {
        cout << "Unable to open file";
        return false;
    }
}


// Prompts player on avaliable characters and takes input. Then returns chosen player
void Game::playerPick(int player_index)
{
    bool valid = false;
    string userChoice;
    string player_name;
    int player_spot = 1;
    int first_player_index = 0;
    cout << "Which character would player " << player_index + 1 << " like to choose? Enter a number." << endl;
    for (int i = 0; i < _MAX_PLAYERS; i++)
    {
        // Checking if player name is the same as the ifrst chosen player
        if (_all_players[i].getName() != "" && _all_players[i].getName() != _players[0].getName())
        {
            cout << "(" << player_spot << ")" << _all_players[i].getName() << "  ";

            player_spot++;
        }
    }
    cout << endl;

    do
    {
        getline(cin, userChoice);
        if (isInteger(userChoice) && stoi(userChoice) >= 1 && stoi(userChoice) < player_spot)
        {
            valid = true;
        }
        else
        {
            cout << "Enter a valid option (1-" << player_spot << ")" << endl;
        }

    } while (!valid);

    int chosen_index = stoi(userChoice) - 1;

    // Find the corresponding player in _all_players array
    int count = 0;
    int actual_index = 0;
    while (count < chosen_index + 1)
    {
        if (_all_players[actual_index].getName() != "" && _all_players[actual_index].getName() != _players[first_player_index].getName())
        {
            count++;
        }
        actual_index++;
    }
    actual_index--; // Adjust for extra increment in while loop

    // Get the chosen player from _all_players array
    Entity player = _all_players[actual_index];

    // Add the chosen player to _players array
    setPlayer(player_index, player);

    return;
}

// Returns the current number of players _num_players
int Game::getNumPlayers()
{
    return _num_players;
}

// Returns the current number of enemies _num_enemies
int Game::getNumEnemies()
{
    return _num_enemies;
}

/* Sets the _players array with the provided array of objects.
The number of objects in the array is specified by the int parameter.
If the number of objects is greater than 2, only the first two objects are considered.
The data member _num_players is updated accordingly.*/
void Game::setPlayersList(Entity arr[], int num_players)
{
    if (num_players > 2)
    {
        _num_players = 2;
    }
    else if (num_players < 0)
    {
        _num_players = 0;
    }
    else
    {
        _num_players = num_players;
    }

    for (int i = 0; i < _num_players; i++)
    {
        _players[i] = arr[i];
    }
}

/*Sets the _enemies array with the provided array of objects.
The number of objects in the array is specified by the int parameter.
If the number of objects is greater than 2, only the first two objects are considered.
The data member _num_enemies is updated accordingly.
 */
void Game::setEnemiesList(Entity arr[], int num_enemies)
{

    if (num_enemies > 2)
    {
        _num_enemies = 2;
    }
    else if (num_enemies < 0)
    {
        _num_enemies = 0;
    }
    else
    {
        _num_enemies = num_enemies;
    }
    for (int i = 0; i < _num_enemies; i++)
    {
        _enemies[i] = arr[i];
    }
}

// Replaces a player object at the given index in the _players array. Returns true is successful and false if not
bool Game::setPlayer(int index, Entity new_player)
{
    if (index >= 0 && index <= 2)
    {
        _players[index] = new_player;
        return true;
    }
    else
    {
        return false;
    }
}

// Returns an object from the _players array based on the index
Entity Game::getPlayer(int index)
{
    Entity E; // Empty entity

    if (index == 1 || index == 0)
    {
        return _players[index];
    }

    cout << "Didnt find player" << endl;
    return E;
}
// Returns an object from the _all_players array based on the provided name
Entity Game::getPlayerFromAll(string name)
{
    Entity E; // Empty entity
    for (int i = 0; i < _MAX_PLAYERS; i++)
    {
        if (_all_players[i].getName() == name)
        {
            return _all_players[i];
        }
    }
    return E;
}

Potion Game::getPotion(string name)
{
    Potion E; // Empty Potion
    // cout << "Name is: \"" << name << "\" in function" << endl;
    for (int i = 0; i < 10; i++) // Hard coded line
    {
        // cout << "Checking if it is " << _all_potions[i].name << endl;
        if (_all_potions[i].name == name)
        {
            // cout << "Name of potion found " << _all_potions[i].name << endl;
            return _all_potions[i];
        }
    }
    // cout << "Not found" << endl;
    return E;
}
Equipment Game::getEquipment(string name)
{
    Equipment E;
    // cout << "Name is: \"" << name << "\" in function" << endl;
    for (int i = 0; i < 20; i++) // Hard coded line
    {
        // cout << "Checking if it is " << _all_potions[i].name << endl;
        if (_all_equipment[i].name == name)
        {
            // cout << "Name of potion found " << _all_equipment[i].name << endl;
            return _all_equipment[i];
        }
    }
    // cout << "Not found" << endl;
    return E;
}

// Replaces an enemy object at the given index in the _enemies array.
bool Game::setEnemy(int index, Entity new_enemy)
{
    if (index >= 0 && index <= _num_enemies)
    {
        _enemies[index] = new_enemy;
        return true;
    }
    else
    {
        return false;
    }
}

void Game::setPlayerCalamity(int player_id, double calamity)
{
    _players[player_id].setCalamity(calamity);
}
double Game::getPlayerCalamity(int player_id)
{
    return _players[player_id].getCalamity();
}
void Game::setPlayerWon(int player_id, bool player_won)
{
    _players[player_id].setPlayerWon(player_won);
}
void Game::setPlayerCondition(int player_id, char condition)
{
    _players[player_id].setCondition(condition);
}
char Game::getPlayerCondition(int player_id)
{
    return _players[player_id].getCondition();
}

void Game::setPlayerHP(int player_id, double hp)
{
    _players[player_id].setHP(hp);
}
double Game::getPlayerHP(int player_id)
{
    return _players[player_id].getHP();
}

void Game::setPlayerStamina(int player_id, double stamina)
{
    _players[player_id].setStamina(stamina);
}
double Game::getPlayerStamina(int player_id)
{
    return _players[player_id].getStamina();
}

// Returns an object from the _enemies array based on the provided name
// I just return the first one if it is not in the array
Entity Game::getEnemy(string name)
{
    for (int i = 0; i < _num_enemies; i++)
    {
        if (_enemies[i].getName() == name)
        {
            return _enemies[i];
        }
    }

    return _enemies[0];
}

// Returns the index of the player object in the _players array based on the provided name.
int Game::findPlayer(string name)
{
    for (int i = 0; i < _num_players; i++)
    {
        if (_players[i].getName() == name)
        {
            return i;
        }
    }

    return -1;
}

// Finds index of potion with a name
int Game::findPotion(string name)
{
    for (int i = 0; i < _MAX_POTIONS; i++)
    {
        if (name == _all_potions[i].name)
        {
            return i;
        }
    }
    return -1;
}

// Returns the index of the enemy object in the _enemies array based on the provided name.
int Game::findEnemy(string name)
{
    for (int i = 0; i < _num_enemies; i++)
    {
        if (_enemies[i].getName() == name)
        {
            return i;
        }
    }

    return -1;
}

void Game::itemShop(int player_id)
{
    cout << "Welcome to the Item shop " << _players[player_id].getName() << "! Pick whatever you like! " << endl;
    string input;
    bool weapon_bought = false;
    bool potion_bought = false;
    do
    {
        cout << "1. Buy Weapon \n2. Buy Potion \n3. Leave Shop " << endl;
        getline(cin, input);

        while (!isInteger(input) || !(stoi(input) == 1 || stoi(input) == 2 || stoi(input) == 3))
        {
            cout << "Enter a valid integer! " << endl;
            getline(cin, input);
        }

        int rand_idx1 = 0;
        int rand_idx2 = 0;
        int rand_idx3 = 0;
        Potion new_potion;                   // New potion we can set to players potions array
        Equipment shop_equipment[3];         // All non epic items for sale array
        Potion shop_Potions[_MAX_EQUIPMENT]; // All non epic items for sale array
        bool is_space = false;               // represents if there is space for item to be added
        string item_pick;                    // String input for item pick
        string item_pick2;                   // String input for item pick2 (Potion sub)
        string substite_input;               // Takes yes or no input
        int item_num = 0;                    // Numbers for available weapons
        int num_choice = stoi(input);
        switch (num_choice)
        {
        case 1:

            if (!weapon_bought)
            {
                cout << "----------Available Equipment---------" << endl;
                // Add three items to shop_equipment and makes sure they havent already been added.
                do
                {
                    rand_idx1 = rand() % _MAX_EQUIPMENT;
                    shop_equipment[0] = _all_equipment[rand_idx1];
                    //cout << "DEBUG Added at idx 0 :" << shop_equipment[rand_idx1].name << " from " << rand_idx1 << endl;
                } while (shop_equipment[0].name == "" || shop_equipment[0].price == 0);
                do
                {
                    rand_idx2 = rand() % _MAX_EQUIPMENT;
                    shop_equipment[1] = _all_equipment[rand_idx2];
                    //cout << "DEBUG Added at idx 1:" << shop_equipment[rand_idx2].name << " from " << rand_idx2 << endl;
                } while (shop_equipment[1].name == "" || shop_equipment[1].name == shop_equipment[0].name || shop_equipment[1].price == 0);
                do
                {
                    rand_idx3 = rand() % _MAX_EQUIPMENT;
                    shop_equipment[2] = _all_equipment[rand_idx3];
                    //cout << "DEBUG Added at idx 2" << shop_equipment[rand_idx3].name << " from " << rand_idx3 << endl;
                } while (shop_equipment[2].name == "" || shop_equipment[2].name == shop_equipment[1].name || shop_equipment[2].name == shop_equipment[0].name || shop_equipment[2].price == 0);

                for (int i = 0; i < 3; i++)
                {

                    // prints items with name and cost, since no cost items are epic


                    cout << "(" << i + 1 << ") " << shop_equipment[i].name << endl;
                    cout << shop_equipment[i].desc << endl;
                    cout << "Type: " << shop_equipment[i].type << endl;
                    cout << "Element: " << shop_equipment[i].element << endl;
                    cout << "Damage: " << shop_equipment[i].damage << endl;
                    cout << "Defense: " << shop_equipment[i].defense << endl;
                    cout << "Cost: " << shop_equipment[i].price << endl;
                    cout << "--------------------------" << endl;
                    item_num++;
                }

                cout << "Which equipment piece do you want to buy? Press 0 to exit" << endl;
                cout << "Gold balance: " << _players[player_id].getGold() << endl;
                getline(cin, item_pick);
                // Checks if valid int, if valid number, if able to puchase
                while ((!isInteger(input) || !(stoi(item_pick) >= 0 && stoi(item_pick) <= item_num)) || _players[player_id].getGold() < shop_equipment[stoi(item_pick) - 1].price)
                {
                    if ((!isInteger(input) || !(stoi(item_pick) >= 0 && stoi(item_pick) <= item_num)))
                    {
                        cout << "Please enter a valid integer from 0-" << item_num << ". " << endl;
                    }
                    else if (_players[player_id].getGold() < shop_equipment[stoi(item_pick) - 1].price)
                    {
                        cout << "You cannot afford " << shop_equipment[stoi(item_pick) - 1].name << ". It costs " << shop_equipment[stoi(item_pick) - 1].price << " And you only have " << _players[player_id].getGold() << endl;
                    }
                    getline(cin, item_pick);
                }

                is_space = false;
                // We only get here if player will buy something it can afford
                if (item_pick != "0")
                {
                    for (int i = 0; i < 10; i++) // Iterating through inventory TO SEE IF THERE IS SPACE
                    {
                        if (_players[player_id].getEquipment(i).name == "")
                        {
                            _players[player_id].addToInventory(shop_equipment[stoi(item_pick) - 1]); // Sets bought equipment in inventory array
                            _players[player_id].setGold(_players[player_id].getGold() - shop_equipment[stoi(item_pick) - 1].price);
                            cout << "You bought " << shop_equipment[stoi(item_pick) - 1].name << ". Nice purchase!" << endl; // We subtract 1 to index since i value starts 1
                            is_space = true;
                            weapon_bought = true;
                            break;
                        }
                    }

                    if (!is_space)
                    {
                        cout << "You dont have enough space to add an equipment. Do you want to substitute one of your equipments? Type 1" << endl;
                        cout << "Equipment inventory: " << endl;
                        for (int i = 0; i < item_num; i++) // Item_num here is the number of all the non epic items
                        {
                            cout << _players[player_id].getEquipment(i).name << endl;
                        }
                        getline(cin, substite_input);
                        if (substite_input == "1")
                        {
                            cout << "Wich Equipment do you want to substitute? " << endl;
                            for (int i = 0; i < item_num; i++)
                            {
                                cout << "(" << i + 1 << ") " << _players[player_id].getEquipment(i).name << endl;
                                cout << _players[player_id].getEquipment(i).desc << endl;
                                cout << "Cost: " << _players[player_id].getEquipment(i).price << endl;
                                cout << "--------------------------" << endl;
                            }
                            getline(cin, item_pick2);
                            // Checks if valid int, if valid number,
                            while ((!isInteger(item_pick2) || !(stoi(item_pick2) > 0 && stoi(item_pick2) <= item_num)))
                            {
                                if ((!isInteger(item_pick2) || !(stoi(item_pick2) > 0 && stoi(item_pick2) <= item_num)))
                                {
                                    cout << "Please enter a valid integer from 1-" << item_num << ". " << endl;
                                }

                                getline(cin, item_pick);
                            }

                            cout << "Substituted " << _players[player_id].getEquipment(stoi(item_pick2) - 1).name << " With " << shop_equipment[stoi(item_pick) - 1].name << endl;
                            _players[player_id].setEquipment(stoi(item_pick2) - 1, shop_equipment[stoi(item_pick) - 1]);
                            _players[player_id].setGold(_players[player_id].getGold() - shop_equipment[stoi(item_pick) - 1].price);

                            weapon_bought = true;
                        }
                        else
                        {
                            cout << "Okay, puchase cancelled" << endl;
                            weapon_bought = false;
                        }
                    }
                }
                else
                {
                    cout << "Maybe I'll have something later. " << endl;
                }
            }
            else
            {
                cout << "You can unfortunately only buy one weapon this shopping round" << endl;
            }

            break;
        case 2:
            if (!potion_bought)
            {
                cout << "----------Available Potions---------" << endl;
                item_num = 0;
                do
                {
                    rand_idx1 = rand() % _MAX_POTIONS;
                    shop_Potions[0] = _all_potions[rand_idx1];
                    //cout << "DEBUG Added at idx 0 :" << shop_Potions[rand_idx1].name << " from " << rand_idx1 << endl;
                } while (shop_Potions[0].name == "" || shop_Potions[0].price == 0);
                do
                {
                    rand_idx2 = rand() % _MAX_POTIONS;
                    shop_Potions[1] = _all_potions[rand_idx2];
                    //cout << "DEBUG Added at idx 1:" << shop_Potions[rand_idx2].name << " from " << rand_idx2 << endl;
                } while (shop_Potions[1].name == "" || shop_Potions[1].name == shop_Potions[0].name || shop_Potions[1].price == 0);
                
                do
                {
                    rand_idx3 = rand() % _MAX_POTIONS;
                    shop_Potions[2] = _all_potions[rand_idx3];
                    //cout << "DEBUG Added at idx 2" << shop_Potions[rand_idx3].name << " from " << rand_idx3 << endl;
                } while (shop_Potions[2].name == "" || shop_Potions[2].name == shop_Potions[1].name || shop_Potions[2].name == shop_Potions[0].name || shop_Potions[2].price == 0);

                for (int i = 0; i < 3; i++)
                {
                    // prints items with name and cost, since no cost items
                        shop_Potions[item_num] = _all_potions[i]; // saves availeable potions into shop array
                        cout << "(" << item_num + 1 << ") " << shop_Potions[item_num].name << endl;
                        cout << shop_Potions[item_num].desc << endl;
                        cout << "Cost: " << shop_Potions[item_num].price << endl;
                        cout << "--------------------------" << endl;
                        item_num++;
                }

                cout << "Which potion do you want to buy? Press 0 to exit" << endl;
                cout << "Gold balance: " << _players[player_id].getGold() << endl;
                getline(cin, item_pick);
                // Checks if valid int, if valid number, if able to puchase
                while ((!isInteger(input) || !(stoi(item_pick) >= 0 && stoi(item_pick) <= item_num)) || _players[player_id].getGold() < shop_Potions[stoi(item_pick) - 1].price)
                {
                    if (isInteger(item_pick) && stoi(item_pick) == 0)
                    {
                        break;
                    }
                    else if ((!isInteger(item_pick) || !(stoi(item_pick) >= 0 && stoi(item_pick) <= item_num)))
                    {
                        cout << "Please enter a valid integer from 0-" << item_num << ". " << endl;
                    }
                    else if (_players[player_id].getGold() < shop_Potions[stoi(item_pick) - 1].price)
                    {
                        cout << "You cannot afford " << shop_Potions[stoi(item_pick) - 1].name << ". It costs " << shop_Potions[stoi(item_pick) - 1].price << " And you only have " << _players[player_id].getGold() << endl;
                    }
                    getline(cin, item_pick);
                }

                is_space = false;

                // We only get here if player will buy something it can afford or exit
                if (item_pick != "0")
                {
                    for (int i = 0; i < 3; i++) // Iterating through inventory
                    {
                        // cout << "DEBUG  _potions[" << i << "] name is: " << _players[player_id].getPotion(i).name << endl;
                        // If we already have that potion equipped
                        if (_players[player_id].getPotion(i).name == shop_Potions[stoi(item_pick) - 1].name)
                        {
                            new_potion = _players[player_id].getPotion(i);
                            new_potion.quantity += 1;
                            _players[player_id].setPotion(i, new_potion);
                            _players[player_id].setGold(_players[player_id].getGold() - new_potion.price);
                            cout << "You have bought another " << shop_Potions[stoi(item_pick) - 1].name << " Nice puchase!" << endl;
                            potion_bought = true;
                            is_space = true;
                            break;
                        }

                        if (_players[player_id].getPotion(i).name == "")
                        {
                            // cout << "Setting potion " << shop_Potions[stoi(item_pick) -1].name << " At index " << i << " in _potions" <<endl;
                            _players[player_id].setPotion(i, shop_Potions[stoi(item_pick) - 1]); // Sets bought potion in inventory array

                            is_space = true;
                            cout << _players[player_id].getName() << " bought " << shop_Potions[stoi(item_pick) - 1].name << " Nice puchase " << endl;

                            _players[player_id].setGold(_players[player_id].getGold() - shop_Potions[stoi(item_pick) - 1].price);
                            _players[player_id].setNumPotion(_players[player_id].getNumPotions() + 1);
                            potion_bought = true;
                            break;
                        }
                    }

                    if (!is_space)
                    {
                        cout << "You dont have enough space to add a Potion. Do you want to substitute one of your potions? Type 1" << endl;
                        cout << "Potion inventory: " << endl;
                        for (int i = 0; i < 3; i++)
                        {

                            cout << _players[player_id].getPotion(i).name << " (" << _players[player_id].getPotion(i).quantity << ")" << endl;
                        }
                        getline(cin, substite_input);
                        if (substite_input == "1")
                        {
                            cout << "Wich potion do you want to substitute? " << endl;
                            for (int i = 0; i < 3; i++)
                            {
                                cout << "(" << i + 1 << ") " << _players[player_id].getPotion(i).name << endl;
                                cout << _players[player_id].getPotion(i).desc << endl;
                                cout << "Cost: " << _players[player_id].getPotion(i).price << endl;
                                cout << "--------------------------" << endl;
                            }
                            getline(cin, item_pick2);
                            // Checks if valid int, if valid number,
                            while ((!isInteger(item_pick2) || !(stoi(item_pick2) > 0 && stoi(item_pick2) <= 3)))
                            {
                                if ((!isInteger(item_pick2) || !(stoi(item_pick2) > 0 && stoi(item_pick2) <= 3)))
                                {
                                    cout << "Please enter a valid integer from 1-3"
                                         << ". " << endl;
                                }

                                getline(cin, item_pick);
                            }

                            cout << "Substituted " << _players[player_id].getPotion(stoi(item_pick2) - 1).name << " With " << shop_Potions[stoi(item_pick) - 1].name << endl;
                            _players[player_id].setPotion(stoi(item_pick2) - 1, shop_Potions[stoi(item_pick) - 1]);
                            _players[player_id].setGold(_players[player_id].getGold() - shop_Potions[stoi(item_pick) - 1].price);

                            weapon_bought = true;
                        }
                        else
                        {
                            cout << "Okay, puchase cancelled" << endl;
                            weapon_bought = false;
                        }
                    }
                }
                else
                {
                    cout << "Thanks for stopping by. Maybe I'll have something for you later. " << endl;
                }
            }
            else
            {
                cout << "You can unfortunately only buy one weapon this shopping round" << endl;
            }

            break;
        case 3:
            // Nothing happens we will leave store
            break;

        default:
            cout << "Default Switch case in item shop. Expected 1 or 2. Got: " << num_choice << endl;
            break;
        }

    } while (stoi(input) != 3);

    cout << "Thank you, come again! " << endl;
}

bool Game::usePotionMenu(int player_id)
{

    if (_players[player_id].getNumPotions() == 0)
    {
        cout << "You unfortunately don't have any potions on you. Visit the item shop or loot a fallen enemy to get a potion. " << endl;
        return false;
    }

    cout << "Which potion do you want to use? Type 0 to go back." << endl;
    string potion_pick;
    int num_potions = 0;
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (_players[player_id].getPotion(i).name != "")
        {
            count++;
            cout << "(" << count << ") " << _players[player_id].getPotion(i).name << endl;
            cout << _players[player_id].getPotion(i).desc << endl;
            cout << "Cost: " << _players[player_id].getPotion(i).price << endl;
            cout << "--------------------------" << endl;
            num_potions++;
        }
    }
    getline(cin, potion_pick);
    // Checks if valid int, if valid number,
    while ((!isInteger(potion_pick) || !(stoi(potion_pick) >= 0 && stoi(potion_pick) <= num_potions)))
    {
        cout << "Please enter a valid integer from 1-" << num_potions << ". or 0 to quit" << endl;
        getline(cin, potion_pick);
    }
    if (potion_pick == "0")
    {

        return false;
    }

    string potion_name = _players[player_id].getPotion(stoi(potion_pick) - 1).name; // Get name of chosen potion

    usePotion(player_id, potion_name);
    Potion E;
    _players[player_id].setPotion(stoi(potion_pick) - 1, E); // gets rid of potion after use
    _players[player_id].setNumPotion(_players[player_id].getNumPotions() - 1);
    return true;
}

void Game::usePotion(int player_id, string potion_name)
{
    // cout << "We recieved potion name\"" << potion_name << "\"" << endl;
    bool potion_exists = false;
    for (int i = 0; i < _MAX_POTIONS; i++)
    {
        if (_all_potions[i].name == potion_name)
        {
            // cout << "Found potion at index " << i << " in _all_potions array" << endl;
            potion_exists = true;
            break;
        }
    }
    if (potion_exists)
    {
        if (potion_name == "Lesser Health Potion")
        {
            _players[player_id].setHP(_players[player_id].getHP() + 10);
            cout << "Added 10 HP to " << _players[player_id].getName() << endl;
        }
        else if (potion_name == "Greater Health Potion")
        {
            _players[player_id].setHP(_players[player_id].getHP() + 25);
            cout << "Added 25 HP to " << _players[player_id].getName() << endl;
        }
        else if (potion_name == "Lesser Stamina Potion")
        {
            _players[player_id].setStamina(_players[player_id].getStamina() + 10);
            cout << "Added 10 Stamina to " << _players[player_id].getName() << endl;
        }
        else if (potion_name == "Greater Stamina Potion")
        {
            _players[player_id].setStamina(_players[player_id].getStamina() + 25);
            cout << "Added 25 Stamina to " << _players[player_id].getName() << endl;
        }
        else if (potion_name == "Cleansing Potion")
        {
            _players[player_id].setCondition('H');
            cout << "Cleansed " << _players[player_id].getName() << " from all health conditions." << endl;
        }
        else if (potion_name == "Lesser Rejuvenation Potion")
        {
            _players[player_id].setHP(_players[player_id].getHP() + 10);
            _players[player_id].setStamina(_players[player_id].getStamina() + 10);
            cout << "Increased " << _players[player_id].getName() << "'s hp and stamina by 10." << endl;
        }
        else if (potion_name == "Greater Rejuvenation Potion")
        {
            _players[player_id].setHP(_players[player_id].getHP() + 25);
            _players[player_id].setStamina(_players[player_id].getStamina() + 25);
            cout << "Increased " << _players[player_id].getName() << "'s hp and stamina by 25." << endl;
        }
        else if (potion_name == "Minor Strength Potion")
        {
            // Assumes weapon is equipped
            if (_players[player_id].getEquipment(0).type == 'D')
            {
                Equipment temp_equip = _players[player_id].getEquipment(0);
                temp_equip.damage += 2;
                _players[player_id].setEquipment(0, temp_equip);
                cout << "Increased " << _players[player_id].getName() << "'s weapon " << _players[player_id].getEquipment(0).name << "'s damage by 2." << endl;
            }
            else if (_players[player_id].getEquipment(1).type == 'D')
            {
                Equipment temp_equip = _players[player_id].getEquipment(1);
                temp_equip.damage += 2;
                _players[player_id].setEquipment(1, temp_equip);
                cout << "Increased " << _players[player_id].getName() << "'s weapon " << _players[player_id].getEquipment(1).name << "'s damage by 2." << endl;
            }
            else
            {
                cout << "Couldn't find an equipped weapon in " << _players[player_id].getName() << "'s _euipped array" << endl;
            }
        }
        else if (potion_name == "Major Strength Potion")
        {
            // Assumes weapon is equipped
            if (_players[player_id].getEquipment(0).type == 'D')
            {
                Equipment temp_equip = _players[player_id].getEquipment(0);
                temp_equip.damage += 5;
                _players[player_id].setEquipment(0, temp_equip);
                cout << "Increased " << _players[player_id].getName() << "'s weapon " << _players[player_id].getEquipment(0).name << "'s damage by 5." << endl;
            }
            else if (_players[player_id].getEquipment(1).type == 'D')
            {
                Equipment temp_equip = _players[player_id].getEquipment(1);
                temp_equip.damage += 5;
                _players[player_id].setEquipment(1, temp_equip);
                cout << "Increased " << _players[player_id].getName() << "'s weapon " << _players[player_id].getEquipment(1).name << "'s damage by 5." << endl;
            }
            else
            {
                cout << "Couldn't find an equipped weapon in " << _players[player_id].getName() << "'s _euipped array" << endl;
            }
        }
    }
    else
    {
        cout << "Could not find potion" << endl;
    }
}

bool Game::swapWeapon(int player_id)
{
    bool swapped = false;
    int num_equipped = 0;
    int num_inventory = 0;

    for (int i = 0; i < 2; i++)
    {
        if (_players[player_id].getEquipped(i).name != "")
        {
            num_equipped++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (_players[player_id].getEquipment(i).name != "")
        {
            num_inventory++;
        }
    }
    // cout << "DEBUG number of equipped: " << num_equipped << endl;
    // cout << "DEBUG number of inventory: " << num_inventory << endl;

    if (num_inventory == 0)
    {
        cout << "You can't swap your inventory since you dont have any equipment in your inventory. Visit the shop or loot an enemy to gather more equipment." << endl;
        swapped = false;
        return swapped;
    }
    int item_index = 0;
    cout << "Current inventory:" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (_players[player_id].getEquipment(i).name != "")
        {
            if (item_index != 0)
            {
                cout << ", ";
            }
            cout << "(" << item_index << ") " << _players[player_id].getEquipment(i).name;
            item_index++;
        }
    }
    cout << endl;
    cout << "Which item do you want to equip?" << endl;
    string choice;
    getline(cin, choice);
    while (!isInteger(choice) || stoi(choice) < 0 || stoi(choice) > item_index)
    {
        cout << "Enter a value between 0-" << item_index - 1 << endl;
        getline(cin, choice);
    }

    if (num_equipped != 2)
    {
        // cout << "Less than 2 items" << endl;
        for (int i = 0; i < 2; i++)
        {
            if (_players[player_id].getEquipped(i).name == "")
            {
                // sets picket invetory item in open spot in _equipped
                _players[player_id].setEquipment(i, _players[player_id].getEquipment(stoi(choice)));
                _players[player_id].setNumEquipment(_players[player_id].getNumEquipment() + 1);
                cout << "You equipped " << _players[player_id].getEquipped(i).name << endl;
                // erase inventory item
                Equipment E;
                _players[player_id].setInventory(stoi(choice), E);
                swapped = true;

                break;
            }
        }
    }
    else
    {
        cout << "Which currently equipped item do you want to swap with the " << _players[player_id].getEquipment(stoi(choice)).name << "? " << endl;
        for (int i = 0; i < 2; i++)
        {
            if (_players[player_id].getEquipped(i).name != "")
            {
                if (i != 0)
                {
                    cout << ", ";
                }
                cout << "DEBUUUG item print" << endl;
                cout << "(" << i << ") " << _players[player_id].getEquipped(i).name;
            }
        }
        cout << endl;
        string swap_choice;
        getline(cin, swap_choice);
        while (!isInteger(swap_choice) || stoi(swap_choice) < 0 || stoi(swap_choice) >= item_index)
        {
            cout << "Enter a value between 0-" << item_index << endl;
            getline(cin, swap_choice);
        }

        _players[player_id].setEquipment(stoi(swap_choice), _players[player_id].getEquipment(stoi(choice)));
        cout << "You swapped " << _players[player_id].getEquipment(stoi(choice)).name << " for " << _players[player_id].getEquipped(stoi(swap_choice)).name << endl;

        swapped = true;
        return swapped;
    }
    return swapped;
}

bool Game::dropWeapon(int player_id)
{
    bool dropped = false;
    int num_inventory = 0;

    for (int i = 0; i < 10; i++)
    {
        if (_players[player_id].getEquipment(i).name != "")
        {
            num_inventory++;
        }
    }

    if (num_inventory == 0)
    {
        cout << "You can't drop any equipment since your inventory is empty. Visit the shop or loot an enemy to gether more equipment." << endl;
        dropped = false;
        return dropped;
    }
    int item_index = 0;
    cout << "Current inventory:" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (_players[player_id].getEquipment(i).name != "")
        {
            if (item_index != 0)
            {
                cout << ", ";
            }
            cout << "(" << item_index + 1 << ") " << _players[player_id].getEquipment(i).name;
            item_index++;
        }
    }
    cout << endl;
    cout << "Which item do you want to drop? Press 0 to quit." << endl;
    string choice;
    getline(cin, choice);
    while (!isInteger(choice) || stoi(choice) < 0 || stoi(choice) > item_index)
    {
        cout << "Enter a value between 0-" << item_index << endl;
        getline(cin, choice);
    }

    if (choice != "0")
    {
        Equipment E;
        //cout << "DEBUG Setting \"" << E.name << "\" in place of \"" << _players[player_id].getEquipment(stoi(choice) - 1).name << endl;

        cout << "You dropped " << _players[player_id].getEquipment(stoi(choice) - 1).name << endl;
        _players[player_id].setInventory(stoi(choice) - 1, E); // erase inventory item
        dropped = true;

        return dropped;
    }
    else
    {
        cout << "You chose to not drop anything. " << endl;
        dropped = false;
        return dropped;
    }
}

void Game::islandCombat(int player_id)
{
    Entity enemy;
    Entity player = getPlayer(player_id); // Saves players stats in player during fight. Later copies back to _players[player_id]

    // Check if weapons are equipped
    if (player.getEquipped(0).type != 'D' && player.getEquipped(1).type != 'D')
    {
        // cout << "Debug equipment types are " << player.getEquipped(0).type << " and " << player.getEquipped(1).type << endl;
        cout << "Players is missing a weapon. Battle cannot commence" << endl;
        return;
    }

    // save random island enemy in enemy variable
    bool player_turn = true;
    do
    {
        int num_enemies = getNumEnemies();
        int rand_num = rand() % num_enemies;
        enemy = _all_enemies[rand_num];
    } while (enemy.getType() != 'I');

    cout << "You have landed on a island and ran into " << enemy.getName() << endl;
    cout << "Here are player and enemy stats:" << endl;
    cout << "----------------------" << endl;
    player.printStats();
    cout << "----------------------" << endl;
    enemy.printStats();
    cout << "----------------------" << endl;

    // Decide who starts
    if ((enemy.getAdvantage() == false && player.getAdvantage() == false) || (enemy.getAdvantage() == true && player.getAdvantage() == true))
    {
        // if player and enemy have same advantage
        if (rand() % 2 == 1)
        {
            player_turn = false;
        }
        if (!player_turn)
        {
            cout << "After a coin-flip it is decided that " << player.getName() << " starts the game." << endl;
        }
        else
        {
            cout << "After a coin-flip it is decided that " << enemy.getName() << " starts the game." << endl;
        }
    }
    else if ((enemy.getAdvantage() == false && player.getAdvantage() == true))
    {
        player_turn = true;
        cout << "Cince " << player.getName() << " has an advantage, they will start" << endl;
    }
    else if ((enemy.getAdvantage() == true && player.getAdvantage() == false))
    {
        player_turn = false;
        cout << "Cince " << enemy.getName() << " has an advantage, they will start" << endl;
    }

    int option = -1;
    bool turn_used = false;
    bool player_ran = false;

    while (player.getHP() > 0 && enemy.getHP() > 0 && !player_ran)
    {
        double damage = 0;
        double defense = 0;
        double damage_result = 0;
        double hp_reduction = 0;

        if (player_turn)
        {
            turn_used = false;
            while (!turn_used) // While noone runs away
            {
                turn_used = false;
                option = combatMenu();

                switch (option)
                {
                case 1:
                    if (rand() % 5 != 0) // 80% chance of successfull hit
                    {
                        damage = player.getEquipped(0).damage;
                        if (player.getEquipped(1).damage > damage)
                        {
                            damage = player.getEquipped(1).damage;
                        }

                        if (damage == 0)
                        {
                            damage = 1;
                        }

                        damage = rand() % (int)damage;
                        defense = enemy.getEquipped(0).defense;
                        if (enemy.getEquipped(1).defense > defense)
                        {
                            defense = enemy.getEquipped(1).defense;
                        }
                        damage_result = damage - defense;
                        if (damage_result <= 0)
                        {
                            damage_result = 1;
                        }
                        hp_reduction = damage_result * 3.5;
                        enemy.setHP(enemy.getHP() - hp_reduction);
                        cout << enemy.getName() << " was hit for " << hp_reduction << " damage points" << endl;
                        cout << "HP went from " << enemy.getHP() + hp_reduction << " to " << enemy.getHP() << endl;
                    }
                    else
                    {
                        cout << player.getName() << " missed the attack! " << endl;
                    }
                    turn_used = true;
                    break;
                case 2:

                    _players[player_id] = player;

                    usePotionMenu(player_id);
                    player = _players[player_id];

                    turn_used = true;
                    break;

                    break;
                case 3:

                    _players[player_id] = player;
                    swapWeapon(player_id);
                    player = _players[player_id];

                    turn_used = false;
                    break;
                case 4:
                    if (player.getStamina() < 35)
                    {
                        cout << "You don't have enough stamina to run" << endl;
                        cout << "Stamina: " << player.getStamina() << endl;
                        turn_used = false;
                    }
                    else
                    {
                        if (rand() % 100 <= 40)  
                        {
                            cout << "You managed to flee " << enemy.getName() << endl;
                            turn_used = true;
                            player_ran = true;
                        }
                        else
                        {
                            cout << "You tried to run, but " << enemy.getName() << " caught up with you" << endl;
                            turn_used = true;
                        }
                    }

                    break;

                default:
                    cout << "ERROR Default case in Island switch case reached" << endl;
                    break;
                }
            }
        }
        else // if enemy turn
        {
            if (rand() % 5 != 0) // 80% chance of successfull hit
            {

                damage = enemy.getEquipped(0).damage;
                if (enemy.getEquipped(1).damage > damage)
                {
                    damage = enemy.getEquipped(1).damage;
                }
                if (damage == 0)
                {
                    damage = 1;
                }

                damage = rand() % (int)damage;

                defense = player.getEquipped(0).defense;

                if (player.getEquipped(1).defense > defense)
                {
                    defense = player.getEquipped(1).defense;
                }

                damage_result = damage - defense;

                if (damage_result <= 0)
                {
                    damage_result = 1;
                }
                hp_reduction = damage_result * 2.5;

                player.setHP(player.getHP() - hp_reduction);
                cout << player.getName() << " was hit for " << hp_reduction << " damage points" << endl;
                cout << "HP went from " << player.getHP() + hp_reduction << " to " << player.getHP() << endl;
            }
            else
            {
                cout << enemy.getName() << " missed the attack! " << endl;
            }
        }

        player_turn = !player_turn; // flip turns
    }

    if (player.getHP() <= 0)
    {
        cout << player.getName() << " died!" << endl;
    }
    else if (enemy.getHP() <= 0)
    {
        cout << enemy.getName() << " was slain! " << endl;
        cout << "You looted " << enemy.getGold() << " gold and a " << enemy.getEquipment(0).name;

        player.setGold(player.getGold() + enemy.getGold()); // add gold loot

        bool is_space = false;
        for (int i = 0; i < 10; i++) // Iterating through inventory TO SEE IF THERE IS SPACE
        {
            if (player.getEquipment(i).name == "")
            {
                cout << enemy.getEquipped(0).name << " has been added tou you inventory. " << endl;
                player.addToInventory(enemy.getEquipped(0)); // Sets enemy loot in inventory
                is_space = true;
                break;
            }
        }
        if (!is_space)
        {
            string substite_input;
            string item_pick2;
            cout << "You dont have enough space for " << enemy.getEquipment(0).name << " in your inventory. Do you want to substitute one of your equipments for it? Type 1." << endl;
            cout << "Equipment inventory: " << endl;
            for (int i = 0; i < 10; i++)
            {
                cout << player.getEquipment(i).name << endl;
            }
            getline(cin, substite_input);
            if (substite_input == "1")
            {
                cout << "Wich Equipment do you want to substitute? " << endl;
                for (int i = 0; i < 10; i++)
                {
                    cout << "(" << i + 1 << ") " << _players[player_id].getEquipment(i).name << endl;
                    cout << _players[player_id].getEquipment(i).desc << endl;
                    cout << "Cost: " << _players[player_id].getEquipment(i).price << endl;
                    cout << "--------------------------" << endl;
                }
                getline(cin, item_pick2);
                // Checks if valid int, if valid number,
                while ((!isInteger(item_pick2) || !(stoi(item_pick2) > 0 && stoi(item_pick2) <= 10)))
                {

                    cout << "Please enter a valid integer from 1-" << 10 << ". " << endl;

                    getline(cin, item_pick2);
                }

                player.setEquipment(stoi(item_pick2) - 1, enemy.getEquipment(0));
                cout << "Substituted " << player.getEquipment(stoi(item_pick2) - 1).name << " With " << enemy.getEquipment(0).name << endl;
            }
            else
            {
                cout << "Okay, " << enemy.getEquipment(0).name << " will be left on the island." << endl;
            }
        }
    }

    /*





    */
    _players[player_id] = player; // save player changes
    if (enemy.getHP() <= 0)       // here because we need to save player first
    {
        cout << "As a reward for beating the great " << enemy.getName() << ". You can now visit the item shop. " << endl;
        itemShop(player_id);
    }
    cout << "Battle over" << endl;
    return;
}

void Game::epicCombat()
{
    Entity enemy;
    Entity player1 = getPlayer(0); // Saves player1s stats in player during fight. Later copies back to _players[player_id]
    Entity player2 = getPlayer(1); // Saves player2s stats in player during fight. Later copies back to _players[player_id]

    // Check if weapons are equipped
    if (player1.getEquipped(0).type != 'D' && player1.getEquipped(1).type != 'D')
    {
        // cout << "Debug equipment types are " << player.getEquipped(0).type << " and " << player.getEquipped(1).type << endl;
        cout << player1.getName() << " is missing a weapon. Battle cannot commence" << endl;
        return;
    }
    if (player2.getEquipped(0).type != 'D' && player2.getEquipped(1).type != 'D')
    {
        // cout << "Debug equipment types are " << player.getEquipped(0).type << " and " << player.getEquipped(1).type << endl;
        cout << player2.getName() << " is missing a weapon. Battle cannot commence" << endl;
        return;
    }

    do
    {
        int num_enemies = getNumEnemies();
        int rand_num = rand() % num_enemies;
        enemy = _all_enemies[rand_num];
        // cout << "DEBUG looking for epic enemy" << endl;
    } while (enemy.getType() != 'E');

    // print stats
    cout << player1.getName() << " and " << player2.getName() << " landed on a island and ran into the epic " << enemy.getName() << endl;
    cout << "Here are the players' and the enemy's stats:" << endl;
    cout << "----------------------" << endl;
    player1.printStats();
    cout << "----------------------" << endl;
    player2.printStats();
    cout << "----------------------" << endl;
    enemy.printStats();
    cout << "----------------------" << endl;

    // players and enemy turns
    int option = -1;
    bool turn_used = false;
    bool players_turns = false; // enemy starts always
    bool is_space = false;

    while (player1.getHP() > 0 && player2.getHP() > 0 && enemy.getHP() > 0)
    {
        double damage = 0;
        char element = 'N';
        double defense = 0;
        double hp_reduction = 0;
        double damage_result = 0;

        if (players_turns)
        {

            // PLayer1 turn
            turn_used = false;
            while (!turn_used) // While noone runs away
            {
                turn_used = false;
                cout << player1.getName() << "'s turn" << endl;
                option = combatMenu();

                switch (option)
                {
                case 1:
                    if (rand() % 5 != 0) // 80% chance of successfull hit
                    {
                        damage = player1.getEquipped(0).damage;
                        element = player1.getEquipped(0).element;
                        if (player1.getEquipped(1).damage > damage)
                        {
                            damage = player1.getEquipped(1).damage;
                            element = player1.getEquipped(1).element;
                        }

                        if (enemy.getElWeak() == element)
                        {
                            cout << "DEBUG player has el adv" << endl;
                            damage *= 2;
                        }

                        defense = enemy.getEquipped(0).defense;
                        element = enemy.getEquipped(0).element;
                        if (enemy.getEquipped(1).defense > defense)
                        {
                            defense = enemy.getEquipped(1).defense;
                            element = enemy.getEquipped(1).element;
                        }

                        if (element == player1.getElWeak())
                        {
                            cout << "Enemy shield has advantage" << endl;
                            damage /= 2;
                        }

                        damage_result = damage - defense;
                        if (damage_result <= 0)
                        {
                            damage_result = 1;
                        }
                        hp_reduction = damage_result * 3.5;
                        enemy.setHP(enemy.getHP() - hp_reduction);
                        cout << enemy.getName() << " was hit for " << hp_reduction << " damage points" << endl;
                        cout << "HP went from " << enemy.getHP() + hp_reduction << " to " << enemy.getHP() << endl;
                    }
                    else
                    {
                        cout << player1.getName() << " missed the attack! " << endl;
                    }
                    turn_used = true;
                    break;
                case 2:

                    _players[0] = player1;

                    usePotionMenu(0);
                    player1 = _players[0];

                    turn_used = true;
                    break;

                    break;
                case 3:

                    _players[0] = player1;
                    swapWeapon(0);
                    player1 = _players[0];

                    turn_used = false;
                    break;
                case 4:

                    cout << "You cant run from a Epic Battle!" << endl;

                    turn_used = false;

                    break;

                default:
                    cout << "ERROR Default case in Island switch case reached" << endl;
                    break;
                }
            }

            // Check if player1 killed enemy
            if (enemy.getHP() <= 0)
            {
                break;
            }

            // player 2 turn
            turn_used = false;
            while (!turn_used) // While noone runs away
            {
                turn_used = false;
                cout << player2.getName() << "'s turn" << endl;
                option = combatMenu();

                switch (option)
                {
                case 1:
                    if (rand() % 5 != 0) // 80% chance of successfull hit
                    {
                        damage = player2.getEquipped(0).damage;
                        element = player2.getEquipped(0).element;
                        if (player2.getEquipped(1).damage > damage)
                        {
                            damage = player2.getEquipped(1).damage;
                            element = player2.getEquipped(1).element;
                        }

                        if (enemy.getElWeak() == element)
                        {
                            //cout << "DEBUG player has el adv" << endl;
                            damage *= 2;
                        }

                        defense = enemy.getEquipped(0).defense;
                        element = enemy.getEquipped(0).element;
                        if (enemy.getEquipped(1).defense > defense)
                        {
                            defense = enemy.getEquipped(1).defense;
                            element = enemy.getEquipped(1).element;
                        }

                        if (element == player2.getElWeak())
                        {
                            cout << "Enemy shield has advantage" << endl;
                            damage /= 2;
                        }

                        damage_result = damage - defense;
                        if (damage_result <= 0)
                        {
                            damage_result = 1;
                        }
                        hp_reduction = damage_result * 3.5;
                        enemy.setHP(enemy.getHP() - hp_reduction);
                        cout << enemy.getName() << " was hit for " << hp_reduction << " damage points" << endl;
                        cout << "HP went from " << enemy.getHP() + hp_reduction << " to " << enemy.getHP() << endl;
                    }
                    else
                    {
                        cout << player2.getName() << " missed the attack! " << endl;
                    }
                    turn_used = true;
                    break;
                case 2:

                    _players[1] = player2;

                    usePotionMenu(1);
                    player2 = _players[1];

                    turn_used = true;
                    break;

                    break;
                case 3:

                    _players[1] = player2;
                    swapWeapon(1);
                    player2 = _players[1];

                    turn_used = false;
                    break;
                case 4:

                    cout << "You cant run from a Epic Battle!" << endl;

                    turn_used = false;

                    break;

                default:
                    cout << "ERROR Default case in Island switch case reached" << endl;
                    break;
                }
            }
        }
        else // if enemy turn
        {
            if (rand() % 5 != 0) // 80% chance of successfull hit
            {

                damage = enemy.getEquipped(0).damage;
                element = enemy.getEquipped(0).element;
                if (enemy.getEquipped(1).damage > damage)
                {
                    damage = enemy.getEquipped(1).damage;
                    element = enemy.getEquipped(1).element;
                }

                // player 1 attacked
                if (player1.getElWeak() == element) // Element str
                {
                    //cout << "DEBUG Enemy weapon has element advantage" << endl;
                    damage *= 2;
                }
                // Get def
                defense = player1.getEquipped(0).defense;
                element = player1.getEquipped(0).element;
                if (player1.getEquipped(1).defense > defense)
                {
                    defense = player1.getEquipped(1).defense;
                    element = player1.getEquipped(1).element;
                }

                if (enemy.getElWeak() == element)
                {
                    //cout << "DEBUG Player shield has elemental advanteage. dam/2" << endl;
                    damage /= 2;
                }

                damage_result = damage - defense;
                //cout << "DEBUG Dam res: " << damage_result << endl;

                if (damage_result <= 0)
                {
                    damage_result = 1;
                }
                hp_reduction = damage_result * 2.5;

                cout << player1.getName() << " was hit for " << hp_reduction << " damage points" << endl;
                cout << "HP went from " << player1.getHP() + hp_reduction << " to " << player1.getHP() << endl;
                player1.setHP(player1.getHP() - hp_reduction);

                // Player 2 attacked
                damage = enemy.getEquipped(0).damage;
                element = enemy.getEquipped(0).element;
                if (enemy.getEquipped(1).damage > damage)
                {
                    damage = enemy.getEquipped(1).damage;
                    element = enemy.getEquipped(1).element;
                }

                if (player2.getElWeak() == element) // Element str
                {
                    //cout << "DEBUG Enemy weapon has element advantage" << endl;
                    damage *= 2;
                }
                // Get def
                defense = player2.getEquipped(0).defense;
                element = player2.getEquipped(0).element;
                if (player2.getEquipped(1).defense > defense)
                {
                    defense = player2.getEquipped(1).defense;
                    element = player2.getEquipped(1).element;
                }

                if (enemy.getElWeak() == element)
                {
                    //cout << "DEBUG Player shield has elemental advanteage. dam/2" << endl;
                    damage /= 2;
                }

                damage_result = damage - defense;
                //cout << "DEBUG Dam res: " << damage_result << endl;

                if (damage_result <= 0)
                {
                    damage_result = 1;
                }
                hp_reduction = damage_result * 2.5;

                cout << player2.getName() << " was hit for " << hp_reduction << " damage points" << endl;
                cout << "HP went from " << player2.getHP() + hp_reduction << " to " << player2.getHP() << endl;
                player2.setHP(player2.getHP() - hp_reduction);
            }
            else
            {
                cout << enemy.getName() << " missed the attack! " << endl;
            }
        }

        players_turns = !players_turns; // flip turns
    }

    // looting
    if (player1.getHP() <= 0)
    {
        cout << player1.getName() << " died!" << endl;
        cout << player2.getName() << " is the winner! " << endl;
    }
    else if (player2.getHP() <= 0)
    {
        cout << player2.getName() << " died!" << endl;
        cout << player1.getName() << " is the winner! " << endl;
    }
    else if (enemy.getHP() <= 0)
    {
        cout << enemy.getName() << " was slain! " << endl;
        cout << "You looted " << enemy.getGold() << " gold and " << enemy.getEquipped(0).name << endl;

        // add gold loot
        player1.setGold(player1.getGold() + enemy.getGold());
        player2.setGold(player2.getGold() + enemy.getGold());

        // Player 1 item looting
        is_space = false;
        for (int i = 0; i < 10; i++) // Iterating through inventory TO SEE IF THERE IS SPACE
        {
            if (player1.getEquipment(i).name == "")
            {
                player1.addToInventory(enemy.getEquipped(0)); // Sets enemy loot in inventory
                cout << enemy.getEquipped(0).name << " has been added to " << player1.getName() << "' inventory. " << endl;
                is_space = true;
                break;
            }
        }
        if (!is_space)
        {
            string substite_input;
            string item_pick2;
            cout << "You dont have enough space for " << enemy.getEquipment(0).name << " in your inventory. \nDo you want to substitute one of your equipments for it? Type 1 for yes, 0 for no." << endl;
            cout << "Equipment inventory: " << endl;
            for (int i = 0; i < 10; i++)
            {
                cout << player1.getEquipment(i).name << endl;
            }
            getline(cin, substite_input);
            if (substite_input == "1")
            {
                cout << "Wich Equipment do you want to substitute? " << endl;
                for (int i = 0; i < 10; i++)
                {
                    cout << "(" << i + 1 << ") " << _players[0].getEquipment(i).name << endl;
                    cout << _players[0].getEquipment(i).desc << endl;
                    cout << "Cost: " << _players[0].getEquipment(i).price << endl;
                    cout << "--------------------------" << endl;
                }
                getline(cin, item_pick2);
                // Checks if valid int, if valid number,
                while ((!isInteger(item_pick2) || !(stoi(item_pick2) > 0 && stoi(item_pick2) <= 10)))
                {

                    cout << "Please enter a valid integer from 1-" << 10 << ". " << endl;

                    getline(cin, item_pick2);
                }

                player1.setEquipment(stoi(item_pick2) - 1, enemy.getEquipment(0));
                cout << "Substituted " << player1.getEquipment(stoi(item_pick2) - 1).name << " With " << enemy.getEquipment(0).name << endl;
            }
            else
            {
                cout << "Okay, " << enemy.getEquipment(0).name << " will be left on the island." << endl;
            }
        }

        /*



        */
        // Player 2 item looting
        is_space = false;
        for (int i = 0; i < 10; i++) // Iterating through inventory TO SEE IF THERE IS SPACE
        {
            if (player2.getEquipment(i).name == "")
            {
                player2.addToInventory(enemy.getEquipped(0)); // Sets enemy loot in inventory
                cout << enemy.getEquipped(0).name << " has been added to " << player2.getName() << "' inventory. " << endl;
                is_space = true;
                break;
            }
        }
        if (!is_space)
        {
            string substite_input;
            string item_pick2;
            cout << "You dont have enough space for " << enemy.getEquipment(0).name << " in your inventory. \nDo you want to substitute one of your equipments for it? Type 1 for yes, 0 for no." << endl;
            cout << "Equipment inventory: " << endl;
            for (int i = 0; i < 10; i++)
            {
                cout << player2.getEquipment(i).name << endl;
            }
            getline(cin, substite_input);
            if (substite_input == "1")
            {
                cout << "Wich Equipment do you want to substitute? " << endl;
                for (int i = 0; i < 10; i++)
                {
                    cout << "(" << i + 1 << ") " << _players[1].getEquipment(i).name << endl;
                    cout << _players[1].getEquipment(i).desc << endl;
                    cout << "Cost: " << _players[1].getEquipment(i).price << endl;
                    cout << "--------------------------" << endl;
                }
                getline(cin, item_pick2);
                // Checks if valid int, if valid number,
                while ((!isInteger(item_pick2) || !(stoi(item_pick2) > 0 && stoi(item_pick2) <= 10)))
                {

                    cout << "Please enter a valid integer from 1-" << 10 << ". " << endl;

                    getline(cin, item_pick2);
                }

                player2.setEquipment(stoi(item_pick2) - 1, enemy.getEquipment(0));
                cout << "Substituted " << player2.getEquipment(stoi(item_pick2) - 1).name << " With " << enemy.getEquipment(0).name << endl;
            }
            else
            {
                cout << "Okay, " << enemy.getEquipment(0).name << " will be left on the island." << endl;
            }
        }
    }

    // copy back players
    _players[0] = player1;
    _players[1] = player2;
}

void Game::hiddenChest(int player_id)
{
    int riddle_idx = 0;
    do
    {
        riddle_idx = rand()%_MAX_RIDDLES;
    } while (_riddles[riddle_idx] == "");
    
    cout << _riddles[riddle_idx]<<endl;
    
    string answer;
    getline(cin,answer);
    
    
    if(_riddles_answers[riddle_idx] == answer)
    {
        cout << "You answer correctly. You now get benefits"<<endl;

        int rand_num = rand() %100;

        if(rand_num <= 30)//Stamina Refill (30% chance):
        {
            int stamina_boost = rand()%20 +10;
            if(_players[player_id].getStamina() + stamina_boost < 100)
            {
                cout << "You found a stamina boost of "<<stamina_boost<<" in the chest" <<endl;
                _players[player_id].setStamina(_players[player_id].getStamina() + stamina_boost);
            }
            else
            {
                cout << "You were about to get a stamina boost from the chest, but it is capped at 100"<<endl;
            }

        }
        else if(rand_num <= 60) //Gold Windfall (30% chance) 
        {
            int gold = rand()%20 + 20;
            _players[player_id].setGold(_players[player_id].getGold() + gold);
            cout << "You found " <<gold << " gold coins in the chest"<<endl;
            //I dont want to cap this

        }
        else // Damage Buff
        {
            int weapon_buff = rand()%5 +5;
            int best_weapon_num = 0;
            if(_players[player_id].getEquipped(1).damage > _players[player_id].getEquipped(best_weapon_num).damage)
            {
                best_weapon_num = 1;
            }
            
            Equipment best_weapon = _players[player_id].getEquipped(best_weapon_num);
            best_weapon.damage += weapon_buff;
            _players[player_id].setEquipment(best_weapon_num,best_weapon);
            cout << "You found a " << weapon_buff << " weapon buff in the chest. It has now been added to "<<best_weapon.name<<"."<<endl;
        }
        

    }
    else
    {
        cout <<"That is not the right answer ("<<_riddles_answers[riddle_idx]<<"). No chest for you!"<<endl;
    }

}

// Prints stats of all the players and enemies that are loaded in
void Game::printAllStats()
{
    cout << "         ALL CHARACTERS " << endl;
    // cout << "DEBUG Iterating players from 0 to " << _num_players << endl;
    for (int i = 0; i < _MAX_PLAYERS; i++)
    {
        // cout << "DEBUG Iteration " << i << "| Player name: " << _all_players[i].getName();
        if (_all_players[i].getName() != "")
        {
            // cout << "DEBUG Trying to print " << _all_players[i].getName() << "'s stats now" << endl;
            _all_players[i].printStats();
            cout << "----------------------------------------------" << endl;
        }
        else
        {
            // cout << "Player not found" << endl;
        }
    }
    // cout << "DEBUG Iterating enemies from 0 to " << _num_enemies << endl;
    cout << "            ALL ENEMIES " << endl;
    for (int i = 0; i < _MAX_ENEMIES; i++)
    {
        // cout << "DEBUG Trying to print " << _all_enemies[i].getName() << "'s stats now" << endl;
        if (_all_enemies[i].getName() != "")
        {
            _all_enemies[i].printStats();
            cout << "----------------------------------------------" << endl;
        }
        else
        {
            // cout << "Enemy not found" << endl;
        }
    }
}

void Game::printAllEquipment()
{
    cout << "         EQUIPMENTS" << endl;
    for (int i = 0; i < _MAX_EQUIPMENT; i++)
    {
        if (_all_equipment[i].name != "")
        {
            cout << "Name:   \t" << _all_equipment[i].name << endl;
            cout << "Description:\t" << _all_equipment[i].desc << endl;
            cout << "Type:   \t" << _all_equipment[i].type << endl;
            cout << "Element:\t" << _all_equipment[i].element << endl;
            cout << "Damage: \t" << _all_equipment[i].damage << endl;
            cout << "Defense:\t" << _all_equipment[i].defense << endl;
            cout << "Price:  \t" << _all_equipment[i].price << endl;
            cout << "--------------------------------------------" << endl;
        }
    }
}

void Game::printAllPotions()
{
    cout << "         POTIONS" << endl;
    for (int i = 0; i < _MAX_POTIONS; i++)
    {
        if (_all_potions[i].name != "")
        {
            cout << "Name:        \t" << _all_potions[i].name << endl;
            cout << "Description: \t" << _all_potions[i].desc << endl;
            cout << "Type:        \t" << _all_potions[i].type << endl;
            cout << "Effect value:\t" << _all_potions[i].effect_value << endl;
            cout << "Price:       \t" << _all_potions[i].price << endl;
            cout << "Quantity:    \t" << _all_potions[i].quantity << endl;
            cout << "--------------------------------------------" << endl;
        }
    }
}

// Prints options, MOve, Swap/Drop, Potion,stats or quir. returns valid option 1-5
int Game::mainMenu()
{
    cout << "MENU OPTIONS" << endl;
    // cout << "Remember that you can always swap/drop weapons and print stats" << endl;
    cout << "1. Move " << endl;
    cout << "2. Swap" << endl;
    cout << "3. Drop Equipment" << endl;
    cout << "4. Use Potion" << endl;
    cout << "5. Print Player Stats" << endl;
    cout << "6. Quit" << endl;

    string pick;
    getline(cin, pick);
    while (pick != "1" && pick != "2" && pick != "3" && pick != "4" && pick != "5" && pick != "6")
    {
        cout << "please choose a valid input (1-6) " << endl;
        getline(cin, pick);
    }
    int option = stoi(pick);
    return option;
}

int Game::combatMenu()
{
    cout << "Which action would you like to take?" << endl;
    cout << "1. Attack " << endl;
    cout << "2. Use Potion" << endl;
    cout << "3. Swap Weapon" << endl;
    cout << "4. Attempt to Run (40% success rate)" << endl;

    string pick;
    getline(cin, pick);
    while (pick != "1" && pick != "2" && pick != "3" && pick != "4")
    {
        cout << "please choose a valid input (1-4) " << endl;
        getline(cin, pick);
    }
    int option = stoi(pick);
    return option;
}

bool Game::saveResults(string file_name)
{
    ofstream out_file(file_name);
    if (out_file.fail()) // Dont think this can happen
    {
        return false;
    }

    for (int i = 0; i < 2; i++)
    {
        if (_players[i].getName() != "")
        {
            if (i != 0)
            {
                out_file << "------------------" << endl;
            }
            out_file << "Name: " << _players[i].getName() << endl;
            out_file << "Was winner: " << _players[i].getPlayerWon() << endl;
            out_file << "Gold: " << _players[i].getGold() << endl;
            out_file << "HP: " << _players[i].getHP() << endl;
            out_file << "Stamina: " << _players[i].getStamina() << endl;
            out_file << "Equipment: ";
            for (int j = 0; j < 2; j++)
            {
                if (_players[i].getEquipment(j).name != "")
                {
                    if (j != 0)
                    {
                        out_file << ", ";
                    }
                    out_file << _players[i].getEquipment(j).name;
                    if (_players[i].getEquipment(j).type == 'D')
                    {
                        out_file << " (Damage: " << _players[i].getEquipment(j).damage << ")";
                    }
                    else
                    {
                        out_file << " (Defense: " << _players[i].getEquipment(j).defense << ")";
                    }
                }
            }
            out_file << endl;
        }
    }

    out_file.close();
    return true;
}