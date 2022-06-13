#include "Menu.h"
#include "Arena.h"

void menuoptions() {
	std::cout << "What would you like to do? (press the index button to select)" << std::endl;
	std::cout << "1. Play Quickmatch" << std::endl;
	std::cout << "2. Tutorial" << std::endl;
	std::cout << "3. Quit " << std::endl;
}

void tutorial() {
	std::cout << "How to play?" << std::endl;
	std::cout << "When quick match is selected you can chose one of 3 predetermined charcters or create a new one" << std::endl;
	std::cout << "There are 3 charachter classes: - warrior, archer and mage." << std::endl;
	std::cout << "There are 2 types of equipment: - weapons and armor." << std::endl;
	std::cout << "There are 3 weapon types: - sword, bow and staff." << std::endl;
	std::cout << "There are 3 types of armor pices: helmet, brestplate, boots" << std::endl;
	std::cout << "Every piece of equipment has durability that is decresed with each use when the durability reaches zero the item is no longer usable" << std::endl;
	std::cout << "The player has an inventory where all items are stored " << std::endl;
	std::cout << "Combat begins when the player has chosen his character" << std::endl;
	std::cout << "If the player wins they earn a random item from their opponent's inventory" << std::endl;
	std::cout << "When the qiuckmatch is over the player has the option to play again" << std::endl;
}

int menu() {
	size_t option;
	std::cout << "Welcome to the arean!" << std::endl;
	//std::cout << "Menu start" << std::endl;
	Arena arena;
	while (true)
	{
		menuoptions();
		std::cin >> option;
		if (option == 1) {
			arena.quickmatch();
			/*std::cout << "Game over" << std::endl;
			return 0;*/
		}
		else if (option == 2) {
			tutorial();//print instructions of how the game plays
		}
		else if (option == 3) {
			return 0;
		}
		else {
			std::cout << "Not an available command";
		}
	}
}