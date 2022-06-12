#include "Staff.h"

void Staff::copy(const Staff& other) {
	name = other.name;
	damage = other.damage;
	durability = other.durability;
}

Staff::Staff(MyString::String name) : Weapon(name, STAFF_DAMAGE, STAFF_DURABILITY) {
}

Staff::Staff(const Staff& other) {
	copy(other);
}

Item* Staff::clone() const{
	return new Staff(*this);
}

/*
	Staff cannot be upgraded
*/
bool Staff::upgrade() {
	return false;
}