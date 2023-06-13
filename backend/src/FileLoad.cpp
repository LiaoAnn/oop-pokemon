/***********************************************************************
 * File: Chance.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-30
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-12
 * Description: file load
************************************************************************/

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
#include "Chance.h"
#include "Item.h"

using namespace std;

FileLoad file = FileLoad();

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

	pokemonList.clear();
	while (getline(in, describe))
	{
		stringstream ss(describe);
		string name, type;
		int typeCount, typeIndex, HP, ATK, DEF, SPATK, SPDEF, SPD;//basic capability
		set<int> typeSet;

		ss >> name;

		getline(in, describe);//next line
		ss = stringstream(describe);
		ss >> typeCount;
		for (size_t i = 0; i < typeCount; i++)
		{
			ss >> type;
			transform(type.begin(), type.end(), type.begin(), ::tolower);
			typeIndex = typeMap.at(type);
			typeSet.insert(typeIndex);
		}

		getline(in, describe);//next line
		ss = stringstream(describe);
		ss >> HP >> ATK >> DEF >> SPATK >> SPDEF >> SPD;
		Pokemon pokemon(name, typeCount, typeSet, HP, ATK, DEF, SPATK, SPDEF, SPD);
		pokemonList.push_back(pokemon);
	}

	this->MonsterLibName = name;//set the monsterlib 
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

	skillList.clear();
	while (getline(in, describe))
	{
		stringstream ss(describe);
		string name, type, category, con;
		int typeIndex, categoryIndex, power, accuracy, pp, effectIndex;
		SkillEffect* effect;

		// Read the data to the skill
		ss >> name >> type >> category >> power >> accuracy >> pp;

		// Set the type
		transform(type.begin(), type.end(), type.begin(), ::tolower);
		typeIndex = typeMap.at(type);

		// Set the category
		transform(category.begin(), category.end(), category.begin(), ::tolower);
		categoryIndex = skillCategoryMap.at(category);

		Skill skill(name, typeIndex, categoryIndex, power, accuracy, pp);

		// Set the effect
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

	this->MoveLibName = name;//set MoveLib file
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

	game.player = Player();
	game.AI = Player();
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

			// Read Pokemon
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
				player.addPokemon(pokemon);// player added pokemon 
			}
			else
			{
				throw string("Pokemon not found");//error
			}

			player.addPokemon(pokemon);// player added pokemon 
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

	this->GameDataName = name;//set GameData file
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
	string describe, logs;
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
		logs = "";
		if (describe == "Battle")
		{
			// Both player and AI use a skill
			string playerSkill, AISkill;
			getline(in, playerSkill);
			getline(in, AISkill);
			int playerSpeed = game.player.getCurrentPokemon().getSpeed();
			int AISpeed = game.AI.getCurrentPokemon().getSpeed();

			Player& firstPlayer = game.player;
			Player& secondPlayer = game.AI;
			if (playerSpeed < AISpeed)
			{
				firstPlayer = game.AI;
				secondPlayer = game.player;
			}
			bool isFristPlayerOpposing = firstPlayer.getIsOpposing();
			bool isSecondPlayerOpposing = secondPlayer.getIsOpposing();

			Pokemon& firstPokemon = firstPlayer.getCurrentPokemon();
			Pokemon& secondPokemon = secondPlayer.getCurrentPokemon();

			if (!firstPokemon.isCanNotMove(isFristPlayerOpposing))
			{
				if (firstPokemon.hasSkill(playerSkill))
					firstPokemon[playerSkill].useSkill
					(
						firstPokemon, secondPokemon, isFristPlayerOpposing
					);
			}

			// Check if the Second Player pokemon is alive
			if (!secondPokemon.isAlive())
			{
				secondPlayer.pokemonFainted(isSecondPlayerOpposing);
				game.playerDotCheck();
				game.turn++;
				continue;
			}

			//judge the pokemon which can move
			if (!secondPokemon.isCanNotMove(isSecondPlayerOpposing))
			{
				if (secondPokemon.hasSkill(AISkill))
					secondPokemon[AISkill].useSkill
					(
						secondPokemon, firstPokemon, isSecondPlayerOpposing
					);
			}

			// Check if the First Player pokemon is alive
			if (!firstPokemon.isAlive())
			{
				firstPlayer.pokemonFainted(isFristPlayerOpposing);
				game.playerDotCheck();
				game.turn++;
				continue;
			}

			// DOT check -- Player first AI second
			game.playerDotCheck();
			game.turn++;
		}
		else if (describe == "Bag")
		{
			// Player use a item and AI use a skill
			string playerItem, playerPokemonName, AISkill;
			getline(in, playerItem);
			getline(in, playerPokemonName);
			getline(in, AISkill);

			// Get the Pokemon
			Pokemon& assignedPokemon = game.player.getPokemonByName(playerPokemonName);
			Pokemon& playerPokemon = game.player.getCurrentPokemon();
			Pokemon& AIPokemon = game.AI.getCurrentPokemon();

			// Get the item
			Item* item = itemMap[playerItem];

			// Player use a item
			item->useItem(assignedPokemon);

			// Opposing Pokemon use a skill
			if (!AIPokemon.isCanNotMove(true))
			{
				if (AIPokemon.hasSkill(AISkill))
					AIPokemon[AISkill].useSkill(AIPokemon, playerPokemon, true);
			}

			// DOT check
			game.playerDotCheck();
			game.turn++;
		}
		else if (describe == "Pokemon")
		{
			// Player change Pokemon and AI use a skill
			string playerPokemonName, AISkill;
			getline(in, playerPokemonName);
			getline(in, AISkill);

			// Return the current Pokemon
			Pokemon& playerPokemon = game.player.getCurrentPokemon();
			game << playerPokemon.getName() + ", switch out!";
			game << "Come back! ";

			// Change Pokemon
			game.player.setCurrentPokemon(playerPokemonName);
			playerPokemon = game.player.getCurrentPokemon();
			game << "Go! " + playerPokemon.getName() + "!";

			// Opposing Pokemon use a skill
			Pokemon& AIPokemon = game.AI.getCurrentPokemon();
			if (!AIPokemon.isCanNotMove(true))
			{
				if (AIPokemon.hasSkill(AISkill))
					AIPokemon[AISkill].useSkill(AIPokemon, playerPokemon, true);
			}

			// DOT check
			game.playerDotCheck();
			game.turn++;
		}
		else if (describe == "Status")
		{
			// Player check the status of the Pokemon
			Pokemon& userPokemon = game.player.getCurrentPokemon();
			Pokemon& AIPokemon = game.AI.getCurrentPokemon();

			logs += userPokemon.getName() + " ";
			logs += to_string(userPokemon.getHp()) + " ";
			vector<SkillEffect*> stat = userPokemon.getCurrentStats();
			for (int i = 0; i < stat.size(); i++)
			{
				string skillEffectName = stat[i]->getName();
				transform(
					skillEffectName.begin(),
					skillEffectName.end(), skillEffectName.begin(),
					::toupper);
				logs += skillEffectName;

				if (i != stat.size() - 1)
				{
					logs += " ";
				}
			}

			logs += AIPokemon.getName() + " ";
			logs += to_string(AIPokemon.getHp()) + " ";
			stat = AIPokemon.getCurrentStats();
			for (int i = 0; i < stat.size(); i++)
			{
				string skillEffectName = stat[i]->getName();
				transform(
					skillEffectName.begin(),
					skillEffectName.end(), skillEffectName.begin(),
					::toupper);
				logs += skillEffectName;

				if (i != stat.size() - 1)
				{
					logs += " ";
				}
			}

			game << logs;
		}
		else if (describe == "Check")
		{
			// Player check the moves of the Pokemon
			Pokemon& pokemon = game.player.getCurrentPokemon();
			vector<Skill> skills = pokemon.getSkillList();

			for (int i = 0; i < skills.size(); i++)
			{
				logs += skills[i].getName() + " ";//set logs 
				logs += to_string(skills[i].getPP());

				if (i != skills.size() - 1)//judge is not the final words
				{
					logs += " ";
				}
			}
		}
		else if (describe == "Run")
		{
			game << "Run";
			break;
		}
		else
		{
			throw string("Invalid command");
		}

		// Check Win
		if (game.isWin())
		{
			game << "You win";
			break;
		}
		else if (game.isLose())
		{
			game << "You lose";
			break;
		}
	}
}