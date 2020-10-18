#ifndef KALANDOR_H
#define KALANDOR_H
#include "Warrior.h"


class Kalandor : public Warrior{

private:
    int exp;
    int hpCurrent;
    int dmgCurrent;

public:
    Kalandor(std::string,int,int);
	void modDatas();
    void addExp();
    ~Kalandor();

};


#endif // KALANDOR_H
