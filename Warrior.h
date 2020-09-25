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

public:
	Warrior(std::string, int, int);
	std::string getName() const;
	int getHp() const;
	int getDmg() const;
    void Attack(Warrior*);
    static std::vector<std::string> parseUnit(std::string);
    void printData();
    ~Warrior();

};

#endif // WARRIOR_H
