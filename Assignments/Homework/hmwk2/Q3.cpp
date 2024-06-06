#include <iostream>
#include <iomanip>
using namespace std;

int main()
{   
    float windSpeed = -1;
    float temperature = -1;
    cout << "What is tomorrow's temperature looking like?"<< endl;
    cin >> temperature;
    
    cout << "What is tomorrow's wind speed looking like?"<< endl;
    cin >> windSpeed;
   
    if (windSpeed < 0)
    {
        cout << "Please enter valid input." << endl;
        
    }

    else if(windSpeed <= 20 && temperature >= -10 && temperature <= 10)
    {
        cout << "The weather conditions are ideal for photography tomorrow." << endl;
    }
    else 
    {
        cout << "The weather conditions are not ideal for photography tomorrow." << endl;

    }
    return 0;   
}