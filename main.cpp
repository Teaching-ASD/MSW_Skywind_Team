#include <iostream>
#include <vector>

#include "Warrior.h"

using namespace std;


int main(int argc, char* argv[]) {

    try{
        if(argc == 7){
            cout << "You have entered the correct amount of data." << endl << endl;
        }
        else{
            throw(argc);
        }
    }
    catch(const int num){
        if(num < 7){
            cout << "You entered less data than necessary.Please try again." << endl;
            return 0;
        }
        else{
            cout << "You entered more data than necessary.Please try again." << endl;
            return 0;
        }
    }

    try{
        for(int i=0;i<argc;i++){
            if(i == 2 || i == 3 || i == 5 || i == 6){
                string argument = argv[i];
                for(int j=0;j<argument.length();j++){
                    if(isdigit(argument[j]) == false){
                        throw(false);
                        break;
                    }
                }
            }
        }
    }
    catch(const bool condition){
        if(condition == false){
        cout << "You have entered an incorrect data type.Please try again." << endl;
        return 0;
        }
    }


	Warrior* w1 = new Warrior(argv[1], stoi(argv[2]), stoi(argv[3]));
	Warrior* w2 = new Warrior(argv[4], stoi(argv[5]), stoi(argv[6]));



    cout << w1->getName() << ": HP: " << w1->getHp() << "\tDMG: " << w1->getDmg() << endl;
    cout << w2->getName() << ": HP: " << w2->getHp() << "\tDMG: " << w2->getDmg() << endl;

    cout << endl;

    int i = 0;
    while(w1->getHp() > 0 && w2->getHp() > 0){
        if(i == 0){
            w1->Attack(w2);

            cout << w1->getName() << " attacks " << w2->getName() << "!" << endl;

            cout << w1->getName() << ": HP: " << w1->getHp() << "\tDMG: " << w1->getDmg() << endl;
            cout << w2->getName() << ": HP: " << w2->getHp() << "\tDMG: " << w2->getDmg() << endl;

            cout << endl;

            i++;
        }
        else{
            w2->Attack(w1);

            cout << w2->getName() << " attacks " << w1->getName() << "!" << endl;

            cout << w1->getName() << ": HP: " << w1->getHp() << "\tDMG: " << w1->getDmg() << endl;
            cout << w2->getName() << ": HP: " << w2->getHp() << "\tDMG: " << w2->getDmg() << endl;

            cout << endl;

            i = 0;
        }
    }
    if(w1->getHp() == 0){
        cout << w2->getName() << " wins!" << endl;
    }
    else{
        cout << w1->getName() << " wins!" << endl;
    }



	return 0;
}
