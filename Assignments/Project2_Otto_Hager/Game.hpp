#ifndef GAME_CPP
#define GAME_CPP

#include "Entity.hpp"

class Game
{
public:
    // Default unparameterized constructor
    Game();

    //Parameterized constructor
    Game(Entity players[], Entity enemies[], int num_players, int num_enemies);

    //Picks starting character and sets it
    void playerPick(int player_index);

    //Loads all entities from a file, the are_players parameters dictates if enteties are loaded to the _all_enemies array or _all_players
    bool loadEnteties(string filename, bool are_players);

    //Loads all items into _all_potions and _all_equipment
    bool loadItems(string filename);

    //Loads all ridldles and asnwers
    bool loadRiddles(string filename);

    // Returns the current number of players _num_players
    int getNumPlayers();

    // Returns the current number of enemies _num_enemies
    int getNumEnemies();

    /* Sets the _players array with the provided array of objects.
    The number of objects in the array is specified by the int parameter.
    If the number of objects is greater than 2, only the first two objects are considered.
    The data member _num_players is updated accordingly.*/
    void setPlayersList(Entity arr[], int num_players);

    /*Sets the _enemies array with the provided array of objects.
    The number of objects in the array is specified by the int parameter.
    If the number of objects is greater than 2, only the first two objects are considered.
    The data member _num_enemies is updated accordingly.
     */
    void setEnemiesList(Entity arr[], int num_enemies);

    // Replaces a player object at the given index in the _players array.
    bool setPlayer(int index, Entity new_player);

    //Changes _players players stamina to stamina parameter
    void setPlayerStamina(int player_id, double stamina);
    double getPlayerStamina(int player_id);

    void setPlayerCondition(int player_id, char condition);
    char getPlayerCondition(int player_id);
    
    void setPlayerHP(int player_id, double hp);
    double getPlayerHP(int player_id);



    void setPlayerCalamity(int player_id,double calamity);
    double getPlayerCalamity(int player_id);

    // Returns an object from the _players array based on the index
    Entity getPlayer(int index);
    void setPlayerWon(int player_id, bool player_won);

    // Returns an object from the _all_players array based on the provided name
    Entity getPlayerFromAll(string name);

    //Returns a potion from _all_potions
    Potion getPotion(string name);
    //Returns a equipment from _all_equipment
    Equipment getEquipment(string name);

    // Replaces an enemy object at the given index in the _enemies array.
    bool setEnemy(int index, Entity new_enemy);

    // Returns an object from the _enemies array based on the provided name
    Entity getEnemy(string name);

    // Returns the index of the player object in the _players array based on the provided name.
    int findPlayer(string name);

    // Returns the index of the enemy object in the _enemies array based on the provided name.
    int findEnemy(string name);

    int findPotion(string name);

    // Prints stats of all the players and enemies.
    void printAllStats();
    
    void printAllPotions();
    void printAllEquipment();

    //Prompts user on potions he can use and calls usePotion
    bool usePotionMenu(int player_id);
    //Uses potion
    void usePotion(int player_id, string potion_name);

    bool swapWeapon(int player_id);

    bool dropWeapon(int player_id);

    //Randomizes an enemy to fight at an island and finishes the fight
    void islandCombat(int player_id);

    //Randomizes an epic enemy to fight and finishes the fight
    void epicCombat();


    //Item shop prompt for a player. Lets player buy items
    void itemShop(int player_id);

    // Prints options, MOve, Swap/Drop, Potion,stats or quir. returns valid option 1-5
    int mainMenu();

    // Prints combat options, Attack, Use Potion, Swap weapon or run. returns valid option 1-4
    int combatMenu();

    void hiddenChest(int player_id);

    //saves player stats and winner in a file called file name. Returns if successfull
    bool saveResults(string file_name);

private:
    Entity _players[2];
    Entity _enemies[2];
    int _num_players;
    int _num_enemies;

    static const int _MAX_PLAYERS = 10;
    static const int _MAX_ENEMIES = 10;
    Entity _all_players[_MAX_PLAYERS];
    Entity _all_enemies[_MAX_ENEMIES];

    static const int _MAX_POTIONS = 10;
    Potion _all_potions[_MAX_POTIONS];
    static const int _MAX_EQUIPMENT = 20;
    Equipment _all_equipment[_MAX_EQUIPMENT];

    static const int _MAX_RIDDLES = 20;
    string _riddles[_MAX_RIDDLES];
    string _riddles_answers[_MAX_RIDDLES];
    

};
#endif