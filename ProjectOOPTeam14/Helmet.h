#pragma once
#include "String.h"
#include "Armor.h"
#include "Constants.h"

class Helmet : public Armor {
private:
	void copy(const Helmet&);
public:
	Helmet(MyString::String);
	Helmet(const Helmet&);
	~Helmet();
	Item* clone() const override;
	bool upgrade() override;
};