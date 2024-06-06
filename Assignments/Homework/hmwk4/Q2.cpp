#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double calculateDistance(double x1, double y1, double x2, double y2, int distance_type);

int main()
{
    int distance_type = -1;
    double x1 = -1;
    double y1 = -1;
    double x2 = -1;
    double y2 = -1;
    cout << "Enter distance type:" << endl;
    cin >> distance_type;
    cout << "Enter x1: " << endl;
    cin >> x1;
    cout << "Enter y1: " << endl;
    cin >> y1;
    cout << "Enter x2: " << endl;
    cin >> x2;
    cout << "Enter y2: " << endl;
    cin >> y2;

    double dist = calculateDistance(x1, y1, x2, y2, distance_type);

    if (dist == -1)
    {
        cout << "Invalid distance type!" << endl;
        return 0;
    }
    else
    {
        cout << "The distance between the points is: " << fixed << setprecision(3) << dist << endl;
        return 0;
    }
}

double calculateDistance(double x1, double y1, double x2, double y2, int distance_type)
{
    if (  !(distance_type == 1 || distance_type == 2)   )
    {
        return -1;
    }
    else if (distance_type == 1) // Manhattan distanceö
    {
        double distance = abs(x2 - x1) + abs(y2 - y1);
        return distance;
    }
    else // Euclidean distance
    {
        double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
        return distance;
    }
}