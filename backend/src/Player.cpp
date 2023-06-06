/***********************************************************************
 * File: Player.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-06
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-06
 * Description: Implementation of class Player
************************************************************************/

#include "Player.h"

/**
 * Intent: Constructor
 * Pre: name is a string
 * Post: A Player object
 */
Player::Player(string name) : name(name), currentPokemon(pokemonList[0]) 
{}

/**
 * Intent: Constructor
 * Pre: name is a string, pokemon1, pokemon2, pokemon3, pokemon4 are Pokemon objects
 * Post: A Player object
 */
Player::Player(
    string name, 
    Pokemon pokemon1, 
    Pokemon pokemon2, 
    Pokemon pokemon3, 
    Pokemon pokemon4) : name(name), currentPokemon(pokemonList[0]) 
{
    pokemonList.push_back(pokemon1);
    pokemonList.push_back(pokemon2);
    pokemonList.push_back(pokemon3);
    pokemonList.push_back(pokemon4);
}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
Player::~Player() {}

/**
 * Intent: Get player's name
 * Pre: None
 * Post: Return player's name
 */
string Player::getName() const 
{
    return name;
}

/**
 * Intent: Get player's Pokemon list
 * Pre: None
 * Post: Return player's Pokemon list
 */
vector<Pokemon> Player::getPokemonList() const 
{
    return pokemonList;

}

/**
 * Intent: Get player's current Pokemon
 * Pre: None
 * Post: Return player's current Pokemon
 */
Pokemon Player::getCurrentPokemon() const 
{
    return currentPokemon;

}

/**
 * Intent: Add a Pokemon to the player's Pokemon list
 * Pre: pokemon is a Pokemon object
 * Post: None
 */
void Player::addPokemon(Pokemon pokemon) 
{
    pokemonList.push_back(pokemon);
}

/**
 * Intent: Set the player's current Pokemon by index
 * Pre: index is an integer
 * Post: None
 */
void Player::setCurrentPokemon(int index) 
{
    currentPokemon = pokemonList[index];
}
