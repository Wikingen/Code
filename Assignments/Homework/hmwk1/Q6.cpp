#include <iostream>
using namespace std;

main(){
    int apples, kiwis = 0, eggs = 0, turkeys = 0;

    cout << "Enter the number of apples:" << endl;
    cin >> apples;

    kiwis = apples/3;
    apples = apples - 3*kiwis;

    eggs = kiwis/2;
    kiwis = kiwis - 2*eggs;

    turkeys = eggs/20;
    eggs = eggs - 20*turkeys;


    
    cout << "Maximum number of turkey(s) " << turkeys << ", egg(s) " << eggs <<", kiwi(s) "<< kiwis <<", apple(s) " << apples;

    return 0;
}