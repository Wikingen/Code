// CSCI 1300 Spring 2024
// Author: Otto Wiking Häger      
// Question 1

#include <iostream>

using namespace std;

int main()
{
    // declare all the variables
    string tax_type;
    int income;

    // prompt the user & get their input
    cout << "What is the tax type?" << endl;
    cin >> tax_type;
    cout << "What is your income?" << endl;
    cin >> income;

    if ( !(tax_type == "federal" ||  tax_type == "state" ))
    {
        cout << "Invalid tax type." << endl;
        
        return 0;
    }

    if (income <=0)
    {
        cout << "Income cannot be negative or zero." << endl;
        return 0;
    }

    // Check for tax type
    if (tax_type == "state")
    {
        // Check for income criteria
        if (income < 5000) // FILL IN THIS LINE
        {
            cout << "You are not required to pay taxes" << endl;
        }
        else
        {
            cout << "You are required to pay $" << 0.045*income << " in taxes" << endl;
        }
    }
    else
    {
        // Check for income criteria

        if (income < 11000) // FILL IN THIS LINE
        {
            cout << "You are required to pay $" << 0.11*income << " in taxes" << endl;
        }
        else
        {
            cout << "You are required to pay $" << 0.22*income << " in taxes" << endl;
        }
    }

    return 0;
}