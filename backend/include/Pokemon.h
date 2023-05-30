/***********************************************************************
 * File: Pokemon.h
 * Author: 劉耀恩
 * Create Date: 2023/05/30
 * Editor: 劉耀恩
 * Update Date: 2023/05/30
 * Description: Definition of Pokemon class
***********************************************************************/
#pragma once
#include <iostream>
#include <vector>
#include <set>
using namespace std;
enum stat { hp, attack, defence, spAttack, spDefence, speed };
class Pokemon
{
private:
	string name; // name of pokemon
	int typeNum; // number of types
	set <int> type; // type of pokemon
	int hp; // health points
	int attack; // attack points
	int defence; // defence points
	int spAttack; // special attack points
	int spDefence; // special defence points
	int speed; // speed points
	vector <int> currentStat; // current stats
};