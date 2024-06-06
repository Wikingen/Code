#include "Rec14.h"

Airport::Airport()
{
    _num_planes = 0;
}

Airport::Airport(Airplane p1, Airplane p2, Airplane p3) 
{
    _num_planes = 3;   //Redeclaration
	Airplane _planes[_MAX] = {p1,p2,p3};
}

void Airport::setNumPlanes(int num_planes)
{
    _num_planes = num_planes; // Redeclaration
}

int Airport::getNumPlanes() const
{
    return _num_planes;
}

Airplane Airport::getPlane(string id)
{
    for (int i = 0; i < _num_planes ; i++) // change i dec and upper bound
    {
        if (_planes[i].id == id)
        {
            return _planes[i];
        }
    }
    Airplane empty = {"", 0};
    return empty;
}

void Airport::addPlane(string id, int speed) //Data type and class specifier in wrong order
{
    if (_num_planes < _MAX)
    {
        _planes[_num_planes].id = id;
        _planes[_num_planes].speed = speed;
        _num_planes++;
    }
    else
    {
        cout << "Cannot add more planes to the airport!" << endl;
    }
}

void Airport::removePlane(Airplane p) //No class specifier
{
    Airplane plane = getPlane(p.id);
    int index;
    if (plane.speed != 0)
    {
        for (int i = 0; i < _num_planes; i++) 
        {
            if (_planes[i].id == plane.id && _planes[i].speed == plane.speed) //Use comparison == and not assigment =
            {
                index = i;
                break;
            }
        }
        for (int i = index; i <_num_planes; i++) 
        {
            _planes[i] = _planes[i+1];
        }
        _planes[_num_planes-1].id = "";
        _planes[_num_planes-1].speed = 0;
       
    }
    
    return;
}