#pragma once
#include "Player.h"

const double START_HEALTH = 70;
const double HEALTH_INC = 5;

const double START_STAMINA = 1;
const double STAMINA_INC = 0.5;
const double START_ACCURACITY = 1;
const double ACC_INC = 0.5;

const double MAX_STAMINA = 10;
const double MAX_ACC = 10;

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
	Archer(const Player& other);
	Archer& operator=(const Archer& other);
	~Archer();

	virtual bool AddXP(const unsigned int xp) override;

	virtual double GetPower() const override;
	virtual Player* clone() const override;
};

