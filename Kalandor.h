#ifndef KALANDOR_H
#define KALANDOR_H
#include "Warrior.h"


class Kalandor : public Warrior{
private:
    int exp;
    int hpcurrent;
    int dmgcurrent;
public:
    Kalandor(std::string,int,int);


	void modstat();

    static std::vector<std::string> parseUnit(std::string);

    ~Kalandor();


};


#endif // KALANDOR_H
