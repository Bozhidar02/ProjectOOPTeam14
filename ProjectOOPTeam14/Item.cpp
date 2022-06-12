#include "Item.h"

Item::Item(MyString::String name, const double durability, const int level) {
	this->name = name;
	this->maxdurability = durability;
	this->durability = durability;
	this->level = level;
}

Item::Item(const Item& other) {
	name = other.name;
	maxdurability = other.maxdurability;
	durability = other.durability;
	level = other.level;
}

Item::~Item()
{
}

MyString::String Item::getName() const {
	return name;
}

double Item::getMaxDurability() const {
	return maxdurability;
}

double Item::getDurability() const {
	return durability;
}
