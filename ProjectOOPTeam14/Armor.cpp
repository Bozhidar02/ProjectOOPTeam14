#include "Armor.h"

Armor::Armor(): Item(MyString::String("Undefined armor"), 0, 0) {
	ap = 0;
}

Armor::Armor(MyString::String name, double ap, double durability) : Item(name, durability, 1) {
	this->ap = ap;
}

double Armor::use() {
	if (durability == 0) {
		return -1; // Cannot use armor
	}
	const double protection = ap - (maxdurability - durability) * 0.1;
	if (maxdurability != -1) {
		durability -= 1;
	}
	return protection;
}

double Armor::getAp() const {
	return ap;
}