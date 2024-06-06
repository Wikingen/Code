#include "Entity.hpp"


//Split function
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

//Validates doubles
bool isDouble(string input)
{
    int size = input.size();
    if (size == 0)
    {
        return false;
    }

    if (input[0] == '-')
    {
        input.erase(0, 1);
    }

    size = input.size();
    if (size == 0)
    {
        return false;
    }

    bool point_found = false;
    bool has_num = false;

    for (int i = 0; i < size; i++)
    {
        if (isdigit(input[i]) && !has_num)
        {
            has_num = true;
        }
        if ((!isdigit(input[i]) && input[i] != '.') || (input[i] == '.' && point_found) || isspace(input[i]))
        {
            return false;
        }
        if (input[i] == '.')
        {
            point_found = true;
        }
    }
    if (has_num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Checks if a string is a integer
bool isInteger(string input)
{
    if(input == "")
    {
        return false;
    }

    if (input[0] == '-')
    {
        input.erase(0, 1);
    }

    if (input == "")
    {
        return false;
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






bool loadCharacters(string filename, Entity characters[], const int CHARACTERS_SIZE, bool is_enemy)
{
    ifstream in_file(filename);
    if (in_file.fail())
    {
        return false;
    }
    
    string name;
    double hp;
    int gold;
    char condition; 

    string splitted_line[10]; //array with all elements from one input line. Size should be 4, but we overshoot with 10
    int num_elements; //number of elements in splitted string
    int curr_index = 0; //Keeps track of where in the character array we are
    
    string line; //Input lines from textfile
    getline(in_file,line); //Get rid of first line since it is a title-line

    while(getline(in_file,line) && curr_index < CHARACTERS_SIZE)
    {
        num_elements = split(line,'|',splitted_line, 10);
        
        if (num_elements !=4)   //skip invalid rows
        {
            continue;
        }
        

        //NOTE THE FOLLOWING VALIDATION IS REPETETIVE SINCE IT IS ALREADY CHECKED IN SETTERS

        name = splitted_line[0];    //If its a valid double we add it otherwise it is set to 0
        if (isDouble(splitted_line[1]))
        {
            hp = stod(splitted_line[1]);
        }
        else
        {
            hp = 0;
        }

        if(isInteger(splitted_line[2])) //if it is a valid int it will be added otherwise it is set to 0
        { 
            gold = stoi(splitted_line[2]);
        }
        else 
        {
            gold = 0;
        }

        if (splitted_line[3][0] == 'H' || splitted_line[3][0] == 'D' || splitted_line[3][0] == 'P')   //if its a valid condition it is set, else it is 'H'
        {
            condition = splitted_line[3][0];   //add index 0 to make it a char
        }
        else
        {
            condition = 'H';
        }


        characters[curr_index].setName(name);
        characters[curr_index].setHP(hp);
        characters[curr_index].setGold(gold);
        characters[curr_index].setCondition(condition);
        characters[curr_index].setIsEnemy(is_enemy);
        curr_index++;
    }
    
    return true;
}

int main()
{

    // Loading only a maximum of PLAYERS_SIZE characters
    Entity enemies[2] = {};

    loadCharacters("enemies_full.txt", enemies, 2, true);

    for (int i = 0; i < 2; i++)
    {
        enemies[i].printStats();
        cout << "----------------------------------------------" << endl;
    }
}