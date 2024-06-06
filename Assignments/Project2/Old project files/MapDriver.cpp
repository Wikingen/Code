#include "Map.hpp"
#include <ctype.h>

#define RED "\033[41m"     /* Red */
#define GREEN "\033[42m"   /* Green */
#define BLUE "\033[44m"    /* Blue */
#define MAGENTA "\033[45m" /* Magenta */
#define CYAN "\033[46m"    /* Cyan */
#define RESET "\033[0m"

using namespace std;

int main()
{

    /* initialize random seed: */
    srand(time(NULL));

    Map starterMap = Map();
    // initialize tiles
    starterMap.initializeMap();

    cout << "Here is our map:" << endl;
    //Initiate positions to zero and print map
    starterMap.setPlayerPos(0,0); 
    starterMap.setPlayerPos(1,0);
    starterMap.printMap();

    while (starterMap.getPlayerPos(0) < 49)
    {
        cout << "Enter steps you want to walk" << endl;
        string steps;
        getline(cin, steps);
        int player_pos = starterMap.getPlayerPos(0) + stoi(steps);
        starterMap.setPlayerPos(0, player_pos);
        starterMap.printMap();

        string color = starterMap.getMapPos(0, starterMap.getPlayerPos(0));
        string color_name = "";

        if (color == BLUE)
        {
            color_name = "blue";
        }
        else if (color == RED)
        {
            color_name = "red";
        }
        else if (color == GREEN)
        {
            color_name = "green";
        }
        else
        {
            cout << "Error finding color of piece" << endl;
        }

        cout << "You landed on " << color_name  << " Which is postion " << player_pos << RESET << endl;
    }

    cout << "You won!!!!" << endl;

    return 0;
}