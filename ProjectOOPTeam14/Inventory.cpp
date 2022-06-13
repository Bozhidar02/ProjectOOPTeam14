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
	capacity = other.capacity;
	items = new Item * [capacity];
	size = other.size;
	for (int i = 0; i < size; i++)
	{
		items[i] = other.items[i]->clone();
	}
}

void Inventory::resize()
{
	capacity *= 2;
	Item** temp = new Item * [capacity];
	for (int i = 0; i < size; i++)
	{
		temp[i] = items[i];
	}
	delete[] items;
	items = temp;
}

Inventory::Inventory()
{
	srand((unsigned int)time(nullptr));
	capacity = 5;
	items = new Item * [capacity];
	size = 0;
}

Inventory::Inventory(const Inventory& other)
{
	srand((unsigned int)time(nullptr));
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

bool Inventory::checkAvailabale(const MyString::String& name) {
	for (int i = 0; i < size; i++)
	{
		if (items[i]->getName() == name)
		{
			return true;
		}
	}
	return false;
}

Item* Inventory::FindItem(const MyString::String& name)
{
	for (int i = 0; i < size; i++)
	{
		if (items[i]->getName() == name)
		{
			return items[i];
		}
	}
	return nullptr;
}

bool Inventory::AddItem(Item* item)
{
	if (item == nullptr)
	{
		return false;
	}

	if (size >= capacity)
	{
		resize();
	}

	items[size++] = item;
	return true;
}

bool Inventory::RemoveItem(const int index)
{
	if (index < 0 || index > size)
	{
		return false;
	}
	delete items[index];
	items[index] = items[size - 1];
	items[size-1] = nullptr;
	size--;
	return true;
}

Item* Inventory::DropRandom()
{
	int temp = size - 1;
	int ind = 0;
	if (temp != 0)
	{
		ind = rand() % temp;
	}
	
	if (ind < 0 || ind >= size)
	{
		return nullptr;
	}
	Item* item = items[ind]->clone();
	RemoveItem(ind);

	return item;
}

void Inventory::display() const
{
	for (int i = 0; i < size; i++)
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
