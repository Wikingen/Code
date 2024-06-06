#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double calculateDistance(double x1, double x2, double y1, double y2)
{
    double distance =  sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    return distance;
}

void calculateDistanceMatrix(double distance[][3], double individual_locations[][2], double city_locations[][2], const int I_ROWS, const int I_COLS, const int C_ROWS, const int C_COLS)
{
    for (int i = 0; i < I_ROWS; i++) //  I = Individuals
    {
        for (int j = 0; j < C_ROWS; j++)   //   J= Cities
        {
            //cout << individual_locations[i][0] << "  " << city_locations[j][0] << "  " << individual_locations[i][1] << "  " << city_locations[j][1] << endl;
            distance[i][j] = calculateDistance(individual_locations[i][0], city_locations[j][0], individual_locations[i][1], city_locations[j][1]);
        }
    }
}


/*
            City 1	City 2	City 3
Person 1	0.00	3.61	8.06
Person 2	5.00	4.24	3.16
Person 3	8.49	5.00	7.28
Person 4	3.61	0.00	7.21
Person 5	8.06	7.21	0.00

*/

int main()
{
    const int I_ROWS = 6;
    const int I_COLS = 2;
    const int C_ROWS = 3;
    const int C_COLS = 2;
    double individual_locations[I_ROWS][I_COLS] = {{0, 0}, {0, 0}, {1, -4.5}, {-3.3, -0.8}, {1, 1}, {1, 0}};
    double city_locations[C_ROWS][C_COLS] = {{1, -1}, {-1, 1}, {-1, -1}};
    double distance[I_ROWS][C_ROWS];
    calculateDistanceMatrix(distance, individual_locations, city_locations, I_ROWS, I_COLS, C_ROWS, C_COLS);
    for (int i = 0; i < I_ROWS; i++)
    {
        for (int j = 0; j < C_ROWS; j++)
        {
            cout << fixed << setprecision(2) << distance[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}