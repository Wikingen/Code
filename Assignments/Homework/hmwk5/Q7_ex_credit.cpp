#include <iostream>
using namespace std;

void printTriangle(int height)
{
    int letter_number = 0;

    if (height < 1)
    {
        cout << "Invalid input." << endl;
        return;
    }

    for (int i = height; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            if (97+letter_number > 122)
            {
                letter_number -= 26;
            }

            cout << (char)(97 + letter_number);
            letter_number +=1;
        }

        cout << endl;
    }
}

int main()
{
    int height = 100;
    printTriangle(height);
    return 0;
}