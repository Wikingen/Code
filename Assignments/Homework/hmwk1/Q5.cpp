#include <iostream>
using namespace std;

main(){

    int hour;
    float fillRateIndoor = 0.4;
    float fillRateOutdoor = 0.7;
    float leakRateIndoor = 0.3;
    float leakRateOutdoor = 0.4;
    float indoorLevel, outdoorLevel;

    

    cout << "How many hours have passed?" << endl;
    cin >> hour;

    indoorLevel = 12 + (hour * fillRateIndoor) - (hour * leakRateIndoor);
    outdoorLevel = 18 + (hour * fillRateOutdoor) - (hour * leakRateOutdoor);


    cout << "The indoor pool has " << indoorLevel << " inches of water, and the outdoor pool has "<< outdoorLevel << " inches of water.";

    return 0;

}