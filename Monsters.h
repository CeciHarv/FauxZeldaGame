#pragma once
#include "Players.h"
#include <string>

using namespace std;

class Monsters :
	public Players
{
public:
	Monsters() : Players() {}; 

protected:
	bool playerChar = false;

};

//Derived Monster Classes

class Bokoblin : public Monsters {

public:
	Bokoblin() : Monsters() {
		name = "Bokoblin";
		attackDamage = 10;
		defense = .20;
		healthPoints = 50;
		dodgeChance = 0.0;
		playerChar = false;
	};

private:

};

class Lizalfo : public Monsters {

public:
	Lizalfo() : Monsters() {
		name = "Lizalfo";
		attackDamage = 20;
		defense = .20;
		healthPoints = 60;
		dodgeChance = 0.6;
		playerChar = false;
	};

private:

};

class Moblin : public Monsters {

public:
	Moblin() : Monsters() {
		name = "Moblin";
		attackDamage = 30;
		defense = .20;
		healthPoints = 70;
		dodgeChance = 0.3;
		playerChar = false;
	};

private:

};

class Hinox : public Monsters {

public:
	Hinox() : Monsters() {
		name = "Hinox";
		attackDamage = 40;
		defense = .20;
		healthPoints = 80;
		dodgeChance = 0.0;
		playerChar = false;
	};

private:

};

class Guardian : public Monsters {

public:
	Guardian() : Monsters() {
		name = "Guardian";
		attackDamage = 50;
		defense = .50;
		healthPoints = 90;
		dodgeChance = 0.0;
		playerChar = false;
	};

private:
	
};

class Lionel : public Monsters {

public:
	Lionel() :Monsters() {
		name = "Lionel";
		attackDamage = 60;
		defense = .40;
		healthPoints = 100;
		dodgeChance = 0.5;
		playerChar = false;
	};

private:
	
};
