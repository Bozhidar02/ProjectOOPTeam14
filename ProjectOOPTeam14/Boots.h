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
	~Boots();
	Item* clone() const override;
	bool upgrade() override;
};