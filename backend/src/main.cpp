/***********************************************************************
 * File: Skill.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-30
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-13
 * Description:main
************************************************************************/

#include "main.h"
//#include "Type.h"
#include "Game.h"
#include "FileLoad.h"
#include "Skill.h"
#include "json.h"
#include "Command.h"

int main()
{
	/*string filename;
	filename = "../../../src/case.txt";
	FileLoad filetest(filename);
	filetest.openFile();
	filetest.PokemonLibfile();
	filetest.Movesfile();
	filetest.Gamedata();*/

	try
	{
		file.loadCaseFile("case.txt");//file case.txt
	}
	catch (string& e)
	{
		game << e;
	}
	for (int i = 0; i < game.battleLog.size(); i++)
	{
		cout << game.battleLog[i] << endl;//go to pokemon battle
	}

	webServer = new WebServer(WEBROOT, WEBPORT);
	webSocketServer = new WebSocketServer();
	thread web(webServerThread);
	thread ws(webSocketServerThread);
	thread gameT(gameThread);
	web.join();
	ws.join();
	gameT.join();
	return 0;
}
/**
 * Intent: webserver
 * Pre: None
 * Post: run
 */
void webServerThread()
{
	webServer->run();

}
/**
 * Intent: websocket server
 * Pre: None
 * Post: run const int WSPORT
 */
void webSocketServerThread()
{
	webSocketServer->run(WSPORT);
}
/**
 * Intent: game tread
 * Pre: None
 * Post: get message or have message
 */
