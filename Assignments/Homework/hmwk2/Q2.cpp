#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float balance = 30.0;
    float price = -1;
    cout << "Enter the amount to be withdrawn from your card:"<< endl;
    cin >> price;
    
    if (price <= 0)
    {
        cout << "Invalid input. Withdrawn amount must be a non-negative value.";
    }
    else if ( (balance - price) < 20)
    {
        cout << "Transaction Failed!";
    }
    else
    {
        balance -=price;
        cout << fixed << setprecision(2) << "Transaction Successful! Your balance is $" << balance << endl;
    }
}