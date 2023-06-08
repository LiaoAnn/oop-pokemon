#include "main.h"
//#include "Type.h"
#include "Game.h"
#include "FileLoad.h"
#include "Skill.h"
int main()
{
	/*string filename;
	filename = "../../../src/case.txt";
	FileLoad filetest(filename);
	filetest.openFile();
	filetest.PokemonLibfile();
	filetest.Movesfile();
	filetest.Gamedata();*/

	FileLoad filetest;
	filetest.loadMonsterLibraryFile("../../../testData/PokemonLib.txt");
	filetest.loadMoveLibraryFile("../../../testData/MoveLib.txt");
	try
	{
		filetest.loadGameDataFile("../../../testData/GameData.txt");
	}
	catch (string& e)
	{
		game << e;
	}
	for (int i = 0; i < game.battleLog.size(); i++)
	{
		cout << game.battleLog[i] << endl;
	}


	/*webServer = new WebServer(WEBROOT, WEBPORT);
	webSocketServer = new WebSocketServer();
	thread web(webServerThread);
	thread ws(webSocketServerThread);
	thread game(gameThread);
	web.join();
	ws.join();
	game.join();*/
	return 0;
}

void webServerThread()
{
	webServer->run();

}
void webSocketServerThread()
{
	webSocketServer->run(WSPORT);
}
void gameThread()
{

}
