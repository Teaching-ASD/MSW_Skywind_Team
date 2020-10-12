#include "Warrior.h"



Warrior::Warrior(const std::string name_,int hp_,const int dmg_, const float attackcooldown_):name(name_), hp(hp_), dmg(dmg_), attackcooldown(attackcooldown_){}


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

void Warrior::Battle(Warrior* w){
    float attackerCd = this->getAttackCoolDown();
    float defenderCd = w->getAttackCoolDown();

    this->Attack(w);
    //std::cout << this->getName() << " attacks " << w->getName() << std::endl;
    //std::cout << w->getName() << " has: " << w->getHp() << " hp!" <<std::endl;
    w->Attack(this);
    //std::cout << w->getName() << " attacks " << this->getName() << std::endl;
    //std::cout << this->getName() << " has: " << this->getHp() << " hp!" <<std::endl;
    float i = 0.1;

    while(this->getHp() > 0 && w->getHp() > 0){
        attackerCd -= i;
        defenderCd -= i;

        if(attackerCd < 0.0){
            this->Attack(w);
            //std::cout << this->getName() << " attacks " << w->getName() << std::endl;
            //std::cout << w->getName() << " has: " << w->getHp() << " hp!" <<std::endl;
            attackerCd = this->getAttackCoolDown();
        }
        else if(attackerCd > 0.0 && defenderCd < 0.0){
            w->Attack(this);
            //std::cout << w->getName() << " attacks " << this->getName() << std::endl;
            //std::cout << this->getName() << " has: " << this->getHp() << " hp!" <<std::endl;
            defenderCd = this->getAttackCoolDown();
        }
    }
}


std::vector<std::string> Warrior::parseUnit(std::string fileName){
    fileName = "units/"+fileName;
    std::string lastString = "";
    std::vector<std::string> wDatas;
    std::string data = "";
    std::ifstream fname(fileName);
    int pos = 0;
    while(std::getline(fname, data)){
        if(data[0] == '"'){
            if(data.find("name") == 1){
                int db = 0;
                while(db < 3){
                    pos = data.find('"');
                    data = data.substr(pos+1);
                    db++;
                }
                for(unsigned int i=0;i<data.length();i++){
                    if(data[i] != '"' && data[i] != ','){
                        lastString += data[i];
                    }
                }

                wDatas.push_back(lastString);

            }
            else if(data.find("hp") == 1){
                lastString = "";
                int db = 0;
                while(db < 2){
                    pos = data.find('"');
                    data = data.substr(pos+1);
                    db++;
                }
                for(unsigned int i=0;i<data.length();i++){
                    if(data[i] != ' ' && data[i] != ':' && data[i] != ','){
                        lastString += data[i];
                    }
                }

                wDatas.push_back(lastString);

            }
            else if(data.find("dmg") == 1){
                lastString = "";
                int db = 0;
                while(db < 2){
                    pos = data.find('"');
                    data = data.substr(pos+1);
                    db++;
                }
                for(unsigned int i=0;i<data.length();i++){
                    if(data[i] != ' ' && data[i] != ':' && data[i] != ','){
                        lastString += data[i];
                    }
                }

                wDatas.push_back(lastString);

            }
        }
    }
    fname.close();
    return wDatas;
}




Warrior::~Warrior(){};


