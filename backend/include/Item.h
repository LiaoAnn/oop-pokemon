/***********************************************************************
 * File: Item.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-08
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-08
 * Description: Definition of class Item
************************************************************************/

#pragma once

#include <string>
#include <map>
#include "Pokemon.h"
#include "json.h"

using namespace std;

class Item
{
protected:
	string name;
	int points;
public:
	Item(string name, int points);
	~Item();
	string getName();
	int getPoints();
	json toJson();

	virtual void useItem(Pokemon& pokemon) = 0;
};

extern map<string, Item*> itemMap;
