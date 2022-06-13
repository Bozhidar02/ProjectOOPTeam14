#pragma once
#include "Weapon.h"
#include "Armor.h"

class Inventory
{
private:
	Item** items;
	int size, capacity;

	void free();
	void copy(const Inventory& other);
	void resize();
public:
	Inventory();
	Inventory(const Inventory& other);
	Inventory& operator=(const Inventory& other);
	~Inventory();

	Item* FindItem(const MyString::String& name);
	bool checkAvailabale(const MyString::String& name);

	bool AddItem(Item* item);
	bool RemoveItem(const int index);

	Item* DropRandom();

	void display() const;
};
