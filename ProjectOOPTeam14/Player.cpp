#include "Player.h"

void Player::copy(const Player& other)
{
	username = other.username;
	password = other.password;
	xp = other.xp;
	max_xp = other.max_xp;
	health = other.health;
	weapon = other.weapon->clone();
	armor = new Armor * [ARMOR_SLOTS];
	for (int i = 0; i < ARMOR_SLOTS; i++)
	{
		armor[i] = other.armor[i]->clone();
	}
	inventory = other.inventory;
}

void Player::free()
{
	delete weapon;
	for (int i = 0; i < ARMOR_SLOTS; i++)
	{
		delete armor[i];
	}
	delete[] armor;
}

Player::Player(MyString::String& username, MyString::String& password, float health)
{
	this->username = username;
	this->password = password;

	this->health = health;

	xp = 0;
	max_xp = LVL_ONE_XP;
	level = 1;

	weapon = nullptr;
	armor = new Armor * [ARMOR_SLOTS];
}

Player::Player(MyString::String& username, MyString::String& password, float health, unsigned int level, int xp, int max_xp)
{
	this->username = username;
	this->password = password;

	this->health = health;

	this->xp = xp;
	this->max_xp = max_xp;
	this->level = level;

	weapon = nullptr;
	armor = new Armor * [ARMOR_SLOTS];
}

Player::Player(const Player& other)
{
	copy(other);
}

Player& Player::operator=(const Player& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
}

Player::~Player()
{
	free();
}

const MyString::String& Player::GetName() const
{
	return username;
}

bool Player::IsUser(const MyString::String& name, const MyString::String& pass) const
{
	return (username == name && password == pass);
}

unsigned int Player::GetLevel() const
{
	return level;
}

float Player::GetHealth() const
{
	return health;
}

void Player::AddXP(const float xp)
{
	this->xp += xp;
	if (xp >= max_xp)
	{
		max_xp *= 2;
		level++;
		health += 10;
	}
}

bool Player::PickWeapon(const MyString::String& weaponName)
{
	Item* temp = inventory.FindItem(weaponName);
	if (temp == nullptr)
	{
		return false;
	}
	weapon = dynamic_cast<Weapon*>(temp);
	if (weapon == nullptr)
	{
		return false;
	}

	return true;
}

bool Player::SetArmorSlot(const MyString::String& armorName, const int slot)
{
	if (slot < 0 || slot >= ARMOR_SLOTS)
	{
		return false;
	}

	Item* temp = inventory.FindItem(armorName);
	if (temp == nullptr)
	{
		return false;
	}

	armor[slot] = dynamic_cast<Armor*>(temp);
	if (armor[slot] == nullptr)
	{
		return false;
	}

	return true;
}
