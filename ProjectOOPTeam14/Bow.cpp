#include "Bow.h"

void Bow::copy(const Bow& other) {
	name = other.name;
	damage = other.damage;
	durability = other.durability;
}

Bow::Bow(MyString::String name) : Weapon(name, BOW_DAMAGE, BOW_DURABILITY) {
}

Bow::Bow(const Bow& other) {
	copy(other);
}

Bow::~Bow()
{
}

Item* Bow::clone() const{
	return new Bow(*this);
}

/*
	Upgrades bow maxdurability by 15 units
	Maxes out durability
	Bow levels up
*/
bool Bow::upgrade() {
	if (maxdurability + 15 > BOW_MAX_DURABILITY) {
		return false;
	}
	maxdurability += 15;
	durability = maxdurability;
	level++;
	return true;
}