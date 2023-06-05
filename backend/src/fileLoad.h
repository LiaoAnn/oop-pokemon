#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "Type.h"
#include <set>
#include <vector>
#include "Pokemon.h"
using namespace std;

class fileLoad {
private:
	string fileName;
	string MonsterLibName, MoveLibName, GameDataName;
	int hp; // health points
	int attack; // attack points
	int defence; // defence points
	int spAttack; // special attack points
	int spDefence; // special defence points
	int speed;
	map<string, int> TypeMap = { {"Normal", 0}, {"Fire", 1}, {"Water", 2}, {"Electric", 3}, {"Grass", 4}, {"Ice", 5}, {"Fighting", 6}, {"Poison", 7}, {"Ground", 8}, {"Flying", 9}, {"Psychic", 10}, {"Bug", 11}, {"Rock", 12}, {"Ghost", 13}, {"Dragon", 14}, {"Dark", 15}, {"Steel", 16}, {"Fairy", 17} };

	set<int> typelist;
	vector<Pokemon> Monster;
	vector<Pokemon>player1, player2;
	vector<Move> MoveLib;

public:
	fileLoad(string file);
	void openFile();
	void setfile();
	void PokemonLibfile();
	void Movesfile();
	void Gamedata();
	void opentest();
	
};