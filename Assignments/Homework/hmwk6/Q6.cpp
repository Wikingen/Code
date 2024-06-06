// CSCI 1300 Spring 2024
// Author: Otto Wiking Häger
// TA: Elise Jordan Tate
// Question 6 (Extra credit)
#include <iostream>
#include <fstream>
using namespace std;

struct Mountain
{
    string name;
    string continent;
    int trail_length;
    int elevation;
    int difficulty;
};

int split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    const int string_length = (int)input_string.length();
    int separator_instances = 0;

    if (input_string == "")
    {
        return 0;
    }

    for (int i = 0; i < string_length; i++)
    {
        if (input_string[i] == separator)
        {
            separator_instances += 1;
        }
    }

    if (separator_instances == 0)
    {
        arr[0] = input_string;
        return 1;
    }

    int max_capacity = ARR_SIZE;
    if ((separator_instances + 1) > ARR_SIZE)
    {
        max_capacity = separator_instances + 1;
    }

    int current_index = 0; // index for array
    int start_index = 0;
    int end_index = 0;
    int NUM_ELEMENTS = 0;
    string substring;
    int substrings_added = 0;

    for (int i = 0; i < string_length; i++)
    {
        if (input_string[i] == separator)
        {
            end_index = i;
            substring = input_string.substr(start_index, (end_index - start_index));
            arr[current_index] = substring;
            substrings_added += 1;
            NUM_ELEMENTS += 1;
            current_index += 1;

            start_index = end_index + 1;
            if (substrings_added >= max_capacity)
                break;
        }
    }

    if (start_index < string_length && substrings_added < max_capacity)
    {
        substring = input_string.substr(start_index, (string_length - start_index));
        arr[current_index] = substring;
        substrings_added += 1;
        NUM_ELEMENTS += 1;
    }

    if (substrings_added < (separator_instances + 1)) // Check if all substrings were added
    {
        return -1;
    }

    return NUM_ELEMENTS;
}

int readMountainDetails(string filename, Mountain maountains[], const int MAX_MOUNTAINS)
{
    ifstream in_file(filename);
    if (in_file.fail())
    {
        return -1;
    }

    string splitted_line[10]; // 10 is an overshot value, we need 5
    int number_of_mountains = 0;
    string name;
    int split_len;
    string line;
    int i = 0;
    while (getline(in_file, line) && i < MAX_MOUNTAINS)
    {

        split_len = split(line, ',', splitted_line, MAX_MOUNTAINS); // Iterate through file, dont get too many rastaurants tho

        if (split_len == 5) // Check if we have the right amount of avalues
        {
            maountains[i].name = splitted_line[0];
            maountains[i].continent = splitted_line[1];
            maountains[i].trail_length = stoi(splitted_line[2]);
            maountains[i].elevation = stoi(splitted_line[3]);
            maountains[i].difficulty = stoi(splitted_line[4]);
            number_of_mountains++;
            i++;
        }
    }

    return number_of_mountains;
}

int getMountains(Mountain mountains[], Mountain selected_mountains[], int choice, string value, int mountain_size)
{

    int arr_idx = 0;
    

    for (int i = 0; i < mountain_size; i++)
    {
        switch (choice)
        {
        case 1:
                cout << mountains[i].name << " dif: " << mountains[i].difficulty << " compared to: " << stoi(value) << endl;;
            if (mountains[i].difficulty == stoi(value))
            {
                selected_mountains[arr_idx] = mountains[i];
                arr_idx++;
            }
            break;

        case 2:
            if (mountains[i].elevation > stoi(value))
            {
                selected_mountains[arr_idx] = mountains[i];
                arr_idx++;
            }

            break;
        case 3:
            if (mountains[i].trail_length > stoi(value))
            {
                selected_mountains[arr_idx] = mountains[i];
                arr_idx++;
            }

            break;
        case 4:
            if (mountains[i].continent == value)
            {
                selected_mountains[arr_idx] = mountains[i];
                arr_idx++;
            }

            break;
        default:
            return -1;
        }
    }

    cout << "returning num: " << arr_idx << endl;
    return arr_idx ;
}

// Assume the proper libraries are included.

// Assume the proper implementation of getMountains is included.

int main()
{
    const int MAX_MOUNTAINS = 30;

    string mountains_filename = "mountains_1.txt";

    Mountain mountains[MAX_MOUNTAINS];
    Mountain selected_mountains[MAX_MOUNTAINS];

    int mountain_size = readMountainDetails(mountains_filename, mountains, MAX_MOUNTAINS);

    // Checking if the file was opened correctly
    if (mountain_size == -1)
    {
        cout << "Failed to open file." << endl;
        return 0;
    }

    string str_choice;
    cout << "Select option:" << endl;
    cout << "1. Obtain mountains with a certain difficulty rating." << endl;
    cout << "2. Obtain mountains taller than a certain elevation." << endl;
    cout << "3. Obtain mountains with a trail longer than a certain trail length." << endl;
    cout << "4. Obtain mountains in a certain continent." << endl;
    getline(cin, str_choice);

    int choice = stoi(str_choice);

    string value;
    cout << "Enter a value based on the choice:" << endl;
    getline(cin, value);

    int selected_size = getMountains(mountains, selected_mountains, choice, value, mountain_size);

    if (selected_size == -1)
    {
        cout << "Invalid choice." << endl;
    }
    else
    {
        for (int i = 0; i < selected_size; i++)
        {
            cout << "Name: " << selected_mountains[i].name << ", ";
            cout << "Continent: " << selected_mountains[i].continent << ", ";
            cout << "Trail length: " << selected_mountains[i].trail_length << ", ";
            cout << "Elevation: " << selected_mountains[i].elevation << ", ";
            cout << "Difficulty: " << selected_mountains[i].difficulty;
            cout << endl;
        }
    }

    return 0;
}