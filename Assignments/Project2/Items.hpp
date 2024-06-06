#ifndef ITEMS_CPP
#define ITEMS_CPP


#include <iostream>
using namespace std;
/* Contains all necessary structs and there data members */



// This struct would contain information for the potions in the game.
struct Potion 
{
    string name;
    string desc; // Potion descriptions
    char type; // H’=healing, ‘C’ = cleanse, ‘S’ = stamina, ‘U’ = ultimate
    double effect_value; // default this to 0 for ‘C’ or ‘U’ potions
    double price;
    int quantity; // to help with keeping track of inventory
};

// This struct would contain information for the equipment in the game.
struct Equipment
{
    string name;
    string desc; //Equipment descriptions
    char type; // W' denotes a weapon, 'S' denotes a shield
    char element; //'W' = water, 'A' = air, 'F' = fire, and 'E' = earth
    double damage; // damage weapons will have a value here, and their defense will be 0
    double defense; // shield weapons will have a value here, and their damage will be 0
    double price; 
};

#endif