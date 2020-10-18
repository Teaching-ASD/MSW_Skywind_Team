#include "Kalandor.h"


Kalandor::Kalandor(const std::string name_,int hp_, int dmg_):Warrior(name_, hp_, dmg_){
this->exp=0;
this->hpCurrent=hp_;
this->dmgCurrent=dmg_;
}

void Kalandor::addExp(){
    this->exp += this->getDmg();
}

void Kalandor::modDatas(){  

    if(this->exp >= 100){

        hpCurrent=hpCurrent*1.1;
        this->setHp(this->hpCurrent);

        this->dmgCurrent=this->dmgCurrent*1.1;
        this->setDmg(this->dmgCurrent);

        this->exp-=100;

    }
}

Kalandor::~Kalandor(){};
