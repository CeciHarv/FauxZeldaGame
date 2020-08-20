#pragma once
#include "Players.h"
#include <string>

using namespace std;

class PlayerCharacter : 
	public Players
{
public:
	PlayerCharacter() : Players() {};
	void setWeapon(int);
	Weapon getWeapon();
	void displayHealthPoints();

private:
	bool playerChar = true;
	int healthPoints = 100;
	Weapon 	weaponEquipped;
};

void PlayerCharacter::displayHealthPoints() {
	cout << getName() << " has " << getHealthPoints() << "/100 Health Points now. " << endl;
}

void PlayerCharacter::setWeapon(int weaponChoice) {
	enum { SWORD = 1, CLAYMORE, BOW};

	switch (weaponChoice) {
	case SWORD: {
		Sword swordEquipped = Sword();
		cout << "TEST WEAPON VALUES: "; 
		swordEquipped.displayWeapon();
		setAttackDamage(swordEquipped.getDamage());
		//cout << endl << "TEST ATTACK DAMAGE calculated in PlayerCharacter setWeapon Function: " << attackDamage << endl;
		setChanceExtraHit(swordEquipped);
		break;
	}
	case CLAYMORE: {
		Claymore claymoreEquipped = Claymore();
		attackDamage = attackDamage * (1 + claymoreEquipped.getDamage());
		chanceExtraHit = claymoreEquipped.getChanceTwoHits();
		//cout << endl << "TEST ATTACK DAMAGE calculated in PlayerCharacter setWeapon Function: " << attackDamage << endl;
		break;
	}
	case BOW: {
		Bow bowEquipped = Bow();
		attackDamage = attackDamage * (1 + bowEquipped.getDamage());
		chanceExtraHit = bowEquipped.getChanceTwoHits();
		//cout << endl << "TEST ATTACK DAMAGE calculated in PlayerCharacter setWeapon Function: " << attackDamage << endl;
		break;
	}
	default:
		break;
	}
}


Weapon PlayerCharacter::getWeapon() {
	return weaponEquipped;
}



