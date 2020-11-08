#include "JSON.h"


JSON::JSON(const std::map<std::string, std::any>& map_) : map(map_) {};

std::string JSON::inputFile(std::string fileName) {
    std::ifstream file(fileName);
    std::string s;
    std::string OriginalS = "";
    while (file >> s)
    {
        OriginalS += s;
        OriginalS += " ";
    }
    file.close();
    return OriginalS;
}

std::string JSON::dataFromFile(std::string s, std::string data) {
   
        std::string value = s.substr(s.find(data));
        int db = 0;
        int pos = 0;
        while (db < 2)
        {
            pos = value.find('"');
            value = value.substr(pos + 1);
            db++;
        }
        pos = value.find('"');
        value = value.substr(0, pos);

        return value;
    
}

JSON JSON::parseFromFile(std::string fileName) {
	std::string s = inputFile(fileName);
    std::map<std::string, std::any> myMap;
    std::string hero = dataFromFile(s, "hero");
    std::string monsters = dataFromFile(s, "monsters");
    myMap.insert(std::pair<std::string,std::any>("hero", hero));
    myMap.insert(std::pair<std::string,std::any>("monsters", monsters));
	return JSON(myMap);

}

JSON::~JSON() {};



