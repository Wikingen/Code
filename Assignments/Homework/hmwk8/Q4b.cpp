#include <iostream>

using namespace std;

int recursiveHelperSum(int num)
{
    if (num < 0)
    {
        return -1;
    }

    if (num < 10)
    {
        return num;
    }

    return num % 10 + recursiveHelperSum(num / 10);
}

int digitsSuperSumRecursive(int num)
{
    if (num <0)
    {
        return -1;
    }

    if(num < 10)
    {
        return num;
    }

    return digitsSuperSumRecursive(recursiveHelperSum(num));

}

int main()
{
    int number = 236;
    int super_sum_result = digitsSuperSumRecursive(number);
    cout << "Super Sum of " << number << " is " << super_sum_result << endl;
}