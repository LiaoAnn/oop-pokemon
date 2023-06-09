﻿/***********************************************************************
 * File: Player.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-06
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-06
 * Description: Definition of class Player
************************************************************************/
#pragma once

#include <string>
#include <vector>
#include "Pokemon.h"

const string OPPOSING_PREFIX = "The opposing ";

using namespace std;
class Player {
public:
	// constructor
	Player();
	Player(string name);
	Player(bool isOpposing);
	Player(
		string name,
		Pokemon pokemon1,
		Pokemon pokemon2,
		Pokemon pokemon3,
		Pokemon pokemon4
	);

	// copy constructor
	Player(const Player& player);

	// oprator = overloading
	Player& operator=(const Player& player);

	// destructor
	~Player();

	// Get player's name
	string getName() const;
	// Get player's Pokemon list
	vector<Pokemon> getPokemonList() const;
	// Get player's current Pokemon
	Pokemon& getCurrentPokemon();

	// Add a Pokemon to the player's Pokemon list
	void addPokemon(Pokemon pokemon);
	// Set the player's current Pokemon by index
	void setCurrentPokemon(int index);
	// Set the player's current Pokemon by name
	void setCurrentPokemon(string name);

	// Clear the player's Pokemon list
	void clearPokemonList();
	// Get the Pokemon by name
	Pokemon& getPokemonByName(string name);

	// Pokemon fainted
	void pokemonFainted(bool isOpposing, bool requireCommand = false);

	// Is the player opposing
	bool getIsOpposing() const;

	// Restore all Pokemon to original state
	void restoreAllPokemon();

	// Is a Pokemon existing in the player's Pokemon list
	bool isPokemonExist(string name) const;
private:
	string name;  // Name of the player
	vector<Pokemon> pokemonList;  // List of Pokemon owned by the player
	int currentPokemon;  // Current Pokemon of the player
	bool isOpposing;  // Is the player opposing
};
