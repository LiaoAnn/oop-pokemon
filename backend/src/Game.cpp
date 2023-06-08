﻿/***********************************************************************
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
void Game::StartGame()
{}

/**
 * Intent: Initialize the game
 * Pre:
 * Post:
 */
void Game::InitGame()
{
	this->player.clearPokemonList();
	this->AI.clearPokemonList();
	this->turn = 1;
	this->battleLog.clear();
}

void Game::HealTime()
{}

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

Game game = Game();

