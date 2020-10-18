#include <iostream>

#include "Warrior.h"

using namespace std;


void Eredmeny(Warrior* w1, Warrior* w2){
    ofstream result;

    result.open ("results.txt", ios_base::app);

    result << "The result of the fight between " << w1->getName() << " and " << w2->getName() << ":" << endl;


    if(w1->getHp() == 0){
        cout << w2->getName() << " wins!" << endl;
        cout << "Remaining HP: " << w2->getHp() << endl;

        result << w2->getName() << " wins!" << endl;
        result << "Remaining HP: " << w2->getHp() << endl;

    }
    else{
        cout << w1->getName() << " wins!" << endl;
        cout << "Remaining HP: " << w1->getHp() << endl;

        result << w1->getName() << " wins!" << endl;
        result << "Remaining HP: " << w1->getHp() << endl;
    }
    delete w1;
    delete w2;
    result.close();
}



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
    
    
    try{
        Warrior* w1 = new Warrior(Warrior::parseUnit(Json::jsonParse(Json::inputFile(argv[1]))));
        Warrior* w2 = new Warrior(Warrior::parseUnit(Json::jsonParse(Json::inputFile(argv[2]))));

    
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
        Eredmeny(w1,w2);
    }catch (exception &e){
        cout<< e.what() <<endl;
        return 1;
    }


	return 0;
}

