// CSCI 1300 Spring 2024
// Author: Otto WIking Häger
// TA: Jordan Tate
// Question # 6

#include <iostream>
using namespace std;

double calculateFarmArea(double length, double width)
{
    if (length <= 0 || width <= 0)
    {
        return -1;
    }
    else
    {
        return (length * width);
    }
}
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
    int choice = -1;
    double length = -1;
    double width = -1;
    double area = -1;
    char seed_type = 'x';
    char machine_type = 'f';
    double cost = -1;
    double time_taken = -1;

    cout << "1. Calculate Farm Area \n2. Calculate Seeds Cost\n3. Estimate Sowing Time\n4. Exit" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter length of the farmland in ft:" << endl;
        cin >> length;
        cout << "Enter width of the farmland in ft:" << endl;
        cin >> width;

        area = calculateFarmArea(length, width);
        if (area != -1)
        {
            cout << "The area is: " << area << " sq ft." << endl;
        }
        else
        {
            cout << "Length or width is invalid. Area cannot be calculated." << endl;
        }
        break;
    case 2:
        cout << "Enter area of the farmland in sq ft:" << endl;
        cin >> area;
        cout << "Enter the grade of seed to be used:" << endl;
        cin >> seed_type;

        cost = calculateSeedCost(area, seed_type);
        if (cost == -1)
        {
            cout << "Area or seed grade is invalid. Cost cannot be calculated." << endl;
        }
        else
        {
            cout << "The cost is: $" << cost << endl;
        }
        break;
    case 3:
        cout << "Enter area of the farmland in sq ft:" << endl;
        cin >> area;
        cout << "Enter the type of sowing machine to be used:" << endl;
        cin >> machine_type;

        time_taken = calculateSowingTime(area, machine_type);
        if (time_taken == -1)
        {
            cout << "Area or machine type is invalid. Time cannot be calculated." << endl;
        }
        else
        {
            cout << "The time taken is: " << time_taken << " minutes." << endl;
        }
        break;
    case 4:
        cout << "You have chosen to exit. Thank you!"<<endl;
        return 0;
    default:
        cout << "Menu choice is invalid." << endl;
        return 0;
    }
}
