#include "Kalandor.h"


Kalandor::Kalandor(const std::string name_,int hp_, int dmg_):Warrior(name_, hp_, dmg_){
this->exp=0;
this->hpCurrent=hp_;
this->dmgCurrent=dmg_;
} //itt a warrior constructor�t kell megh�vni + az exp

//Ezen a r�szen megval�sitani a az �rt�keke n�vel�s�t

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

int Kalandor::getExp() const {
    return this->exp;
}

/*int Kalandor::modDmg(){

    if(this->exp<100){
        this->exp+=getDmg();
    }
    else{
            dmgCurrent=dmgCurrent*1.1;
            this->setDmg(dmgCurrent*1.1);
            this->exp-=0;
            return this->getDmg();
        }
    }
}*/


/*void Kalandor::Attack(Kalandor* k){

    if(k->getHp() - this->getDmg() > 0){
    k->setHp(k->getHp()-this->getDmg());
    }
    else{
        k->setHp(0);
    }
}*/



std::vector<std::string> Kalandor::parseUnit(std::string fileName){
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



Kalandor::~Kalandor(){};
