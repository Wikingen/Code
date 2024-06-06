#include "Entity.hpp"

// reates a new instance of Entity with _gold and _hp as zero, _name as an empty string, _condition as H and _is_enemy as false.
Entity::Entity()
{
    _gold = 0;
    _hp = 0;
    _name = "";
    _condition = 'H';
    _is_enemy = false;
}

// This parameterized constructor creates a new instance of the Entity class and sets the data members as provided.
Entity::Entity(string name, double hp, int gold, char condition, bool is_enemy)
{
    _name = name;

    // check if gold value is valid
    if (hp >= 0)
    {
        _hp = hp;
    }
    else
    {
        _hp = 0;
    }

    // check if gold value is valid, otherwise it is not changed
    if (gold >= 0)
    {
        _gold = gold;
    }
    else
    {
        gold = 0;
    }
   

    // check if condition input is valid
    if (condition == 'H' || condition == 'D' || condition == 'P')
    {
        _condition = condition;
    }
    else
    {
        _condition = 'H';
    }

    _is_enemy = is_enemy;
}

// Returns the name of the entity
string Entity::getName()
{
    return _name;
}

// Returns the current health points _hp of the entity
double Entity::getHP()
{
    return _hp;
}

// Returns the current condition of the entity (H, D, or P)
char Entity::getCondition()
{
    return _condition;
}

// Returns the amount of gold the entity possesses
int Entity::getGold()
{
    return _gold;
}

// Returns if the entity is an enemy
bool Entity::getIsEnemy()
{
    return _is_enemy;
}

// Sets the name of the entity
void Entity:: setName(string name)
{
    _name = name;
}

// Sets the health points _hp for the entity to hp only if it is a non-negative value, else it is not changed
void Entity::setHP(double hp)
{
    //Negative hp will caus it to not change
    if(hp >= 0 )
    {
        _hp = hp;
    }
  
}

// Sets the condition of the entity (H, D, or P) to the given value condition only if it is one among H, D or P, else it is not changed
void Entity::setCondition(char condition)
{
    // check if condition input is valid
    if (condition == 'H' || condition == 'D' || condition == 'P')
    {
        _condition = condition;
    }
    else
    {
        _condition = 'H';
    }
}

// Sets the amount of _gold the entity possesses to the given value gold only if it is a non-negative value, else it is not changed
void Entity::setGold(int gold)
{
    // check if gold value is valid, otherwise it is not changed
    if (gold >= 0)
    {
        _gold = gold;
    }
}

// Sets if the entity is an enemy based on the boolean parameter
void Entity::setIsEnemy(bool is_enemy)
{
    _is_enemy = is_enemy;
}

// Prints the stats of the entity
void Entity::printStats()
{
    cout << _name << "'s stats:" << endl;
    cout << fixed << setprecision(2) << "HP: " << _hp << endl;
    cout << "Condition: " << _condition << endl;
    cout << "Gold: " << _gold << endl;
    if(_is_enemy)
    {
    cout << "Is Enemy: Yes" << endl;
    }
    else
    {
        cout << "Is Enemy: No" << endl;
    }
}