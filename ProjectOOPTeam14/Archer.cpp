#include "Archer.h"


Archer::Archer(MyString::String& username, MyString::String& password)
	: Player(username, password, ARCHER_START_HEALTH)
{
	srand((unsigned int)time(nullptr));
	stamina = ARCHER_START_STAMINA;
	accuracity = ARCHER_START_ACCURACITY;

	type = Type::ARCHER;
}

Archer::Archer(MyString::String& username, MyString::String& password, double health, double stamina, double accuracity,
	unsigned int level, int xp, int max_xp)
	: Player(username, password, health, level, xp, max_xp)
{
	srand((unsigned int)time(nullptr));
	this->stamina = stamina;
	this->accuracity = accuracity;
	type = Type::ARCHER;
}

Archer::Archer(const Archer& other)
	: Player(other)
{
	srand((unsigned int)time(nullptr));
	this->stamina = other.stamina;
	this->accuracity = other.accuracity;

	type = other.type;
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
		health += ARCHER_HEALTH_INC;
		if (stamina < ARCHER_MAX_STAMINA)
		{
			stamina += ARCHER_STAMINA_INC;

		}
		if (accuracity < ARCHER_MAX_ACC)
		{
			accuracity += ARCHER_ACC_INC;
		}
		return true;
	}
	return false;
}

double Archer::GetPower() const
{
	double power = 1;
	if (weapon != nullptr)
	{
		for (int i = 0; i < stamina; i++)
		{
			double ap = weapon->use();
			if (ap > 0)
			{
				double acc = (rand() % 10 + accuracity) / 10.0f;

				power += ap * acc;
			}
		}
	}
	return power;
}

Player* Archer::clone() const
{
	return new Archer(*this);
}