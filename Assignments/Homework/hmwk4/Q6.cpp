#include <iostream>
using namespace std;
// Assume the proper implementation of purchasePass is included.
double purchasePass(double budget, char pass_type);
bool budgetCheck(double budget, char pass_type);

int main()
{
    double budget = 500;
    double updated_budget = purchasePass(budget, 'B');
    if (budget != updated_budget)
    {
        cout << "Pass purchased successfully. Updated budget: $" << updated_budget << endl;
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