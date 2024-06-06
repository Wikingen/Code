#include <iostream>
using namespace std;


double emissionReduction(double current_reduction, int years)
{
    if(current_reduction < 0 || years < 0)
    {
        return -1;
    }

    if(years == 0)
    {
        return current_reduction;
    }

    return emissionReduction(current_reduction + 0.1*current_reduction + 20,years -1);

}



int main()
{
    double next_year_reduction = emissionReduction(100, 3);
    cout << "Predicted reduction in carbon emissions: " << next_year_reduction << endl;
}