#include <iostream>
using namespace std;



bool isInteger(string input);

int main()
{
    string input;
    cout << "Enter the integer : " << endl;
    getline( cin, input);
    bool int_status = isInteger(input);
    if(int_status)
    {
        cout << "This is an integer! Wohoooo" << endl;
    }
    else
    {
        cout << "Come on man, that aint no integer! " << endl;
    }
}

bool isInteger(string input)
{
    if (input[0] == '-')
    {
        input.erase(0,1);
    }

    int size = input.size();

    
    for (int i = 0; i < size; i++)
    {
        if(isdigit(input[i]) == false)
        {
            return false;
        }

    }
    return true;
}
