#pragma once
#include "Player.h"

const double START_HEALTH = 70;
const double HEALTH_INC = 5;
const double START_MANA = 20;
const double MANA_INC = 10;

class Mage :
	public Player
{
private:
	double mana;
public:
	Mage(MyString::String& username, MyString::String& password);
	Mage(MyString::String& username, MyString::String& password, double health, double mana,
		unsigned int level, int xp, int max_xp);
	Mage(const Player& other);
	Mage& operator=(const Mage& other);
	~Mage();

	virtual bool AddXP(const unsigned int xp) override;

	virtual double GetPower() const override;
	virtual Player* clone() const override;
};