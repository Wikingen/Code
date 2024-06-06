#include <iostream>
#include <iomanip>
using namespace std;

void findClosestCity(double distance[][3], int closest_cities[], const int DISTANCE_ROWS, const int DISTANCE_COLS)
{
    for (int i = 0; i < DISTANCE_ROWS; i++)
    {
        int closest_city = 1;
        for (int j = 1; j < DISTANCE_COLS; j++) // We start at 1 since we already assumes distance a 0 was shortest
        {
            if (distance[i][j] < distance[i][closest_city - 1]) // closest city -1 since that is the index of closest city
            {
                closest_city = j + 1;
            }
        }
        closest_cities[i] = closest_city;
    }
}

int main()
{
    const int DISTANCE_ROWS = 5;
    const int DISTANCE_COLS = 3;
    int closest_cities[DISTANCE_ROWS];
    double distance[DISTANCE_ROWS][DISTANCE_COLS] = {{0.00, 3.61, 8.06}, {5.00, 4.24, 3.16}, {8.49, 5.00, 7.28}, {3.61, 0.00, 7.21}, {8.06, 7.21, 0.00}};
    findClosestCity(distance, closest_cities, DISTANCE_ROWS, DISTANCE_COLS);

    // We are printing the contents of the closest_cities array here.
    for (int i = 0; i < DISTANCE_ROWS; i++)
    {
        cout << closest_cities[i] << endl;
    }
    return 0;
}