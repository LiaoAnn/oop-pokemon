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
#include "GameMode.h"

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
 * Post: bool of whether the battle can be started
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

	this->MonsterLibName = name;
	this->isLoadMonsterLib = true;
	return this->canBeBattle();
}

/**
 * Intent: Load the move library
 * Pre: data is the content of the file
 * Post: bool of whether the battle can be started
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

	this->MoveLibName = name;
	this->isLoadMoveLib = true;
	return this->canBeBattle();
}

/**
 * Intent: Load the game data
 * Pre: data is the content of the file
 * Post: bool of whether the battle can be started
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

	this->GameDataName = name;
	this->isLoadGameData = true;
	return this->canBeBattle();
}

/**
 * Intent: Load the case file
 * Pre: name is the name of the file
 * Post: None
 */
void FileLoad::loadCaseFile(string name)
{
	ifstream in;
	in.open(name);
	string describe;
	stringstream ss;
	int gameMode;

	/* Load the type library */
	try
	{
		getline(in, describe);
		this->loadMonsterLibraryFile(describe);

		getline(in, describe);
		this->loadMoveLibraryFile(describe);

		getline(in, describe);
		this->loadGameDataFile(describe);
	}
	catch (string& e)
	{
		game << e;
	}

	/* Set the game mode */
	getline(in, describe);
	if (describe == "Test")
		gameMode = TEST;
	else
		gameMode = NORMAL;
	game.setGameMode(gameMode);

	/* Game Start */
	while (getline(in, describe))
	{
		if (describe == "Battle")
		{
			// Both player and AI use a skill
		}
		else if (describe == "Bag")
		{
			// Player use a item and AI use a skill
		}
		else if (describe == "Pokemon")
		{
			// Player change Pokemon and AI use a skill
		}
		else if (describe == "Status")
		{
			// Player check the status of the Pokemon
		}
		else if (describe == "Run")
		{
			break;
		}
		else
		{
			throw string("Invalid command");
		}
	}
}
