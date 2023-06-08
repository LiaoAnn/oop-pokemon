/***********************************************************************
 * File: Potion.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-08
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-08
 * Description: Definition of class Potion
************************************************************************/
#pragma once

#include "Item.h"
#include "Pokemon.h"
#include <map>

// Potions can affect the HP of the current Pokémon, but they cannot be used on a copied Pokémon.
class Potion : public Item
{
public:
	Potion();
	Potion(string name, int points);
	~Potion();

	virtual void usePotion() = 0;
};

class NormalPotion : public Potion
{
public:
	NormalPotion();
	~NormalPotion();

	void usePotion(Pokemon& pokemon) override;
};

class SuperPotion : public Potion
{
public:
	SuperPotion();
	~SuperPotion();

	void usePotion(Pokemon& pokemon) override;
};

class HyperPotion : public Potion
{
public:
	HyperPotion();
	~HyperPotion();

	void usePotion(Pokemon& pokemon) override;
};

class MaxPotion : public Potion
{
public:
	MaxPotion();
	~MaxPotion();

	void usePotion(Pokemon& pokemon) override;
};

enum PotionType
{
	NormalPotionType,
	SuperPotionType,
	HyperPotionType,
	MaxPotionType
};

extern map<string, Potion&> potionMap;
