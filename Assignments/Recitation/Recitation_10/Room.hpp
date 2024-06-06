#include <fstream>
#include "Functions.hpp" //includes iostream

struct Booking
{
    string name;    // Name of people who made booking
    int num_people; // NUmber of people in the booking
};

class Room
{
private:
    string _room_id;
    static const int _MAX_OCCUPANTS = 10;
    static const int _NUM_BOOKINGS = 10;
    int _num_current_occupants; // TOTAL
    int _num_current_bookings;  // TOTAL
    Booking _bookings[_NUM_BOOKINGS];

public:
    Room()
    {
        _room_id = "";
        _num_current_bookings = 0;
        _num_current_occupants = 0;
    }
    Room(string id)
    {
        _room_id = id;
        _num_current_occupants = 0;
        _num_current_bookings = 0;
    }

    void setRoomId(string id)
    {
        _room_id = id;
    }
    string getRoomId()
    {
        return _room_id;
    }
    void setNumCurrentOccupants(int n)
    {
        _num_current_occupants = n;
    }
    int getNumeCurrentOccupants()
    {
        return _num_current_occupants;
    }

    // Sets all booking sizes to zero
    void resetNumCurrentOccupants()
    {
        for (int i = 0; i < _NUM_BOOKINGS; i++) // iterate through bookings and setting them to 0
        {
            _bookings[i].num_people = 0;
        }
    }

    bool addBooking(string file_name)
    {
        ifstream in_file(file_name);
        if (in_file.fail())
        {
            cout << "Could not open " << file_name << endl;
            return false;
        }

        resetNumCurrentOccupants(); // set all booking companies to 0

        string line_split[2];
        string line;
        int count = 0;
        string guest_name = "";
        int guest_company = 0;

        while (getline(in_file, line))
        {

            if (split(line, ',', line_split, 2) == 2)
            {
                guest_name = line_split[0];
                guest_company = stoi(line_split[1]);

                // cout << "MAX: " << _MAX_OCCUPANTS << " Booking count: " << _bookings[count].num_people << endl;
                if (guest_company + _num_current_occupants > _MAX_OCCUPANTS)
                {

                    cout << "Could not fit " << guest_name << "'s company of " << guest_company << " people in room " << count << "." << endl;
                    cout << " We only have room for " << _MAX_OCCUPANTS - _bookings[count].num_people << " people" << endl;
                    return false;
                }

                _bookings[count].name = guest_name;
                _bookings[count].num_people = guest_company;
                _num_current_occupants += guest_company;
                _num_current_bookings++;

                cout << "Now room " << getRoomId() << " has " << _num_current_occupants << " occupants." << endl;

                count++;
            }
        }

        cout << "Successfully added all bookings!" << endl;
        return true;
    }

    bool removeBooking(string booking_name)
    {
        // int num_company = 0;  //What we subttract when they remove
        for (int i = 0; i < _NUM_BOOKINGS; i++)
        {
            if (_bookings[i].name == booking_name) // Iterate through booking array
            {
                _num_current_occupants -= _bookings[i].num_people;
                _bookings[i].name = "";
                _bookings[i].num_people = 0;

                // num_company = _bookings[i].num_people;

                for (int j = i; j < _NUM_BOOKINGS; j++) // Iterate from removed value and move all back one essentially deleting one value
                {
                    _bookings[i].num_people = _bookings[i + 1].num_people;
                    _bookings[i].name = _bookings[i + 1].name;
                }
                _bookings[_NUM_BOOKINGS - 1].name = "";      // Delete last name
                _bookings[_NUM_BOOKINGS - 1].num_people = 0; // Delete last number

                cout << "Successfully removed " << booking_name << " from room! " << endl;

                return true;
            }
        }
        cout << "Couldn't find " << booking_name << " in their room" << endl;
        return false;
    }
};
