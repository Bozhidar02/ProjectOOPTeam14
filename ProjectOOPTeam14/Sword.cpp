#include "Sword.h"

void Sword::copy(const Sword& other) {
	name = other.name;
	damage = other.damage;
	durability = other.durability;
}

Sword::Sword(MyString::String name) : Weapon(name, SWORD_DAMAGE, SWORD_DURABILITY) {
}

Sword::Sword(const Sword& other) {
	copy(other);
}

Item* Sword::clone() const{
	return new Sword(*this);
}

/* 
	Upgrades sword damage by 10 units
	Maxes out durability
	Sword levels up
*/
bool Sword::upgrade() {
	if (damage + 10 > SWORD_MAX_DAMAGE) {
		return false;
	}
	damage += 10;
	durability = maxdurability;
	level++;
	return true;
}