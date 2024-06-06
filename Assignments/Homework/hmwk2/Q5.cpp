#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char car = 'x';
    float days = -1;
    float cost = -1;

    cout << "Which car type ( A, B, C, or D ) would you like to rent?" << endl;
    cin >> car;
    cout << "How many days would you like to rent this car?" << endl;
    cin >> days;

    if (days < 1 || !(car == 'A' || car == 'B' || car == 'C' || car == 'D'))
    {
        cout << "Please enter valid input." << endl;
    }
    else
    {
        switch (car)
        {
            case 'A':
                cost = 1.21 * (75 + days * 10);
                cout << fixed << setprecision(2) << "Your bill total is $" << cost << endl;
                break;

            case 'B':
                cost = 1.21 * (100 + days * 20);
                cout << fixed << setprecision(2) << "Your bill total is $" << cost << endl;

                break;
            case 'C':
                cost = 1.21 * (150 + days * 30);
                cout << fixed << setprecision(2) << "Your bill total is $" << cost << endl;

                break;
            case 'D':
                cost = 1.21 * (200 + days * 40);
                cout << fixed << setprecision(2) << "Your bill total is $" << cost << endl;

                break;


        }
    }




}