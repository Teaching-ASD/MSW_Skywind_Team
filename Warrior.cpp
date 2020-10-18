#include "Warrior.h"




Warrior::Warrior(const std::string name_,int hp_,int dmg_, float attackcooldown_):name(name_), hp(hp_), dmg(dmg_), attackcooldown(attackcooldown_){}



std::string Warrior::getName() const{
	return name;
}

int Warrior::getHp() const{
    return hp;
}

int Warrior::getDmg() const{
    return dmg;
}


float Warrior::getAttackCoolDown() const{
    return this->attackcooldown;
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


std::vector<std::string> Warrior::parseUnit(std::string fileName){
    fileName = "units/"+fileName;
    std::string lastString = "";
    std::vector<std::string> wDatas;
    std::string data = "";
    std::ifstream fname(fileName);
    if ( fname.is_open() == false) throw std::runtime_error("The given file does not exist!");
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