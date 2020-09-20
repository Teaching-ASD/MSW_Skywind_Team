#ifndef WARRIOR_H
#define WARRIOR_H

#include<iostream>


class Warrior
{

private:
    const std::string name;
	int hp;
    const int dmg;

public:
	Warrior(std::string, int, int);
	std::string getName() const;
	int getHp() const;
	int getDmg() const;
    void Attack(Warrior*);
    ~Warrior();


};

#endif // WARRIOR_H
