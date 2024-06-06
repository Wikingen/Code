#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double budget = -1;
    char pass;
    cout << "What is your budget?"<< endl;
    cin >> budget;
    
    cout << "Which of these passes would you like to take (B, I, A or P)?" << endl;
    cin >> pass;
   
    if (budget < 0 || !(pass == 'B' || pass == 'I' || pass == 'A' || pass == 'P'))
    {

        cout << "Please enter valid input." << endl;
        
    }
   
    else if (pass == 'B')
    {
        

        if ( budget < 250.15)
        {
            cout << "Sorry, this pass is outside your budget.";
        }

        else
        {
            cout << "Yes, this pass is within your budget!";
        }
    }

    else if (pass == 'I')
    {
        if ( (budget - 479.85) < 0.0)
        {
            cout << "Sorry, this pass is outside your budget.";
        }

        else
        {
            cout << "Yes, this pass is within your budget!";
        }
    }
    
    else if (pass == 'A')
    {
        if ( budget < 684.29 - 0.001)
        {
            cout << "Sorry, this pass is outside your budget.";
        }

        else
        {
            cout << "Yes, this pass is within your budget!";
        }
    }
    else if (pass == 'P')
    {
        if ( budget < 950.33 - 0.001)
        {
            cout << "Sorry, this pass is outside your budget.";
        }

        else
        {
            cout << "Yes, this pass is within your budget!";
        }
    }



    return 0;
}