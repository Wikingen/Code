#include <iostream>
using namespace std;

double calculateSowingTime(double area, char machine_type)
{
    if (area <= 0)
    {
        return -1;
    }
    else
    {
        switch (machine_type)
        {
        case 'W':
            return (area / (5.0 / 12.0));
        case 'X':
            return (area / (3.0 / 10.0));
        case 'Y':
            return (area / (2.0 / 5.0));
        case 'Z':
            return (area / (7.0 / 15.0));
        default:
            return -1;
        }
    }
}

int main()
{
    double area = -1;
    char machine_type = 'f';
    cout << "Enter area of the farmland in sq ft:" << endl;
    cin >> area;
    cout << "Enter the type of sowing machine to be used:" << endl;
    cin >> machine_type;

    double time_taken = calculateSowingTime(area, machine_type);

    if (time_taken == -1)
    {
        cout << "Area or machine type is invalid. Time cannot be calculated." << endl;
    }
    else
    {
        cout << "The time taken is: " << time_taken << " minutes." << endl;
    }

    return 0;
}