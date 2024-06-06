#include<iostream>
#include<fstream>
using namespace std;


#define _MAX_SIZE 10  //Have define it here because static const doesnt work

class Galaxy
{
public:
Galaxy();   //default constructor
Galaxy(string name); //parameterized constructor
Galaxy(string name, int _radii[], int arr_size); // parameterized constructor
string getName();  // Returns the _name of the Galaxy
int getCurrentSize(); // Returns the _current_size of the Galaxy
int getRadius(int idx); // Returns radius at the provided index in the _radii array. If the index is greater than or equal to _current_size, return -1
void setName(string name); // Sets the _name to the value of the string parameter
bool addRadius(int r); // Returns true if the new radius can be added to the _radii array. If the _current_size is already equal to _MAX_SIZE, return false.
double getAverageRadius(); // Calculates and returns the average radius of the Planets in the Galaxy.

private:
    string _name;
    int _radii[_MAX_SIZE];
    int _current_size;
};