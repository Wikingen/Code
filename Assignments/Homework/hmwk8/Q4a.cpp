#include <iostream>

using namespace std;


int recursiveHelperSum(int num)
{
    if(num <0)
    {
        return -1;
    }
    
    if(num<10)
    {
        return num;
    }
    
    return num%10 + recursiveHelperSum(num/10);
}



int main()
{
    int number = 999;
    int sum_of_digits = recursiveHelperSum(number);
    cout << "Sum of digits " << number << " is " << sum_of_digits << endl;
}