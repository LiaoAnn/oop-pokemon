/***********************************************************************
 * File: FileLoad.h
 * Author: Alan
 * Create Date: 2023-05-23
 * Editor: Alan, BING-JIA TAN (B11115001)
 * Update Date: 2023-06-08
 * Description: Header file for FileLoad
************************************************************************/
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
public:
	bool isLoadGameData = false;
	bool isLoadMonsterLib = false;
	bool isLoadMoveLib = false;

	// default constructor
	FileLoad();
	FileLoad(string file);

	// Load the monster library
	bool loadMonsterLibraryFile(string name);

	// Load the move library
	bool loadMoveLibraryFile(string name);

	// Load the game data
	bool loadGameDataFile(string name);

	// Load the case file
	void loadCaseFile(string name);

	// Return true if the file is loaded
	bool canBeBattle();
};

extern FileLoad file;
