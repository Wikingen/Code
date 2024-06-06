#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
    ofstream out_file("output.txt");
    for(int i = 97;i<102;i++)
    {
        out_file<<char(i)<<endl;
    }
    out_file.close();
    
}