#include "Kalandor.h"


Kalandor::Kalandor(std::string name_,int hp_, int dmg_, float attackcooldown_):Warrior(name_, hp_, dmg_, attackcooldown_){
this->exp=0;
this->hpCurrent=hp_;
this->dmgCurrent=dmg_;
this->attackCdCurrent = attackcooldown_;
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

        attackCdCurrent=attackCdCurrent*0.9;
        this->setAttackCd(this->attackCdCurrent);

        this->exp-=100;

    }
}

int Kalandor::getExp() const{
    return this->exp;
}

void Kalandor::Attack(Kalandor* k){
    if(k->getHp() - this->getDmg() > 0){
    k->setHp(k->getHp() - this->getDmg());
    }
    else{
        k->setHp(0);
    }
}

void Kalandor::Battle(Kalandor* k){

    if(this->getHp() > 0){
        this->Attack(k);
        this->addExp();
        this->modDatas();
    }

    if(k->getHp() > 0){
        k->Attack(this);
        k->addExp();
        k->modDatas();
    }

    float attackerCd = this->getAttackCoolDown();
    float defenderCd = k->getAttackCoolDown();
    

    while(this->getHp() > 0 && k->getHp() > 0){
        if(attackerCd < defenderCd){
            this->Attack(k);
            this->addExp();
            this->modDatas();
            defenderCd -= attackerCd;
            attackerCd = this->getAttackCoolDown();
        }
        else if(attackerCd > defenderCd){
            k->Attack(this);
            k->addExp();
            k->modDatas();
            attackerCd -= defenderCd;
            defenderCd = k->getAttackCoolDown();
        }
        else{
            this->Attack(k);
            this->addExp();
            this->modDatas();
            attackerCd = this->getAttackCoolDown();
            if(k->getHp() > 0){
                k->Attack(this);
                k->addExp();
                k->modDatas();
                defenderCd = k->getAttackCoolDown();
            }
        }
    }
}

Kalandor Kalandor::parseUnit(std::map<std::string,std::string> map){
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
    Kalandor k1(name, hp, dmg, attackcooldown);
    return k1;
}

Kalandor::~Kalandor(){};
