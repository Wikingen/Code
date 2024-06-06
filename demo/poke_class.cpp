#include <iostream>
using namespace std;

class Pokemon
{
public:
    Pokemon() // Constructor, unparameterized
    {
        name = "your name here";
        type = "generic";
        hit_point = 100;
        speed = 10;
        attack = 4;
        defence = 6;
    }
    Pokemon(string n, string t, double HP,double s, double a, double d)   //Parametized constructor
    {
        name = n;
        type = t;
        hit_point = setHP(HP);
        speed = s;
        attack = a;
        defence = d;
    }


    void rename(string n)
    {
        name = n;
    }
    void showHP()
    {
        cout << name << " has HP " << hit_point << " HP" << endl;
    }
    string getName()
    {
        return name;
    }

private:
    string name;
    string type;
    double hit_point;
    double speed;
    double attack;
    double defence;
    string moves[4];
   
    double setHP(double HP)
    {
        if(HP <= 200 && HP > 0 )
        {
            return HP;
        }
        else
        {
            return 100;
        }
    }
};




int main()
{

    Pokemon pikachu;
    pikachu.rename("Otto");
    string name = pikachu.getName();
    cout << "Pikachu is named: " << name << endl;
    pikachu.showHP();

    Pokemon charmander("Riley", "Fire ", 100, 2, 7, 5);
    charmander.showHP();

    return 0;
}