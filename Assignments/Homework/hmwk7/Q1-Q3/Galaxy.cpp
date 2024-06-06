#include "Galaxy.hpp"

Galaxy::Galaxy()
{
    _name = "";
    _current_size = 0;
    for (int i = 0; i < _MAX_SIZE; i++)
    {
        _radii[i] = 0;
    }
}

Galaxy::Galaxy(string name)
{
    _name = name;
    _current_size = 0;
    for (int i = 0; i < _MAX_SIZE; i++)
    {
        _radii[i] = 0;
    }
}

Galaxy::Galaxy(string name, int radii[], int arr_size)
{
    _name = name;
    if (arr_size <= _MAX_SIZE)
    {
        _current_size = arr_size;
    }
    else
    {
        _current_size = _MAX_SIZE;
    }

    for (int i = 0; i < _current_size; i++)
    {
        _radii[i] = radii[i];
    }
}

bool Galaxy::addRadius(int radius)
{
    if (_current_size == _MAX_SIZE || radius <= 0)
    {
        return false;
    }

    _radii[_current_size] = radius;
    _current_size++;

    return true;
}

string Galaxy::getName()
{
    return _name;
}

int Galaxy::getRadius(int idx)
{
    if (idx < 0 || idx >= _current_size)
    {
        return -1;
    }
    return _radii[idx];
}

int Galaxy::getCurrentSize()
{
    return _current_size;
}

void Galaxy::setName(string name)
{
    _name = name;
}

double Galaxy::getAverageRadius()
{
    if (_current_size <= 0 || _current_size > _MAX_SIZE)
    {
        return 0;
    }

    double sum = 0;
    for (int i = 0; i < _current_size; i++)
    {
        sum +=_radii[i];
    }
    
    double avg = sum / _current_size;

    return avg;
}

string findGalaxyWithLargestAverageRadius(Galaxy galaxies[], const int ARR_SIZE)
{
    double biggest_rad = galaxies[0].getAverageRadius();
    int biggest_idx = 0;
    int avg_rad = 0;
    for( int i = 1; i < ARR_SIZE; i++)
    {
        avg_rad = galaxies[i].getAverageRadius();
        if(avg_rad > biggest_rad)
        {
            biggest_idx = i;
            biggest_rad = avg_rad;
        }
        
    }
    string biggest_galaxy = galaxies[biggest_idx].getName();
    return biggest_galaxy;
}