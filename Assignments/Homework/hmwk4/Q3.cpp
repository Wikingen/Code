#include <iostream>
using namespace std;

char encryptUpper(char letter, int shift_value);



int main()
{
    char letter = 'X';
    int shift_value = -1;
    cout << "Enter an uppercase letter to encrypt:" << endl;
    cin >>  letter;
    cout << "Enter the encryption value: " << endl;
    cin >> shift_value;

    char encrypted_letter = encryptUpper(letter, shift_value);
    cout << "Letter " << letter << " was encrypted to " << encrypted_letter << endl;
            
}

char encryptUpper( char letter , int shift_value)
{
    if (   (65 <= letter) && (letter <= 90) && (33 <= (letter + shift_value))  && ((letter + shift_value) <= 126) )
    {
        return (letter + shift_value);
    }
    else
    {
        return letter;
    }
}