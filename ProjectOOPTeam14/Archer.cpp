#include "Archer.h"


Archer::Archer(MyString::String& username, MyString::String& password)
	: Player(username, password, START_HEALTH)
{
	stamina = START_STAMINA;
	accuracity = START_ACCURACITY;

	type = Type::ARCHER;
}

Archer::Archer(MyString::String& username, MyString::String& password, double health, double stamina, double accuracity,
	unsigned int level, int xp, int max_xp)
	: Player(username, password, health, level, xp, max_xp)
{
	this->stamina = stamina;
	this->accuracity = accuracity;
	type = Type::ARCHER;
}

Archer::Archer(const Archer& other)
	: Player(other)
{
	this->stamina = other.stamina;
	this->accuracity = other.accuracity;

	type = Type::ARCHER;
}

Archer& Archer::operator=(const Archer& other)
{
	Player::operator=(other);
	this->stamina = other.stamina;
	this->accuracity = other.accuracity;
	type = other.type;

	return *this;
}

Archer::~Archer()
{
}

bool Archer::AddXP(const unsigned int xp)
{
	this->xp += xp;
	if (xp >= max_xp)
	{
		max_xp *= 2;
		level++;
		health += HEALTH_INC;
		stamina += STAMINA_INC;
		accuracity += ACC_INC;
		return true;
	}
	return false;
}

double Archer::GetPower() const
{
	double power = 1;
	if (weapon != nullptr)
	{
		for (int i = 0; i < stamina; i+=20)
		{
			//TODO: Add accuracity logic
			power += weapon->use();
		}
	}

	// TODO: Add Weapon Type and class logic
	return power;
}

Player* Archer::clone() const
{
	return new Archer(*this);
}