#include <iostream>
using namespace std;

double useWater(double currentLevel, double amount)
{
    if (currentLevel < amount || amount < 0)
    {
        return -1;
    }
    else
    {
        return (currentLevel - amount);
    }
}

double refillWater(double currentLevel, double amount)
{
    if (amount < 0)
    {
        return -1;
    }
    else
    {
        return (amount + currentLevel);
    }
}

int main()
{
    int result;

    result = useWater(3, 4);

    if (result == -1)
    {
        cout << "invalid amount entered" << endl;
    }
    else
    {
        cout << "water level after use is: " << result << endl;
    }

    result = refillWater(3, 5);

    if (result == -1)
    {
        cout << "invalid amount entered" << endl;
    }
    else
    {
        cout << "water level after fill is: " << result << endl;
    }
}
