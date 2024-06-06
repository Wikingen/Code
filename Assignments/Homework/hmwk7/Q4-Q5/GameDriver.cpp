#include "Game.hpp"

int main()
{
    Game game = Game();
    cout << "Number of Players: " << game.getNumPlayers() << endl;
    cout << "Number of Enemies: " << game.getNumEnemies() << endl;
}