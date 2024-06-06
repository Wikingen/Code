#include <iostream>
#include <iomanip>
#include <limits> // Include the <limits> header for numeric_limits
using namespace std;

int main()
{
    int cardio, strength, flexibility, time;
    string choice;
    while (choice != "exit")
    {
        cout << "Enter a category (Cardio, Strength, Flexibility, or 'exit') :" << endl;
        getline(cin, choice);

        if (choice == "Cardio")
        {
            cout << "Enter the exercised time: " << endl;
            cin >> time;
            cardio += time;
        }
        else if (choice == "Strength")
        {
            cout << "Enter the exercised time: " << endl;
            cin >> time;
            strength += time;
        }
        else if (choice == "Flexibility")
        {
            cout << "Enter the exercised time: " << endl;
            cin >> time;
            flexibility += time;
        }
        else if (choice != "exit")
        {
            cout << "Invalid category. Please enter a valid category. " << endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Category-wise totals:\nCardio:\t\t"<<cardio<<" mins\nStrength:\t"<<strength<<" mins\nFlexibility:\t"<<flexibility<<" mins\n";
    cout <<"Total exercise time for the day:\t"<<cardio+strength+flexibility<<"mins\n";
}
