#pragma once
#include <string>
#include <iostream>
#include "Weapon.h"  

using namespace std;

class Players
{
public:
	Players();
	void setName(string);
	string getName();

	void setHealth(int); //manually set healthpoints to a specific value
	void setHealthPoints(int);
	int getHealthPoints();

	void setAttack(double);

	void setAttackDamage(double);
	double getAttackDamage();

	void setDefense(double);
	double getDefense();

	void setDodgeChance(double);
	double getDodgeChance();

	//void setShield(int);
	//int getShield();

	void displayHealthPoints();
	void displayStats();

	void setChanceExtraHit(Weapon);
	double getChanceExtraHit();

protected:

	string name;
	double attackDamage; //how much damage you do
	double defense;
	int healthPoints;
	//Shield shield; //create this class or struct
	double dodgeChance;
	int damage; //how much damage you receive

	bool playerChar;
	double chanceExtraHit;


};

Players::Players() {

	name = "";
	attackDamage = 1;
	defense = 0.0;
	healthPoints = 100;
	//Shield shield; //create this class or struct
	dodgeChance = .1;
	damage = 0;
	playerChar = false;
	chanceExtraHit = 0.0;

}

void Players::setName(string userName) {
	name = userName;
}

string Players::getName() {

	return name;
}
//allows you to manually set the health points value
void Players::setHealth(int health) {
	healthPoints = health;
}
//resets health points after hit with damage as the argument taking defense into account
void Players::setHealthPoints(int damage) {
	
	double d = (damage * (1 - defense));
	//cout << d << endl;
	//cout << damage << endl;
	//cout << defense << endl;

	healthPoints -= (int) d;
	if (healthPoints < 0) {
		healthPoints = 0;
	}
}

int Players::getHealthPoints() {

	return healthPoints;
}

//hardcode the attack damage
void Players::setAttack(double attack) {
	attackDamage = attack;
}

//reset the attack damage after setting weapon
void Players::setAttackDamage(double attack) {
	attackDamage *= (1 + attack);
}

double Players::getAttackDamage() {

	return attackDamage;
}

//used to reset defense value with the argument value
void Players::setDefense(double d) {
	defense = d;
}

double Players::getDefense() {

	return defense;
}

//used to reset the chance of dodging (with a percentage in decimal form)
void Players::setDodgeChance(double dodge) {
	dodgeChance = dodge;
}

double Players::getDodgeChance() {

	return dodgeChance;
}

//resets chance of extra hit of character to add the weapon's chance of extra hit with the weapon as the argument
void Players::setChanceExtraHit(Weapon weapon) {
	chanceExtraHit = chanceExtraHit + weapon.getChanceTwoHits();
}

//returns the chance (percent expressed as decimal) of getting an extra hit//FIX ME!!!! Needs to account for weapon chance of extra hit
double Players::getChanceExtraHit() {

	return chanceExtraHit;
}

//print statement to show how many health points monsters have (PlayerCharacter has its own function)
void Players::displayHealthPoints() {
	if (getHealthPoints() > 0) {
		cout << getName() << " has " << getHealthPoints() << endl;
	}
	else {
		cout << getName() << " has 0 Health Points remaining." << endl;
	}
}

//displays stats for Monsters and PlayerCharacters
void Players::displayStats() {
	cout << "Name: " << name << endl;
	cout << "Attack Damage: " << attackDamage << endl;
	cout << "Defense: " << defense*100 << "% " << endl;;
	cout << "Health Points: " << healthPoints << endl;
	cout << "Chance to Dodge: " << dodgeChance*100 << "%" << endl;
}


