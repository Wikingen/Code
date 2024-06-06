#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;


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

//Checks if a string is a integer
bool isInteger(string input)
{
    if (input[0] == '-')
    {
        input.erase(0, 1);
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

/**
 * doublesEqual will test if two doubles are equal to each other within two decimal places.
 */
bool doublesEqual(double a, double b, const double epsilon = 1e-2)
{
    double c = a - b;
    return c < epsilon && -c < epsilon;
}

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
    // cout << "we have " << separator_instances << " separator instances which means " << separator_instances + 1 << " substrings. " << endl;

    if (separator_instances == 0)
    {
        arr[0] = input_string;
        return 1;
    } // no need for else statement since it returns if condition is true

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

    int i = 0;
    while (i < string_length && substrings_added < max_capacity)
    {
        // cout << "Iteration " << i << endl;

        if (input_string[i] == separator || i == string_length)
        {
            end_index = i;
            substring = input_string.substr(start_index, (end_index - start_index));

            if (current_index < ARR_SIZE)
            {
                arr[current_index] = substring;
                substrings_added += 1;
                NUM_ELEMENTS += 1;
                current_index += 1;
            }
            else
            {
                // If there are more substrings than the array can hold, return -1
                return -1;
            }
            start_index = end_index + 1;
        }

        i++;
        // cout << "i:" << i << " < String length:"<< string_length << " AND  Substrings added:" << substrings_added << " <= Max capacity:" << max_capacity << endl;
    }
    if (start_index < string_length && substrings_added <= max_capacity) // takes care of last substring.
    {
        substring = input_string.substr(start_index, (string_length - start_index));
        if (current_index < ARR_SIZE)
        {
            arr[current_index] = substring;
            substrings_added += 1;
            NUM_ELEMENTS += 1;
            current_index += 1;
        }
        else
        {
            // If there are more substrings than the array can hold, return -1
            return -1;
        }
        start_index = end_index + 1;
    }
    // cout << "Number of elements: " << separator_instances + 1 << " Arr size: " << ARR_SIZE << endl;
    if (separator_instances + 1 > ARR_SIZE) // There is one more substring elements than separator instance
    {
        return -1;
    }

    return NUM_ELEMENTS;
}