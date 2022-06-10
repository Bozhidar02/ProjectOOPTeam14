#pragma once
#include "String.h"
#include "Item.h"

class Weapon: public Item{
	double damage;
public:
	virtual void attack() = 0;
	virtual Weapon* clone() = 0;
};