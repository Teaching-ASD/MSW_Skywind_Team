#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>


class Warrior
{

private:
    const std::string name;
	int hp;
    const int dmg;
    const float attackcooldown;

public:
	Warrior(std::string, int, int, float);
	std::string getName() const;
	int getHp() const;
	int getDmg() const;
    float getAttackCoolDown() const;
    void Attack(Warrior*);
    void Battle(Warrior*);
    static std::vector<std::string> parseUnit(std::string);
    ~Warrior();

};

#endif // WARRIOR_H
