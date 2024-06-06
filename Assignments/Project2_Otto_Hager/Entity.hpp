#ifndef ENTITY_CPP
#define ENTITY_CPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Items.hpp"
using namespace std;

// Entity class that will be used as characters in the game
class Entity
{
public:
    Entity();
    Entity(string name, double hp, int gold, double stamina, double defense, char condition, bool advantage, Potion potions[], Equipment equipped[], Equipment inventory[], int items[]);
        
    /* Getters */
    string getName();
    double getHP();
    char getType();
    char getCondition();
    int getGold();
    bool getAdvantage();
    bool getIsEnemy();
    int getNumPotions();
    int getNumEquipment(); //returns _num_equipment
    double getStamina();
    Equipment getEquipment(int idx); //Returns Equipment struct from players _inventory at index idx
    Equipment getEquipped(int idx); //Returns Equipment from players _equipped 0,1 index. Else returns empty
    Potion getPotion(int idx); //returns Potion struct from _potions at index idx
    double getCalamity();
    bool getPlayerWon();
    char getElWeak();

    /* Setters */
    void setName(string name);
    void setHP(double HP);
    void setStamina(double stamina);
    void setDefense(double defense);
    void setAdvantage(bool advantage);
    void setItems(int items[]);
    void setPlayerWon(bool player_won);
    // Replaces the objects potion list at a certain index with a new potion
    bool setPotion(int potion_index, Potion new_potion);
    //Sets the number of potions of an entity
    void setNumPotion(int num);
    //Assigns an equippment to an entity in _equipped at given index 
    bool setEquipment( int index, Equipment new_equipment);
    //adds an equipment to inventory of an Entity if open spot exists
    bool addToInventory(Equipment new_equipment);
    //Adds an equipment to inventory at given index
    void setInventory(int index, Equipment new_equipment);
    //Sets the number of equipment in _euipped for an entity
    void setNumEquipment(int num);
    void setCondition(char consition);
    void setGold(int gold);
    void setIsEnemy(bool isEnemy);
    void setType(char type);
    void setCalamity(double calamity);

    void printStats();

private:
    string _name;
    char _type; //'p' - playeable character, 'I' - Island enemy, 'E' - Epic enemy
    double _hp;
    double _stamina;
    double _defense;
    char _condition; // H,D,P
    bool _advantage; // Deciding weather you have an advanteage to start first
    char _el_weak;   // Elemental weakness
    int _gold;

    //list of all potions of an entity
    Potion _potions[3];  
    int _num_potions;   

    
    //List of all items of an entity
    Equipment _equipped[2];    
    int _num_equipment;

    //Contains all items not currently equipped. I capped it at 10
    Equipment _inventory[10]; 

    // First number represents total player stock of potions, 
    //second number represents totalplayer stock of equipment (in equipped and inventory)
    int _items[2]; 

    double _calamity;

    bool _player_won;

    string _ultimate;
};
#endif