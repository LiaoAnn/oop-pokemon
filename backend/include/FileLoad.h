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

class FileLoad {
private:
	string caseFilename;
	string MonsterLibName, MoveLibName, GameDataName;
	//int hp; // health points
	//int attack; // attack points
	//int defence; // defence points
	//int spAttack; // special attack points
	//int spDefence; // special defence points
	//int speed;
	//map<string, int> TypeMap = { {"Normal", 0}, {"Fire", 1}, {"Water", 2}, {"Electric", 3}, {"Grass", 4}, {"Ice", 5}, {"Fighting", 6}, {"Poison", 7}, {"Ground", 8}, {"Flying", 9}, {"Psychic", 10}, {"Bug", 11}, {"Rock", 12}, {"Ghost", 13}, {"Dragon", 14}, {"Dark", 15}, {"Steel", 16}, {"Fairy", 17} };

	/*set<int> typelist;
	vector<Pokemon> Monster;
	vector<Pokemon>player1, player2;*/
	//vector<Move> MoveLib;
	bool isLoadGameData = false;
	bool isLoadMonsterLib = false;
	bool isLoadMoveLib = false;
public:
	// default constructor
	FileLoad();
	FileLoad(string file);
	void openFile();

	// Set the file name
	void setCaseFileName(string name);
	void setMonsterLibName(string name);
	void setMoveLibName(string name);
	void setGameDataName(string name);

	// Load the monster library
	void loadMonsterLibraryFile(string name);

	// Load the move library
	void loadMoveLibraryFile(string name);

	// Load the game data
	void loadGameDataFile(string name);

	// Load the case file
	void loadCaseFile(string name);

	// Return true if the file is loaded
	bool canBeBattle();

	void Movesfile();
	void Gamedata();
	void opentest();
	void setfile();
};