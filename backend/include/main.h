/***********************************************************************
 * File: main.h
 * Author: 劉耀恩
 * Create Date: 2023/06/15
 * Editor: 劉耀恩
 * Update Date: 2023/06/15
 * Description: main header
 ************************************************************************/
#pragma once
#include <iostream>
#include <thread>
#include "WebServer.h"
#include "WebSocketServer.h"

using namespace std;

WebServer* webServer;
WebSocketServer* webSocketServer;

const int WEBPORT = 80;
const int WSPORT = 9002;
const string WEBROOT = "dist";

void webServerThread();
void webSocketServerThread();
void gameThread();
