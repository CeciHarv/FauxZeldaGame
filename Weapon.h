#pragma once
#include <string>

using namespace std;

class Weapon
{
public:
	void setDamage(double);
	double getDamage();
	void setChanceTwoHits(double);
	double getChanceTwoHits();
	void displayWeapon();
protected:
	string name = "";
	bool twoHanded = false; //to determine whether you can use a shield or not
	double damage = .1; //% of extra damage (expressed as decimal) this weapon adds to your base damage
	double chanceTwoHits = 0.0; //%chance that this weapon will give you a second hit

};

//takes the weapon's Damage as an argument and adds it to the Player's damage
void Weapon::setDamage(double weaponDamage) {
	damage = weaponDamage;
}

double Weapon::getDamage() {
	return damage;
}

//sets value for weapon chance of two hits (% expressed as decimal)
void Weapon::setChanceTwoHits(double chance) {
	chanceTwoHits = chance;
}

double Weapon::getChanceTwoHits() {
	return chanceTwoHits;	
}

void Weapon::displayWeapon() {
	cout << "Name: " << name << endl;
	//cout << "Two-Handed: " << twoHanded << endl;
	cout << "Damage rating: plus " << damage * 100 << "% damage" << endl;
	cout << "Chance for an Extra Hit: " << chanceTwoHits * 100 << "% " << endl;
}

class Sword : public Weapon
{
public: 
	Sword() : Weapon() {
		twoHanded = false;
		damage = .1;
		name = "Sword";
		chanceTwoHits = 0.50;
	};

private:

};

class Claymore : public Weapon
{
public:
	Claymore() : Weapon() {
		twoHanded = true;
		damage = .2;
		name = "Claymore";
		chanceTwoHits = 0.1;
	};

private:

};

class Bow : public Weapon
{
public:
	Bow() : Weapon() {
		twoHanded = true;
		damage = .15;
		name = "Bow";
		chanceTwoHits = 0.25;
	};

private:

};