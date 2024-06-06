#include <iostream>
using namespace std;

double calculateFarmArea(double length, double width)
{
    if (length <= 0 || width <= 0)
    {
        return -1;
    }
    else
    {
        return (length * width);
    }
}

int main()
{
    double length = -1;
    cout << "Enter length of the farmland in ft:" << endl;
    cin >> length;
    double width = -1;
    cout << "Enter width of the farmland in ft:" << endl;
    cin >> width;

    double area = calculateFarmArea(length, width);

    // Validating the area
    if (area == -1)
    {
        cout << "Length or width is invalid. Area cannot be calculated." << endl;
    }
    else
    {
        cout << "The area is: " << area << " sq ft." << endl;
    }

    return 0;
}