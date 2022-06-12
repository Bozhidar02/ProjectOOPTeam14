#include "Helmet.h"

void Helmet::copy(const Helmet& other) {
	name = other.name;
	ap = other.ap;
	durability = other.durability;
}

Helmet::Helmet(MyString::String name) : Armor(name, HELMET_AP, HELMET_DURABILITY) {
}

Helmet::Helmet(const Helmet& other) {
	copy(other);
}

Armor* Helmet::clone() {
	return new Helmet(*this);
}

bool Helmet::upgrade() {
	if (ap + 5 > HELMET_MAX_AP) {
		return false;
	}
	ap += 5;
	durability = maxdurability;
	level++;
	return true;
}