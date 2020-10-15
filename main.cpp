#include <iostream>


#include "Kalandor.h"

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

    for(unsigned int i=1;i<argc ;i++){
        string fileName = argv[i];
        fileName = "units/" + fileName;
        ifstream testFile(fileName);
        if(testFile.is_open() == false){
            if(i==1){
                cout << "The first file is not exist!" << endl;
                return 0;
            }
            else{
                cout << "The second file is not exist!" << endl;
                return 0;
            }
        }
        testFile.close();
    }


    Warrior*  w1 = new Warrior(Warrior::parseUnit(argv[1])[0],stoi(Warrior::parseUnit(argv[1])[1]),stoi(Warrior::parseUnit(argv[1])[2]));
    Warrior*  w2 = new Warrior(Warrior::parseUnit(argv[2])[0],stoi(Warrior::parseUnit(argv[2])[1]),stoi(Warrior::parseUnit(argv[2])[2]));


    int i =0;
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



//kalandor l�trehoz
    Kalandor* k1 =new Kalandor(Kalandor::parseUnit(argv[1])[0],stoi(Kalandor::parseUnit(argv[1])[1]),stoi(Kalandor::parseUnit(argv[1])[2]));//negyedik tag az a indul� exp=0
    Kalandor* k2 =new Kalandor(Kalandor::parseUnit(argv[2])[0],stoi(Kalandor::parseUnit(argv[2])[1]),stoi(Kalandor::parseUnit(argv[2])[2]));


//

//kalandor f�le csata
    int p =0;
    while(k1->getHp() > 0 && k2->getHp() > 0){
        if(p == 0){
            k1->Attack(k2);
            k1->modstat();

            p++;
        }
        else{
            k2->Attack(k1);
            k2->modstat();

            p = 0;
        }
    }
//

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

    result.close();

    delete w1;
    delete w2;


	return 0;
}

