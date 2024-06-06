#include "HostelClass.h"




int main()
{

    string file_name = "Bookings1.txt";

    Room room("1B25");
    

    // test return value for a file that exist and all booking in the file CAN be accomodated in the room
    assert(room.addBooking("bookings1.txt") == 1);

    // test return value for removing a booking which is NOT added to the Room
    assert(room.removeBooking("Sara") == 0);

    // test return value for removing a booking which is already added to the Room
    assert(room.removeBooking("Leo") == 1);

    return 0;
}