void gameThread()
{
	json result, recive;
	while (true)
	{
		string message, type;
		while (!webSocketServer->hasMessage())
		{
		}

		message = webSocketServer->getMessage();
		recive = stringToJson(message);
		type = recive["type"];

		if (type == "init")
		{
			game.player = Player();
			game.AI = Player();
			game.battleLog.clear();
			skillList.clear();
			pokemonList.clear();
			game.turn = 1;

			file.isLoadMoveLib = false;
			file.isLoadMonsterLib = false;
			file.isLoadGameData = false;

			result = json();
			result["type"] = "init";
			result["success"] = true;
			webSocketServer->send(jsonToString(result));
			continue;
		}

		if (type == "load_monster")
		{
			bool canBattle = false;
			try
			{
				canBattle = file.loadMonsterLibraryFile(recive["file"]);
			}
			catch (const std::exception& e)
			{
				result = json();
				result["type"] = "load_monster";
				result["success"] = false;
				result["message"] = e.what();
				webSocketServer->send(jsonToString(result));
				continue;
			}

			result = json();
			result["type"] = "load_monster";
			result["success"] = true;
			result["can_battle"] = canBattle;
			webSocketServer->send(jsonToString(result));
			continue;
		}

		if (type == "load_move")
		{
			bool canBattle = false;
			try
			{
				file.loadMoveLibraryFile(recive["file"]);
			}
			catch (const std::exception& e)
			{
				result = json();
				result["type"] = "load_move";
				result["success"] = false;
				result["message"] = e.what();
				webSocketServer->send(jsonToString(result));
				continue;
			}

			result = json();
			result["type"] = "load_move";
			result["success"] = true;
			result["can_battle"] = canBattle;
			webSocketServer->send(jsonToString(result));
			continue;
		}

		if (type == "load_game_data")
		{
			bool canBattle = false;
			if (!(file.isLoadMonsterLib && file.isLoadMoveLib))
			{
				result = json();
				result["type"] = "load_game_data";
				result["success"] = false;
				result["message"] = "Monster library or move library not loaded";
				webSocketServer->send(jsonToString(result));
				continue;
			}
			try
			{
				canBattle = file.loadGameDataFile(recive["file"]);
			}
			catch (const std::exception& e)
			{
				result = json();
				result["type"] = "load_game";
				result["success"] = false;
				result["message"] = e.what();
				webSocketServer->send(jsonToString(result));
				continue;
			}

			result = json();
			result["type"] = "load_game";
			result["success"] = true;
			result["can_battle"] = canBattle;
			webSocketServer->send(jsonToString(result));
			continue;
		}

		// Commands needs to load data before execute
		if (!file.canBeBattle())
		{
			result = json();
			result["type"] = "init_team";
			result["success"] = false;
			result["message"] = "No pokemon can be battle";
			webSocketServer->send(jsonToString(result));
			continue;
		}

		if (type == "init_attack")
		{
			Pokemon& myMonster = game.player.getCurrentPokemon();
			Pokemon& otherMonster = game.AI.getCurrentPokemon();

			result["type"] = "init_attack";
			result["success"] = true;

			result["myMonster"] = game.player.getCurrentPokemon().toJson();
			result["otherMonster"] = game.AI.getCurrentPokemon().toJson();
			webSocketServer->send(jsonToString(result));
			continue;
		}

		if (type == "init_team")
		{
			vector<Pokemon> playerPokemonList = game.player.getPokemonList();
			vector<Pokemon> opposingPokemonList = game.AI.getPokemonList();

			game.player.restoreAllPokemon();
			game.AI.restoreAllPokemon();

			result["type"] = "init_team";
			result["success"] = true;

			result["myMonster"] = json::array();
			for (int i = 0; i < playerPokemonList.size(); i++)
			{
				result["playerPokemon"].push_back(playerPokemonList[i].toJson());
			}

			result["otherMonster"] = json::array();
			for (int i = 0; i < opposingPokemonList.size(); i++)
			{
				result["otherMonster"].push_back(opposingPokemonList[i].toJson());
			}
		}

		if (type == "attack")
		{
			int firstAttack = 0, secondAttack = 0;
			// Both player and AI use a skill
			string playerSkillName, opposingSkillName;
			playerSkillName = recive["move"];

			Skill opposingRandomSkill = game.AI.getCurrentPokemon().randomSkill();

			opposingSkillName = opposingRandomSkill.getName();

			int playerSpeed = game.player.getCurrentPokemon().getSpeed();
			int opposingSpeed = game.AI.getCurrentPokemon().getSpeed();

			Player* playerArray[2] = { &game.player, &game.AI };
			int firstPlayerIndex = 0;
			int secondPlayerIndex = 1;

			Skill* skillArray[2] =
			{
				&game.player.getCurrentPokemon()[playerSkillName],
				&game.AI.getCurrentPokemon()[opposingSkillName]
			};

			if (playerSpeed < opposingSpeed)
			{
				firstPlayerIndex = 1;
				secondPlayerIndex = 0;
			}
			Player& firstPlayer = *playerArray[firstPlayerIndex];
			Player& secondPlayer = *playerArray[secondPlayerIndex];

			Skill& firstSkill = *skillArray[firstPlayerIndex];
			Skill& secondSkill = *skillArray[secondPlayerIndex];

			Pokemon& firstPokemon = firstPlayer.getCurrentPokemon();
			Pokemon& secondPokemon = secondPlayer.getCurrentPokemon();

			bool isFristPlayerOpposing = firstPlayer.getIsOpposing();
			bool isSecondPlayerOpposing = secondPlayer.getIsOpposing();

			firstSkill.reducePP();
			if (!firstPokemon.isCanNotMove(isFristPlayerOpposing))
			{
				firstAttack = firstSkill.useSkill
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

				result = attactCommandResult
				(
					firstPokemon, secondPokemon,
					firstSkill, secondSkill,
					firstAttack, secondAttack,
					firstPlayerIndex
				);
				webSocketServer->send(jsonToString(result));
				continue;
			}

			secondSkill.reducePP();
			//judge the pokemon which can move
			if (!secondPokemon.isCanNotMove(isSecondPlayerOpposing))
			{
				secondAttack = secondSkill.useSkill
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

				result = attactCommandResult
				(
					firstPokemon, secondPokemon,
					firstSkill, secondSkill,
					firstAttack, secondAttack,
					firstPlayerIndex
				);
				webSocketServer->send(jsonToString(result));
				continue;
			}

			// DOT check -- Player first AI second
			game.playerDotCheck();
			game.turn++;


			result = attactCommandResult
			(
				firstPokemon, secondPokemon,
				firstSkill, secondSkill,
				firstAttack, secondAttack,
				firstPlayerIndex
			);
			webSocketServer->send(jsonToString(result));
		}
	}
}
