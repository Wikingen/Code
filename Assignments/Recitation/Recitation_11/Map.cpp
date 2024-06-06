#include "Map.hpp"

#define RED "\033[41m"     /* Red */
#define GREEN "\033[42m"   /* Green */
#define BLUE "\033[44m"    /* Blue */
#define MAGENTA "\033[45m" /* Magenta */
#define CYAN "\033[46m"    /* Cyan */
#define RESET "\033[0m"

Map::Map() {}

Map::Map(int players_num, int size)
{
    m_mapArr[players_num][size] = {};
}

// setter for position on map given the value and which player and then the index for their lane
void Map::setMapPos(string value, int playerID, int index)
{
    m_mapArr[playerID][index] = value;
}

// getter for position on map given which player and then the index for their lane
string Map::getMapPos(int playerID, int index)
{
    return m_mapArr[playerID][index];
}

//Initilizes the boards colours
//A little less than 30% chance of green and red each. At least 3 green and 4 red tiles
void Map::initializeMap()
{
    // keeps track on how many green and red tiles we have in each lane
    int num_red_tiles1 = 0;
    int num_green_tiles1 = 0;
    int num_red_tiles2 = 0;
    int num_green_tiles2 = 0;

    do
    {
        // Set counters to 0
        num_green_tiles1 = 0;
        num_red_tiles1 = 0;
        num_green_tiles2 = 0;
        num_red_tiles2 = 0;

        // variables to hold random numbers
        int rand_num1, rand_num2;

        for (int i = 0; i < 50; i++)
        {
            /* generate secret number between 1 and 10: */
            rand_num1 = rand() % 10 + 1;
            rand_num2 = rand() % 10 + 1;

            // These conditions roughly set probability for red, green, and blue tiles to roughly 1/3ish
            // STUDENTS: You must alter these to get correct ratios of the tiles that you need
            // Remember, the map is ALWAYS randomized at the start of a new game!!!!
            
            if(i==0)
            {
                m_mapArr[0][i] = BLUE;
            }
            else if (rand_num1 <= 3) // 40% chance of red
            {
                // Keep in mind, I told the compiler that writing the word RED represents the string "\033[41m"

                if (i != 0 && m_mapArr[0][i - 1] == RED)
                {
                    m_mapArr[0][i] = BLUE;
                }
                else
                {
                    m_mapArr[0][i] = RED;
                    num_red_tiles1++;
                }
            }
            else if (rand_num1 <= 6) // 40% CHANCE OF GREEN
            {
                // Keep in mind, I told the compiler that writing the word GREEN represents the string "\033[42m"
                if (i != 0 && m_mapArr[0][i - 1] == GREEN)
                {
                    m_mapArr[0][i] = BLUE;
                }
                else
                {
                    m_mapArr[0][i] = GREEN;
                    num_green_tiles1++;
                }
            }
            else // 20%
            {
                // Keep in mind, I told the compiler that writing the word GREEN represents the string "\033[44m"
                m_mapArr[0][i] = BLUE;
            }

            // This part populates the other lane for the second player
            if (i == 0)
            {
                m_mapArr[1][i] = BLUE;
            }
            else if (rand_num2 <= 3) // 30% chance of red
            {
                // Keep in mind, I told the compiler that writing the word RED represents the string "\033[41m"

                if (i != 0 && m_mapArr[1][i - 1] == RED)
                {
                    m_mapArr[1][i] = BLUE;
                }
                else
                {
                    m_mapArr[1][i] = RED;
                    num_red_tiles2++;
                }
            }
            else if (rand_num2 <= 6) // 30% CHANCE OF GREEN
            {
                // Keep in mind, I told the compiler that writing the word GREEN represents the string "\033[42m"
                if (i != 0 && m_mapArr[1][i - 1] == GREEN)
                {
                    m_mapArr[1][i] = BLUE;
                }
                else
                {
                    m_mapArr[1][i] = GREEN;
                    num_green_tiles2++;
                }
            }
            else
            {
                m_mapArr[1][i] = BLUE;
            }
        }
    } while (num_red_tiles1 < 4 || num_green_tiles1 < 3 || num_red_tiles2 < 4 || num_green_tiles2 < 3);
}