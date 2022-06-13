#include "Warrior.h"

Warrior::Warrior(MyString::String& username, MyString::String& password)
	: Player(username, password, WARRIOR_START_HEALTH)
{
	strength = WARRIOR_START_STRG;
	type = Type::WARRIOR;
}

Warrior::Warrior(MyString::String& username, MyString::String& password, double health, double strength, unsigned int level, int xp, int max_xp)
	: Player(username, password, health, level, xp, max_xp)
{
	this->strength = strength;
	type = Type::WARRIOR;
}

Warrior::Warrior(const Warrior& other) 
	: Player(other)
{
	strength = other.strength;
	type = other.type;
}

Warrior& Warrior::operator=(const Warrior& other)
{
	Player::operator=(other);
	strength = other.strength;
	type = other.type;

	return *this;
}

Warrior::~Warrior()
{
}

bool Warrior::AddXP(const unsigned int xp)
{
	this->xp += xp;
	if (xp >= max_xp)
	{
		max_xp *= 2;
		level++;
		health += WARRIOR_HEALTH_INC;
		return true;
	}
	return false;
}


double Warrior::GetPower() const
{
	double power = 1;
	if (weapon != nullptr)
	{
		double ap = weapon->use();
		if (ap > 0)
		{
			power += ap;
		}
	}

	return power * strength;
}

Player* Warrior::clone() const
{
	return new Warrior(*this);
}
