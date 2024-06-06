#include "game.hpp"

// Split function
int split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    const int string_length = (int)input_string.length();
    int separator_instances = 0;

    if (input_string == "")
    {
        return 0;
    }

    for (int i = 0; i < string_length; i++)
    {
        if (input_string[i] == separator)
        {
            separator_instances += 1;
        }
    }
    // cout << "we have " << separator_instances << " separator instances which means " << separator_instances + 1 << " substrings. " << endl;

    if (separator_instances == 0)
    {
        arr[0] = input_string;
        return 1;
    } // no need for else statement since it returns if condition is true

    int max_capacity = ARR_SIZE;
    if ((separator_instances + 1) > ARR_SIZE)
    {
        max_capacity = separator_instances + 1;
    }

    int current_index = 0; // index for array
    int start_index = 0;
    int end_index = 0;
    int NUM_ELEMENTS = 0;
    string substring;
    int substrings_added = 0;

    int i = 0;
    while (i < string_length && substrings_added < max_capacity)
    {
        // cout << "Iteration " << i << endl;

        if (input_string[i] == separator || i == string_length)
        {
            end_index = i;
            substring = input_string.substr(start_index, (end_index - start_index));

            if (current_index < ARR_SIZE)
            {
                arr[current_index] = substring;
                substrings_added += 1;
                NUM_ELEMENTS += 1;
                current_index += 1;
            }
            else
            {
                // If there are more substrings than the array can hold, return -1
                return -1;
            }
            start_index = end_index + 1;
        }

        i++;
        // cout << "i:" << i << " < String length:"<< string_length << " AND  Substrings added:" << substrings_added << " <= Max capacity:" << max_capacity << endl;
    }
    if (start_index < string_length && substrings_added <= max_capacity) // takes care of last substring.
    {
        substring = input_string.substr(start_index, (string_length - start_index));
        if (current_index < ARR_SIZE)
        {
            arr[current_index] = substring;
            substrings_added += 1;
            NUM_ELEMENTS += 1;
            current_index += 1;
        }
        else
        {
            // If there are more substrings than the array can hold, return -1
            return -1;
        }
        start_index = end_index + 1;
    }
    // cout << "Number of elements: " << separator_instances + 1 << " Arr size: " << ARR_SIZE << endl;
    if (separator_instances + 1 > ARR_SIZE) // There is one more substring elements than separator instance
    {
        return -1;
    }

    return NUM_ELEMENTS;
}

