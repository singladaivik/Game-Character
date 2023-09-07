#include "GameCharacterAdvanced.h"
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

GameCharacter::GameCharacter(const string& name, int maxHealth, int attackPoints, 
		int defensePoints)
	    : name(name), maxHealth(maxHealth), healthPoints(maxHealth), attackPoints(attackPoints),
	          defensePoints(defensePoints), isAlive(true) {}

const string& GameCharacter::getName() const {
	return name;
}
int GameCharacter::getMaxHealth() const {
	return maxHealth;
}
int GameCharacter::getHealthPoints() const {
	return healthPoints;
}
int GameCharacter::getAttackPoints() const {
	return attackPoints;
}
int GameCharacter::getDefensePoints() const {
	return defensePoints;
}
bool GameCharacter::getIsAlive() const {
	return isAlive;
}

void GameCharacter::takeDamage(int damage) {
       healthPoints -= damage;
	if (healthPoints <= 0) {
	 	healthPoints = 0;
		isAlive = false;
	}
}

void GameCharacter::attack(GameCharacter& target) {
	int damage = max(0, attackPoints - target.defensePoints);
	target.takeDamage(damage);
}

GameCharacter GameCharacter::operator+(const GameCharacter& other) const {
	string newName = name + "_" + other.name;
	int newMaxHealth = (maxHealth + other.maxHealth) / 2;
	int newAttackPoints = (attackPoints + other.attackPoints) / 2;
	int newDefensePoints = (defensePoints + other.defensePoints) / 2;
	return GameCharacter(newName, newMaxHealth, newAttackPoints, newDefensePoints);
}

bool GameCharacter::operator>(const GameCharacter& other) const {
	return healthPoints > other.healthPoints;
}

bool GameCharacter::operator<(const GameCharacter& other) const {
	return healthPoints < other.healthPoints;
}

ostream& operator<<(ostream& os, const GameCharacter& character) {
	os << "Name: " << character.name << "\n" << "Health: " << character.healthPoints << "/" << 
		character. maxHealth << "\n" << "Attack: " << character.attackPoints << "\n" << 
	       "Defense: " << character.defensePoints << "\n" << "Status: " << (character.isAlive ?
		       "Alive" : "Defeated") << endl;
	return os;
} 

void GameCharacter::displayDateTimeOfLastSave() const{
	time_t lastSaveTime = getLastSaveTime();
	cout << "Last Saved: " << ctime(&lastSaveTime);
}

void GameCharacter::displayTimeSinceLastSave() const {
	time_t lastSaveTime = getLastSaveTime();
	time_t currentTime = time(nullptr);
	double timeDiff = difftime(currentTime, lastSaveTime);
	cout << "Time Since Last Save: " << timeDiff << " seconds" << endl;
}

void GameCharacter::saveToFile(const string& filename) const {
	ofstream outFile(filename);
	if (outFile.fail()) {
		cout << "Failed to open file for writing." << endl;
		exit(1);
	}
	outFile << name << endl;
	outFile << maxHealth << endl;
	outFile << healthPoints << endl;
	outFile << attackPoints << endl;
	outFile << defensePoints << endl;
	outFile << isAlive << endl;
	outFile.close();
}

void GameCharacter::loadFromFile(const string& filename) {
	ifstream inFile(filename);
	if (inFile.fail()) {
		cout << "Failed to open file for reading." << endl;
		exit(1);
	}

	getline(inFile, name);
	inFile >> maxHealth;
	inFile >> healthPoints;
	inFile >> attackPoints;
	inFile >> defensePoints;
	inFile >> isAlive;
	inFile.close();
}





















