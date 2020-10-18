#ifndef KALANDOR_H
#define KALANDOR_H
#include "Warrior.h"


class Kalandor : public Warrior{

private:
    int exp;
    int hpCurrent;
    int dmgCurrent;
    float attackCdCurrent;
    void Attack(Kalandor*);

public:
    Kalandor(std::string,int,int,float);
	void modDatas();
    void addExp();
    void Battle(Kalandor*);
    static Kalandor parseUnit(std::map<std::string, std::string>);
    ~Kalandor();

};


#endif // KALANDOR_H
