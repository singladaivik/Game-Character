#ifndef GAMECHARACTERADVANCED_H
#define GAMECHARACTERADVANCED_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class GameCharacter {
private:
	string name;
	int maxHealth;
	int healthPoints;
	int attackPoints;
	int defensePoints;
	bool isAlive;
	time_t lastSaveTime;

public:
	GameCharacter(const string& name, int maxHealth, int attackPoints, int defensePoints);
	const string& getName() const;
	int getMaxHealth() const;
	int getHealthPoints() const;
	int getAttackPoints() const;
	int getDefensePoints() const;
	bool getIsAlive() const;

	void takeDamage(int damage);
	void attack (GameCharacter& target);

	void displayDateTimeOfLastSave() const;
	void displayTimeSinceLastSave() const;

	GameCharacter operator+(const GameCharacter& other) const;
	bool operator>(const GameCharacter& other) const;
	bool operator<(const GameCharacter& other) const;

	friend ostream& operator<<(ostream& os, const GameCharacter& character);

	void saveToFile(const string& filename) const;
	void loadFromFile(const string& filename);

};

#endif

