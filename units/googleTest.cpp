#include "../Json.h"
#include "../Warrior.h"
#include "../Kalandor.h"

#include <gtest/gtest.h>


TEST(parse, inputFile) {
	std::string teszt = Json::inputFile("Maple.json");
	std::string expected = "{\"attackcooldown\":14,\"name\":\"Maple\",\"dmg\":10,\"hp\":150}";
	ASSERT_EQ(teszt, expected);

	teszt = Json::inputFile("Alduin.json");
	expected = "{\"name\":\"Alduin\",\"hp\":200,\"attackcooldown\":12.2,\"dmg\":30}";
	ASSERT_EQ(teszt, expected);
}

TEST(parse, jsonParse) {
	std::string name = Json::jsonParse(Json::inputFile("Alduin.json")).at("name");
	ASSERT_EQ(name, "Alduin");

	name = Json::jsonParse(Json::inputFile("Maple.json")).at("name");
	ASSERT_EQ(name, "Maple");

	std::string hp = Json::jsonParse(Json::inputFile("Maple.json")).at("hp");
	ASSERT_EQ(hp, "150");

	hp = Json::jsonParse(Json::inputFile("Alduin.json")).at("hp");
	ASSERT_EQ(hp, "200");

	std::string attackcooldown = Json::jsonParse(Json::inputFile("Sally.json")).at("attackcooldown");
	ASSERT_EQ(attackcooldown, "18.2");

	attackcooldown = Json::jsonParse(Json::inputFile("Alduin.json")).at("attackcooldown");
	ASSERT_EQ(attackcooldown, "12.2");
}

TEST(parse, parseUnit_and_getters) {
	Warrior w = Warrior::parseUnit(Json::jsonParse(Json::inputFile("Alduin.json")));
	ASSERT_EQ(w.getName(), "Alduin");
	ASSERT_EQ(w.getDmg(), 30);
	ASSERT_EQ(w.getHp(), 200);
	ASSERT_NEAR(w.getAttackCoolDown(), 12.2, 1e-1);

	Warrior w2 = Warrior::parseUnit(Json::jsonParse(Json::inputFile("Maple.json")));
	ASSERT_EQ(w2.getName(), "Maple");
	ASSERT_EQ(w2.getDmg(), 10);
	ASSERT_EQ(w2.getHp(), 150);
	ASSERT_NEAR(w2.getAttackCoolDown(), 14, 1e-1);
}

TEST(units, setters) {
	Warrior w("Batman", 120, 10, 13.2);

	w.setHp(200);
	ASSERT_EQ(w.getHp(), 200);

	w.setAttackCd(32.4);
	ASSERT_NEAR(w.getAttackCoolDown(), 32.4, 1e-1);

	w.setDmg(20);
	ASSERT_EQ(w.getDmg(), 20);
}

TEST(units, addExp) {
	Kalandor k("Batman", 200, 30, 12.2);
	k.addExp();
	ASSERT_EQ(k.getExp(), 30);
}

TEST(units, Battle) {
	Kalandor* k1 = new Kalandor("Batman", 200, 30, 12.2);
	Kalandor* k2 = new Kalandor("Superman", 150, 10, 14);

	k1->Battle(k2);

	EXPECT_EQ(k1->getHp(), 210);
	EXPECT_EQ(k2->getHp(), 0);

	EXPECT_EQ(k1->getDmg(), 33);
	EXPECT_EQ(k2->getDmg(), 10);

	EXPECT_NEAR(k1->getAttackCoolDown(), 10.9, 1e-1);
	EXPECT_NEAR(k2->getAttackCoolDown(), 14, 1e-1);

	delete k1, k2;
}

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}