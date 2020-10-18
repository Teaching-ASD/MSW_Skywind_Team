#include <iostream>

#include "Kalandor.h"

using namespace std;


void Eredmeny(Kalandor* k1,Kalandor* k2){
    ofstream result;

    result.open ("results.txt", ios_base::app);

    result << "The result of the fight between " << k1->getName() << " and " << k2->getName() << ":" << endl;


    if(k1->getHp() == 0){
        cout << k2->getName() << " wins!" << endl;
        cout << "Remaining HP: " << k2->getHp() << endl;

        result << k2->getName() << " wins!" << endl;
        result << "Remaining HP: " << k2->getHp() << endl;

    }
    else{
        cout << k1->getName() << " wins!" << endl;
        cout << "Remaining HP: " << k1->getHp() << endl;

        result << k1->getName() << " wins!" << endl;
        result << "Remaining HP: " << k1->getHp() << endl;
    }
    delete k1;
    delete k2;
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
            return 1;
        }
        else{
            cout << "You entered more file than necessary.Please try again." << endl;
            return 1;
        }
    }

    try{
        Kalandor* k1 = new Kalandor(Kalandor::parseUnit(Json::jsonParse(Json::inputFile(argv[1]))));
        Kalandor* k2 = new Kalandor(Kalandor::parseUnit(Json::jsonParse(Json::inputFile(argv[2]))));
        k1->Battle(k2);
        Eredmeny(k1,k2);
        
    }catch (exception &e){
        cout<< e.what() <<endl;
        return 1;
    }

	return 0;
}