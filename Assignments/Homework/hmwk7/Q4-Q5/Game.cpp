#include "Game.hpp"

Game::Game()
{
    _num_players = 0;
    _num_enemies = 0;
}

// Parameterized constructor
Game::Game(Entity players[], Entity enemies[], int num_players, int num_enemies)
{

    //cout << "We pass num_players with the value " << num_players <<endl;

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
    if (index >= 0 && index <= _num_players)
    {
        _players[index] = new_player;
        return true;
    }
    else
    {
        return false;
    }
}

// Returns an object from the _players array based on the provided name
// I dont know what I return if i cant find them
Entity Game::getPlayer(string name)
{
    for (int i = 0; i < _num_players; i++)
    {
        if (_players[i].getName() == name)
        {
            return _players[i];
        }
    }

    return _players[0];
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

// Prints stats of all the players and enemies.
void Game::printAllStats()
{
    for (int i = 0; i < _num_players; i++)
    {
        if (_players[i].getName() != "")
        {

            _players[i].printStats();
            cout << "----------------------------------------------" << endl;
        }
    }
    for (int i = 0; i < _num_enemies; i++)
    {
        if (_enemies[i].getName() != "")
        {
            _enemies[i].printStats();
            cout << "----------------------------------------------" << endl;
        }
    }
}