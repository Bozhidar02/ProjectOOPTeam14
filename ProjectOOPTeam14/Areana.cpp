#include "Areana.h"

Areana::Areana(){
	capacity = 4;
	size = 0;
	chars = new Player * [capacity];
	player = new Player* [1];
	MyString::String name = "Archer" , password = "archer";
	Archer archer(name, password, 50, 100, 100, 1, 0, 900);
	this->addPlayerArcher(archer);
	//Finish up here. Add bow for archer, medium armour 
	//chars[0]->GetInventory().AddItem();
	name = "Mage", password = "archer";
	Mage mage(name, password, 25, 300, 1, 0, 900);
	this->addPlayerMage(mage);
	//Add staff and light armour
	name = "Warrior", password = "warrior";
	Warrior warrior(name, password, 100, 1, 0, 900);
	this->addPlayerWarrior(warrior);
	//Add sword and heavy armour
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

bool Areana::fight(Player* player, Player& opponent) {
	return player->Attack(opponent);
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
		//warrior.GetInventory().AddItem(); add sword and heavy armor
		this->addPlayerWarrior(warrior);
	}
	else if (pick == 2) {
		Mage mage(name, password);
		//mage.GetInventory().AddItem(); add staff and light armor
		this->addPlayerMage(mage);
	}
	else if (pick == 3) {
		Archer archer(name, password);
		//archer.GetInventory().AddItem(); add staff and light armor
		this->addPlayerArcher(archer);
	}

}

void Areana::quickmatch(){
	printallchars();
	std::cout << "Choose a character or create a new one. To create new character select -1."<<std::endl;
	//finish up here. Remember: i-1 for charcter select
	size_t selection;
	std::cin >> selection;
	selection++;
	bool selecmade = false;
	if (selection == -1) {
		createchar();
		this->player[0] = chars[size];
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
	int opp = rand() % size;
	if (fight(player[0], *chars[opp])) {
		std::cout << "You won!" << std::endl;
	}
	else {
		std::cout << "You lost!" << std::endl;
	}
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


