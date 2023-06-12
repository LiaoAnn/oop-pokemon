/***********************************************************************
 * File: GameStatus.cpp
 * Author: Alan
 * Create Date: 2023-06-06
 * Editor: BING-JIA TAN (B11115001), Alan
 * Update Date: 2023-06-06
 * Description: Describe here
************************************************************************/
#include"Game.h"
#include <random>

// random number generator
// for invoiding keep generating the same random number
random_device rd;
mt19937 gen(rd());

/**
 * Intent: Default constructor
 * Pre: None
 * Post: A new Game object is created
 */
Game::Game() : player(), AI(), turn(1), mode(0), battleLog()
{}

/**
 * Intent: Constructor
 * Pre: None
 * Post: A new Game object is created
 */
Game::Game(Player player1, Player player2)
{
	this->player = player1;
	this->AI = player2;
	this->turn = 1;
	this->mode = 0;
	this->battleLog.clear();
}

/**
 * Intent: Start the game
 * Pre:
 * Post:
 */
void Game::startGame()
{}

/**
 * Intent: Initialize the game
 * Pre:
 * Post:
 */
void Game::initGame()
{
	this->player.clearPokemonList();
	this->AI.clearPokemonList();
	this->turn = 1;
	this->battleLog.clear();
}

void Game::healTime()
{}

/**
 * Intent: Check if the status infliction is successful or not
 * Pre: probability is between 0 and 1 means the probability of success
 * Post: return true if the status infliction is successful, otherwise return false
 */
bool Game::checkChance(double probability)
{
	// generate random number between 0.0 and 1.0
	uniform_real_distribution<> dis(0.0, 1.0);

	// if the random number is less than or equal to the given probability, then return true
	if (dis(gen) <= probability) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * Intent: Operator overload <<
 * Pre: a string
 * Post: push the string into battleLog
 */
void Game::operator<<(string str)
{
	string temp = "[Turn " + to_string(this->turn) + "] " + str;
	this->battleLog.push_back(temp);
}

/**
 * Intent: Set game mode
 * Pre: mode is the game mode
 * Post: None
 */
void Game::setGameMode(int mode)
{
	this->mode = mode;
}

Game game = Game();

