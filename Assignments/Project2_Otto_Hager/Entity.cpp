#include "Entity.hpp"

// reates a new instance of Entity with _gold and _hp as zero, _name as an empty string, _condition as H and _is_enemy as false.
Entity::Entity()
{
    _name = "";
    _type = 'X';
    _hp = 0;
    _gold = 0;
    _stamina = 0;
    _defense = 0;
    _condition = 'H';
    _advantage = false;
    _el_weak = 'N'; //None
    
    _num_potions = 0;
    _num_equipment = 0;

    _ultimate = "";
    _calamity = 30;

    _player_won = false;
    
}

// This parameterized constructor creates a new instance of the Entity class and sets the data members as provided.
Entity::Entity(string name, double hp, int gold, double stamina, double defense, char condition, bool advantage, Potion potions[], Equipment equipped[], Equipment inventory[], int items[])
{
    _name = name;

    // check if gold value is valid
    if (hp > 100)
    {
        _hp = 100;
    }
    else if(hp<0)
    {
        _hp = 0;
    }
    else
    {
        _hp = hp;
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

    if (stamina > 0)
    {
        _stamina = stamina;
    }
    else
    {
        _stamina = 0;
    }

    if (defense > 0)
    {
        _defense = defense;
    }
    else
    {
        _defense = 0;
    }

    _advantage = advantage;

    for (int i = 0; i < 3; i++)
    {
        if (potions[i].name != "")
        {
            _potions[i] = potions[i];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        cout << "Adding equipment... | Eqipment" << i << " name:" << equipped[i].name << endl;
        if (equipped[i].name != "")
        {
            cout << equipped[i].name << " added at idx" << i <<endl;
            _equipped[i] = equipped[i];
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (inventory[i].name != "")
        {
            _inventory[i] = inventory[i];
        }
    }

    _items[0] = items[0];
    _items[1] = items[1];

    _calamity = 30;

    _player_won = false;
}

// Returns the name of the entity
string Entity::getName()
{
    return _name;
}
bool Entity::getAdvantage()
{
    return _advantage;
}

// Returns the current health points _hp of the entity
double Entity::getHP()
{
    return _hp;
}
char Entity::getType()
{
    return _type;
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
/* bool Entity::getIsEnemy()
{
    return _is_enemy;
} */

//returns equipment from _inventory idx 0-9, if not returns empty
Equipment Entity::getEquipment(int idx)
{
    Equipment E;
    if (idx >= 0 && idx  < 10)
    {
        return _inventory[idx];
    }
    return E;
}
//returns equipment from _equipped idx 0-1, if not returns empty
Equipment Entity::getEquipped(int idx)
{
    Equipment E;
    if (idx >= 0 && idx  < 2)
    {
        return _equipped[idx];
    }
    return E;
}

double Entity::getCalamity()
{
    return _calamity;
}

bool Entity::getPlayerWon()
{
    return _player_won;
}

char Entity::getElWeak()
{
    return _el_weak;
}


Potion Entity::getPotion(int idx)
{
    Potion E;
    if (idx >= 0 && idx <= 3)
    {
        return _potions[idx];
    }
    return E;
}


// Sets the name of the entity
void Entity::setName(string name)
{
    _name = name;
}

// Sets the health points _hp for the entity to hp only if it is a non-negative value, else it is not changed
void Entity::setHP(double hp)
{
    // Negative hp will caus it to not change
    if (hp >= 0)
    {
        _hp = hp;
    }
    else
    {
        _hp = 0;
    }
}

void Entity::setStamina(double stamina)
{
    if (stamina >= 0)
    {
        _stamina = stamina;
    }
    if(_stamina < 0)
    {
        _stamina = 0;
    }
}

double Entity::getStamina()
{
    return _stamina;
}

int Entity::getNumPotions()
{
    return _num_potions;
}
int Entity::getNumEquipment()
{
    return _num_equipment;
}


void Entity::setDefense(double defense)
{
    if (defense >= 0)
    {
        _defense = defense;
    }
}

void Entity::setType(char type)
{
    if ( type == 'I' || type == 'E')
    {
        _type = type;
    }
    else
    {
        _type = 'X';
    }
}

void Entity::setPlayerWon(bool player_won)
{
    _player_won = player_won;
}

void Entity::setAdvantage(bool advantage)
{
    _advantage = advantage;
}

void Entity::setCalamity(double calamity)
{
    _calamity = calamity;
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

void Entity::setItems(int items[])
{
    for (int i = 0; i<2; i++)
    {
        _items[i] = items[i];
    }
}

// Replaces the objects potion list at a certain index with a new potion
bool Entity::setPotion(int potion_index, Potion new_potion)
{
    if(potion_index >=0)
    {
        _potions[potion_index] = new_potion;
        return true;
    }
    return false;
}

void Entity:: setNumPotion(int num)
{
    _num_potions = num;
}

//Setting new_equipment in _equipped at either 1,2 depending in index given. Otherwise returns false.
bool Entity::setEquipment(int index, Equipment new_equipment)
{
    if (index == 0 || index == 1)
    {
        //cout << "Name in set Equipment:  " << new_equipment.name << endl;
        _equipped[index] = new_equipment;
        return true;
    }
    return false;
}
//Setting new_equipment in _inventory at open spot.  if no empty spot return false
bool Entity::addToInventory( Equipment new_equipment)
{
    for (int i = 0; i<10; i++) //10=_MAX_EQUIPMENT
    {
        if(_inventory[i].name == "")
        {
            _inventory[i] = new_equipment;
            //cout << "Added: " << new_equipment.name << " in invetnory at index " << i<< endl;
            return true;
        }
    }
    return false;
}
void Entity::setInventory(int index, Equipment new_equipment)
{
    _inventory[index] = new_equipment;
}

void Entity::setNumEquipment(int num)
{
    _num_equipment = num;
}

// Sets if the entity is an enemy based on the boolean parameter
/* void Entity::setIsEnemy(bool is_enemy)
{
    _is_enemy = is_enemy;
} */

// Prints the stats of the entity
void Entity::printStats()
{
    cout << _name << "'s stats:" << endl;
    //print type for enemies
   /*  if(getType() != 'P')
    {
        cout << "Type: "<< getType() <<endl;
    } */
    cout << fixed << setprecision(2) << "HP: " << _hp << endl;
    cout << fixed << setprecision(2) << "Stamina: " << _stamina << endl;
    cout << fixed << setprecision(2) << "Defense: " << _defense << endl;
    cout << "Condition: " << _condition << endl;
    cout << "Gold: " << _gold << endl;
    cout << "Advantage: " << _advantage << endl;
    cout << "Potions: ";
    for (int i = 0; i < 3; i++)
    {
        if (_potions[i].name != "")
        {
            if (i != 0)
            {
                cout << ", ";
            }
            cout << _potions[i].name << "(" << _potions[i].quantity << ")";
        }
    }
    cout << endl;
    cout << "Equipment: ";
    for (int i = 0; i < 2; i++)
    {
        if (_equipped[i].name != "")
        {
            if (i != 0)
            {
                cout << ", ";
            }
            cout << _equipped[i].name ;
            if(_equipped[i].type == 'D')
            {
                cout << " (Damage: "<<_equipped[i].damage <<")";
            }
            else
            {
                cout << " (Defense: "<< _equipped[i].defense<<")";
            }

        }
    }
    cout << endl;

    cout << "Inventory: ";
    for (int i = 0; i < 5; i++)
    {
        if (_inventory[i].name != "")
        {
            if (i != 0)
            {
                cout << ", ";
            }
            cout << _inventory[i].name;
            if (_inventory[i].type == 'D')
            {
                cout << " (Damage: " << _inventory[i].damage << ")";
            }
            else
            {
                cout << " (Defense: " << _inventory[i].defense << ")";
            }
        }
    }
    cout << endl;

}