#include "Monster.h"


Monster::Monster(const std::string name_, int hp_, int dmg_, float attackcooldown_) : name(name_), hp(hp_), dmg(dmg_), attackCd(attackcooldown_) {}

std::string Monster::getName() const {
	return this->name;
}
int Monster::getHealthPoints() const {
	return this->hp;
}
int Monster::getDamage() const {
	return this->dmg;
}
float Monster::getAttackCoolDown() const {
	return this->attackCd;
}


void Monster::setHp(int hp_) {
	this->hp = hp_;
}


bool Monster::isAlive() const {
	if (this->getHealthPoints() > 0) {
		return true;
	}
	else {
		return false;
	}
}

void Monster::Attack(Monster* m) {
    if (m->hp - this->getDamage() > 0) {
		m->setHp(m->hp - this->getDamage());
	}
	else {
		m->setHp(0);
	}
}

void Monster::fightTilDeath(Monster& m) {

    float HeroCd = this->getAttackCoolDown();
    float MonsterCd = m.getAttackCoolDown();
    int i = 0;

    if (this->isAlive()) {
        this->Attack(&m);
    }

    if (m.isAlive()) {
        m.Attack(this);
    }

 
    while (this->isAlive() && m.isAlive()) {
        if (HeroCd <= 0) {
            this->Attack(&m);
            HeroCd = this->getAttackCoolDown();
        }
        else {
            HeroCd--;
        }
        if (MonsterCd <= 0) {
            m.Attack(this);
            MonsterCd = m.getAttackCoolDown();
        }
        else {
            MonsterCd--;
        }
    }
}


std::string Monster::inputFile(std::string fileName) {
    std::ifstream file(fileName);
    std::string s;
    std::string OriginalS = "";
    while (file >> s)
    {
        OriginalS += s;
    }
    file.close();
    return OriginalS;
}


std::string Monster::stringFromFile(std::string s, std::string data) {


    if (s.find(data) > s.size())
    {
        throw std::runtime_error(data+ " not found!");
    }
    else
    {
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
}

std::string Monster::intFromFile(std::string s, std::string data){

    if (s.find(data) > s.size())
    {
        throw std::runtime_error(data+" not found!");
    }
    else {
        std::string value = s.substr(s.find(data));
        value = value.substr(value.find(':') + 1);
        if (value.find(',') < value.find('}'))
        {
            value = value.substr(0, value.find(','));
        }
        else
        {
            value = value.substr(0, value.find('}'));
        }

        for (int i = 0; i < value.size(); i++)
        {
            if (!isdigit(value[i]))
            {
                throw std::runtime_error("Wrong value on "+ data+"!");
            }
        }
        return value;
    }
}

std::string Monster::floatFromFile(std::string s, std::string data) {

    if (s.find("attack_cooldown") > s.size())
    {
        throw std::runtime_error(data+" not found!");
    }
    else {
        std::string value = s.substr(s.find(data));
        value = value.substr(value.find(':') + 1);
        if (value.find(',') < value.find('}'))
        {
            value = value.substr(0, value.find(','));
        }
        else
        {
            value = value.substr(0, value.find('}'));
        }
        int cnt = 0;
        for (int i = 0; i < value.size(); i++)
        {
            if (value[i] == '.')
            {
                cnt++;
            }
            else if (!isdigit(value[i]))
            {
                throw std::runtime_error("Wrong value on "+data+"!");
            }
            if (cnt > 1)
            {
                throw std::runtime_error("Wrong value on " + data + "!");
            }
        }
        return value;
    }
}


Monster Monster::parse(std::string file) {
    std::map<std::string, std::string> Datas;
    Datas.insert(std::pair<std::string, std::string>("name", Monster::stringFromFile(Monster::inputFile(file), "name")));
    Datas.insert(std::pair<std::string, std::string>("hp", Monster::intFromFile(Monster::inputFile(file), "health_points")));
    Datas.insert(std::pair<std::string, std::string>("dmg", Monster::intFromFile(Monster::inputFile(file), "damage")));
    Datas.insert(std::pair<std::string, std::string>("attackcooldown", Monster::floatFromFile(Monster::inputFile(file), "attack_cooldown")));

    
    Monster m(Datas["name"], std::stoi(Datas["hp"]), std::stoi(Datas["dmg"]), std::stof(Datas["attackcooldown"]));
    
    return m;
}

Monster::~Monster() {};
