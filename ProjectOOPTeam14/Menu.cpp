#include "Menu.h"
#include "Areana.h"

void menuoptions(){
	std::cout << "What would you like to do? (press the index button to select)" << std::endl;
	std::cout << "1. Play Quickmatch" << std::endl;
	std::cout << "2. Tutorial (maybe add?)" << std::endl;
	std::cout << "3. Quit " << std::endl;
}

void menu() {
	size_t option;
	std::cout << "Welcome to the arean!" << std::endl;
	while (true) {
		menuoptions();
		std::cin >> option;
		if (option == 1) {
			Areana areana;
			areana.quickmatch();
		}
		else if (option == 2) {
			//tutorial? print instructions of how the game plays
		}
		else if (option == 3) {
			return;
		}
		else {
			std::cout << "Not an available command";
		}

	}
}