/**
 * \class Kalandor
 *
 * A Kalandor adatait és metódusait tartalmazó class
 *
 * \authors DanielZettis, kormendiakos, MZsolt97
 *
 * \date 2020/11/06
 *
 * Létrehozva: 2020/11/06
*/

#ifndef KALANDOR_H
#define KALANDOR_H
#include "Warrior.h"


class Kalandor : public Warrior{

private:
    int exp; ///< A Kalandor tapasztalati pontjainak száma.
    int hpCurrent; ///< A Kalandor pillanatnyi életerőpontja.
    int dmgCurrent; ///< A Kalandor pillanatnyi sebzéspontja.
    float attackCdCurrent; ///< A Kalandor pillanatnyi támadásának újratöltési ideje.


    void Attack(Kalandor*);

public:

    /**
    * \brief A Kalandor konstruktora.
    * A Kalandor létrehozásakor paraméterként megadott értékekkel ruházza fel a Warriort.
    * (név, hp, dmg, attackcooldown)
    */
    Kalandor(std::string,int,int,float);


    /**
    * \brief modDatas metódus.
    * A Kalandor adatainak módosításáért felelős függvény.
    */
	void modDatas();

    /**
    * \brief addExp metódus.
    * A Kalandor szintlépéseihez szükséges tapasztalati pontokat növelő függvény.
    */
    void addExp();

    /**
    * \brief Battle metódus.
    * Egy csatát vezényel le 2 Kalandor között, az a harcos veszít akinek hamarabb elfogy az életerőpontja.
    * A metódus figyelembe veszi a támadások újratöltési idejét és a csata közben történő szintlépéseket is.
    */
    void Battle(Kalandor*);


    /**
    * \brief parseUnit metódus.
    * Kinyeri a paraméterként kapott map-ből a Kalandor létrehozásához szükséges adatokat.
    * Létrehozza a Kalandort és visszaadja.
    */
    static Kalandor parseUnit(std::map<std::string, std::string>);


    /**
     * \brief A Kalandor destruktora.
    */
    ~Kalandor();

};


#endif // KALANDOR_H
