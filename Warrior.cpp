#include "Warrior.h"


Warrior::Warrior(std::string name_, int hp_, int dmg_) {
	this->name = name_;
	this->hp = hp_;
	this->dmg = dmg_;
}

std::string Warrior::getName() const{
	return this->name;
}

int Warrior::getHp() const{
    return this->hp;
}

int Warrior::getDmg() const{
    return this->dmg;
}

void Warrior::Attack(Warrior* w){
    if(w->hp - this->dmg > 0){
    w->hp = w->hp - this->dmg;
    }
    else{
        w->hp = 0;
    }
}

