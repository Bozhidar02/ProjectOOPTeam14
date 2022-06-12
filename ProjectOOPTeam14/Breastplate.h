#pragma once
#include "String.h"
#include "Armor.h"
#include "Constants.h"

class Breastplate : public Armor {
private:
	void copy(const Breastplate&);
public:
	Breastplate(MyString::String);
	Breastplate(const Breastplate&);
	~Breastplate();
	Item* clone() const override;
	bool upgrade() override;
};