#include "main.h"
//#include "Type.h"
int main()
{
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
