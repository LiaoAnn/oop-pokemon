#pragma once
#pragma once
#include <iostream>
#include <vector>
#include "Type.h"
using namespace std;

class PokemonCreature {
private:
	string name;
	int maxHP;
	int HP;
	int ATK;
	int DEF;
	int SPatk;
	int SPdef;
	int speed;
	int level = 50;
	vector<Type> typeList;
public:

	PokemonCreature(string name, vector<Type> typeList,
		int HP, int atk, int def, int sPatk, int sPdef, int speed) :
		name(name), typeList(typeList), maxHP(HP), HP(HP), ATK(atk),
		DEF(def), SPatk(sPatk), SPdef(sPdef), speed(speed) {};
};