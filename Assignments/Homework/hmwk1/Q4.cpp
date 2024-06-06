#include <iostream>
using namespace std;

main(){

    double simple_interest, amount, rate, time;

    cout << "Enter principal amount:" << endl;
    cin >> amount;

    cout << "Enter rate of interest:" << endl;
    cin >> rate;

    cout << "Enter time (in years):" << endl;
    cin >> time;

    simple_interest = (amount * rate * time)/100.0;

    cout << "Simple interest: " << simple_interest;

    return 0;

}