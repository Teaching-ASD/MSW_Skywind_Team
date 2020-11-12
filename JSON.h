/**
 * \class JSON
 *
 * A JSON adatait és metódusait tartalmazó class
 *
 * \authors DanielZettis, kormendiakos, MZsolt97
 *
 * \version 2.0
 *
 * \date 2020/11/06
 *
 * Létrehozva: 2020/11/06
*/

#ifndef JSON_H
#define JSON_H

#include<exception>
#include<string>
#include<map>
#include<any>

#include<istream>
#include<fstream>

class JSON
{

protected:
	std::map<std::string, std::any> map; ///<A Hero-t és a Monster(eke)t tartalmazó map.


public:

	/**
	 * \brief A JSON konstruktora.
	 * A JSON létrehozásához egy map-ot vár.
	*/
	JSON(const std::map<std::string, std::any>&);

	template <typename T>

	/**
	 * \brief get metódus.
	 * Visszaadja a paraméterként megadott kulcshoz rendelt értéket egy map-ből.
	*/
	T get(std::string key) {
		std::any value = map[key];
		return std::any_cast<T>(value);
	}


	/**
	 * \brief count metódus.
	 * Megszámolja, hogy a paranéterként adott kulcs hányszor szerepel a map-ben.
	 * 0 vagy 1 lehet
	 * 0, ha nincs a map-ben, 1, ha van
	*/
	int count(std::string key)
	{
		return this->map.count(key);
	}


	/**
	 * \brief inputFile metódus.
	 * Megnyitja a paraméterként megadott fájlt és betölti a tartalmát egy stringbe, minden betöltött string után egy szóközt téve.
	*/
	static std::string inputFile(std::string);


	/**
	 * \brief dataFromFile metódus.
	 * Az első paraméterként megadott stringből, kinyeri, majd visszaadja a második paraméterként megadott kulcshoz tartozó értéket.
	*/
	static std::string dataFromFile(std::string,std::string);



	/**
	 * \brief parseFromFile metódus.
	 * A paraméterként megadott fájlból kinyeri a Hero-t és a Monster(eke)t és eltárolja őket egy mapben, 
	 * amellyel létrehoz egy JSON objektumot és visszatér vele.
	*/
	static JSON parseFromFile(std::string);


	/**
	 * \brief A JSON osztály destruktora.
	*/
	~JSON();


	/**
	* \class ParseException
	*
	* \authors DanielZettis, kormendiakos, MZsolt97
	*
	* \version 2.0
	*
	* \date 2020/11/06
	*
	* Létrehozva: 2020/11/06
	*/
	class ParseException : public std::exception
	{
	public:

		/**
		* \brief A ParseException osztály konstruktora.
		*/
		ParseException() {};


		/**
		* \brief A ParseException osztály destruktora.
		*/
		~ParseException() {};
	};
	
		
};

#endif //JSON_H

