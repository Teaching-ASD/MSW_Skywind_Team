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
    int getExp() const;
    //void Attack(Kalandor*);
    static std::vector<std::string> parseUnit(std::string);
    ~Kalandor();


};


#endif // KALANDOR_H
