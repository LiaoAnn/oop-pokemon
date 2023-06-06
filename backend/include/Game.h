#include <iostream>
#include "Pokemon.h"
#include "Player.h""
using namespace std;
class Game {
private:
	Player player, AI;
	int turn;
	int mode;
public:
	// default constructor
	Game();
	// constructor
	Game(Player player1, Player player2);

	void GameStart();
	void HealTime();
};