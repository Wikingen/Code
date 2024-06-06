#include <iostream>
#include <fstream> // FILL IN THIS LINE
using namespace std;
struct Triangle
{
    double base, height;
};

double area(Triangle t)
{
    return 0.5 * t.base * t.height;
}

void setBase(Triangle t, double _base)
{
    t.base = _base;
}

void setHeight(Triangle t, double _height)
{
    t.height = _height;
}
int main()
{
    Triangle t;
    t.base = 20.0;
    t.height = 5.0;
    setBase(t, 7.0);
    setHeight(t, 12.0);
    cout << t.base << t.height << endl;
    cout << "Area: " << area(t) << endl;
    return 0;
}
