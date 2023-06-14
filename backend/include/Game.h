/***********************************************************************
 * File: Game.h
 * Author: 劉耀恩
 * Create Date: 2023/06/15
 * Editor: 劉耀恩
 * Update Date: 2023/06/15
 * Description: Definition of Game
 ************************************************************************/
#include <iostream>
#include "Pokemon.h"
#include "Player.h"
#include "FileLoad.h"
#include "WebSocketServer.h"
using namespace std;
class Game {
public:
	Player player, AI;
	int turn;
	int mode;
	vector<string> battleLog;
public:
	// default constructor
	Game();
	// constructor
	Game(Player player1, Player player2);

	// set game mode
	void setGameMode(int mode);

	// start the game
	void startGame();
	// initialize the game
	void initGame();
	// Lose check
	bool isLose();
	// Win check
	bool isWin();
	// Dot check
	void playerDotCheck(WebSocketServer* socketServer = nullptr);

	void operator<<(string str);
};

extern Game game;
