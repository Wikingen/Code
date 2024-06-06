#include <iostream>
using namespace std;

int main()
{
    double water;
    cout << "How much water did you drink today?   (in liters)" << endl;
    
    cin >> water;
    
    double waterLeft = (3.0 - water);
    
    

    if (water <= 1.5)
    {
        cout <<"You're very dehydrated! Get that water in! You have "<< waterLeft <<" liters left to drink"<< endl;
    }
    else if(water < 3)
    {
        cout << "You're doing great, but you're still halfway to your goal!"<< endl << "Get that water in! You have " << waterLeft << " liter left to drink"<<endl;
    }
    else
    {
        cout << "You've hit your goal for the day! great job getting hydrated!" << endl;
    }
}