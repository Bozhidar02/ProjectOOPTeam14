#include "Warrior.h"

Warrior::Warrior(MyString::String& username, MyString::String& password)
	: Player(username, password, START_HEALTH)
{
	type = Type::WARRIOR;
}

Warrior::Warrior(MyString::String& username, MyString::String& password, double health, unsigned int level, int xp, int max_xp)
	: Player(username, password, health, level, xp, max_xp)
{
	type = Type::WARRIOR;
}

Warrior::Warrior(const Warrior& other) 
	: Player(other)
{
	type = Type::WARRIOR;
}

Warrior& Warrior::operator=(const Warrior& other)
{
	Player::operator=(other);
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
		health += HEALTH_INC;
		return true;
	}
	return false;
}


double Warrior::GetPower() const
{
	double power = 1;
	if (weapon != nullptr)
	{
		power += weapon->use();
	}

	// TODO: Add Weapon Type and class logic
	return power;
}

Player* Warrior::clone() const
{
	return new Warrior(*this);
}
