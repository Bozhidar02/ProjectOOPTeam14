#pragma once
#include "Player.h"

const double START_HEALTH = 200;
const double HEALTH_INC = 15;

const double START_STRG = 1;
const double STRG_INC = 0.1f;

class Warrior :
    public Player
{
private:
	double strength;
public:
	Warrior(MyString::String& username, MyString::String& password);
	Warrior(MyString::String& username, MyString::String& password, double health, double strength, unsigned int level, int xp, int max_xp);
	Warrior(const Player& other);
	Warrior& operator=(const Warrior& other);
	~Warrior();

	virtual bool AddXP(const unsigned int xp) override;

	virtual double GetPower() const override;
	virtual Player* clone() const override;
};

