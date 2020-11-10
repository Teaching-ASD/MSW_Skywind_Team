#include "../JSON.h"
#include "../Monster.h"
#include "../Hero.h"

#include <gtest/gtest.h>

TEST(parse, inputFile) {
	std::string test = JSON::inputFile("scenarios/scenario1.json");
	std::string expected = "{ \"hero\" : \"Dark_Wanderer.json\", \"monsters\" : \" Fallen.json Fallen.json Zombie.json Fallen.json Fallen.json Zombie.json Fallen.json Blood_Raven.json \" } ";
	ASSERT_EQ(test, expected);

	test = JSON::inputFile("scenarios/scenario1_whitespaces.json");
	ASSERT_EQ(test, expected);


	test = JSON::inputFile("scenarios/scenario2_changed_keys.json");
	expected = "{ \"monsters\" : \" Blood_Raven.json \", \"hero\" : \"Dark_Wanderer.json\" } ";
	ASSERT_EQ(test, expected);


	test = JSON::inputFile("scenarios/scenario2_empty_rows_and_whitespaces.json");
	expected = "{ \"hero\" : \"Dark_Wanderer.json\", \"monsters\" : \" Blood_Raven.json \" } ";
	ASSERT_EQ(test, expected);
}

TEST(parse, dataFromFile) {
	std::string test = JSON::inputFile("scenarios/scenario1.json");
	ASSERT_EQ(JSON::dataFromFile(test, "hero"), "Dark_Wanderer.json");

	test = JSON::inputFile("scenarios/scenario1_whitespaces.json");
	ASSERT_EQ(JSON::dataFromFile(test, "monsters"), " Fallen.json Fallen.json Zombie.json Fallen.json Fallen.json Zombie.json Fallen.json Blood_Raven.json ");
}

TEST(parse, stringFromFile) {

	std::string test = Monster::stringFromFile(Monster::inputFile("units/Zombie.json"), "name");
	ASSERT_EQ(test, "Zombie");
	
	test = Monster::stringFromFile(Monster::inputFile("units/Fallen.json"), "name");
	ASSERT_EQ(test, "Fallen");
}

TEST(parse, intFromFile) {

	std::string test = Monster::intFromFile(Monster::inputFile("units/Zombie.json"), "health_points");
	ASSERT_EQ(test, "10");

	test = Monster::intFromFile(Monster::inputFile("units/Dark_Wanderer.json"), "base_health_points");
	ASSERT_EQ(test, "30");
}

TEST(parse, floatFromFile) {

	std::string test = Monster::floatFromFile(Monster::inputFile("units/Zombie.json"), "attack_cooldown");
	ASSERT_EQ(test, "2.8");

	test = Monster::floatFromFile(Monster::inputFile("units/Dark_Wanderer.json"), "base_attack_cooldown");
	ASSERT_EQ(test, "1.1");
}


TEST(units, getters) {
	Hero h("Prince Aidan of Khanduras", 30, 3, 1.1, 20, 5, 1, 0.9);
	Monster m("Fallen", 4, 2, 1.6);

	ASSERT_EQ(h.getName(), "Prince Aidan of Khanduras");
	ASSERT_EQ(m.getName(), "Fallen");

	ASSERT_EQ(h.getHealthPoints(), 30);
	ASSERT_EQ(m.getHealthPoints(), 4);

	ASSERT_EQ(h.getDamage(), 3);
	ASSERT_EQ(m.getDamage(), 2);

	ASSERT_NEAR(h.getAttackCoolDown(), 1.1, 1e-1);
	ASSERT_NEAR(m.getAttackCoolDown(), 1.6, 1e-1);

	ASSERT_EQ(h.getMaxHealthPoints(), h.getHealthPoints());
	
}

TEST(units, isALive) {
	Hero h("Prince Aidan of Khanduras", 30, 3, 1.1, 20, 5, 1, 0.9);
	Monster m("Fallen", 0, 2, 1.6);

	ASSERT_EQ(h.isAlive(), true);
	ASSERT_EQ(m.isAlive(), false);
}

TEST(units, Attack) {
	Hero* h = new Hero("Prince Aidan of Khanduras", 30, 3, 1.1, 20, 5, 1, 0.9);
	Monster* m = new Monster("Fallen", 4, 2, 1.6);

	h->Attack(m);

	ASSERT_EQ(m->getHealthPoints(), 1);
	ASSERT_EQ(h->getExp(), 3);

	m->Attack(h);

	ASSERT_EQ(h->getHealthPoints(), 28);
	
	delete h;
	delete m;
}

TEST(units, fightTilDeath) {
	Hero h("Prince Aidan of Khanduras", 30, 3, 1.1, 20, 5, 1, 0.9);
	Monster m1("Fallen", 4, 2, 1.6);
	Monster m2("Zombie", 10, 1, 2.8);
	Monster m3("Blood Raven", 113, 8, 1.2);
	h.fightTilDeath(m1);

	EXPECT_EQ(h.getHealthPoints(), 26);
	EXPECT_EQ(m1.getHealthPoints(), 0);

	EXPECT_EQ(h.getExp(), 4);
	EXPECT_EQ(h.getLevel(), 1);
	EXPECT_EQ(h.getDamage(), 3);
	EXPECT_NEAR(h.getAttackCoolDown(), 1.1, 1e-1);

	h.fightTilDeath(m2);

	EXPECT_EQ(h.getHealthPoints(), 23);
	EXPECT_EQ(m2.getHealthPoints(), 0);

	EXPECT_EQ(h.getExp(), 14);
	EXPECT_EQ(h.getLevel(), 1);
	EXPECT_EQ(h.getDamage(), 3);
	EXPECT_NEAR(h.getAttackCoolDown(), 1.1, 1e-1);

	h.fightTilDeath(m3);

	EXPECT_EQ(h.getHealthPoints(), 52);
	EXPECT_EQ(m3.getHealthPoints(), 0);

	EXPECT_EQ(h.getExp(), 127);
	EXPECT_EQ(h.getLevel(), 7);
	EXPECT_EQ(h.getDamage(), 9);
	EXPECT_NEAR(h.getAttackCoolDown(), 0.5, 1e-1);
}


int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}