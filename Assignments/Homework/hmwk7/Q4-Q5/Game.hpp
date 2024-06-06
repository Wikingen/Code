#include "Entity.hpp"

class Game
{
public:
    // Default unparameterized constructor
    Game();

    //Parameterized constructor
    Game(Entity players[], Entity enemies[], int num_players, int num_enemies);

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

    // Returns an object from the _players array based on the provided name
    Entity getPlayer(string name);

    // Replaces an enemy object at the given index in the _enemies array.
    bool setEnemy(int index, Entity new_enemy);

    // Returns an object from the _enemies array based on the provided name
    Entity getEnemy(string name);

    // Returns the index of the player object in the _players array based on the provided name.
    int findPlayer(string name);

    // Returns the index of the enemy object in the _enemies array based on the provided name.
    int findEnemy(string name);

    // Prints stats of all the players and enemies.
    void printAllStats();

private:
    Entity _players[2];
    Entity _enemies[2];
    int _num_players;
    int _num_enemies;
};