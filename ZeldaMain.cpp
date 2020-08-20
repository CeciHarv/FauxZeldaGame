#include "Players.h"
#include "PlayerCharacter.h"
#include "Monsters.h"
#include "Weapon.h"
#include <string>
#include <iostream>
#include <time.h>

using namespace std;
Monsters setEnemy();
void setCharacter(PlayerCharacter&, int);
void userTurn();
bool extraHit(double);
bool dodge(double);

int main() {

	//declare vars
	srand(time(NULL)); //seeding random
	string play;
	int choice;
	PlayerCharacter user;
	Monsters currentEnemy;

	cout << "Welcome to a Poor Man's Zelda" << endl << "Ready to play?" << endl;//print welcome statement
	cin >> play;
	
	play[0] = tolower(play[0]);

	//loop if they want to play
	while (play[0] == 'y') {
		
		//reset PlayerCharacter HP
		user.setHealth(100);

		//print character menu and choose character to play
		cout << "Which character would you like to play? " << endl;
		cout << "1. Link \n2. Zelda \n3. Tingle \n";
		cin >> choice;//receive character choice input
		
		
		setCharacter(user, choice); //set player character 

		//choose weapon
		int chosenWeapon;
		cout << endl << "Choose your weapon: " << endl;    //ask character what weapon they would like to use
		cout << "1. Sword \n2.Claymore \n3.Bow" << endl;
		cin >> chosenWeapon;		//receive weapon input
		user.setWeapon(chosenWeapon); //setWeapon calculated attack value correctly
		user.displayStats();
		string carryOn;

			
		cout << "\nGet ready to fight..." << endl;//assign a random enemy to fight
		currentEnemy = setEnemy(); 

		while (user.getHealthPoints() > 0 && currentEnemy.getHealthPoints() > 0) {//press enter to start the fight
								
			//cout << endl << "TEST: this is the user attack damage " << user.getAttackDamage() << endl;
			//cout << "TEST: this is the current enemy defense " << currentEnemy.getDefense() << endl;
			cout << "Press any key + Enter to attack.";
			cin >> carryOn;

			cout << "\nYou attack! " << endl;  //you attack first
			//cout << (int) (user.getAttackDamage() * (1 - currentEnemy.getDefense())); 
			//cout << " damage to the ";
			//cout << currentEnemy.getName(); 

			if (dodge(currentEnemy.getDodgeChance())) {
				cout << "The " << currentEnemy.getName() << " is wiley. It dodged your attack. " << endl;
				currentEnemy.setHealthPoints(0);
			}
			else {
				cout << "You do " << (int)user.getAttackDamage() * (1 - currentEnemy.getDefense()) << " damage." << endl;//you attack monster
				currentEnemy.setHealthPoints(user.getAttackDamage());
			}

			cout << "The " << currentEnemy.getName() << "'s Health Points are down to " << currentEnemy.getHealthPoints() << endl;//prints the damage done, and the new stat values for monster	
			if (currentEnemy.getHealthPoints() < 1) {
				cout << "You won! You have vanquished your foe!" << endl;
				break;
			}
				
			//if extraHit() returns true you get an extra hit
			if (extraHit(user.getChanceExtraHit())) {
				cout << "You get in another hit before the " << currentEnemy.getName() << " can retaliate!" << endl;
				currentEnemy.setHealthPoints(user.getAttackDamage());	//you attack first
				cout << " The " << currentEnemy.getName() << "'s Health Points are down to " << currentEnemy.getHealthPoints() << endl;//prints the damage done, and the new stat values for monster
			}
			if (currentEnemy.getHealthPoints() < 1) {
				cout << endl << "\nYOU WIN! You have vanquished your foe!";
				break;
			}
			
			//end of user turn

			//cout << endl << "TEST: this is the enemy attack damage " << currentEnemy.getAttackDamage() << endl;
			//cout << "TEST: this is the current user defense " << user.getDefense() << endl;
			cout << "\nThe " << currentEnemy.getName() << " strikes. " << endl; 
			
			//if the character dodges, then don't subtract any hit points
			if (dodge(user.getDodgeChance())) {
				cout << "Smooth move! You dodged the attack. " << endl;
				user.setHealthPoints(0);
			}
			else {
				cout << "It does " << (int) currentEnemy.getAttackDamage()* (1-user.getDefense()) << " damage." << endl;//monster attacks you 
				user.setHealthPoints(currentEnemy.getAttackDamage());
			}

			user.displayHealthPoints();
			
			if (user.getHealthPoints() < 1) {
				cout << endl << "\nGAME OVER! \nYou dun got keeld.";
				break;
			}//prints out if you dodged, or if it hit you. Prints out damage done. Prints out your updated stats
			//end loop after either your HP or the monster's HP is 0
		}
		//announce the winner

		cout << endl << "Would you like to play again? " << endl;
		cin >> play;
		play[0] = tolower(play[0]);
	} //end while loop for if they want to play the game. 
	
	 //graceful closing
	cout << "Thank you for playing a Poor Man's Zelda!" << endl;

	return 0;
}

