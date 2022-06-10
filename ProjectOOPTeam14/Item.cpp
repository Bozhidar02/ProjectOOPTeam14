#include "Item.h"

Item::Item(MyString::String name, const double maxdurability = 0, const double durability = 0) {
	this->name = name;
	this->maxdurability = maxdurability;
	this->durability = durability;
}

Item::Item(const Item& other) {
	name = other.name;
	maxdurability = other.maxdurability;
	durability = other.durability;
}
