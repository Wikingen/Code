#include "Room.hpp"


class Hostel
{
    public:
        Hostel();
        Hostel(double cost_per_night);

        void setCostPerNight(double cost_per_night);
        void setRoom(int idx, Room new_room);

        double getCostPerNight();
        Room getRoom(int idx);

        int findRoom(Booking new_booking);

        bool isAtCapacity();

        double calculateNightlyRevenue();

    


    private:
        const static int _MAX_ROOMS = 20;
        double _cost_per_night;
        Room _rooms[_MAX_ROOMS];
};