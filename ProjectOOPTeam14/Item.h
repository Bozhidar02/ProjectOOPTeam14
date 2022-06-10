#pragma once
#include "String.h"

class Item {
protected:
	MyString::String name;
	double maxdurability;// maximum durability item has. -1 means it is unbreakable
	double durability;
public:
	Item(MyString::String name, const double maxdurability = 0, const double durability = 0);
	Item(const Item& other);

	virtual double use() = 0;
};