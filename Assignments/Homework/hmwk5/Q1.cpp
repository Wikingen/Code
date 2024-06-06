#include <iostream>
#include <cmath>
using namespace std;

void chemicalElements(string elements[], const int ELEMENTS_SIZE);
void squareRoots(double numbers[], const int NUMBERS_SIZE);
void fillNumbers(int divisible_numbers[], const int DIVISIBLE_NUMBERS_SIZE);
void fillLetters(char letters[], const int LETTERS_SIZE);

int main()
{
    const int NUMBERS_SIZE = 10;
    double numbers[NUMBERS_SIZE];
    squareRoots(numbers, NUMBERS_SIZE);
    for (int i = 0; i < NUMBERS_SIZE; i++)
    {
        cout << numbers[i] << endl;
    }

    // Initialize letters array and LETTERS_SIZE
    const int LETTERS_SIZE = 52;
    char letters[LETTERS_SIZE];
    fillLetters(letters, LETTERS_SIZE);
    for (int i = 0; i < 52; i++)
    {
        cout << letters[i] << endl;
    }
    return 0;
}

void fillLetters(char letters[], const int LETTERS_SIZE)
{
    int array_index = 0;
    for (int i = 90; i > 64; i--)
    {
        letters[array_index] = (char)i;
        array_index += 1;
        letters[array_index] = (char)(i+32);
        array_index += 1;

    }
}

void fillNumbers(int divisible_numbers[], const int DIVISIBLE_NUMBERS_SIZE)
{
    int array_index = 0;

    for (int i = 50; i < 100; i++)
    {
        if (i % 7 == 0)
        {
            divisible_numbers[array_index] = i;
            array_index += 1;
        }
    }
}

void chemicalElements(string elements[], const int ELEMENTS_SIZE)
{

    string list[] = {"Hydrogen",
                     "Helium",
                     "Lithium",
                     "Beryllium",
                     "Boron",
                     "Carbon",
                     "Nitrogen",
                     "Oxygen",
                     "Fluorine",
                     "Neon"};

    for (int i = 0; i < ELEMENTS_SIZE; i++)
    {
        elements[i] = list[i];
    }
}

void squareRoots(double numbers[], const int NUMBERS_SIZE)
{
    int array_index =0;
    for (int i = 1; i <= NUMBERS_SIZE; i++)
    {
        numbers[array_index] = sqrt(i);
        array_index += 1;
    }
}