#include "Rec14.h"
using namespace std;

double travelTime(string id, double distance, Airport a)
{
    Airplane plane = a.getPlane(id);
    if (plane.id != "")
    {
        return distance / plane.speed;
    }
    return -1;
}

int main()
{
    Airport DEN;
    DEN.addPlane("F92210", 500);
    DEN.addPlane("UA1811", 300);
    // DEN.addPlane("AA1647", 400);

    cout << "Travel time of F92210 is: " << travelTime("F92210", 250, DEN) << " hours" << endl;

    cout << "Travel time of UA1811 is: " << travelTime("AA1647", 600, DEN) << " hours" << endl;

    return 0;
}