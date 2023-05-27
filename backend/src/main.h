#pragma once
#include <iostream>
#include <thread>
#include "WebServer.h"
#include "WebSocketServer.h"

using namespace std;

WebServer* webServer;
WebSocketServer* webSocketServer;

const int WEBPORT = 5173;
const int WSPORT = 9002;
const string WEBROOT = "dist";

void webServerThread();
void webSocketServerThread();
