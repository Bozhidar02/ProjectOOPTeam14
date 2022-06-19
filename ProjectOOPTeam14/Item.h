#pragma once
#include "String.h"

class Item {
protected:
	MyString::String name;
	double maxdurability;// maximum durability item has. -1 means it is unbreakable
	double durability;
	int level;
public:
	Item(MyString::String, const double, const int);
	Item(const Item&);
	virtual ~Item();
	enum Type
	{
		WEAPON,
		ARMOR
	}type;

	virtual double use() = 0;

	MyString::String getName() const;
	double getMaxDurability() const;
	double getDurability() const;

	virtual Item* clone() const = 0;
};
