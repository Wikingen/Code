#include <iostream>
using namespace std;

int maxProfit(int prices[], const int NUM_MONTHS)
{
    int buy_price = -1;
    int sell_price = -1;
    int profit = 0;
    int max_profit = 0;
    for (int i = 0; i < NUM_MONTHS - 1; i++)
    {

        buy_price = prices[i];
        sell_price = prices[i + 1];
        
        profit = sell_price - buy_price;
        if (profit > max_profit)
        {
            max_profit = profit;
        }


        for (int j = i+1; j < NUM_MONTHS; j++)
        {
            if (prices[j] > sell_price)
            {
                sell_price = prices[j];
                profit = sell_price - buy_price;
                if (profit > max_profit)
                {
                    
                    max_profit = profit;
                }
            }
        }
        
    }
    return max_profit;
}



int main()
{
    const int NUM_MONTHS = 6;
    int prices[NUM_MONTHS] = {700000, 100000, 500000, 300000, 600000, 400000};
    int profit = maxProfit(prices, NUM_MONTHS);
    cout << "Maximum profit: " << profit << endl;
    return 0;
}