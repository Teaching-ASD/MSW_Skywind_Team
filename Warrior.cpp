#include "Warrior.h"



Warrior::Warrior(std::string name_,int hp_,int dmg_,float attackcooldown_):name(name_), hp(hp_), dmg(dmg_), attackcooldown(attackcooldown_){}


std::string Warrior::getName() const{
	return this->name;
}

int Warrior::getHp() const{
    return this->hp;
}

int Warrior::getDmg() const{
    return this->dmg;
}

float Warrior::getAttackCoolDown() const{
    return this->attackcooldown;
}

void Warrior::Attack(Warrior* w){
    if(w->hp - this->dmg > 0){
    w->hp = w->hp - this->dmg;
    }
    else{
        w->hp = 0;
    }
}

void Warrior::setHp(int hp){
    this->hp=hp;
}

void Warrior::setDmg(int dmg){
    this->dmg=dmg;
}
void Warrior::setAttackCd(float){
    this->attackcooldown=attackcooldown;
}

Warrior Warrior::parseUnit(std::map<std::string,std::string> map){
    std::string name = "";
    int hp = 0;
    int dmg = 0;
    float attackcooldown = 0;
    for (const auto& x : map) {
        if(x.first == "name"){
            name = x.second;
        }
        else if(x.first == "hp"){
            hp = std::stoi(x.second);
        }
        else if(x.first == "dmg"){
            dmg = std::stoi(x.second);
        }
        else if(x.first == "attackcooldown"){
            attackcooldown = std::stof(x.second);
        }
    }
    Warrior w1(name, hp, dmg, attackcooldown);
    return w1;
}



Warrior::~Warrior(){};


