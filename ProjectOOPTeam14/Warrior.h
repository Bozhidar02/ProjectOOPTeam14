#pragma once
#include "Player.h"
#include "Constants.h"

class Warrior :
    public Player
{
private:
	double strength;
public:
	Warrior(MyString::String& username, MyString::String& password);
	Warrior(MyString::String& username, MyString::String& password, double health, double strength, unsigned int level, int xp, int max_xp);
	Warrior(const Warrior& other);
	Warrior& operator=(const Warrior& other);
	~Warrior();

	virtual bool AddXP(const unsigned int xp) override;

	virtual double GetPower() const override;
	virtual Player* clone() const override;
};

