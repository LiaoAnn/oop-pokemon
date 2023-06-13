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
	thread game(gameThread);
	web.join();
	ws.join();
	game.join();
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
	while (true)
	{
		string test;
		while (!webSocketServer->hasMessage())
		{
		}

		test = webSocketServer->getMessage();
		// Write code here
	}
}
