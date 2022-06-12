#include "Inventory.h"

void Inventory::free()
{
	for (int i = 0; i < size; i++)
	{
		delete items[i];
	}
	delete[] items;
}

void Inventory::copy(const Inventory& other)
{
	size = other.size;
	items = new Item * [size];
	for (int i = 0; i < size; i++)
	{
		items[i] = other.items[i]->clone();
	}
}

void Inventory::resize()
{
	size *= 2;
	Item** temp = new Item * [size];
	for (int i = 0; i < capacity; i++)
	{
		temp[i] = items[i];
	}
	delete[] items;
	items = temp;
	temp = nullptr;
}

Inventory::Inventory()
{
	size = 5;
	items = new Item * [size];
	capacity = 0;
}

Inventory::Inventory(const Inventory& other)
{
	copy(other);
}

Inventory& Inventory::operator=(const Inventory& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Inventory::~Inventory()
{
	free();
}

Item* Inventory::FindItem(const MyString::String& name)
{
	for (int i = 0; i < capacity; i++)
	{
		if (items[i]->getName() == name)
		{
			return items[i];
		}
	}
}

bool Inventory::AddItem(Item* item)
{
	if (item == nullptr)
	{
		return false;
	}

	if (capacity >= size)
	{
		resize();
	}

	items[capacity++] = item;
	return true;
}

bool Inventory::RemoveItem(const int index)
{
	if (index < 0 || index > capacity)
	{
		return false;
	}
	delete items[index];
	items[index] = items[capacity - 1];
	items[capacity--] = nullptr;
	
	return true;
}

Item* Inventory::DropRandom()
{
	srand(time(nullptr));

	int ind = rand() % (capacity - 1);
	if (ind < 0 || ind >= capacity)
	{
		return nullptr;
	}
	Item* item = items[ind]->clone();
	RemoveItem(ind);

	return item;
}

void Inventory::display() const
{
	for (int i = 0; i < capacity; i++)
	{
		std::cout << items[i]->getName() << " durability: " << items[i]->getDurability();
		if (items[i]->type == Item::Type::WEAPON)
		{
			std::cout << " Damage: " << dynamic_cast<Weapon*>(items[i])->getDamage() << '\n';
		}
		if (items[i]->type == Item::Type::ARMOR)
		{
			std::cout << " Defence: " << dynamic_cast<Armor*>(items[i])->getAp() << '\n';
		}
	}
}
