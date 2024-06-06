#include <iostream>
#include <fstream>
using namespace std;

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

int countIfConditions(string line)
{
    const int MAX_WORD = 40;
    int line_length = line.length();
    string line_splitted[40];
    int line_words = split(line, ' ', line_splitted, MAX_WORD);
    int word_length = 0;

    if (line_length == 0 || line_words == -1)
    {
        return 0;
    }

    int num_ifs = 0;
    for (int i = 0; i < line_words; i++)
    {

        if (line_splitted[i] == "if")
        {
            num_ifs += 1;
        }
        else if (line_splitted[i] == "else")
        {
            num_ifs += 1;
            if (i + 1 < line_words) // Chesh if it is a "else if"
            {
                if (line_splitted[i + 1] == "if")
                {
                    i++;
                }
            }
        }
        else
        {
            word_length = line_splitted[i].length(); // check for // in a word
            for (int j = 0; j < word_length; j++)
            {

                if (j + 1 < word_length)
                {
                    if (line_splitted[i][j] == '/' && line_splitted[i][j + 1] == '/') // Sees if there is two consecuteive /
                    {
                        return num_ifs;
                    }
                }
            }
        }
    }

    return num_ifs;
}

int countLoopConditions(string line)
{
    const int MAX_WORD = 40;
    int line_length = line.length();
    string line_splitted[40];
    int line_words = split(line, ' ', line_splitted, MAX_WORD);
    int word_length = 0;

    if (line_length == 0 || line_words == -1)
    {
        return 0;
    }

    int num_loops = 0;
    for (int i = 0; i < line_words; i++)
    {

        if (line_splitted[i] == "while" || line_splitted[i] == "for")
        {
            num_loops += 1;
        }
        else
        {

            word_length = line_splitted[i].length(); // check for // in a word
            for (int j = 0; j < word_length; j++)
            {

                if (j + 1 < word_length)
                {
                    if (line_splitted[i][j] == '/' && line_splitted[i][j + 1] == '/') // Sees if there is two consecuteive /
                    {
                        return num_loops;
                    }
                }
            }
        }
    }

    return num_loops;
}

int main()
{
    string line = "for (int i = 0; i < 10; i++) { while (i > 10) { cout << \"Never\" << do //while endl; } }";

    int loop_count = countLoopConditions(line);

    cout << "Conditions in loops: " << loop_count << endl;

    return 0;
}