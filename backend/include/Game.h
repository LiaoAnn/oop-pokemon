#include <iostream>
#include "Pokemon.h"
#include "Player.h""
#include "fileLoad.h"
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

	// start the game
	void StartGame();
	// initialize the game
	void InitGame();

	void HealTime();

	void operator<<(string str);
};

extern Game game;
