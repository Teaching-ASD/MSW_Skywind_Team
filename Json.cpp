#include "Json.h"

Json::Json(){};

std::string Json::inputFile(std::string fileName){
    fileName = "units/" + fileName;
    std::ifstream file(fileName);
    if (file.is_open() == false)
    {
        throw std::runtime_error("The given file does not exist!");
        return 0;
    }
    std::string s;
    std::string OriginalS = "";
    while (file >> s)
    {
        OriginalS += s;
    }
    return OriginalS;
}

std::string Json::nameFromFile(std::string s){
    if (s.find("name") > s.size())
    {
        throw std::runtime_error("Name not found!");
    }
    else
    {
        std::string name = s.substr(s.find("name"));
        int db = 0;
        int pos = 0;
        while (db < 2)
        {
            pos = name.find('"');
            name = name.substr(pos + 1);
            db++;
        }
        pos = name.find('"');
        name = name.substr(0, pos);

        return name;
    }
}

std::string Json::hpFromFile(std::string s){

    if (s.find("hp") > s.size())
    {
        throw std::runtime_error("HP not found!");
    }
    else{
    std::string hp = s.substr(s.find("hp"));
    hp = hp.substr(hp.find(':') + 1);
    if (hp.find(',') < hp.find('}'))
    {
        hp = hp.substr(0, hp.find(','));
    }
    else
    {
        hp = hp.substr(0, hp.find('}'));
    }

    for (int i = 0; i < hp.size(); i++)
    {
        if (!isdigit(hp[i]))
        {
            throw std::runtime_error("Wrong value on HP!");
        }
    }

    return hp;
    }
}

std::string Json::dmgFromFile(std::string s){
    if (s.find("dmg") > s.size())
    {
        throw std::runtime_error("DMG not found!");
    }
    else{
    std::string dmg = "";
    dmg = s.substr(s.find("dmg"));
    dmg = dmg.substr(dmg.find(':') + 1);
    if (dmg.find(',') < dmg.find('}'))
    {
        dmg = dmg.substr(0, dmg.find(','));
    }
    else
    {
        dmg = dmg.substr(0, dmg.find('}'));
    }

    for (int i = 0; i < dmg.size(); i++)
    {
        if (!isdigit(dmg[i]))
        {
            throw std::runtime_error("Wrong value on DMG!");
        }
    }

    return dmg;
    }
}

std::string Json::attackCdFromFile(std::string s){
    if (s.find("attackcooldown") > s.size())
    {
        throw std::runtime_error("Attackcooldown not found!");
    }
    else{
    std::string attackcooldown = s.substr(s.find("attackcooldown"));
    attackcooldown = attackcooldown.substr(attackcooldown.find(':') + 1);
    if (attackcooldown.find(',') < attackcooldown.find('}'))
    {
        attackcooldown = attackcooldown.substr(0, attackcooldown.find(','));
    }
    else
    {
        attackcooldown = attackcooldown.substr(0, attackcooldown.find('}'));
    }
    int cnt = 0;
    for (int i = 0; i < attackcooldown.size(); i++)
    {
        if (attackcooldown[i] == '.')
        {
            cnt++;
        }
        else if (!isdigit(attackcooldown[i]))
        {
            throw std::runtime_error("Wrong value on Attackcooldown!");
        }
        if (cnt > 1)
        {
            throw std::runtime_error("Wrong value on Attackcooldown!");
        }
    }
    return attackcooldown;
    }
}

std::map<std::string, std::string> Json::jsonParse(std::string file){

    std::map<std::string, std::string> Datas;
    Datas.insert(std::pair<std::string, std::string>("name", Json::nameFromFile(file)));
    Datas.insert(std::pair<std::string, std::string>("hp", Json::hpFromFile(file)));
    Datas.insert(std::pair<std::string, std::string>("dmg", Json::dmgFromFile(file)));
    Datas.insert(std::pair<std::string, std::string>("attackcooldown", Json::attackCdFromFile(file)));

    return Datas;
}