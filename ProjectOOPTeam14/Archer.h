#pragma once
#include "Player.h"
#include "Constants.h"

class Archer :
    public Player
{
private:
	double stamina;
	double accuracity;

public:
	Archer(MyString::String& username, MyString::String& password);
	Archer(MyString::String& username, MyString::String& password, double health, double stamina, double accuracity,
		unsigned int level, int xp, int max_xp);
	Archer(const Archer& other);
	Archer& operator=(const Archer& other);
	~Archer();

	bool AddXP(const unsigned int xp) override;

	double GetPower() const override;
	Player* clone() const override;
};

