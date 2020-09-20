#ifndef WARRIOR_H
#define WARRIOR_H

#include<iostream>


class Warrior
{

public:
	Warrior(std::string, int, int);
	std::string getName() const;
	int getHp() const;
	int getDmg() const;
    void Attack(Warrior*);
private:
	std::string name;
	int hp;
	int dmg;

};

#endif // WARRIOR_H
