#include <iostream>
using namespace std;

double calculateSeedCost(double area, char seed_grade)
{
    if (area <= 0 || !(seed_grade == 'A' || seed_grade == 'B' || seed_grade == 'C' || seed_grade == 'a' || seed_grade == 'b' || seed_grade == 'c'))
    {
        return -1;
    }
    else if (seed_grade == 'A' || seed_grade == 'a')
    {
        return (7.5 * area);
    }
    else if (seed_grade == 'B' || seed_grade == 'b')
    {
        return (12.5 * area);
    }
    else if (seed_grade == 'C' || seed_grade == 'c')
    {
        return (27.5 * area);
    }
    else
    {
        return -1;
    }
}

int main()
{
    double area = -1;
    char seed_type = 'x';
    cout << "Enter area of the farmland in sq ft:" << endl;
    cin >> area;
    cout << "Enter the grade of seed to be used:" << endl;
    cin >> seed_type;

    double cost = calculateSeedCost(area, seed_type);

    if (cost == -1)
    {
        cout << "Area or seed grade is invalid. Cost cannot be calculated." << endl;
    }
    else
    {
        cout << "The cost is: $" << cost << endl;
    }

    return 0;
}
