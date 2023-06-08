/***********************************************************************
 * File: Potion.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-08
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-08
 * Description: Implementation of class Potion
************************************************************************/

#include "Potion.h"

/**
 * Intent: Default constructor
 * Pre: None
 * Post: A Potion object is created with name "Potion" and points 0
 */
Potion::Potion() : Item("Potion", 0)
{}

/**
 * Intent: Constructor with parameters
 * Pre: None
 * Post: A Potion object is created with name and points
 */
Potion::Potion(string name, int points) : Item(name, points)
{}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
Potion::~Potion()
{}

/**
 * Intent: Normal potion constructor
 * Pre: None
 * Post: A NormalPotion object is created with name "Normal Potion" and points 20
 */
NormalPotion::NormalPotion() : Potion("Potion", 20)
{}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
NormalPotion::~NormalPotion()
{}

/**
 * Intent: Use the potion on the pokemon
 * Pre: None
 * Post: The pokemon's HP is increased by 20
 */
void NormalPotion::usePotion(Pokemon& pokemon)
{
	pokemon.healHp(20);
}

/**
 * Intent: Hyper potion constructor
 * Pre: None
 * Post: A HyperPotion object is created with name "Hyper Potion" and points 200
 */
SuperPotion::SuperPotion() : Potion("Super Potion", 50)
{}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
SuperPotion::~SuperPotion()
{}

/**
 * Intent: Use the potion on the pokemon
 * Pre: None
 * Post: The pokemon's HP is increased by 50
 */
void SuperPotion::usePotion(Pokemon& pokemon)
{
	pokemon.healHp(50);
}

/**
 * Intent: Hyper potion constructor
 * Pre: None
 * Post: A HyperPotion object is created with name "Hyper Potion" and points 200
 */
HyperPotion::HyperPotion() : Potion("Hyper Potion", 200)
{}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
HyperPotion::~HyperPotion()
{}

/**
 * Intent: Use the potion on the pokemon
 * Pre: None
 * Post: The pokemon's HP is increased by 200
 */
void HyperPotion::usePotion(Pokemon& pokemon)
{
	pokemon.healHp(200);
}

/**
 * Intent: Max potion constructor
 * Pre: None
 * Post: A MaxPotion object is created with name "Max Potion" and points 999
 */
MaxPotion::MaxPotion() : Potion("Max Potion", 999)
{}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
MaxPotion::~MaxPotion()
{}

/**
 * Intent: Use the potion on the pokemon
 * Pre: None
 * Post: The pokemon's HP is increased to its maximum
 */
void MaxPotion::usePotion(Pokemon& pokemon)
{
	int mapHp = pokemon.getMaxHp();
	pokemon.healHp(mapHp);
}

map<string, Potion&> potionMap = {
	{"Potion", NormalPotion()},
	{"Super Potion", SuperPotion()},
	{"Hyper Potion", HyperPotion()},
	{"Max Potion", MaxPotion()}
};
