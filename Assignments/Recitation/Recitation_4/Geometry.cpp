#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

double calculateVolumeOfSphericalCandy(double radius);
double calculateVolumeOfHeartCandy(double radius);

int main()
{
    const int pi = 3.14159;
    double radius = 1;

    assert(calculateVolumeOfHeartCandy(1) == pi + 4 * sqrt(3));
    assert(calculateVolumeOfHeartCandy(0) == 0);
    assert(calculateVolumeOfHeartCandy(-1) != (pi + 4 * sqrt(3)) * pow(radius, 3));

    double volumeHeart = calculateVolumeOfHeartCandy(radius);
    cout << "The volume of a heart with radius " << radius << " is " << volumeHeart << endl;

    assert(calculateVolumeOfSphericalCandy(0) == 0);
    assert(calculateVolumeOfSphericalCandy(-1) != 4 * pi / 3);
    assert(calculateVolumeOfSphericalCandy(1) == 4 * pi / 3);

    double volumeSphere = calculateVolumeOfSphericalCandy(radius);
    cout << "The volume of a spherical candy with radius " << radius << " is " << volumeSphere << endl;
}

double calculateVolumeOfHeartCandy(double radius)
{
    const int pi = 3.14159;
    return (pi + 4 * sqrt(3)) * pow(radius, 3);
}

double calculateVolumeOfSphericalCandy(double radius)
{
    const int pi = 3.14159;
    return (4.0 / 3.0) * pi * pow(radius, 3);
}
