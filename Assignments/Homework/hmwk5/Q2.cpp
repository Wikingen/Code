#include <iostream>
#include <iomanip>
using namespace std;

void stepCountCumulativeSum(int daily_steps[], const int NUM_DAYS, int cumulative_steps[]);
double stepCountDeviation(int daily_steps[], const int NUM_DAYS, const int OPTIMAL_STEP_COUNT);
void stepCountDelta(int daily_steps[], int last_month_steps[], int delta[], const int NUM_DAYS);

int main()
{
    const int NUM_DAYS = 5;
    int daily_steps[NUM_DAYS] = {5000, 4000, 5000, 2000, 4000};
    // const int OPTIMAL_STEP_COUNT = 5000;
    // int last_month_steps[NUM_DAYS] = {4000, 5000, 5000, 1000, 7000};
    int cumulative_steps[NUM_DAYS];
   
    

    stepCountCumulativeSum(daily_steps, NUM_DAYS, cumulative_steps);


    for (int i = 0; i < NUM_DAYS; i++)
    {
        cout << cumulative_steps[i] << endl;
    }

    return 0;
}

void stepCountDelta(int daily_steps[], int last_month_steps[], int delta[], const int NUM_DAYS)
{

    for (int i = 0; i < NUM_DAYS; i++)
    {
        delta[i] = daily_steps[i] - last_month_steps[i];
    }
}

double stepCountDeviation(int daily_steps[], const int NUM_DAYS, const int OPTIMAL_STEP_COUNT)
{
    int sum = 0;
    for (int i = 0; i < NUM_DAYS; i++)
    {
        sum += daily_steps[i];
    }
    double mean = sum / NUM_DAYS;
    double deviation = mean - OPTIMAL_STEP_COUNT;
    return deviation;
}

void stepCountCumulativeSum(int daily_steps[], const int NUM_DAYS, int cumulative_steps[])
{
    for (int i = 0; i < NUM_DAYS; i++)
    {
        cumulative_steps[i] = 0;
    }

    for (int i = 0; i < NUM_DAYS; i++)
    {

        for (int j = 0; j <= i; j++)
        {
            // cout << "Day " << i << " Adds daily steps: " << daily_steps[j] << " to " << "comulative steps " <<cumulative_steps[i] << endl;
            cumulative_steps[i] += daily_steps[j];
        }
    }
}