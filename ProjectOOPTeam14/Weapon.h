#pragma once
#include "String.h"
#include "Item.h"

class Weapon: public Item{
	double damage;
public:
	virtual double use() override;
	virtual Weapon* clone() = 0;
};