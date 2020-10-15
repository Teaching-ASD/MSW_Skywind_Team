#include "Kalandor.h"


Kalandor::Kalandor(const std::string name_,int hp_, int dmg_):Warrior(name_, hp_, dmg_){


this->exp=0;
this->hpcurrent=hp_;
this->dmgcurrent=dmg_;

}

void Kalandor::modstat(){




if(this->exp<100){
        this->exp+=this->getDmg();
        }
        else if(this->exp>=100){
            hpcurrent=hpcurrent*1.1;
            dmgcurrent=dmgcurrent*1.1;
            this->sethp(hpcurrent);
            this->setdmg(dmgcurrent*1.1);

            this-> exp-=100;


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
