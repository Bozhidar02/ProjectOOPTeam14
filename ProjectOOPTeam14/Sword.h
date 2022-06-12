#pragma once
#include "String.h"
#include "Weapon.h"
#include "Constants.h"

class Sword : public Weapon {
private:
	void copy(const Sword&);
public:
	Sword(MyString::String);
	Sword(const Sword&);
	Weapon* clone() override;
	bool upgrade() override;
};