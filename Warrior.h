#ifndef WARRIOR_H
#define WARRIOR_H

#include <vector>
#include <fstream>
#include <string>


class Warrior
{

private:
    const std::string name;
	int hp;
    int dmg;

public:
	Warrior(std::string, int, int);
	std::string getName() const;
	int getHp() const;
	int getDmg() const;
	void setHp(int);
	void setDmg(int);
    void Attack(Warrior*);
    static std::vector<std::string> parseUnit(std::string);
    ~Warrior();

};


#endif // WARRIOR_H
