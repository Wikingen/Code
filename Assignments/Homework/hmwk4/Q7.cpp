#include <iostream>
using namespace std;

double purchasePass(double budget, char pass_type);
bool budgetCheck(double budget, char pass_type);

int main()
{
    double budget = -1;
    char pass_type = 'x';
    cout << "Enter your budget:" << endl;
    cin >> budget;
    cout << "Enter the type of pass you wish to purchase ('B', 'I', 'A', 'P'):" << endl;
    cin >> pass_type;

    double updated_budget = purchasePass(budget, pass_type);      
    if (budget != updated_budget)
    {
        cout << "Pass purchased successfully. Updated budget: $" << updated_budget << endl;
        
        double updated_budget2 = purchasePass(updated_budget, pass_type);

        if(updated_budget2 != updated_budget)
        {
            cout << "Another pass purchased for your friend. Remaining budget: $" << updated_budget2 << endl;
        }
        else
        {
            cout << "Insufficient budget to purchase another pass for your friend." << endl;
        }

    }
    else
    {
        cout << "Sorry, this pass is outside your budget or invalid entry for budget and/or pass type." << endl;
    }

    return 0;
}

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
        if (budget >= 950.33)
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

double purchasePass(double budget, char pass_type)
{
    double newBudget = budget;

    if (budgetCheck(budget, pass_type))
    {
        switch (pass_type)
        {
        case 'B':
            newBudget -= 250.15;
            break;
        case 'I':
            newBudget -= 479.85;
            break;
        case 'A':
            newBudget -= 684.29;
            break;
        case 'P':
            newBudget -= 950.33;
            break;
        }
        return newBudget;
    }
    else
    {
        return budget;
    }
}