﻿#include "FileLoad.h"
#include "Pokemon.h"
#include "Move.h"
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Type.h"
#include "Game.h"

using namespace std;

/**
 * Intent: Default constructor
 * Pre: None
 * Post: FileLoad object is created
 */
FileLoad::FileLoad()
{
	caseFilename = "";
	MonsterLibName = "";
	MoveLibName = "";
	GameDataName = "";
}

/**
 * Intent:
 * Pre:
 * Post:
 */
FileLoad::FileLoad(string name)
{
	caseFilename = name;
}

/**
 * Intent: Is the required files loaded?
 * Pre: None
 * Post: Return true if the file is loaded, false otherwise
 */
bool FileLoad::canBeBattle()
{
	return this->isLoadGameData && this->isLoadMonsterLib && this->isLoadMoveLib;
}

/**
 * Intent: Load the monster library
 * Pre: data is the content of the file
 * Post:
 */
void FileLoad::loadMonsterLibraryFile(string name)
{
	//cout << data << endl;
	/* e.g.
	*	Venusaur
	*	2 Grass Poison
	*	187 147 148 167 167 145
	*/

	ifstream in;
	in.open(name);
	string describe;
	while (getline(in, describe)) {
		stringstream ss(describe);
		string name, type;
		int typeCount, typeIndex, HP, ATK, DEF, SPATK, SPDEF, SPD;
		set<int> typeSet;

		ss >> name;
		getline(in, describe);
		ss = stringstream(describe);

		ss >> typeCount;
		for (size_t i = 0; i < typeCount; i++)
		{
			ss >> type;
			transform(type.begin(), type.end(), type.begin(), ::tolower);
			typeIndex = typeMap.at(type);
			typeSet.insert(typeIndex);
		}

		getline(in, describe);
		ss = stringstream(describe);
		ss >> HP >> ATK >> DEF >> SPATK >> SPDEF >> SPD;
		Pokemon pokemon(name, typeCount, typeSet, HP, ATK, DEF, SPATK, SPDEF, SPD);
		pokemonList.push_back(pokemon);
	}
}

void FileLoad::openFile()
{
	ifstream in;
	in.open(caseFilename);
	in >> MonsterLibName;
	//cout << MonsterLibName;
	MonsterLibName += ".txt";
	//MonsterLibName = "../../../src/" + MonsterLibName;

	in >> MoveLibName;
	MoveLibName += ".txt";
	//MoveLibName = "../../../src/" + MoveLibName;

	in >> GameDataName;
	GameDataName += ".txt";
	//GameDataName = "../../../src/" + GameDataName;

	in.close();
}
void FileLoad::Movesfile() {
	/*ifstream Moves;
	Moves.open(MoveLibName);
	string describe;
	AdditionalEffect effect;
	effect = NOR;
	vector<string>properList;
	type movetype;
	while (getline(Moves, describe)) {
		effect = NOR;
		stringstream ss(describe);
		string movename, propertys, ATKtype;
		int power1, power2, power3;
		ss >> movename >> propertys >> ATKtype >> power1 >> power2 >> power3;
		movetype = type(TypeMap[propertys]);
		if (ATKtype == "Special") {
			string temp;
			ss >> temp;
			if (temp == "BRN") {
				effect = BRN;
			}
			else if (temp == "PAR") {
				effect = PAR;
			}
			else if (temp == "PSN") {
				effect = PSN;
			}
		}
		MoveLib.push_back(Move(movename, movetype, propertys, power1, power2, power3, effect));
	}
	Moves.close();*/

}
void FileLoad::Gamedata() {
	//ifstream Game;
	//Game.open(GameDataName);
	//int cnt, skill;
	//Game >> cnt;
	//for (int i = 0; i < cnt; i++) {
	//	string PokemonName;
	//	Game >> PokemonName >> skill;
	//	for (int j = 0; j < Monster.size(); j++) {
	//		if (Monster[j].getName() == PokemonName) {
	//			player1.push_back(Monster[j]);
	//			break;
	//		}
	//	}
	//	vector<string>skillList(skill);
	//	for (int j = 0; j < skill; j++) {
	//		Game >> skillList[j];
	//		for (int k = 0; k < MoveLib.size(); k++) {
	//			if (MoveLib[k].getName() == skillList[j]) {
	//				player1[i].skillMove(MoveLib[k]);//攻擊招式player1函式未寫
	//				break;
	//			}
	//		}
	//	}
	//}
	//Game >> cnt;
	//for (int i = 0; i < cnt; i++) {
	//	string PokemonName;
	//	Game >> PokemonName >> skill;
	//	for (int j = 0; j < Monster.size(); j++) {
	//		if (Monster[j].getName() == PokemonName) {
	//			player2.push_back(Monster[j]);
	//			break;
	//		}
	//	}
	//	vector<string>skillList(skill);
	//	for (int j = 0; j < skill; j++) {
	//		Game >> skillList[j];
	//		for (int k = 0; k < MoveLib.size(); k++) {
	//			if (MoveLib[k].getName() == skillList[j]) {
	//				player2[i].skillMove(MoveLib[k]);//攻擊招式player2函式未寫
	//				break;
	//			}
	//		}
	//	}
	//}
}
void FileLoad::opentest() {
	/*ifstream in;
	in.open(fileName);
	in >> MonsterLibName;
	cout << MonsterLibName;
	in >> MoveLibName;
	in >> GameDataName;
	string commend;
	bool start = false;
	bool player1creature = false;
	bool medical = false;
	Game GS(player1,player2);
	while (in >> commend) {
		if (commend == "Test") {
			start = true;
			cout << "Attention: Test start " << endl;
		}
		if (commend == "battle"&&start == true) {
			cout << "Two Pokemon battle" << endl;

		}
		if (commend == "Bag") {
			cout << "use medicial" << endl;
			medical = true;
		}
		if (commend == "Potion" && medical == true) {
			GS.HealTime();
		}
	}*/
}