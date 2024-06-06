#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Entity class that will be used as characters in the game
class Entity
{
public:
    Entity();
    Entity(string name, double hp, int gold, char condition, bool is_enemy);

    string getName();
    double getHP();
    char getCondition();
    int getGold();
    bool getIsEnemy();

    void setName(string name);
    void setHP(double HP);
    void setCondition(char consition);
    void setGold(int gold);
    void setIsEnemy(bool isEnemy);

    void printStats();

private:
    string _name;
    double _hp;
    int _gold;
    char _condition;
    bool _is_enemy;
};