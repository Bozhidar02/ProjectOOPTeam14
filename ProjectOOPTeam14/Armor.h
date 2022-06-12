#pragma once
#include "String.h"
#include "Item.h"

class Armor: public Item {
protected:
	double ap; //armor points
public:
	Armor();
	Armor(MyString::String, double, double);
	virtual double use() override;
	virtual bool upgrade() = 0;
	virtual Item* clone() const = 0;

	double getAp() const;
};