#pragma once
#include "String.h"
#include "Weapon.h"
#include "Constants.h"

class Staff : public Weapon {
private:
	void copy(const Staff&);
public:
	Staff(MyString::String);
	Staff(const Staff&);
	Item* clone() const override;
	bool upgrade() override;
};