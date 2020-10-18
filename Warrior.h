/**
 * \class Warrior
 * 
 * A Warrior adatait és metódusait tartalmazó class
 * 
 * \authors DanielZettis, kormendiakos, MZsolt97
 * 
 * \date 2020/10/16
 * 
 * Létrehozva: 2020/10/16
*/

#ifndef WARRIOR_H
#define WARRIOR_H

#include <vector>
#include <fstream>
#include <string>


class Warrior
{

private:

    const std::string name; ///< A Warrior neve
	int hp; ///< A Warrior életerőpontja
    int dmg;  ///< A Warrior sebzéspontja
    float attackcooldown; ///< A Warrior támadásának betöltési ideje

    /** 
     * \brief Ez a metódus felel a támadás végrehajtásáért.
     *  A támadó sebzéspontját kivonja a védekező életerőpontjából,
     *  ha az kisebb lenne mint 0 akkor 0-ra állítja.*/
    //void Attack(Warrior* /** [in] A megtámadni kívánt Warrior memória címe.*/);

public:

    /** 
     * \brief A Warrior konstruktora.
     * A Warrior létrehozásakor paraméterként megadott értékekkel ruházza fel a Warriort.
     * (név, hp, dmg, attackcooldown)
    */
	  Warrior(std::string, int, int, float);

    /** 
     * \brief Name getter.
     * Visszaadja a Warrior nevét.
    */
	  std::string getName() const;

    /** 
     * \brief Hp getter.
     * Visszaadja a Warrior életerőpontját.
    */
	  int getHp() const;

    /** 
     * \brief Dmg getter.
     * Visszaadja a Warrior sebzéspontját.
    */
	  int getDmg() const;

	  void setHp(int);
	  void setDmg(int);

	  void setAttackCd(float);

    /** 
     * \brief Attackcooldown getter.
     * Visszaadja a Warrior támadásának töltési idejét.
    */
    float getAttackCoolDown() const;

    /** 
     * \brief Battle metódus.
     * Levezényel egy csatát 2 Warrior között a támadási időket figyelembe véve.
     * Először a támadó Warrior támad, utána a védekező,
     * ezt követően pedig mindig az amelyiknek hamarabb töltődik be a támadása,
     * ha egyszerre töltődik be akkor a támadó fél támadhat először,
     * utána pedig a védekező fél (persze csak, ha nem semmisül meg a támadás során)
    */
    //void Battle(Warrior* /** [in] A megtámadni kívánt Warrior memória címe.*/);

    /**
     * \brief Adat kinyerő metódus.
     * Kinyeri a Warrior adatait a paraméterként megadott fájlból és eltárolja azokat egy vektorban,
     * majd, ha megvan az összes adat visszaadja a vektort
    */
    static std::vector<std::string> parseUnit(std::string /** [in] A fájl neve, amelyből ki szeretnénk nyerni a Warrior adatait.*/);

    /**
     * \brief A Warrior osztály destruktora.
    */
    ~Warrior();

};


#endif // WARRIOR_H
