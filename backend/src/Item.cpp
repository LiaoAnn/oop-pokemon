/***********************************************************************
 * File: Item.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-08
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-08
 * Description: Implementation of class Item
************************************************************************/

#include "Item.h"

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


