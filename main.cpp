#include <iostream>
#include <vector>
#include <fstream>
#include <jsoncpp/json/json.h>

#include "Warrior.h"

using namespace std;


int main(int argc, char* argv[]) {

    try{
        if(argc != 3){
            throw(argc);
        }
    }
    catch(const int num){
        if(num < 3){
            cout << "You entered less file than necessary.Please try again." << endl;
            return 0;
        }
        else{
            cout << "You entered more file than necessary.Please try again." << endl;
            return 0;
        }
    }

//próbálgatás alatt!!!-----------------------------------------


    ifstream warrior1(argv[1]);
    Json::Reader reader;
    Json::Value value;

    reader.parse(warrior1, value);
    vector<string> w1Datas;
    w1Datas.push_back(value["name"].asString());
    w1Datas.push_back(value["hp"].asString());
    w1Datas.push_back(value["dmg"].asString());

    warrior1.close();

    ifstream warrior2(argv[2]);

    reader.parse(warrior2, value);
    vector<string> w2Datas;
    w2Datas.push_back(value["name"].asString());
    w2Datas.push_back(value["hp"].asString());
    w2Datas.push_back(value["dmg"].asString());



    warrior2.close();
//-------------------------------------------------------------


	Warrior* w1 = new Warrior(w1Datas[0], stoi(w1Datas[1]), stoi(w1Datas[2]));
	Warrior* w2 = new Warrior(w2Datas[0], stoi(w2Datas[1]), stoi(w2Datas[2]));

    int i = 0;
    while(w1->getHp() > 0 && w2->getHp() > 0){
        if(i == 0){
            w1->Attack(w2);
            i++;
        }
        else{
            w2->Attack(w1);
            i = 0;
        }
    }
    if(w1->getHp() == 0){
        cout << w2->getName() << " wins!" << endl;
        cout << "Remaining HP: " << w2->getHp() << endl;
    }
    else{
        cout << w1->getName() << " wins!" << endl;
        cout << "Remaining HP: " << w1->getHp() << endl;
    }

    delete w1;
    delete w2;


	return 0;
}
