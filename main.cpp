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

	vector<Warrior*> W;

	W.push_back(w1);
	W.push_back(w2);

    cout << W[0]->getName() << ": HP: " << W[0]->getHp() << "\tDMG: " << W[0]->getDmg() << endl;
    cout << W[1]->getName() << ": HP: " << W[1]->getHp() << "\tDMG: " << W[1]->getDmg() << endl;

    cout << endl;

    int i = 0;
    while(W[0]->getHp() > 0 && W[1]->getHp() > 0){
        if(i == 0){
            W[0]->Attack(W[1]);

            cout << W[0]->getName() << " attacks " << W[1]->getName() << "!" << endl;

            cout << W[0]->getName() << ": HP: " << W[0]->getHp() << "\tDMG: " << W[0]->getDmg() << endl;
            cout << W[1]->getName() << ": HP: " << W[1]->getHp() << "\tDMG: " << W[1]->getDmg() << endl;

            cout << endl;

            i++;
        }
        else{
            W[1]->Attack(W[0]);

            cout << W[1]->getName() << " attacks " << W[0]->getName() << "!" << endl;

            cout << W[0]->getName() << ": HP: " << W[0]->getHp() << "\tDMG: " << W[0]->getDmg() << endl;
            cout << W[1]->getName() << ": HP: " << W[1]->getHp() << "\tDMG: " << W[1]->getDmg() << endl;

            cout << endl;

            i = 0;
        }
    }
    if(W[0]->getHp() == 0){
        cout << W[1]->getName() << " wins!" << endl;
    }
    else{
        cout << W[0]->getName() << " wins!" << endl;
    }

    for (int i = 0; i < W.size(); i++){
        delete W[i];
    }

	return 0;
}
