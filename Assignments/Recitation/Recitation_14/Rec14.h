#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <string>
using namespace std;

struct Airplane
{
    string id;
    int speed;
};

class Airport
{
private:
    const static int _MAX = 3;
    Airplane _planes[_MAX];
    int _num_planes;

public:
    Airport();
    Airport(Airplane, Airplane, Airplane);
    void setNumPlanes(int);
    int getNumPlanes() const;
    Airplane getPlane(string);
    void addPlane(string, int);
    void removePlane(Airplane);
};

#endif