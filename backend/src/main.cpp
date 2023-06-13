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
		}

		if (type == "load_monster")
		{
			bool canBattle = false;
			try
			{
				canBattle = file.loadMonsterLibraryFile(recive["file"]);
			}
			catch (string& e)
			{
				result = json();
				result["type"] = "load_monster";
				result["success"] = false;
				result["message"] = e;
				webSocketServer->send(jsonToString(result));
				continue;
			}

			result = json();
			result["type"] = "load_monster";
			result["success"] = true;
			result["can_battle"] = canBattle;
			webSocketServer->send(jsonToString(result));
		}

		if (type == "load_move")
		{
			bool canBattle = false;
			try
			{
				file.loadMoveLibraryFile(recive["file"]);
			}
			catch (string& e)
			{
				result = json();
				result["type"] = "load_move";
				result["success"] = false;
				result["message"] = e;
				webSocketServer->send(jsonToString(result));
				continue;
			}

			result = json();
			result["type"] = "load_move";
			result["success"] = true;
			result["can_battle"] = canBattle;
			webSocketServer->send(jsonToString(result));
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
			catch (string& e)
			{
				result = json();
				result["type"] = "load_game";
				result["success"] = false;
				result["message"] = e;
				webSocketServer->send(jsonToString(result));
				continue;
			}

			result = json();
			result["type"] = "load_game";
			result["success"] = true;
			result["can_battle"] = canBattle;
			webSocketServer->send(jsonToString(result));
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
			vector<Pokemon> playerPokemonList = game.player.getPokemonList();
			vector<Pokemon> opposingPokemonList = game.AI.getPokemonList();

			result["type"] = "init_attack";
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
	}
}
