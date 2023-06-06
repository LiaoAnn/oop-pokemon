/***********************************************************************
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

using namespace std;
class Player {
public:
    // constructor
    Player(string name);
    Player(
        string name,
        Pokemon pokemon1, 
        Pokemon pokemon2, 
        Pokemon pokemon3, 
        Pokemon pokemon4
    );

    // destructor
    ~Player();

    // Get player's name
    string getName() const;
    // Get player's Pokemon list
    vector<Pokemon> getPokemonList() const;
    // Get player's current Pokemon
    Pokemon getCurrentPokemon() const;

    // Add a Pokemon to the player's Pokemon list
    void addPokemon(Pokemon pokemon);
    // Set the player's current Pokemon by index
    void setCurrentPokemon(int index);

private:
    string name;  // Name of the player
    vector<Pokemon> pokemonList;  // List of Pokemon owned by the player
    Pokemon& currentPokemon;  // Current Pokemon of the player
};
