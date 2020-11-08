/**
 * \class Json
 *
 * A Json adatait és metódusait tartalmazó class
 *
 * \authors DanielZettis, kormendiakos, MZsolt97
 *
 * \date 2020/11/06
 *
 * Létrehozva: 2020/11/06
*/


#ifndef JSON_H
#define JSON_H

#include <string>
#include <fstream>
#include <map>

class Json {
    private:

        /**
        * \brief nameFromFile metódus.
        * Kinyeri a Warrior nevét a paraméterként megadott fájlból.
        * Ez a metódus kizárólag string típusú adatok kinyerésére alkalmas.
        */
        static std::string nameFromFile(std::string);


        /**
        * \brief hpFromFile metódus.
        * Kinyeri a Warrior életerőpontját a paraméterként megadott fájlból.
        * Ez a metódus kizárólag integer típusú adatok kinyerésére alkalmas.
        */
        static std::string hpFromFile(std::string);


        /**
        * \brief dmgFromFile metódus.
        * Kinyeri a Warrior sebzéspontját a paraméterként megadott fájlból.
        * Ez a metódus kizárólag integer típusú adatok kinyerésére alkalmas.
        */
        static std::string dmgFromFile(std::string);


        /**
        * \brief dmgFromFile metódus.
        * Kinyeri a Warrior támadásának újratöltési idejét a paraméterként megadott fájlból.
        * Ez a metódus kizárólag float/double típusú adatok kinyerésére alkalmas.
        */
        static std::string attackCdFromFile(std::string);
        
    public:

        /**
        * \brief A Json konstruktora.
        */
        Json();


        /**
        * \brief inputFile metódus.
        * Megnyitja a paraméterként megadott fájlt és betölti a tartalmát egy stringbe a szóközök és a sorvégződések kivételével,
        * majd visszatér az így kapott stringgel.
        */
        static std::string inputFile(std::string);


        /**
        * \brief jsonParse metódus.
        * A ...FromFile metódusok segítségével kinyeri a Warrior nevét, életerőpontját, sebzéspontját és a támadásának újratöltési idejét.
        * A kinyert értékeket eltárolja egy map-ben és visszatér az így kapott mappel.
        */
        static std::map<std::string,std::string> jsonParse(std::string);


        /**
        * \brief A Json destruktora.
        */
        ~Json();
};

#endif