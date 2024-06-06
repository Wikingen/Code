#include <iostream>
#include <fstream>
using namespace std;

int readIngredients(string filename, string ingredients[], const int MAX_INGREDIENTS)
{

    ifstream file_in(filename);
    if (file_in.fail())
    {
        return -1;
    }

    int num_ingr = 0;
    string line;
    while (getline(file_in, line) && num_ingr < MAX_INGREDIENTS)
    {
        ingredients[num_ingr] = line;
        num_ingr++;
    }

    file_in.close();
    return num_ingr;
}

int compareIngredients(string original_ingredients[], string friend_ingredients[], int original_ingredients_size,
                       int friend_ingredients_size, string missing_ingredients[])

{
    int missing_ingr = 0;
    bool is_missing = true;
    for (int i = 0; i < original_ingredients_size; i++)
    {
        is_missing = true;
        for (int j = 0; j < friend_ingredients_size; j++)
        {
            if (original_ingredients[i] == friend_ingredients[j])
            {
                is_missing = false;
            }
        }

        if (is_missing)
        {
            missing_ingredients[missing_ingr] = original_ingredients[i];
            missing_ingr += 1;
        }
    }

    return missing_ingr;
}

// Assume the proper libraries are included.

// Assume the proper implementation of compareIngredients is included.
int main()
{
    const int MAX_INGREDIENTS = 20;

    string original_ingredients[MAX_INGREDIENTS];
    string friend_1_ingredients[MAX_INGREDIENTS];
    string friend_2_ingredients[MAX_INGREDIENTS];
    string missing_ingredients_1[MAX_INGREDIENTS];
    string missing_ingredients_2[MAX_INGREDIENTS];

    int original_ingredients_size = readIngredients("ingredients_1.txt", original_ingredients, MAX_INGREDIENTS);
    int friend_1_ingredients_size = readIngredients("ingredients_1_friend_1.txt", friend_1_ingredients, MAX_INGREDIENTS);
    int friend_2_ingredients_size = readIngredients("ingredients_1_friend_2.txt", friend_2_ingredients, MAX_INGREDIENTS);

    int missing_ingredients_1_size = compareIngredients(original_ingredients,
                                                        friend_1_ingredients,
                                                        original_ingredients_size,
                                                        friend_1_ingredients_size,
                                                        missing_ingredients_1);
    int missing_ingredients_2_size = compareIngredients(original_ingredients,
                                                        friend_2_ingredients,
                                                        original_ingredients_size,
                                                        friend_2_ingredients_size,
                                                        missing_ingredients_2);

    cout << "Missing ingredients for friend 1:" << endl;
    for (int i = 0; i < missing_ingredients_1_size; i++)
    {
        cout << i + 1 << ": " << missing_ingredients_1[i] << " ";
    }
    cout << endl;
    cout << "Missing ingredients for friend 2:" << endl;
    for (int i = 0; i < missing_ingredients_2_size; i++)
    {
        cout << i + 1 << ": " << missing_ingredients_2[i];
    }
    cout << endl;
    if (missing_ingredients_1_size < missing_ingredients_2_size)
    {
        cout << "Friend 1 wins !" << endl;
    }
    else if (missing_ingredients_1_size > missing_ingredients_2_size)
    {
        cout << "Friend 2 wins!" << endl;
    }
    else
    {
        cout << "It's a tie!" << endl;
    }

    return 0;
}