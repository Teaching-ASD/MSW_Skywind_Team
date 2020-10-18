#ifndef JSON_H
#define JSON_H

#include <string>
#include <fstream>
#include <map>
#include <iostream>

class Json {
    private:
        static std::string nameFromFile(std::string);
        static std::string hpFromFile(std::string);
        static std::string dmgFromFile(std::string);
        static std::string attackCdFromFile(std::string);
        
    public:
        Json();
        static std::string inputFile(std::string);
        static std::map<std::string,std::string> jsonParse(std::string);
};

#endif