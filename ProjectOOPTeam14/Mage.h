#pragma once
#include "Player.h"
#include "Constants.h"

class Mage :
	public Player
{
private:
	double mana;
public:
	Mage(MyString::String& username, MyString::String& password);
	Mage(MyString::String& username, MyString::String& password, double health, double mana,
		unsigned int level, int xp, int max_xp);
	Mage(const Mage& other);
	Mage& operator=(const Mage& other);
	~Mage();

	virtual bool AddXP(const unsigned int xp) override;

	virtual double GetPower() const override;
	virtual Player* clone() const override;
};