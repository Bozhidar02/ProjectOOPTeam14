#include "Boots.h"

void Boots::copy(const Boots& other) {
	name = other.name;
	ap = other.ap;
	durability = other.durability;
}

Boots::Boots(MyString::String name) : Armor(name, BOOTS_AP, BOOTS_DURABILITY) {
}

Boots::Boots(const Boots& other) {
	copy(other);
}

Boots::~Boots()
{
}

Item* Boots::clone() const {
	return new Boots(*this);
}

bool Boots::upgrade() {
	if (ap + 5 > BOOTS_MAX_AP) {
		return false;
	}
	ap += 5;
	durability = maxdurability;
	level++;
	return true;
}