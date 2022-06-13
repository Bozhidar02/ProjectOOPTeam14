#pragma once
#include <stdlib.h>
#include <time.h>
#include "Inventory.h"
#include "String.h"

const int ARMOR_SLOTS = 3;
const int LVL_ONE_XP = 100;

class Player
{
protected:
	MyString::String username;
	MyString::String password;

	unsigned int xp;
	unsigned int max_xp;
	unsigned int level;
	double health;

	Weapon* weapon;
	Armor** armor;
	
	Inventory* inventory;

	void copy(const Player& other);
	void free();

	enum Type
	{
		WARRIOR,
		ARCHER,
		MAGE,
		UNKNOWN
	} type;
public:
	Player(MyString::String& username, MyString::String& password, double health);
	Player(MyString::String& username, MyString::String& password, double health, unsigned int level, unsigned int xp, unsigned int max_xp);
	Player(const Player& other);
	Player& operator=(const Player& other);
	virtual ~Player();

	const MyString::String& GetName() const;
	bool IsUser(const MyString::String& name, const MyString::String& pass) const;
	unsigned int GetLevel() const;
	double GetHealth() const;
	double GetDefence() const;
	Inventory* GetInventory();
	const char* getType();

	virtual bool AddXP(const unsigned int xp) = 0;

	bool PickWeapon(const MyString::String& weaponName);
	bool SetArmorSlot(const MyString::String& armorName, const int slot);
	void droparmor();

	virtual double GetPower() const = 0;

	void Attack(Player* other);

	virtual Player* clone() const = 0;
};

