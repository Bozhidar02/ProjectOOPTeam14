#pragma once
#include "Vector.h"
#include "String.h"
#include "Player.h"
#include "Mage.h"
#include "Warrior.h"
#include "Archer.h"
#include "Inventory.h"
#include "Bow.h"
#include "Sword.h"
#include "Staff.h"
#include "Helmet.h"
#include "Breastplate.h"
#include "Boots.h"
//the areana is where the gameplay happens

class Areana {
	Player** chars;
	Player** player;
	size_t size, capacity;

public:
	Areana();
	~Areana();
	void addPlayerArcher(Archer newchar);
	void addPlayerMage(Mage newchar);
	void addPlayerWarrior(Warrior newchar);
	void printallchars();
	void createchar();
	Weapon* pickweapon();
	void quickmatch();
private:
	void free();
	void resize();
};