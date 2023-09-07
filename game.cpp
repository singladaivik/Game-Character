#include "GameCharacterAdvanced.h"
using namespace std;

int main() {	

	// Create characters
	GameCharacter character1("Warrior", 100, 20, 15);
	GameCharacter character2("Thief", 80, 25, 10);
	GameCharacter character3("Fighter", 90, 18, 20);

	// Simulate battles
	character1.attack(character2);
	character2.attack(character1);

	// Compare characters' health
	if (character1 > character2) {
		cout << character1.getName() << " is stronger." << endl;
	}
	else if (character2 > character1) {
		cout << character2.getName() << " is stronger." << endl;
	}
	else {
		cout << "Both characters have the same health." << endl;
	}

	// Display all characters
	cout << character1 << endl;
	cout << character2 << endl;
	cout << character3 << endl;

	// Save and Load
	character1.saveToFile("character1.txt");
	character3.loadFromFile("character1.txt");
	cout << "Character 3 loaded from file:\n" << character3;

	//Display Last Date Time
	character3.displayDateTimeOfLastSave();
	character3.displayTimeSinceLastSave();

	return 0;
}

