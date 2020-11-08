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
	std::map<std::string, std::any> map;


public:

	JSON(const std::map<std::string, std::any>&);

	template <typename T>

	T get(std::string key) {
		std::any value = map[key];
		return std::any_cast<T>(value);
	}

	int count(std::string key)
	{
		return this->map.count(key);
	}

	static std::string inputFile(std::string);


	static std::string dataFromFile(std::string,std::string);



	static JSON parseFromFile(std::string);


	~JSON();

	class ParseException : public std::exception
	{
	public:

		ParseException() {};

		~ParseException() {};
	};
	
		
};

#endif //JSON_H

