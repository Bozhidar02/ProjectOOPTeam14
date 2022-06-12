#pragma once
#include "String.h"
#include "Weapon.h"
#include "Constants.h"

class Bow : public Weapon {
	void copy(const Bow&);
public:
	Bow(MyString::String);
	Bow(const Bow&);
	~Bow();
	Item* clone() const override;
	bool upgrade() override;
};