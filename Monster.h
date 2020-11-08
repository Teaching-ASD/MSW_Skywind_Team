#ifndef MONSTER_H
#define MONSTER_H

#include "JSON.h"

class Monster
{
protected:
	const std::string name;
	int hp;
	int dmg;
	float attackCd;

public:
	
	Monster(const std::string, int, int, float);

	std::string getName() const;
	int getHealthPoints() const;
	int getDamage() const;
	float getAttackCoolDown() const;

	void setHp(int);

	bool isAlive() const;

	virtual void Attack(Monster*);

	void fightTilDeath(Monster&);

	static std::string inputFile(std::string);
	static std::string stringFromFile(std::string, std::string);
	static std::string intFromFile(std::string, std::string);
	static std::string floatFromFile(std::string, std::string);

	static Monster parse(std::string);

	~Monster();
};

#endif //MONSTER_H

