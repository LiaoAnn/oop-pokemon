#include <iostream>
#include "Pokemon.h"
#include "Player.h""
#include "fileLoad.h"
using namespace std;
class Game {
private:
	Player player, AI;
	int turn;
	int mode;
	fileLoad file;
public:
	// default constructor
	Game();
	// constructor
	Game(Player player1, Player player2);

	void GameStart();
	void HealTime();
};