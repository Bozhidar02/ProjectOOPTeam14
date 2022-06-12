#pragma once
#include "String.h"
#include "Armor.h"
#include "Constants.h"

class Boots : public Armor {
private:
	void copy(const Boots&);
public:
	Boots(MyString::String);
	Boots(const Boots&);
	Armor* clone() override;
	bool upgrade() override;
};