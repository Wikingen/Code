#include <iostream>
using namespace std;

int main()
{
    string input1;
    string input2;
    char array1[4];
    char array2[3];

    cout << "Please enter 4 characters for the first array" << endl;
    getline(cin, input1);

    cout << "Please enter 3 characters for the second array" << endl;
    getline(cin, input2);

    int a = 0;

    // Fill array1 with non-space characters from input1
    for (int i = 0; i < (int)input1.length() && a < 4; i++)
    {
        if (input1[i] != ' ')
        {
            array1[a] = input1[i];
            a++;
        }
    }

    a = 0; // Reset a to 0 for array2

    // Fill array2 with non-space characters from input2
    for (int i = 0; i < (int)input2.length() && a < 3; i++)
    {
        if (input2[i] != ' ')
        {
            array2[a] = input2[i];
            a++;
        }
    }

    // Print all combinations of elements in array1 with elements in array2
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << array1[i] << array2[j] << " ";
        }

        cout << "\n";
    }

    return 0;
}
