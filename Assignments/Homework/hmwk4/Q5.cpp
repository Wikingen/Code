/*

#include <iostream>
#include <iomanip>
using namespace std;

bool budgetCheck(double budget, char pass_type);

int main()
{
    double budget = -1;
    char pass;
    bool can_purchase;
    cout << "What is your budget?" << endl;
    cin >> budget;

    cout << "Which of these passes would you like to take (B, I, A or P)?" << endl;
    cin >> pass;

    can_purchase = budgetCheck(budget, pass);

    if(can_purchase)
    {
        cout << "Yes, this pass is within your budget!" << endl;
    }
    else
    {
        cout << "Sorry, this pass is outside your budget or invalid entry for budget and/or pass type." << endl;
    }


    return 0;
}
*/


bool budgetCheck(double budget, char pass_type)
{
    bool can_purchase = false;
    switch (pass_type)
    {
    case 'B':
        if (budget >= 250.15)
        {
            can_purchase = true;
        }
        else
        {
            can_purchase = false;
        }

        break;
    case 'I':
        if (budget >= 479.85)
        {
            can_purchase = true;
        }
        else
        {
            can_purchase = false;
        }

        break;
    case 'A':
        if (budget >= 684.29)
        {
            can_purchase = true;
        }
        else
        {
            can_purchase = false;
        }

        break;
    case 'P':
        if (budget >= 950.33 )
        {
            can_purchase = true;
        }
        else
        {
            can_purchase = false;
        }

        break;
    }
    return can_purchase;
}