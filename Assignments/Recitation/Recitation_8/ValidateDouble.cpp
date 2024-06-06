#include <iostream>
using namespace std;

bool isDouble(string input);

int main()
{
    string input = "";
    do
    {
        cout << "Give double: ";
        getline(cin,input);
        if (isDouble(input))
        {
            cout << "That is a valid double" << endl;
        }
        else
        {
            cout << "That is not a valid double" << endl;
        }

    } while (input != "end");
}

bool isDouble(string input)
{
    if (input[0] == '-')
    {
        input.erase(0, 1);
    }

    int size = input.size();
    if (size == 0)
    {
        return false;
    }

    bool point_found = false;

    for (int i = 0; i < size; i++)
    {
        if ((!isdigit(input[i]) && input[i] != '.') || (input[i] == '.' && point_found) || isspace(input[i]))
        {
            return false;
        }
        if (input[i] == '.')
        {
            point_found = true;
        }
    }
    return true;
}