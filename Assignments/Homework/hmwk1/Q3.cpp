#include <iostream>
using namespace std;

main(){

    double fahrenheit, celsius;

    cout << "What is the temperature in Fahrenheit?" << endl;

    cin >> fahrenheit;

    celsius = (fahrenheit - 32.0) * (5.0/9.0);

    cout << "The temperature is " <<celsius<< " degree Celsius." << endl;

    return 0;

}