#pragma once
#include "Weapon.h"
#include "Armor.h"

class Inventory
{
private:
	Item** weapons;
	int capacity, size;

	void free();
	void copy(const Inventory& other);
	void resize();
public:
	Inventory();
	Inventory(const Inventory& other);
	Inventory& operator=(const Inventory& other);
	~Inventory();

	Item* FindItem(const MyString::String& name);

	bool AddItem(const Item* item);
	bool RemoveItem(const int index);

	Item* DropRandom();
};
