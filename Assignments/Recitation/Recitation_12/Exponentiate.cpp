#include <iostream>
#include "Functions.hpp"
using namespace std;

double exponentiate(double num, int exponent)
{
    if(exponent < 0)
    {
        return -1;
    }
    else if ( exponent == 0 || exponent == 1)
    {
        return num;
    }
    else
    {
        return num*exponentiate(num, exponent -1);
    }
}



int main()
{
    // receive the number and exponent values from user
    string Principal, rate, time;
    double P,r;
    int t;
    cout << "Enter the Principal amount: " << endl;
    getline(cin, Principal);
    if(isDouble(Principal) && stod(Principal) > 0)
    {
         P = stod(Principal);
    }
    else
    {
        cout <<"invalid input" << endl;
        return -1;
    }
    cout << "Enter the rate of interest: " << endl;
    getline(cin, rate);
    if (isDouble(rate) && stod(rate) > 0 && stod(rate) < 1)
    {
        r = stod(rate);
    }
    else
    {
        cout << "Invalid Input(s)" << endl;
        return -1;
    }
    cout << "Enter the time in years: " << endl;
    getline(cin, time);
    if (isInteger(time) && stoi(time) > 0)
    {
         t = stoi(Principal);
    }
    else
    {
        cout << "invalid input" << endl;
        return -1;
    }

   
    double result = P*exponentiate((1+r), t) - P;
    if (result != -1)
    {
        cout << "Result: " << result << endl;
    }
    else
    {
        cout << "Something went wrong" << endl;
    }
}
