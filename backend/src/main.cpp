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

	FileLoad file;
	try
	{
		file.loadCaseFile("case.txt");
	}
	catch (string& e)
	{
		game << e;
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
