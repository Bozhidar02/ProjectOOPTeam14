#pragma once
#include "String.h"
#include "Item.h"

class Armor: public Item {
	double ap;//armour points
public:
	virtual double use() override;
	virtual Armor* clone() = 0;
};