// Validates doubles
bool isDouble(string input)
{
    int size = input.size();
    if (size == 0)
    {
        return false;
    }

    if (input[0] == '-')
    {
        input.erase(0, 1);
    }

    size = input.size();
    if (size == 0)
    {
        return false;
    }

    bool point_found = false;
    bool has_num = false;

    for (int i = 0; i < size; i++)
    {
        if (isdigit(input[i]) && !has_num)
        {
            has_num = true;
        }
        if ((!isdigit(input[i]) && input[i] != '.') || (input[i] == '.' && point_found) || isspace(input[i]))
        {
            return false;
        }
        if (input[i] == '.')
        {
            point_found = true;
        }
    }
    if (has_num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Checks if a string is a integer
bool isInteger(string input)
{
    if (input == "")
    {
        return false;
    }

    if (input[0] == '-')
    {
        input.erase(0, 1);
    }

    if (input == "")
    {
        return false;
    }

    int size = input.size();

    for (int i = 0; i < size; i++)
    {
        if (isdigit(input[i]) == false)
        {
            return false;
        }
    }
    return true;
}

// Reads data from the text file filename and fills the array of Entity objects characters[].
// For each character, set the value of _is_enemy based on the provided is_enemy parameter.
bool loadCharacters(string filename, Entity characters[], const int CHARACTERS_SIZE, bool is_enemy)
{
    ifstream in_file(filename);
    if (in_file.fail())
    {
        return false;
    }

    string name;
    double hp;
    int gold;
    char condition;

    string splitted_line[10]; // array with all elements from one input line. Size should be 4, but we overshoot with 10
    int num_elements;         // number of elements in splitted string
    int curr_index = 0;       // Keeps track of where in the character array we are

    string line;            // Input lines from textfile
    getline(in_file, line); // Get rid of first line since it is a title-line

    while (getline(in_file, line) && curr_index < CHARACTERS_SIZE)
    {
        num_elements = split(line, '|', splitted_line, 10);

        if (num_elements != 4) // skip invalid rows
        {
            continue;
        }

        // NOTE THE FOLLOWING VALIDATION IS REPETETIVE SINCE IT IS ALREADY CHECKED IN SETTERS

        name = splitted_line[0]; // If its a valid double we add it otherwise it is set to 0
        if (isDouble(splitted_line[1]))
        {
            hp = stod(splitted_line[1]);
        }
        else
        {
            hp = 0;
        }

        if (isInteger(splitted_line[2])) // if it is a valid int it will be added otherwise it is set to 0
        {
            gold = stoi(splitted_line[2]);
        }
        else
        {
            gold = 0;
        }

        if (splitted_line[3][0] == 'H' || splitted_line[3][0] == 'D' || splitted_line[3][0] == 'P') // if its a valid condition it is set, else it is 'H'
        {
            condition = splitted_line[3][0]; // add index 0 to make it a char
        }
        else
        {
            condition = 'H';
        }

        characters[curr_index].setName(name);
        characters[curr_index].setHP(hp);
        characters[curr_index].setGold(gold);
        characters[curr_index].setCondition(condition);
        characters[curr_index].setIsEnemy(is_enemy);
        curr_index++;
    }

    return true;
}

// Prints main menu with 6 options
void printMenu()
{
    cout << "Select from the following options:" << endl;
    cout << "1. Select Players and Enemies" << endl;
    cout << "2. Display Players' stats" << endl;
    cout << "3. Display Enemies' stats" << endl;
    cout << "4. Edit a Player's Stats" << endl;
    cout << "5. Edit an Enemy's Stats" << endl;
    cout << "6. Exit" << endl;
}

void mainMenu()
{
    Game new_game; // instanciate game with default constructor

    Entity players[2]; // declare aray of 2 players for game initialization
    Entity enemies[2]; // declare aray of 2 enemies for game initialization
    string player1_name;
    string player2_name;
    string enemy1_name;
    string enemy2_name;

    int choice = -1;
    while (choice != 6) // run code until choice 6
    {
        const int MAX_CHARACTERS = 5;
        const int MAX_ENEMIES = 5;
        string player_file = "players_full.txt";
        string enemy_file = "enemies_full.txt";
        Entity avalible_characters[MAX_CHARACTERS]; // List of avalible character of size MAX_CHARACTERS
        Entity avalible_enemies[MAX_ENEMIES];       // List of avalible enemies of size MAX_ENEMIES

        string player_choice;
        string enemy_choice;
        bool valid_player_choice = false;
        bool valid_enemy_choice = false;
        string value; // varable for value inputs for changing enteties attributes
        int player_index; //Used when finding a players index to edit attributes
        int enemy_index; //Used when finding a enemy's index to edit attributes

        string str_choice;
        string str_sub_choice;
        int sub_choice;

        printMenu();
        getline(cin, str_choice);
        // Get valid input
        while (!(str_choice == "1" || str_choice == "2" || str_choice == "3" || str_choice == "4" || str_choice == "5" || str_choice == "6"))
        {
            cout << "Invalid input. Please enter a valid choice (1-6)" << endl;
            printMenu();
            getline(cin, str_choice);
        }

        choice = stoi(str_choice); // turn it into an integer so we can use switch-statement
        switch (choice)            // switch between all options
        {
        case 1:

            if (!loadCharacters(player_file, avalible_characters, MAX_CHARACTERS, false)) // Loads in all players to avaible_players array, if fail propt why
            {
                cout << "Could not open " << player_file << " to initialize avalible players array " << endl;
            }

            if (!loadCharacters(enemy_file, avalible_enemies, MAX_ENEMIES, true)) // Loads in all enemies to avalible_enemies array, if fail propt
            {
                cout << "Could not open " << enemy_file << " to initialize avalible enemies array " << endl;
            }

            // PLAYER 1 PICK
            cout << "Player 1" << endl;
            cout << "Here is a list of players you can select from:" << endl;
            for (int j = 0; j < MAX_CHARACTERS; j++)
            {
                //Shows all avalible players (Not the ones currently active)
                if (avalible_characters[j].getName() == "" )
                {
                    continue;
                }
                avalible_characters[j].printStats();
                cout << "----------------------------------------------" << endl;
            }

            do
            {
                cout << "The selected character is: " << endl;
                valid_player_choice = false; // reset valid chice bool value
                getline(cin, player_choice);
                for (int j = 0; j < MAX_CHARACTERS; j++) // iterate through all avalible characters and check if there is a player with that name
                {
                    if (avalible_characters[j].getName() == player_choice)
                    {
                        valid_player_choice = true;          // if valid choice then update bool value which will break the outer loop an inner
                        players[0] = avalible_characters[j]; // save first player in player array

                        break;
                    }
                }

                if (!valid_player_choice)
                {
                    cout << "Invalid selection. Select from the list!" << endl;
                }

            } while (!valid_player_choice);
            player1_name = player_choice;

            // PLAYER 2 PICK
            cout << "Player 2" << endl;
            cout << "Here is a list of players you can select from:" << endl;
            for (int j = 0; j < MAX_CHARACTERS; j++)
            {
                //Shows all characters except active ones which will be skipped
                if (avalible_characters[j].getName() == "" || avalible_characters[j].getName() == player1_name )
                {
                    continue;
                }
                avalible_characters[j].printStats();
                cout << "----------------------------------------------" << endl;
            }

            do
            {
                cout << "The selected character is: " << endl;
                valid_player_choice = false; // reset valid chice bool value
                getline(cin, player_choice);
                for (int j = 0; j < MAX_CHARACTERS; j++) // iterate through all avalible characters and check if there is a player with that name
                {
                    if (avalible_characters[j].getName() == player_choice && player_choice != player1_name)
                    {
                        valid_player_choice = true;          // if valid choice then update bool value which will break the outer loop and inner loop
                        players[1] = avalible_characters[j]; // save second player in player array
                        break;
                    }
                }

                if (!valid_player_choice)
                {
                    cout << "Invalid selection. Select from the list!" << endl;
                }

            } while (!valid_player_choice);
            player2_name = player_choice;
            //cout << player_choice << " is picked!" << endl;

            /*
            -------------------------ENEMY PICKS --------------------------
            */

            // Enemy 1 PICK
            cout << "Enemy 1" << endl;
            cout << "Here is a list of enemies you can select from:" << endl;
            for (int j = 0; j < MAX_ENEMIES; j++)
            {
                //shows all avalible enemies excepts selected ones
                if (avalible_enemies[j].getName() == "" )
                {
                    continue;
                }
                avalible_enemies[j].printStats();
                cout << "----------------------------------------------" << endl;
            }

            do
            {
                cout << "The selected character is: " << endl;
                valid_enemy_choice = false; // reset valid chice bool value
                getline(cin, enemy_choice);
                for (int j = 0; j < MAX_ENEMIES; j++) // iterate through all avalible enemies and check if there is an enemy with that name
                {
                    if (avalible_enemies[j].getName() == enemy_choice )
                    {
                        valid_enemy_choice = true;           // if valid choice then update bool value which will break the outer loop an inner
                        enemies[0] = avalible_enemies[j]; // save first enemy in array
                        break;
                    }
                }

                if (!valid_enemy_choice)
                {
                    cout << "Invalid selection. Select from the list!" << endl;
                }

            } while (!valid_enemy_choice);
            enemy1_name = enemy_choice;

            // ENEMY 2 PICK
            cout << "Enemy 2" << endl;
            cout << "Here is a list of enemies you can select from:" << endl;
            for (int j = 0; j < MAX_ENEMIES; j++)
            {
                if (avalible_enemies[j].getName() == enemy1_name || avalible_enemies[j].getName() == "")
                {
                    continue; // skips previously picked enemies
                }

                avalible_enemies[j].printStats();
                cout << "----------------------------------------------" << endl;
            }

            do
            {
                cout << "The selected character is: " << endl;
                valid_enemy_choice = false; // reset valid chice bool value
                getline(cin, enemy_choice);
                for (int j = 0; j < MAX_ENEMIES; j++) // iterate through all avalible enemy and check if there is an enemy with that name
                {
                    if (avalible_enemies[j].getName() == enemy_choice && enemy_choice != enemy1_name)
                    {
                        valid_enemy_choice = true;           // if valid choice then update bool value which will break the outer loop and inner loop
                        enemies[1] = avalible_enemies[j]; // save second enemy in array
                        break;
                    }
                }

                if (!valid_enemy_choice)
                {
                    cout << "Invalid selection. Select from the list!" << endl;
                }

            } while (!valid_enemy_choice);
            enemy2_name = enemy_choice;
            //cout << enemy_choice << " is picked!" << endl;

            new_game.setPlayersList(players, 2); // set the players in the game
            new_game.setEnemiesList(enemies, 2); // set the enemies in the game
            // game entity arrays should be filled now

            break;

        case 2:

            for (int i = 0; i < new_game.getNumPlayers(); i++)
            {
                players[i].printStats();
                cout << "----------------------------------------------" << endl;
            }

            break;
        case 3:

            for (int i = 0; i < new_game.getNumEnemies(); i++)
            {
                enemies[i].printStats();
                cout << "----------------------------------------------" << endl;
            }

            break;
        case 4:

            valid_player_choice = false;
            cout << "Which player's stats do you want to edit?" << endl;
            for (int i = 0; i < new_game.getNumPlayers(); i++)
            {
                players[i].printStats();
                cout << "----------------------------------------------" << endl;
            }
            cout << "The selected character is: " << endl;

            do // Gets a valid name for the characters
            {
                valid_player_choice = false; // reset valid chice bool value
                getline(cin, player_choice);
                for (int j = 0; j < new_game.getNumPlayers(); j++) // iterate through player array to see if input is valid
                {
                    if (players[j].getName() == player_choice)
                    {
                        valid_player_choice = true; // if valid choice then update bool value which will break the outer loop an inner
                        break;
                    }
                }

                if (!valid_player_choice)
                {
                    cout << "Invalid selection. Select from the list!" << endl;
                }

            } while (!valid_player_choice);

            cout << "Editing player " << new_game.getPlayer(player_choice).getName() << "'s stats:" << endl;
            cout << "1. Edit hp\n2. Edit condition\n3. Edit gold\n";
            getline(cin, str_sub_choice);

            // makes sure it is a valid input to sub menu
            while (!(str_sub_choice == "1" || str_sub_choice == "2" || str_sub_choice == "3"))
            {
                cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                getline(cin, str_sub_choice);
            }
            
            sub_choice = stoi(str_sub_choice);
            // Switch case for different sub menu options
            switch (sub_choice)
            {
            case 1:
                cout << "Enter the new value: " << endl;
                getline(cin, value);

                while (!isDouble(value) || stod(value) < 0) //whgile its not a double
                {
                    if (!isDouble(value))
                    {
                        cout << "Please give a valid number" << endl;
                    }
                    else if (stod(value) < 0)
                    {
                        cout << "Enter a non-negative value!" << endl;
                    }
                    else
                    {
                        cout << "Invalid input. Please enter a valid choice" << endl;
                    }
                    cout << "Enter the new value: " << endl;
                    getline(cin, value);
                }

                player_index = new_game.findPlayer(player_choice);
                players[player_index].setHP(stod(value)); // assigns new value to selected player

                break;

            case 2:
                cout << "Enter the new value:" << endl;
                getline(cin, value);


                while ((int)value.length() != 1 || !(value[0] == 'H' || value[0] == 'D' || value[0] == 'P')) 
                {
                    if ((int)value.length() != 1)
                    {
                        cout << "Please give just one character" << endl;
                    }
                    else if (!(value[0] == 'H' || value[0] == 'D' || value[0] == 'P'))
                    {
                        cout << "Enter a value among 'H', 'D' or 'P'!" << endl;
                    }
                    else
                    {
                        cout << "Invalid input. Enter new value among 'H', 'D' or 'P'!" << endl;
                    }
                    cout << "Enter the new value:" << endl;
                    getline(cin, value);
                }


                player_index = new_game.findPlayer(player_choice);
                players[player_index].setCondition(value[0]); // assigns new condition to selected player

                break;

            case 3:
                cout << "Enter the new value: " << endl;
                getline(cin, value);

                while (!isInteger(value) || stoi(value) < 0) // whgile its not an int or negative
                {
                    if (!isInteger(value))
                    {
                        cout << "Please give a valid number" << endl;
                    }
                    else if (stoi(value) < 0)
                    {
                        cout << "Enter a non-negative value!" << endl;
                    }
                    else
                    {
                        cout << "Invalid input. Please enter a valid choice" << endl;
                    }
                    cout << "Enter the new value: " << endl;
                    getline(cin, value);
                }

                player_index = new_game.findPlayer(player_choice);
                players[player_index].setGold(stoi(value));  //sets gold value to active player in use
                
                
                break;

            default:
                cout << "Something went wrong. Reached default case in inner switch case" << endl;
                break;
            }

            break;
        case 5:

            valid_enemy_choice = false;
            cout << "Which enemy's stats do you want to edit?" << endl;
            for (int i = 0; i < new_game.getNumEnemies(); i++)
            {
                enemies[i].printStats();
                cout << "----------------------------------------------" << endl;
            }
            cout << "The selected character is: " << endl;

            do // Gets a valid name for the enemies
            {
                valid_enemy_choice = false; // reset valid chice bool value
                getline(cin, enemy_choice);
                for (int j = 0; j < new_game.getNumEnemies(); j++) // iterate through enemies array to see if input is valid
                {
                    if (enemies[j].getName() == enemy_choice)
                    {
                        valid_enemy_choice = true; // if valid choice then update bool value which will break the outer loop an inner
                        break;
                    }
                }

                if (!valid_enemy_choice)
                {
                    cout << "Invalid selection. Select from the list!" << endl;
                }

            } while (!valid_enemy_choice);

            cout << "Editing enemy " << new_game.getEnemy(enemy_choice).getName() << "'s stats:" << endl;
            cout << "1. Edit hp\n2. Edit condition\n3. Edit gold\n";
            getline(cin, str_sub_choice);

            // makes sure it is a valid input to sub menu
            while (!(str_sub_choice == "1" || str_sub_choice == "2" || str_sub_choice == "3"))
            {
                cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                getline(cin, str_sub_choice);
            }

            sub_choice = stoi(str_sub_choice);
            // Switch case for different sub menu options
            switch (sub_choice)
            {
            case 1:
                cout << "Enter the new value: " << endl;
                getline(cin, value);

                while (!isDouble(value) || stod(value) < 0) // whgile its not a double
                {
                    if (!isDouble(value))
                    {
                        cout << "Please give a valid number" << endl;
                    }
                    else if (stod(value) < 0)
                    {
                        cout << "Enter a non-negative value!" << endl;
                    }
                    else
                    {
                        cout << "Invalid input. Please enter a valid choice" << endl;
                    }
                    cout << "Enter the new value: " << endl;
                    getline(cin, value);
                }

                enemy_index = new_game.findEnemy(enemy_choice);
                enemies[enemy_index].setHP(stod(value)); // assigns new value to selected enemy

                break;

            case 2:
                cout << "Enter the new value:" << endl;
                getline(cin, value);

                while ((int)value.length() != 1 || !(value[0] == 'H' || value[0] == 'D' || value[0] == 'P'))
                {
                    if ((int)value.length() != 1)
                    {
                        cout << "Please give just one character" << endl;
                    }
                    else if (!(value[0] == 'H' || value[0] == 'D' || value[0] == 'P'))
                    {
                        cout << "Enter a value among 'H', 'D' or 'P'!" << endl;
                    }
                    else
                    {
                        cout << "Invalid input. Enter new value among 'H', 'D',¨or 'P'!" << endl;
                    }
                    cout << "Enter the new value:" << endl;
                    getline(cin, value);
                }

                enemy_index = new_game.findEnemy(enemy_choice);
                enemies[enemy_index].setCondition(value[0]); // assigns new condition to selected enemy

                break;

            case 3:
                cout << "Enter the new value: " << endl;
                getline(cin, value);

                while (!isInteger(value) || stoi(value) < 0) // whgile its not an int or negative
                {
                    if (!isInteger(value))
                    {
                        cout << "Please give a valid number" << endl;
                    }
                    else if (stoi(value) < 0)
                    {
                        cout << "Enter a non-negative value!" << endl;
                    }
                    else
                    {
                        cout << "Invalid input. Please enter a valid choice" << endl;
                    }
                    cout << "Enter the new value: " << endl;
                    getline(cin, value);
                }

                enemy_index = new_game.findEnemy(enemy_choice);
                enemies[enemy_index].setGold(stoi(value)); // sets gold value to active enemy in use

                break;

            default:
                cout << "Something went wrong. Reached default case in inner switch case" << endl;
                break;
            }

            break;
        case 6:

            cout << "Bye!!" << endl;
            break;

        default:
            cout << "Default switch case reached. Something went wrong!" << endl;
            break;
        }
    }

    return;
}

int main()
{
    mainMenu();
    return 1;
}