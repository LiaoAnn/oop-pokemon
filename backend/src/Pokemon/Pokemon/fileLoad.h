#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "Type.h"
using namespace std;

class fileLoad {
private:
	string fileName;
	string MonsterLibName, MoveLibName, GameDataName;
	int HP, ATK, DEF, SPatk, SPdef, speed;
	map<string, int> TypeMap = { {"Normal", 0}, {"Fire", 1}, {"Water", 2}, {"Electric", 3}, {"Grass", 4}, {"Ice", 5}, {"Fighting", 6}, {"Poison", 7}, {"Ground", 8}, {"Flying", 9}, {"Psychic", 10}, {"Bug", 11}, {"Rock", 12}, {"Ghost", 13}, {"Dragon", 14}, {"Dark", 15}, {"Steel", 16}, {"Fairy", 17} };
	
	vector<Type> typelist;
public:
	fileLoad(string file);
	void openFile();
	void setfile();
	void PokemonLibfile();
	void Movesfile();
};