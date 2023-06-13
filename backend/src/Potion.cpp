/***********************************************************************
 * File: Potion.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-08
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-08
 * Description: Implementation of class Potion
************************************************************************/

#include "Potion.h"
#include "Game.h"

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
 * Intent: Use the potion on the pokemon
 * * Pre: None
 * * Post: The pokemon's HP is increased by the points of the potion
 * */
void Potion::useItem(Pokemon& pokemon)
{
	if (pokemon.getHp() > 0)
		pokemon.healHp(this->points);

	game << "You used a " + this->name + "!";
	game << pokemon.getName() + " had its HP restored.";
}

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
 * Intent: Hyper potion constructor
 * Pre: None
 * Post: A HyperPotion object is created with name "Hyper Potion" and points 200
 */
SuperPotion::SuperPotion() : Potion("SuperPotion", 50)
{}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
SuperPotion::~SuperPotion()
{}

/**
 * Intent: Hyper potion constructor
 * Pre: None
 * Post: A HyperPotion object is created with name "Hyper Potion" and points 200
 */
HyperPotion::HyperPotion() : Potion("HyperPotion", 200)
{}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
HyperPotion::~HyperPotion()
{}

/**
 * Intent: Max potion constructor
 * Pre: None
 * Post: A MaxPotion object is created with name "Max Potion" and points 999
 */
MaxPotion::MaxPotion() : Potion("MaxPotion", 999)
{}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
MaxPotion::~MaxPotion()
{}
