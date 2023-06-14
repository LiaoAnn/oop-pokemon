/***********************************************************************
 * File: Game.cpp
 * Author: Alan
 * Create Date: 2023-06-06
 * Editor: BING-JIA TAN (B11115001), Alan
 * Update Date: 2023-06-06
 * Description: game basic function
************************************************************************/
#include"Game.h"
#include "Command.h"

/**
 * Intent: Default constructor
 * Pre: None
 * Post: A new Game object is created
 */
Game::Game() : player(false), AI(true), turn(1), mode(0), battleLog()
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

/**
 * Intent: Operator overload <<
 * Pre: a string
 * Post: push the string into battleLog
 */
void Game::operator<<(string str)
{
	string temp = "[Turn " + to_string(this->turn) + "] " + str;
	cout << temp << endl;
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

/**
 * Intent: Check if the game is over
 * Pre: None
 * Post: Return true if the game is over, false otherwise
 */
bool Game::isLose()
{
	vector<Pokemon> temp = this->player.getPokemonList();
	if (temp.size() == 0)
		return false;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].getHp() > 0)
			return false;
	}
	return true;
}

/**
 * Intent: Check if the game is Win
 * Pre: None
 * Post: Return true if the game is Win, false otherwise
 */
bool Game::isWin()
{
	vector<Pokemon> temp = this->AI.getPokemonList();
	if (temp.size() == 0)
		return false;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].getHp() > 0)
			return false;
	}

	return true;
}

/**
 * Intent: Check both player's pokemon's skill effect dot
 * Pre: None
 * Post: None
 */
void Game::playerDotCheck(WebSocketServer* socketServer)
{
	Player& player = game.player;
	Pokemon& playerPokemon = player.getCurrentPokemon();

	Player& opposing = game.AI;
	Pokemon& opposingPokemon = opposing.getCurrentPokemon();

	playerPokemon.isHurtByDot(false);
	if (!playerPokemon.isAlive())
	{
		player.pokemonFainted(false, true);
		if (socketServer != nullptr)
		{
			json result;
			result = playerPokemonFainted(player.getIsOpposing());
		}
	}

	opposingPokemon.isHurtByDot(true);
	if (!opposingPokemon.isAlive())
	{
		opposing.pokemonFainted(true, false);
		if (socketServer != nullptr)
		{
			json result;
			result = playerPokemonFainted(opposing.getIsOpposing());
		}
	}
}

Game game = Game();

