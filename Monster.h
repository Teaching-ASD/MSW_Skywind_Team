/**
 * \class Monster
 *
 * A Monster adatait és metódusait tartalmazó class
 *
 * \authors DanielZettis, kormendiakos, MZsolt97
 *
 * \date 2020/11/06
 *
 * Létrehozva: 2020/11/06
*/

#ifndef MONSTER_H
#define MONSTER_H

#include "JSON.h"

class Monster
{
protected:
	const std::string name; ///< A Monster neve.
	int hp;	///< A Monster sebzéspontja.
	int dmg; ///< A Monster életerőpontja.
	float attackCd; ///< A Monster támadásának betöltési ideje.


public:
	
	/**
	 * \brief A Monster konstruktora.
	 * A Monster létrehozásakor paraméterként megadott értékekkel ruházza fel a Monster-t.
	 * (name, hp, dmg, attackcooldown)
	*/
	Monster(const std::string, int, int, float);


	/**
	 * \brief Név lekérő metódus.
	 * Visszaadja a Monster nevét.
	*/
	std::string getName() const;


	/**
	 * \brief Életerőpont lekérő metódus.
	 * Visszaadja a Monster életerőpontját.
	*/
	int getHealthPoints() const;


	/**
	 * \brief Sebzéspont lekérő metódus.
	 * Visszaadja a Monster sebzéspontját.
	*/
	int getDamage() const;


	/**
	 * \brief Attackcooldown lekérő metódus.
	 * Visszaadja a Monster támadásának töltési idejét.
	*/
	float getAttackCoolDown() const;


	/**
	 * \brief Életerőpont beállító metódus.
	 * Beállítja a Monster életerőpontját a paraméterként megadott értékre
	*/
	void setHp(int /** [in] A beállítani kívánt érték*/);


	/**
	 * \brief isAlive metódus.
	 * A Monster életerejét megvizsgálva visszaad egy lokikai értéket. Ha a Monster életereje 0 akkor a Monster halott, tehát
	 * false eredménnyel tér vissza, ha nagyobb mint 0 akkor a Monster él, így a visszatérési érték true lesz.
	*/
	bool isAlive() const;


	/**
	 * \brief Attack metódus.
	 * A függvényt meghívó Monster megtámadja a paraméterben megadott Monster-t,
	 * így a paraméterben megadott Monster életerőpontját csökkenti a hívó Monster sebzéspontjával, feltéve, ha az adott Monster még kibír ekkora támadást,
	 * ha nem akkor a védekező fél életerpontját 0-ra állítja.
	 *
	*/
	virtual void Attack(Monster* /** [in] A megtámadni kívánt Monster memóriacíme.*/);


	/**
	 * \brief fightTilDeath metódus.
	 * Levezényel egy harcot 2 Monster között, figyelembe véve a a támadási idők betöltését
	 * és a Hero szintlépéseivel járó adattagjainak változásait.
	*/
	void fightTilDeath(Monster& /** [in] A megtámadni kívánt Monster.*/);


	/**
	 * \brief inputFile metódus.
	 * Megnyitja a paraméterként megadott fájlt és betölti a tartalmát egy stringbe a szóközök és a sorvégződések kivételével,
	 * majd visszatér az így kapott stringgel.
	*/
	static std::string inputFile(std::string /**A fájl neve*/);


	/**
	 * \brief stringFromFile metódus.
	 * Kinyeri a második paraméterként megadott adatot az első paraméterként megadott stringből.
	 * Ez a metódus kizárólag string típusú adatok kinyerésére alkalmas.
	*/
	static std::string stringFromFile(std::string /** [in] A string amelyből ki szeretnénk nyerni az adatot.*/, std::string /** [in] Az adat amit ki szeretnénk nyerni a stringből.*/);
	

	/**
	 * \brief intFromFile metódus.
	 * Kinyeri a második paraméterként megadott adatot az első paraméterként megadott stringből.
	 * Ez a metódus kizárólag int típusú adatok kinyerésére alkalmas.
	*/
	static std::string intFromFile(std::string /** [in] A string amelyből ki szeretnénk nyerni az adatot.*/, std::string /** [in] Az adat amit ki szeretnénk nyerni a stringből.*/);
	
	
	/**
	 * \brief floatFromFile metódus.
	 * Kinyeri a második paraméterként megadott adatot az első paraméterként megadott stringből.
	 * Ez a metódus kizárólag float típusú adatok kinyerésére alkalmas.
	*/
	static std::string floatFromFile(std::string /** [in] A string amelyből ki szeretnénk nyerni az adatot.*/, std::string /** [in] Az adat amit ki szeretnénk nyerni a stringből.*/);


	/**
	 * \brief parse metódus.
	 * A paraméterként megadott fájlból kinyeri a Monster létrehozásához szükséges adatokat majd létrehozza és vissza is tér vele.
	*/
	static Monster parse(std::string /** [in] A string amelyből ki szeretnénk nyerni az adatokat.*/);


	/**
	 * \brief A Hero osztály destruktora.
	*/
	~Monster();

};

#endif //MONSTER_H

