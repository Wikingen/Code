#include "Hostel.hpp"

Hostel::Hostel()
{
    _cost_per_night = 0;
}

Hostel::Hostel(double cost_per_night)
{
    _cost_per_night = cost_per_night;
}

void Hostel::setCostPerNight(double cost_per_night)
{
    _cost_per_night = cost_per_night;
}

void Hostel::setRoom(int idx, Room new_room)
{
    _rooms[idx] = new_room;
}

double Hostel::getCostPerNight()
{
    return _cost_per_night;
}
Room Hostel::getRoom(int idx)
{
    return _rooms[idx];
}

int Hostel::findRoom(Booking new_booking)
{
    if(new_booking.num_people <= 0)
    {
        return -1;
    }
    for (int i = 0; i < _MAX_ROOMS; i++)
    {
        if ( (10 - _rooms[i].getNumeCurrentOccupants()) > new_booking.num_people)
        {
            return i;
        } 
    }
    return -1;
}

bool Hostel::isAtCapacity()
{
    for (int i = 0; i < _MAX_ROOMS; i++)
    {
        if(_rooms[i].getNumeCurrentOccupants() < 10)
        {
            return false;
        }
    }
    return true;
}

double Hostel::calculateNightlyRevenue()
{
    double total = 0;
    for (int i = 0; i < _MAX_ROOMS; i++)
    {
        total += _rooms[i].getNumeCurrentOccupants() * _cost_per_night;
    }
    return total;
}