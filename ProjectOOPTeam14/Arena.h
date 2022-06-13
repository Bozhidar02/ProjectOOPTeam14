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
//the Arena is where the gameplay happens

class Arena {
	Player** chars;
	Player** player;
	size_t size, capacity;
	bool first;

public:
	Arena();
	~Arena();
	void addPlayerArcher(const Archer&);
	void addPlayerMage(const Mage&);
	void addPlayerWarrior(const Warrior&);
	void printallchars();
	void createchar();
	void quickmatch();
private:
	void free();
	void resize();
};