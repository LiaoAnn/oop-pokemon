#pragma once
#include <iostream>
#include <vector>
#include <set>
#include "Type.h"
#include "Move.h"
using namespace std;
//enum stat { hp, attack, defence, spAttack, spDefence, speed };
class Pokemon
{
private:
	string name; // name of pokemon
	int typeNum; // number of types
	set <int> type; // type of pokemon
	int hp; // health points
	float attack; // attack points
	float defence; // defence points
	float spAttack; // special attack points
	float spDefence; // special defence points
	float speed; // speed points
	vector <int> currentStat; // current stats
	vector<float>atkList, defList;
public:
	Pokemon() { atkList.clear(); }
	Pokemon(string name, set<int> typeList,
		int HP, float atk, float def, float sPatk, float sPdef, float speed) :
		name(name), type(typeList), hp(HP), attack(atk),
		defence(def), spAttack(sPatk), spDefence(sPdef), speed(speed) {};
	void battle(string power1, string power2);
	float getATK();
	string getName();
	void skillMove(Move skill);
};