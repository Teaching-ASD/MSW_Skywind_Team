#include "Kalandor.h"


Kalandor::Kalandor(const std::string name_,int hp_, int dmg_,int exp_):Warrior(name, hp, dmg),exp(exp_){} //itt a warrior constructorát kell meghívni + az exp




//Ezen a részen megvalósitani a az értékeke növelését

int Kalandor::modHp(){
int hpcurrent;
hpcurrent=this->hp;


if(this->exp<100){
        this->exp=+getDmg();
    if(this->exp>=100){
        this->hp=hpcurrent*1.1;
        hpcurrent=hpcurrent*1.1;
        this-> exp=0;
        return this->hp;

}
}
}



int Kalandor::moddmg(){




int dmgcurrent;
dmgcurrent=this->dmg;

if(this->exp<100){
        this->exp=+getDmg();
    if(this->exp>=100){
        this->dmg=dmgcurrent*1.1;
        this->exp=0;
        return this->dmg;

}



}








void Kalandor::Attack(Kalandor* k){


    if(k->hp - this->dmg > 0){
    k->hp = k->hp - this->dmg;
    }
    else{
        k->hp = 0;
    }
}
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
