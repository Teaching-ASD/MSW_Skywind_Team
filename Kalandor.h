#ifndef KALANDOR_H
#define KALANDOR_H
#include "Warrior.h"


class Kalandor : public Warrior{
private:
  int xp;

public:
    Kalandor(std::string,int,int,int);


	int modHp();
	int moddmg();




    void Attack(Kalandor*);

    static std::vector<std::string> parseUnit(std::string);

    ~Kalandor();


};


#endif // KALANDOR_H
