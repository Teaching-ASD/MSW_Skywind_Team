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

    if(this->getHp() > 0){
        this->Attack(w);

        /*std::cout << this->getName() << " attacks: " << w->getName() << std::endl;
        std::cout << "Attacker dmg: " << this->getDmg() << std::endl;
        std::cout << "Defender hp: " << w->getHp() << std::endl << std::endl;*/
    }

    if(w->getHp() > 0){
        w->Attack(this);

        /*std::cout << w->getName() << " attacks: " << this->getName() << std::endl;
        std::cout << "Attacker dmg: " << w->getDmg() << std::endl;
        std::cout << "Defender hp: " << this->getHp() << std::endl << std::endl;*/
    }

    float attackerCd = this->getAttackCoolDown();
    float defenderCd = w->getAttackCoolDown();
    

    while(this->getHp() > 0 && w->getHp() > 0){
        if(attackerCd < defenderCd){
            this->Attack(w);
            defenderCd -= attackerCd;
            attackerCd = this->getAttackCoolDown();

            /*std::cout << this->getName() << " attacks: " << w->getName() << std::endl;
            std::cout << "Attacker dmg: " << this->getDmg() << std::endl;
            std::cout << "Defender hp: " << w->getHp() << std::endl << std::endl;*/
        }
        else if(attackerCd > defenderCd){
            w->Attack(this);
            attackerCd -= defenderCd;
            defenderCd = w->getAttackCoolDown();

            /*std::cout << w->getName() << " attacks: " << this->getName() << std::endl;
            std::cout << "Attacker dmg: " << w->getDmg() << std::endl;
            std::cout << "Defender hp: " << this->getHp() << std::endl << std::endl;*/
        }
        else{
            this->Attack(w);
            attackerCd = this->getAttackCoolDown();
            defenderCd = w->getAttackCoolDown();

            /*std::cout << this->getName() << " attacks: " << w->getName() << " Equal cooldown!" << std::endl;
            std::cout << "Attacker dmg: " << this->getDmg() << std::endl;
            std::cout << "Defender hp: " << w->getHp() << std::endl << std::endl;*/
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


