#include "Weapon.h"

Weapon::Weapon(): Item(MyString::String("Undefined weapon"), 0, 0) {
	damage = 0;
	type = Type::WEAPON;
}

Weapon::Weapon(MyString::String name, double damage, double durability) : Item(name, durability, 1) {
	this->damage = damage;
	type = Type::WEAPON;
}

double Weapon::use() {
	if (durability == 0) {
		return -1; // Cannot attack opponent
	}
	const double hitDamage = damage - (maxdurability - durability) * 0.1;
	if (maxdurability != -1) {
		durability -= 1;
	}
	return hitDamage;
}

double Weapon::getDamage() const {
	return damage;
}