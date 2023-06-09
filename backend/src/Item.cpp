﻿/***********************************************************************
 * File: Item.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-08
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-08
 * Description: Implementation of class Item
************************************************************************/

#include "Item.h"
#include "Potion.h"

/**
 * Intent: Constructor
 * Pre: None
 * Post: None
 */
Item::Item(string name, int points)
{
	this->name = name;
	this->points = points;
}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
Item::~Item()
{}

/**
 * Intent: Get the name of the item
 * Pre: None
 * Post: A string of the name of the item
 */
string Item::getName()
{
	return name;
}

/**
 * Intent: Get the points of the item
 * Pre: None
 * Post: An integer of the points of the item
 */
int Item::getPoints()
{
	return points;
}

/**
 * Intent: Convert the item to json
 * Pre: None
 * Post: A json object of the item
 */
json Item::toJson()
{
	json j;
	j["name"] = name;
	j["points"] = points;
	return j;
}

map<string, Item*> itemMap = {
	{"Potion", new NormalPotion()},
	{"SuperPotion", new SuperPotion()},
	{"HyperPotion", new HyperPotion()},
	{"MaxPotion", new MaxPotion()}
};