#include "Areana.h"

Areana::Areana(){
	capacity = 4;
	size = -1;
	chars = new Player * [capacity];
	player = new Player* [1];
	MyString::String name = "Archer" , password = "archer";
	Archer archer(name, password, 50, 100, 100, 1, 0, 900);
	this->addPlayerArcher(archer);
	Bow bow("Bow");
	Breastplate bp("Breatsplate");
	Boots boot("Boots");
	chars[0]->GetInventory().AddItem(&bow);
	chars[0]->GetInventory().AddItem(&bp);
	chars[0]->GetInventory().AddItem(&boot);
	//Finish up here. Add bow for archer, medium armour 
	name = "Mage", password = "archer";
	Mage mage(name, password, 25, 300, 1, 0, 900);
	this->addPlayerMage(mage);
	Staff staff("staff");
	chars[1]->GetInventory().AddItem(&staff);
	chars[1]->GetInventory().AddItem(&boot);
	name = "Warrior", password = "warrior";
	Warrior warrior(name, password, 100, 1, 0, 100, 900);
	this->addPlayerWarrior(warrior);
	//Add sword and heavy armour
	Sword sword("sword");
	Helmet helmet("helmet");
	chars[2]->GetInventory().AddItem(&sword);
	chars[2]->GetInventory().AddItem(&helmet);
	chars[2]->GetInventory().AddItem(&bp);
	chars[2]->GetInventory().AddItem(&boot);
}

Areana::~Areana() {
	free();
}

void Areana::addPlayerArcher(Archer newchar){
	if (size+1 > capacity) {
		resize();
	}
	chars[this->size++] = newchar.clone();
}

void Areana::addPlayerMage(Mage newchar) {
	if (size + 1 > capacity) {
		resize();
	}
	chars[this->size++] = newchar.clone();
}

void Areana::addPlayerWarrior(Warrior newchar) {
	if (size + 1 > capacity) {
		resize();
	}
	chars[this->size++] = newchar.clone();
}

void Areana::printallchars(){
	for (int i = 0; i < size; i++) {//add password
		std::cout << i << ". Name: " << chars[i]->GetName() << " level:" << chars[i]->GetLevel() << " Power:" << chars[i]->GetPower() << std::endl;
	}
}

//buffer 
MyString::String getStringfrominput() {
	int maxsize = 1024;
	char* buffer = new char[maxsize];
	std::cin.ignore();
	std::cin.getline(buffer, maxsize);
	int size = strlen(buffer);
	char* arr = new char[size+1];
	strcpy_s(arr, size+1, buffer);
	MyString::String was(arr);
	return was;
}

void Areana::createchar(){
	std::cout << "Pick a class:" << std::endl;
	std::cout << "1>Warrior, 2>Mage, 3>Archer"<<std::endl;
	size_t pick;
	std::cin >> pick;
	while (pick > 3) {
		std::cout << "Invalid command:"<<std::endl;
		std::cin >> pick;
	}
	MyString::String name, password;
	std::cout << "Enter name of char" << std::endl;
	name = getStringfrominput();//buffer
	std::cout << "Enter password for character" << std::endl;
	password = getStringfrominput();//buffer
	if (pick == 1) {
		Warrior warrior(name, password);//make is a full construct?
		Sword sword("sword");
		Helmet helmet("helmet");
		Breastplate bp("breastplate");
		Boots boot("boots");
		warrior.GetInventory().AddItem(&sword);
		warrior.GetInventory().AddItem(&helmet);
		warrior.GetInventory().AddItem(&bp);
		warrior.GetInventory().AddItem(&boot);
		this->addPlayerWarrior(warrior);
	}
	else if (pick == 2) {
		Mage mage(name, password);
		Staff staff("staff");
		Boots boot("boots");
		mage.GetInventory().AddItem(&staff);
		mage.GetInventory().AddItem(&boot);
		this->addPlayerMage(mage);
		chars[size]->GetInventory().AddItem(&staff);
		chars[size]->GetInventory().AddItem(&boot);
	}
	else if (pick == 3) {
		Archer archer(name, password);
		Bow bow("bow");
		Breastplate bp("breastplate");
		Boots boot("boots");
		archer.GetInventory().AddItem(&bow);
		archer.GetInventory().AddItem(&bp);
		archer.GetInventory().AddItem(&boot);
		this->addPlayerArcher(archer);
	}
}


void Areana::quickmatch(){
	printallchars();
	std::cout << "Choose a character or create a new one. To create new character select -1."<<std::endl;
	size_t selection;
	std::cin >> selection;
	selection++;
	bool selecmade = false;
	if (selection == -1) {
		createchar();
		this->player[0] = chars[size];//create charc
	}
	while (true) {
		for (int i = 0; i < size; i++) {
			if (i == selection) {
			
			}
			this->player[0] = chars[i];
		}
		std::cout << "No such command. Enter another index of existing character" << std::endl;
		std::cin >>selection;
	}
	player[0]->GetInventory().display();
	std::cout << "Select a weapon to equip" << std::endl;
	MyString::String weapon = getStringfrominput();
	player[0]->PickWeapon(weapon);
	std::cout << "Would you like to equip armour? y/n" << std::endl;
	char ans;
	
	while (ans == 'y') {
		std::cout << "Select armor slot to equip: 0>head, 1>torso, 2>legs" << std::endl;
		size_t as;
		std::cin >> as;
		MyString::String name = getStringfrominput();
		player[0]->SetArmorSlot(name, as);
		std::cout << "Would you like to equip another pice of armor?" << std::endl;
		std::cin >> ans;
	}
	int opp = rand() % size;
	MyString::String cool = chars[opp]->getType();
	if (cool == "WARRIOR") {
		chars[opp]->PickWeapon("sword");
		chars[opp]->SetArmorSlot("helmet", 0);
		chars[opp]->SetArmorSlot("brestplate", 1);
		chars[opp]->SetArmorSlot("boots", 2);
	}
	else if (cool == "ARCHER") {
		chars[opp]->PickWeapon("bow");
		chars[opp]->SetArmorSlot("brestplate", 1);
		chars[opp]->SetArmorSlot("boots", 2);
	}
	else if (cool == "MAGE") {
		chars[opp]->PickWeapon("staff");
		chars[opp]->SetArmorSlot("boots", 2);
	}
	player[0]->Attack(*chars[opp]);
	std::cout << "Would you like to fight again? y/n" << std::endl;
	char agree;
	std::cin >> agree;
	if (agree == 'y') {
		quickmatch();
	}
}

void Areana::free(){
	for (size_t i = 0; i < size; i++) {
		delete chars;
	}
	delete[] chars;
}

void Areana::resize(){
	Player** newCollection = new Player * [capacity *= 2];
	for (size_t i = 0; i < size; i++)
		newCollection[i] = chars[i];
	delete[] chars;
	chars = newCollection;
}


