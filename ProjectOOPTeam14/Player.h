#pragma once
#include "Inventory.h"
#include "String.h"

const int ARMOR_SLOTS = 3;
const float LVL_ONE_XP = 100;

class Player
{
private:
	MyString::String username;
	MyString::String password;

	float xp;
	float max_xp;
	unsigned int level;
	float health;

	Weapon* weapon;
	Armor** armor;
	
	Inventory inventory;

	void copy(const Player& other);
	void free();

protected:
	enum Type
	{
		WARRIOR,
		ARCHER,
		MAGE,
		UNKNOWN
	} type;
public:
	Player(MyString::String& username, MyString::String& password, float health);
	Player(MyString::String& username, MyString::String& password, float health, unsigned int level, int xp, int max_xp);
	Player(const Player& other);
	Player& operator=(const Player& other);
	~Player();

	const MyString::String& GetName() const;
	bool IsUser(const MyString::String& name, const MyString::String& pass) const;
	unsigned int GetLevel() const;
	float GetHealth() const;

	void AddXP(const float xp);

	bool PickWeapon(const MyString::String& weaponName);
	bool SetArmorSlot(const MyString::String& armorName, const int slot);

	virtual bool Attack(const Player& other) = 0;
	virtual bool TakeDamage(const Player& other) = 0;
};

