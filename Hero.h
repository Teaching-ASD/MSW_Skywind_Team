/**
 * \class Hero
 *
 * A Hero adatait és metódusait tartalmazó class
 *
 * \authors DanielZettis, kormendiakos, MZsolt97
 *
 * \version 2.0
 *
 * \date 2020/11/06
 *
 * Létrehozva: 2020/11/06
*/

#ifndef HERO_H
#define HERO_H

#include "Monster.h"


class Hero : public Monster
{
private:
	const int expPerLvl; ///< A szintlépéshez szükséges tapasztalati pont mennyisége.
	const int hpBonus; ///< A szintlépéssel járó hp növekedés nagysága.
	const int dmgBonus; ///< A szintlépéssel járó dmg növekedés nagysága.
	const float attackCdMp; ///< A szintlépéssel járó attackcooldown változás szorzója.

	int maxHp; ///< A Hero pillanatnyi maximum életerőpontja. Kezdetben megegyezik az alap életerőpontjával majd a szintek növekedésének köszönhetően folyamatosan emelkedik.
	int level; ///< A Hero pillanatnyi szintje. Kezdetben 1 az értéke, az tapasztalati pont gyűjtés hatására növekedik.
	int exp; ///< Eltárolja, hogy a Hero mennyi tapasztalati ponttal rendelkezik. Kezdetben 0, az ellenfélnek bevitt sebzés hatására növekedik.

public:
	

	/**
	 * \brief A Hero konstruktora.
	 * A Hero létrehozásakor paraméterként megadott értékekkel ruházza fel a Hero-t.
	 * (name, hp, dmg, attackcooldown, expPerLvl, hpBonus, dmgBonus, attackCdMp)
	*/
	Hero(const std::string, int, int, float,const int, const int, const int, const float);
	

	/**
	 * \brief Exp lekérő metódus.
	 * Visszaadja, hogy mennyi tapasztalati ponttal rendelkezik a Hero.
	*/
	int getExp() const;


	/**
	 * \brief Szint lekérő metódus.
	 * Visszaadja a Hero szintjét.
	*/
	int getLevel() const;


	/**
	 * \brief Maximum élererőpont lekérő metódus.
	 * Visszaadja a Hero maximum élererőpontját.
	*/
	int getMaxHealthPoints() const;


	/**
	 * \brief Sebzéspont beállító metódus.
	 * Beállítja a Hero sebzéspontját a paraméterként megadott értékre.
	*/
	void setDmg(int /** [in] A beállítani kívánt érték*/);


	/**
	 * \brief Attackcooldown beállító metódus.
	 * Beállítja a Hero támadásának betöltési idejét a paraméterként megadott értékre.
	*/
	void setAttackCd(float /** [in] A beállítani kívánt érték*/);

	
	/**
	 * \brief Adatmódosító metódus.
	 * A Hero szintlépésével járó adatokat változtatja meg.
	*/
	void modDatas();

	/**
	 * \brief Attack metódus.
	 * A függvényt meghívó Hero megtámadja a paraméterben megadott Monster-t,
	 * így a paraméterben megadott Monster életerőpontját csökkenti a hívó Hero sebzéspontjával, feltéve, ha az adott Monster még kibír ekkora támadást,
	 * ha nem akkor a védekező fél életerpontját 0-ra állítja továbbá gondoskodik, hogy a Hero megkapja a neki járó tapasztalatot
	 * és az ennek köszönhető szinteket.
	 *
	*/
	void Attack(Monster* /** [in] A megtámadni kívánt Monster memóriacíme.*/) override;


	/**
	 * \brief parse metódus.
	 * A paraméterként megadott fájlból kinyeri a Hero létrehozásához szükséges adatokat majd létrehozza és vissza is tér vele.
	*/
	static Hero parse(std::string);


	/**
	 * \brief A Hero osztály destruktora.
	*/
	~Hero();

};

#endif //HERO_H

