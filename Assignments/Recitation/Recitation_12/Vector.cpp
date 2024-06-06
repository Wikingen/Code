#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<float> values;
    cout << "Enter 10 floating point values:" << std::endl;
    float input;
    for (int i = 0; i < 10; ++i)
    {
        cin >> input;
        values.push_back(input);
    }
    
    float biggest=values[0];
    for (int i= 1; i < (int)values.size(); i++)
    {
        if(values[i] > biggest)
        {
            biggest = values[i];
        }
    }
    float smallest=values[0];
    for (int i = 1; i < (int)values.size(); i++)
    {
        if(values[i] < smallest)
        {
            smallest = values[i];
        }
    }

    float average = (biggest + smallest)/2;

    vector<float> new_values;
    for (int i = 0; i < (int)values.size(); i++)
    {
        if(values[i] > average)
        {
            new_values.push_back(values[i]);
        }
    }

    for (int i = 0; i < (int)new_values.size(); i++)
    {
        cout << 1 << ":    " << new_values[i] <<endl;
    }
}