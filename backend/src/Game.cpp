/***********************************************************************
 * File: GameStatus.cpp
 * Author: Alan
 * Create Date: 2023-06-06
 * Editor: BING-JIA TAN (B11115001), Alan
 * Update Date: 2023-06-06
 * Description: Describe here
************************************************************************/
#include"Game.h"

/**
 * Intent: Default constructor
 * Pre: None
 * Post: A new Game object is created
 */
Game::Game() : player(), AI(), turn(0), status(0), result(0)
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
	this->turn = 0;
	this->status = 0;
	this->result = 0;
}


void Game::GameStart() 
{}

void Game::HealTime() 
{}