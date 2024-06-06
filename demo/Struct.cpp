#include <iostream>
#include <fstream>
using namespace std;

struct myData
{
    string city;
    int population;

};

int main()
{
    ifstream file_in;
    file_in.open("input.txt");
    if (file_in.fail())
    {
        cout << "Could not open file" << endl;
        return -1;
    }

    myData data;

    string line;
    while (getline(file_in, line))
    {
        const int l = line.length();
        int i;
        for (i = 0;i < l; i++)
        {
            if (isspace(line[i]))
            {
                data.city = line.substr(0,i);
                cout << "found city: "<< data.city << endl;
                break;
            }
        }

        int s = i+1;

        i = i +1;
        for (i=i; i < l; i++)
        {
            if (isspace(line[i]))
            {
                string my_double = line.substr(s, i- s);
                data.population = stoi(my_double);

                cout << "\tFound a population: " << data.population << endl;
            }
        }




    }

    file_in.close();
    return 0;
}