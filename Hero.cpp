#include "Hero.h"




Hero::Hero(const std::string name_, int hp_, int dmg_, float attackcooldown_,
    const int expPerLvl_, const int hpBonus_, const int dmgBonus_, const float attackCdMp_) : Monster(name_, hp_, dmg_, attackcooldown_),
	expPerLvl(expPerLvl_), hpBonus(hpBonus_), dmgBonus(dmgBonus_), attackCdMp(attackCdMp_) {

    this->exp = 0;
	this->maxHp = hp_;
	this->level = 1;
}

int Hero::getExp() const {
    return this->exp;
}


int Hero::getLevel() const{
	return this->level;
}

int Hero::getMaxHealthPoints() const {
	return this->maxHp;
}


void Hero::setDmg(int dmg_) {
	this->dmg = dmg_;
}
void Hero::setAttackCd(float attackCd_) {
	this->attackCd = attackCd_;
}


void Hero::modDatas() {

    while (this->level <= (this->exp / this->expPerLvl)) {
        this->maxHp += this->hpBonus;
        this->setHp(this->maxHp);

        this->dmg += this->dmgBonus;
        this->setDmg(this->dmg);

        this->attackCd *= this->attackCdMp;
        this->setAttackCd(this->attackCd);

        this->level++;
    }
}

void Hero::Attack(Monster* m) {
	if (m->getHealthPoints() - this->getDamage() > 0) {
		m->setHp(m->getHealthPoints() - this->getDamage());
		this->exp+=this->getDamage();
		this->modDatas();
	}
	else {
        this->exp += m->getHealthPoints();
        this->modDatas();
        m->setHp(0);
        
	}
}


Hero Hero::parse(std::string file) {

    std::map<std::string, std::string> Datas;
    Datas.insert(std::pair<std::string, std::string>("name", Monster::stringFromFile(Monster::inputFile(file), "name")));
    Datas.insert(std::pair<std::string, std::string>("hp", Monster::intFromFile(Monster::inputFile(file), "base_health_points")));
    Datas.insert(std::pair<std::string, std::string>("dmg", Monster::intFromFile(Monster::inputFile(file), "base_damage")));
    Datas.insert(std::pair<std::string, std::string>("attackcooldown", Monster::floatFromFile(Monster::inputFile(file), "base_attack_cooldown")));


    Datas.insert(std::pair<std::string, std::string>("ExpPerLvl", Monster::intFromFile(Monster::inputFile(file), "experience_per_level")));
    Datas.insert(std::pair<std::string, std::string>("hpBonus", Monster::intFromFile(Monster::inputFile(file), "health_point_bonus_per_level")));
    Datas.insert(std::pair<std::string, std::string>("dmgBonus", Monster::intFromFile(Monster::inputFile(file), "damage_bonus_per_level")));
    Datas.insert(std::pair<std::string, std::string>("cooldownMp", Monster::floatFromFile(Monster::inputFile(file), "cooldown_multiplier_per_level")));


    Hero h(Datas["name"], std::stoi(Datas["hp"]), std::stoi(Datas["dmg"]), std::stof(Datas["attackcooldown"]),
        std::stoi(Datas["ExpPerLvl"]), std::stoi(Datas["hpBonus"]), std::stoi(Datas["dmgBonus"]), std::stof(Datas["cooldownMp"]));
    return h;
}

Hero::~Hero() {};

