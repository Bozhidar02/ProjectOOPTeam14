#include "Arena.h"

Arena::Arena(){
	srand((unsigned int)time(NULL));
	first = true;
	capacity = 4;
	size = 0;
	chars = new Player * [capacity];
	player = new Player* [1];
	MyString::String name = "Archer" , password = "archer";
	Archer archer(name, password, 50, 1, 100, 1, 1, 900);
	archer.GetInventory()->AddItem(new Bow("bow"));
	archer.GetInventory()->AddItem(new Breastplate("breastplate"));
	archer.GetInventory()->AddItem(new Boots("boots"));
	this->addPlayerArcher(archer);

	name = "Mage", password = "archer";
	Mage mage(name, password, 25, 1, 1, 1, 900);
	this->addPlayerMage(mage);
	chars[1]->GetInventory()->AddItem(new Staff("staff"));
	chars[1]->GetInventory()->AddItem(new Boots("boots"));

	name = "Warrior", password = "warrior";
	Warrior warrior(name, password, 100, 1, 1, 100, 900);
	this->addPlayerWarrior(warrior);
	//Add sword and heavy armour
	chars[2]->GetInventory()->AddItem(new Sword("sword"));
	chars[2]->GetInventory()->AddItem(new Helmet("helmet"));
	chars[2]->GetInventory()->AddItem(new Breastplate("breastplate"));
	chars[2]->GetInventory()->AddItem(new Boots("boots"));
}

Arena::~Arena() {
	free();
}

void Arena::addPlayerArcher(const Archer& newchar){

	if (size+1 > capacity) {
		resize();
	}

	chars[size++] = newchar.clone();
}

void Arena::addPlayerMage(const Mage& newchar) {
	if (size + 1 > capacity) {
		resize();
	}
	chars[size++] = newchar.clone();
}

void Arena::addPlayerWarrior(const Warrior& newchar) {
	if (size + 1 > capacity) {
		resize();
	}
	chars[size++] = newchar.clone();
	chars[size - 1]->GetInventory()->display();
}

void Arena::printallchars(){
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
	delete[] arr;
	delete[] buffer;
	return was;
}

void Arena::createchar(){
	MyString::String name, password;
	std::cout << "Enter username:" << std::endl;
	name = getStringfrominput();//buffer
	std::cout << "Enter password for character:" << std::endl;
	password = getStringfrominput();//buffer
	std::cout << "Pick a class:" << std::endl;
	std::cout << "1> Warrior, 2> Mage, 3> Archer"<<std::endl;
	size_t pick;
	std::cin >> pick;
	while (pick > 3) {
		std::cout << "Invalid command:"<<std::endl;
		std::cin >> pick;
	}
	if (pick == 1) {
		Warrior* warrior = new Warrior(name, password);//make is a full construct?
		warrior->GetInventory()->AddItem(new Sword("sword"));
		warrior->GetInventory()->AddItem(new Helmet("helmet"));
		warrior->GetInventory()->AddItem(new Breastplate("breastplate"));
		warrior->GetInventory()->AddItem(new Boots("boots"));
		this->player[0] = dynamic_cast<Player*>(warrior);
	}
	else if (pick == 2) {
		Mage* mage = new Mage(name, password);
		mage->GetInventory()->AddItem(new Staff("staff"));
		mage->GetInventory()->AddItem(new Boots("boots"));
		this->player[0] = dynamic_cast<Player*>(mage);
	}
	else if (pick == 3) {
		Archer* archer = new Archer(name, password);
		archer->GetInventory()->AddItem(new Bow("bow"));
		archer->GetInventory()->AddItem(new Breastplate("breastplate"));
		archer->GetInventory()->AddItem(new Boots("boots"));
		this->player[0] = dynamic_cast<Player*>(archer);
	}
}


void Arena::quickmatch() {
	if (this->first) {
		std::cout << "Registration " << std::endl;
		createchar();
		first = false;
	}
	std::cout << "Inventory: " << std::endl;
	this->player[0]->GetInventory()->display();
	std::cout << "Select a weapon to equip (u to go unarmed):" << std::endl;
	//MyString::String weapon = getStringfrominput();
	player[0]->PickWeapon(getStringfrominput());
	std::cout << "Would you like to equip armour? y/n" << std::endl;
	char ans;
	std::cin >> ans;
	while (ans == 'y') {
		std::cout << "Select armor slot to equip: 0> head, 1> torso, 2> legs" << std::endl;
		size_t as;
		std::cin >> as;
		std::cout << "Inventory: " << std::endl;
		this->player[0]->GetInventory()->display();
		std::cout << "Select item form inventory:" << std::endl;
		player[0]->SetArmorSlot(getStringfrominput(), as);
		std::cout << "Would you like to equip another pice of armor? y/n" << std::endl;
		std::cin >> ans;
	}
	int opp = rand() % (size - 1);
	MyString::String cool = chars[opp]->getType();
	if (cool == "WARRIOR") {
		chars[opp]->PickWeapon("sword");
		chars[opp]->SetArmorSlot("helmet", 0);
		chars[opp]->SetArmorSlot("breastplate", 1);
		chars[opp]->SetArmorSlot("boots", 2);
	}
	else if (cool == "ARCHER") {
		chars[opp]->PickWeapon("bow");
		chars[opp]->SetArmorSlot("breastplate", 1);
		chars[opp]->SetArmorSlot("boots", 2);
	}
	else if (cool == "MAGE") {
		chars[opp]->PickWeapon("staff");
		chars[opp]->SetArmorSlot("boots", 2);
	}
	std::cout << "\nResult: \n";
	player[0]->Attack(chars[opp]);
	std::cout << '\n';
}

void Arena::free(){
	for (size_t i = 0; i < size; i++) {
		delete chars[i];
	}
	delete[] chars;
	delete player[0];
	delete[] player;
}

void Arena::resize(){
	Player** newCollection = new Player * [capacity *= 2];
	for (size_t i = 0; i < size; i++)
		newCollection[i] = chars[i];
	delete[] chars;
	chars = newCollection;
}


