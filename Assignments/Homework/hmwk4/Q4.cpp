#include <iostream>
using namespace std;

int manageFeeder(int feeder, int days_since_last_fill);

int main()
{
    int choice = -1;
    int feederID = -1;
    int days_since_last_fill = -1;
    int remainingDays = -1;
    cout << "1. Check Feeder 1 \n2. Check Feeder 2 \n3. Check Feeder 3 \n4. Check All Feeders" << endl;
    cout << "Enter your choice:" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        feederID = 1;
        cout << "How many days ago was feeder " << feederID << " filled? " << endl;
        cin >> days_since_last_fill;
        if (days_since_last_fill >= 0)
        {
            remainingDays = manageFeeder(feederID, days_since_last_fill);
            if (remainingDays <= 0)
            {
                cout << "Feeder " << feederID << " is currently empty and should be filled immediately." << endl;
            }
            else
            {
                cout << "Feeder " << feederID << " will need to be filled in " << remainingDays << " days." << endl;
            }
        }
        else
        {
            cout << "Invalid input for days_since_last_fill!" << endl;
        }

        break;
    case 2:
        feederID = 2;
        cout << "How many days ago was feeder " << feederID << " filled? " << endl;
        cin >> days_since_last_fill;
        if (days_since_last_fill >= 0)
        {
            remainingDays = manageFeeder(feederID, days_since_last_fill);

            if (remainingDays <= 0)
            {
                cout << "Feeder " << feederID << " is currently empty and should be filled immediately." << endl;
            }
            else
            {
                cout << "Feeder " << feederID << " will need to be filled in " << remainingDays << " days." << endl;
            }
        }
        else
        {
            cout << "Invalid input for days_since_last_fill!" << endl;
        }

        break;
    case 3:
        feederID = 3;
        cout << "How many days ago was feeder " << feederID << " filled? " << endl;
        cin >> days_since_last_fill;
        if (days_since_last_fill >= 0)
        {
            remainingDays = manageFeeder(feederID, days_since_last_fill);

            if (remainingDays <= 0)
            {
                cout << "Feeder " << feederID << " is currently empty and should be filled immediately." << endl;
            }
            else
            {
                cout << "Feeder " << feederID << " will need to be filled in " << remainingDays << " days." << endl;
            }
        }
        else
        {
            cout << "Invalid input for days_since_last_fill!" << endl;
        }

        break;
    case 4:
        cout << "How many days ago were all the feeders filled?" << endl;
        cin >> days_since_last_fill;
        feederID = 1;
        if (days_since_last_fill >= 0)
        {
            remainingDays = manageFeeder(feederID, days_since_last_fill);
            if (remainingDays <= 0)
            {
                cout << "Feeder " << feederID << " is currently empty and should be filled immediately." << endl;
            }
            else
            {
                cout << "Feeder " << feederID << " will need to be filled in " << remainingDays << " days." << endl;
            }

            feederID = 2;
            remainingDays = manageFeeder(feederID, days_since_last_fill);
            if (remainingDays <= 0)
            {
                cout << "Feeder " << feederID << " is currently empty and should be filled immediately." << endl;
            }
            else
            {
                cout << "Feeder " << feederID << " will need to be filled in " << remainingDays << " days." << endl;
            }

            feederID = 3;
            remainingDays = manageFeeder(feederID, days_since_last_fill);
            if (remainingDays <= 0)
            {
                cout << "Feeder " << feederID << " is currently empty and should be filled immediately." << endl;
            }
            else
            {
                cout << "Feeder " << feederID << " will need to be filled in " << remainingDays << " days." << endl;
            }
        }
        else
        {
            cout << "Invalid input for days_since_last_fill!" << endl;
            cout << "Invalid input for days_since_last_fill!" << endl;
            cout << "Invalid input for days_since_last_fill!" << endl;
        }

        break;
    default:
        cout << "Invalid menu choice!" << endl;
            break;
    }
}

int manageFeeder(int feeder, int days_since_last_fill)
{
    int remainingDays = -1;
    switch (feeder)
    {
    case 1:
        remainingDays = (33 - 2 * days_since_last_fill) / 2;
        break;
    case 2:
        remainingDays = (27 - 4 * days_since_last_fill) / 4;
        break;
    case 3:
        remainingDays = (16 - 3 * days_since_last_fill) / 3;
        break;
    }
    if (remainingDays <= 0)
    {
        return -1;
    }
    else
    {
        return remainingDays;
    }
}
