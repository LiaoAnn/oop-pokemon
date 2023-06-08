#include "FileLoad.h"
#include "Pokemon.h"
#include "Move.h"
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Type.h"
#include "Game.h"
#include "Skill.h"
#include "SkillEffectList.h"
#include "SkillCategory.h"

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
 * Post: None
 */
bool FileLoad::loadMonsterLibraryFile(string name)
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

	this->isLoadMonsterLib = true;
	return this->canBeBattle();
}

/**
 * Intent: Load the move library
 * Pre: data is the content of the file
 * Post: None
 */
bool FileLoad::loadMoveLibraryFile(string name)
{
	//cout << data << endl;
	/* e.g.
	*	Tackle Normal Physical 40 100 35
	*	Vine Whip Grass Physical 45 100 25
	*	...
	*/

	ifstream in;
	in.open(name);
	string describe;
	while (getline(in, describe)) {
		stringstream ss(describe);
		string name, type, category, con;
		int typeIndex, categoryIndex, power, accuracy, pp, effectIndex;
		SkillEffect effect;

		ss >> name >> type >> category >> power >> accuracy >> pp;

		transform(type.begin(), type.end(), type.begin(), ::tolower);
		typeIndex = typeMap.at(type);

		transform(category.begin(), category.end(), category.begin(), ::tolower);
		categoryIndex = skillCategoryMap.at(category);

		Skill skill(name, typeIndex, categoryIndex, power, accuracy, pp);

		ss >> con;
		transform(con.begin(), con.end(), con.begin(), ::tolower);
		if (con != "")
		{
			effectIndex = skillEffectTypeMap.at(con);
			effect = skillEffectList[effectIndex];
			skill.setEffect(effect);
		}
		skillList.push_back(skill);
	}
	this->isLoadMoveLib = true;

	return this->canBeBattle();
}

/**
 * Intent: Load the game data
 * * Pre: data is the content of the file
 * * Post: None
 */
bool FileLoad::loadGameDataFile(string name)
{
	bool firstPlayer = true;
	ifstream in;
	stringstream ss;
	int pokemonCount;
	in.open(name);
	string describe;
	while (in >> pokemonCount)
	{
		Player player;
		getline(in, describe);

		// Find Pokemon
		for (int i = 0; i < pokemonCount; i++)
		{
			Pokemon pokemon;
			string pokemonName, skillName;
			int pokemonIndex, skillCount, skillIndex;
			getline(in, describe);
			ss = stringstream(describe);
			ss >> pokemonName >> skillCount;

			pokemonIndex = findPokemonByName(pokemonName);
			if (pokemonIndex != -1)
			{
				// To next line
				getline(in, describe);
				ss = stringstream(describe);

				// Copy Pokemon
				pokemon = pokemonList[pokemonIndex];
				for (int j = 0; j < skillCount; j++)
				{
					// Find Skill
					ss >> skillName;
					skillIndex = findSkillByName(skillName);

					if (skillIndex == -1)
					{
						throw string("Skill not found");
					}

					// Copy Skill
					Skill skill = skillList[skillIndex];
					pokemon.addSkill(skill);
				}
				player.addPokemon(pokemon);
			}
			else
			{
				throw string("Pokemon not found");
			}

			player.addPokemon(pokemon);
		}

		// Set the game.player if it is the first player
		if (firstPlayer)
		{
			game.player = player;
			firstPlayer = false;
		}
		else
		{
			game.AI = player;
		}
	}

	this->isLoadGameData = true;
	return this->canBeBattle();
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