#include <iostream>
#include <fstream>

using namespace std;

void listNationalParks(string filename)
{
    // initialize variables
    ifstream file_in(filename); // opens a file

    if (file_in.fail())
    {
        cout << "This file does not exist." << endl;
        return;
    }

    const int MAX_SIZE = 63;
    string parks[MAX_SIZE];

    string park;

    int idx = 0;


    // Fill in the blank below with code to read from the file and store in the parks array
    while (getline(file_in, park))
    {
        parks[idx] = park;
        idx += 1;

        // Fill in the blank below with code to check if you are trying to store more values than possible in the parks array
        if (idx >= MAX_SIZE)
        {
            break;
        }
    }

    for (int i = 0; i < idx; ++i)
    {
        cout << i << ": " << parks[i] << endl;
    }

    file_in.close();
}

int main()
{
    string filename;
    cout << "Enter national parks filename" << endl;
    cin >> filename;
    listNationalParks(filename);
    return 0;
}