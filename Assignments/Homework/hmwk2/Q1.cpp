#include <iostream>
using namespace std;

int main()
{
    int snowfall = -1;

    cout << "What is the amount of snowfall?" << endl;
    cin >> snowfall;

    if (snowfall <= 0)
        {
            cout << "Invalid snowfall amount." << endl;
            
            return 0;
        }

    else if (snowfall > 5)
        {
            cout << "You need your snow boots." << endl;   

        }

    else
        {
            cout << "You don't need snow boots." << endl;

        }
    
    return 0;

}