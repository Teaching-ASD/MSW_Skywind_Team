#ifndef WARRIOR_H
#define WARRIOR_H

#include <fstream>
#include <string>
#include "Json.h"

class Warrior
{

private:
    std::string name;
	int hp;
    int dmg;
    float attackcooldown;

public:
	Warrior(std::string, int, int, float);
	std::string getName() const;
	int getHp() const;
	int getDmg() const;
    void Attack(Warrior*);
    static Warrior parseUnit(std::map<std::string, std::string>);
    void printData();
    ~Warrior();

};

#endif // WARRIOR_H
