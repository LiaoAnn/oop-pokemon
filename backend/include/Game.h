#include <iostream>
#include "Pokemon.h"
#include "Player.h"
#include "FileLoad.h"
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
	void playerDotCheck();

	void operator<<(string str);
};

extern Game game;
