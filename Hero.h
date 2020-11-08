#ifndef HERO_H
#define HERO_H

#include "Monster.h"


class Hero : public Monster
{
private:
	const int expPerLvl;
	const int hpBonus;
	const int dmgBonus;
	const float attackCdMp;

	int maxHp;
	int level;
	int exp;

public:
	
	Hero(const std::string, int, int, float,const int, const int, const int, const float);
	
	int getExp() const;
	int getLevel() const;
	int getMaxHealthPoints() const;

	void setDmg(int);
	void setAttackCd(float);

	void modDatas();

	void Attack(Monster*) override;

	static Hero parse(std::string);

	~Hero();

};

#endif //HERO_H

