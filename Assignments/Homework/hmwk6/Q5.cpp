// CSCI 1300 Spring 2024
// Author: Otto Wiking Häger
// TA: Elise Jordan Tate
// Question 1

#include <iostream>
#include <fstream>
using namespace std;

struct Restaurant
{
    string name;
    int food_quality;
    int cleanliness;
    int wait_time;
    double overall;
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

double getOverallRating(Restaurant restaurant)
{
    if (restaurant.cleanliness < 0 || restaurant.cleanliness > 10 || restaurant.food_quality > 10 || restaurant.food_quality < 0 || restaurant.wait_time < 0 || restaurant.wait_time > 5)
    {
        return -1;
    }
    double result = 6.3 * restaurant.food_quality + 4.3 * restaurant.cleanliness + 3.4 * (5 - restaurant.wait_time);
    return result;
}

int readRestaurantDetails(string filename, Restaurant restaurants[], const int MAX_RESTAURANTS)
{
    ifstream in_file(filename);
    if (in_file.fail())
    {
        return -1;
    }

    string splitted_line[10]; // 10 is an overshot value, we need 4
    int num_res = 0;
    string name;
    int split_len;
    string line;
    int i = 0;
    while (getline(in_file, line) && i < MAX_RESTAURANTS)
    {

        split_len = split(line, '~', splitted_line, MAX_RESTAURANTS); // Iterate through file, dont get too many rastaurants tho

        if (split_len == 4) // Check if we have the right amount of avalues
        {
            restaurants[i].name = splitted_line[0];
            restaurants[i].food_quality = stoi(splitted_line[1]);
            restaurants[i].cleanliness = stoi(splitted_line[2]);
            restaurants[i].wait_time = stoi(splitted_line[3]);
            restaurants[i].overall = getOverallRating(restaurants[i]);
            num_res++;
            i++;
        }
    }

    return num_res;
}

int getBest(Restaurant restaurants[], int arr_size, string metric)
{
    int metric_num = 0;

    if (metric == "Food Quality")
    {
        metric_num = 1;
    }
    else if (metric == "Cleanliness")
    {
        metric_num = 2;
    }
    else if (metric == "Wait Time")
    {
        metric_num = 3;
    }
    else if (metric == "Overall")
    {
        metric_num = 4;
    }
    else
    {
        return -1;
    }

    int best_rest_index = 0;

    for (int i = 1; i < arr_size; i++)
    {
        switch (metric_num)
        {
        case 1:
            if (restaurants[i].food_quality > restaurants[best_rest_index].food_quality)
            {
                best_rest_index = i;
            }

            break;
        case 2:
            if (restaurants[i].cleanliness > restaurants[best_rest_index].cleanliness)
            {
                best_rest_index = i;
            }

            break;
        case 3:
            if (restaurants[i].wait_time > restaurants[best_rest_index].wait_time)
            {
                best_rest_index = i;
            }

            break;
        case 4:
            if (restaurants[i].overall > restaurants[best_rest_index].overall)
            {
                best_rest_index = i;
            }

            break;
        }
    }

    return best_rest_index;
}

int main()
{
    const int MAX_RESTAURANTS = 30;

    string restaurants_filename = "restaurants_1.txt";
    Restaurant restaurants[MAX_RESTAURANTS];

    int arr_size = readRestaurantDetails(restaurants_filename, restaurants, MAX_RESTAURANTS);

    // Checking if the file was opened correctly
    if (arr_size == -1)
    {
        cout << "Failed to open file." << endl;
    }
    else if (arr_size == 0)
    {
        cout << "Empty file." << endl;
    }
    else
    {
        int idx = getBest(restaurants, arr_size, "Food Quality");

        if (idx == -1)
        {
            cout << "Invalid metric." << endl;
        }
        else
        {
            cout << "Restaurant: " << restaurants[idx].name << " ";
            cout << "Ratings: ";
            cout << restaurants[idx].food_quality << " ";
            cout << restaurants[idx].cleanliness << " ";
            cout << restaurants[idx].wait_time << " ";
            cout << "Overall: ";
            cout << restaurants[idx].overall << " ";
            cout << endl;
        }
    }

    return 0;
}