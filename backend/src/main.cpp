#include "main.h"

int main()
{
	webServer = new WebServer(WEBROOT, WEBPORT);
	webSocketServer = new WebSocketServer();
	thread webServerThread(webServerThread);
	thread webSocketServerThread(webSocketServerThread);
	webServerThread.join();
	webSocketServerThread.join();
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
