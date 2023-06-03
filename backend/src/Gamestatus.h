#include <iostream>
#include "Pokemon.h"
using namespace std;
class Gamestatus {
private:
	vector<Pokemon>play1, play2;
public:
	Gamestatus(vector<Pokemon> player1, vector<Pokemon> player2) :
		play1(player1), play2(player2) {};
};