//sets the values of the player character //FIX ME!!! It's not calculating attack damage correctly
void setCharacter(PlayerCharacter& user, int choice) {

	user;
	if (choice == 1) {

		user.setName("Link");
		user.setAttack(40); //manually sets the attack damage for the user with the argument value
		user.setDefense(0.40);
		user.setDodgeChance(.2);
		cout << "You're playing as " << user.getName() << endl;
	}

	else if (choice == 2) {
		user.setName("Zelda");
		user.setAttack(30);
		user.setDefense(0.50);
		user.setDodgeChance(.3);
		cout << "You're playing as " << user.getName() << endl;
	}

	else if (choice == 3) {

		user.setName("Tingle");
		user.setAttack(20);
		user.setDefense(0.60);
		user.setDodgeChance(.4);
		cout << "You're playing as " << user.getName() << endl;
	}

	else {
		cout << "Maybe another time, then?" << endl;
	}

}

Monsters setEnemy() {
	int randEnemy = rand() % 5 + 1; //randomly choose a mob to fight
			//cout << "This is the random number I just generated: " << randEnemy << endl;//TESTING RANDOM NUMBER GENERATOR
	Monsters currentEnemy;
	enum enemy { BOKOBLIN, LIZALFO, MOBLIN, HINOX, GUARDIAN, LIONEL };

	switch (randEnemy) { //enemy chosen from the enemy enum
	case BOKOBLIN: {
		currentEnemy = Bokoblin();	
		currentEnemy.displayStats();
		break;
	}
	case LIZALFO: {
		currentEnemy = Lizalfo();
		currentEnemy.displayStats();
		break;
	}
	case MOBLIN: {
		currentEnemy = Moblin();
		currentEnemy.displayStats();
		break;
	}
	case HINOX: {
		currentEnemy = Hinox();
		currentEnemy.displayStats();
		break;
	}
	case GUARDIAN: {
		currentEnemy = Guardian();
		currentEnemy.displayStats();
		break;
	}
	case LIONEL: {
		currentEnemy = Lionel();
		currentEnemy.displayStats();
		break;
	}
	default:
		break;
	}

	cout << endl;
	return currentEnemy;

}

void userTurn() {

}

bool extraHit(double extraHitChance) {
	bool secondHit = false;
	int randNum = rand() % 10 + 1; //randomly choose a number between 1-10

	if (randNum < extraHitChance * 10) {
		secondHit = true;
	}
	else {
		secondHit = false;
	}

	return secondHit;
}

//returns a boolean to main as to whether the player dodged the hit or not
bool dodge(double dodgeChance) {
	bool dodge = false;
	int randNum = rand() % 10 + 1; //randomly choose a number between 1-10

	if (randNum < dodgeChance * 10) {
		dodge = true;
	}
	else {
		dodge = false;
	}

	return dodge;
}