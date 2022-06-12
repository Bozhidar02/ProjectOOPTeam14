#include "Breastplate.h"

void Breastplate::copy(const Breastplate& other) {
	name = other.name;
	ap = other.ap;
	durability = other.durability;
}

Breastplate::Breastplate(MyString::String name) : Armor(name, BREASTPLATE_AP, BREASTPLATE_DURABILITY) {
}

Breastplate::Breastplate(const Breastplate& other) {
	copy(other);
}

Breastplate::~Breastplate()
{
}

Item* Breastplate::clone() const{
	return new Breastplate(*this);
}

bool Breastplate::upgrade() {
	if (ap + 10 > BREASTPLATE_MAX_AP) {
		return false;
	}
	ap += 10;
	durability = maxdurability;
	level++;
	return true;
}