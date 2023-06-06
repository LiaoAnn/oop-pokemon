/***********************************************************************
 * File: Pokemon.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-06
 * Editor: BING-JIA TAN (B11115001), Alan 
 * Update Date: 2023-06-06
 * Description: Implementation for Pokemon class
************************************************************************/
#include "Pokemon.h"
//Pokemon::Pokemon(string name, set<int> typeList,
//	int HP, float atk, float def, float sPatk, float sPdef, float speed) {
//	atkList.push_back(atk);
//	atkList.push_back(sPatk);
//	defList.push_back(def);
//	defList.push_back(sPdef);
//}
//void Pokemon::battle(string play1, string play2) {
//
//}
//string Pokemon::getName() {
//	return name;
//}
//void Pokemon::skillMove(Move skill) {
//
//}


/**
 * Intent: Constructor
 * Pre: name is a string, 
		typeNum is an integer, 
		type is a set of integers, 
		hp, attack, defence, spAttack, spDefence, speed are integers
 * Post: A Pokemon object
 */
Pokemon::Pokemon(
	string name, 
	int typeNum, 
	set <int> type, 
	int hp, 
	int attack, 
	int defence, 
	int spAttack, 
	int spDefence, 
	int speed)
	: 
	name(name), 
	type(type), 
	hp(hp), 
	attack(attack), defence(defence), 
	spAttack(spAttack), spDefence(spDefence), 
	speed(speed)
{}

/**
 * Intent: Copy Constructor
 * Pre: Pokemon object
 * Post: None
 */
Pokemon::Pokemon(const Pokemon& pokemon)
	:
	name(pokemon.name),
	type(pokemon.type),
	hp(pokemon.hp),
	attack(pokemon.attack),
	defence(pokemon.defence),
	spAttack(pokemon.spAttack),
	spDefence(pokemon.spDefence),
	speed(pokemon.speed)
{}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
Pokemon::~Pokemon()
{}

/**
 * Intent: Get the name of the Pokemon
 * Pre: None
 * Post: Return the name of the Pokemon
 */
string Pokemon::getName() const
{
	return name;
}

/**
 * Intent: Get the type of the Pokemon
 * Pre: None
 * Post: Return the type of the Pokemon
 */
set <int> Pokemon::getType() const
{
	return type;
}

/**
 * Intent: Get the HP of the Pokemon
 * Pre: None
 * Post: Return the HP of the Pokemon
 */
int Pokemon::getHp() const
{
	return hp;
}

/**
 * Intent: Get the attack of the Pokemon
 * Pre: None
 * Post: Return the attack of the Pokemon
 */
int Pokemon::getAttack() const
{
	return attack;
}

/**
 * Intent: Get the defence of the Pokemon
 * Pre: None
 * Post: Return the defence of the Pokemon
 */
int Pokemon::getDefence() const
{
	return defence;
}

/**
 * Intent: Get the special attack of the Pokemon
 * Pre: None
 * Post: Return the special attack of the Pokemon
 */
int Pokemon::getSpAttack() const
{
	return spAttack;
}

/**
 * Intent: Get the special defence of the Pokemon
 * Pre: None
 * Post: Return the special defence of the Pokemon
 */
int Pokemon::getSpDefence() const
{
	return spDefence;
}

/**
 * Intent: Get the speed of the Pokemon
 * Pre: None
 * Post: Return the speed of the Pokemon
 */
int Pokemon::getSpeed() const
{
	return speed;
}

/**
 * Intent: Set the name of the Pokemon
 * Pre: name is a string
 * Post: None
 */
void Pokemon::setName(string name)
{
	this->name = name;
}

/**
 * Intent: Set the type of the Pokemon
 * Pre: type is a set of integers
 * Post: None
 */
void Pokemon::setType(set <int> type)
{
	this->type = type;
}

/**
 * Intent: Set the HP of the Pokemon
 * Pre: hp is an integer
 * Post: None
 */
void Pokemon::setHp(int hp)
{
	this->hp = hp;
}

/**
 * Intent: Set the attack of the Pokemon
 * Pre: attack is an integer
 * Post: None
 */
void Pokemon::setAttack(int attack)
{
	this->attack = attack;
}

/**
 * Intent: Set the defence of the Pokemon
 * Pre: defence is an integer
 * Post: None
 */
void Pokemon::setDefence(int defence)
{
	this->defence = defence;
}

/**
 * Intent: Set the special attack of the Pokemon
 * Pre: spAttack is an integer
 * Post: None
 */
void Pokemon::setSpAttack(int spAttack)
{
	this->spAttack = spAttack;
}

/**
 * Intent: Set the special defence of the Pokemon
 * Pre: spDefence is an integer
 * Post: None
 */
void Pokemon::setSpDefence(int spDefence)
{
	this->spDefence = spDefence;
}

/**
 * Intent: Set the speed of the Pokemon
 * Pre: speed is an integer
 * Post: None
 */
void Pokemon::setSpeed(int speed)
{
	this->speed = speed;
}