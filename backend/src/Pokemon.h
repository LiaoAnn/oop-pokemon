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