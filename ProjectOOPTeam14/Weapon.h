#pragma once
#include "String.h"
#include "Item.h"

class Weapon : public Item {
protected:
	double damage;
public:
	Weapon();
	Weapon(MyString::String, double, double);
	virtual double use() override;
	virtual bool upgrade() = 0;
	virtual Weapon* clone() = 0;

	double getDamage() const;
};