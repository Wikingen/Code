#include <iostream>
#include <vector>
using namespace std;

vector<int> vectorManipulation(vector<int> vect, int input)
{
    if (input < 1)
    {
        return vect;
    }

    if ((int)vect.size() == 0)
    {
        vect.push_back(input);
        return vect;
    }

    if (input % 10 == 0)
    {
        vector<int> newVect;
        for (size_t i = 1; i < vect.size(); ++i)
        {
            newVect.push_back(vect[i]);
        }
        vect = newVect;
    }
    if (input % 5 == 0 && (int)vect.size() > 0)
    {
        vect.pop_back();
    }

    if (input % 10 != 0 && input % 5 != 0)
    {
        vect.push_back(input);
    }
    return vect;
}

bool isInteger(string input)
{
    if (input == "")
    {
        return false;
    }

    if (input[0] == '-')
    {
        input = input.substr(1);
    }

    if (input == "")
    {
        return false;
    }

    int size = input.size();

    for (int i = 0; i < size; i++)
    {
        if (isdigit(input[i]) == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> vect;
    cout << "Enter positive integers (Enter -1 to stop):" << endl;
    string input;
    while (input != "-1")
    {
        getline(cin, input);
        if (!isInteger(input) || stoi(input) < -1)
        {
            cout << "The number should be a positive integer or -1. Please enter again:" << endl;
        }
        else
        {
            vect = vectorManipulation(vect, stoi(input));
        }
    }

    if ((int)vect.size() == 0)
    {
        cout << "The vector is empty." << endl;
    }
    else
    {
        cout << "The elements in the vector are: ";
        for (int i = 0; i < (int)vect.size(); i++)
        {
            cout << vect[i] << " ";
        }
    }
}