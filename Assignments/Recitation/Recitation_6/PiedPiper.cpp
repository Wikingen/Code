#include <iostream>
using namespace std;

int raccoonPiepPiper(int years);

int main()
{

    int years = 0;
    string input;
    cout << "please enter number of years: " << endl;
    getline(cin, input);
    years = stoi(input);
    cout << "The cost are as follows" << endl;
    int total_cost = raccoonPiepPiper(years);
    cout << "The total cost is " << total_cost << " dollars" << endl;
}

int raccoonPiepPiper(int years)
{
    int total_cost = 0;
    int cost = 50;
    int raccoons = 0;
    int raccoon_cost = 0;

    for (int i = 0; i < years; i++)
    {
        cost = 50;
        cost = cost - 5 * i;
        if (cost < 1)
        {
            cost = 1;
        }
        total_cost += cost;
        raccoons = i;
        cout << cost << " ";
        for (int j = 0; j < raccoons; j++)
        {
            raccoon_cost = cost - (j + 1);
            if (raccoon_cost < 1)
            {
                raccoon_cost = 1;
            }
            total_cost += raccoon_cost;
            cout << raccoon_cost << " ";
        }
        cout << "\n";
    }

    return total_cost;
}