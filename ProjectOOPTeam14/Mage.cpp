#include "Mage.h"

Mage::Mage(MyString::String& username, MyString::String& password)
	: Player(username, password, START_HEALTH)
{
	mana = START_MANA;

	type = Type::ARCHER;
}

Mage::Mage(MyString::String& username, MyString::String& password, double health, double mana,
	unsigned int level, int xp, int max_xp)
	: Player(username, password, health, level, xp, max_xp)
{
	this->mana = mana;
	type = Type::MAGE;
}

Mage::Mage(const Mage& other)
	: Player(other)
{
	this->mana = other.mana;

	type = Type::MAGE;
}

Mage& Mage::operator=(const Mage& other)
{
	Player::operator=(other);
	this->mana = other.mana;
	type = other.type;

	return *this;
}

Mage::~Mage()
{
}

bool Mage::AddXP(const unsigned int xp)
{
	this->xp += xp;
	if (xp >= max_xp)
	{
		max_xp *= 2;
		level++;
		health += HEALTH_INC;
		mana += MANA_INC;
		return true;
	}
	return false;
}

double Mage::GetPower() const
{
	double power = 1;
	if (weapon != nullptr)
	{
		for (int i = 0; i < mana; i += 10)
		{
			//TODO: Add accuracity logic
			power += weapon->use();
		}
	}

	// TODO: Add Weapon Type and class logic
	return power;
}

Player* Mage::clone() const
{
	return new Mage(*this);
}