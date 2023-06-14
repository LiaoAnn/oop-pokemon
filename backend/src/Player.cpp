/***********************************************************************
 * File: Player.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-06
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-06
 * Description: Implementation of class Player
************************************************************************/

#include "Player.h"
#include "Game.h"

/**
 * Intent: Default constructor
 * Pre: None
 * Post: A Player object
 */
Player::Player() : name(""), currentPokemon(0), pokemonList(), isOpposing(false)
{}

/**
 * Intent: Constructor
 * Pre: isOpposing is a boolean
 * Post: A Player object
 */
Player::Player(bool isOpposing) : name(""), currentPokemon(0), pokemonList(), isOpposing(isOpposing)
{}

/**
 * Intent: Constructor
 * Pre: name is a string
 * Post: A Player object
 */
Player::Player(string name) : name(name), currentPokemon(0), pokemonList(), isOpposing(false)
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
	Pokemon pokemon4) : name(name), currentPokemon()
{
	pokemonList.push_back(pokemon1);
	pokemonList.push_back(pokemon2);
	pokemonList.push_back(pokemon3);
	pokemonList.push_back(pokemon4);
	isOpposing = false;
}

/**
 * Intent: Copy constructor
 * Pre: player is a Player object
 * Post: A Player object
 */
Player::Player(const Player& player)
	:
	name(player.name), pokemonList(player.pokemonList), currentPokemon(player.currentPokemon), isOpposing(player.isOpposing)
{}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
Player::~Player() {}

/**
 * Intent: Assignment operator
 * Pre: player is a Player object
 * Post: A Player object
 */
Player& Player::operator=(const Player& player)
{
	name = player.name;
	pokemonList = player.pokemonList;
	currentPokemon = player.currentPokemon;
	return *this;
}

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
Pokemon& Player::getCurrentPokemon()
{
	return this->pokemonList[currentPokemon];
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
	currentPokemon = index;
}

/**
 * Intent: Clear the player's Pokemon list
 * Pre: None
 * Post: None
 */
void Player::clearPokemonList()
{
	pokemonList.clear();
}

/**
 * Intent: Get the Pokemon by name
 * Pre: name is a string
 * Post: Return the Pokemon Reference
 */
Pokemon& Player::getPokemonByName(string name)
{
	for (int i = 0; i < pokemonList.size(); i++)
	{
		if (pokemonList[i].getName() == name)
		{
			return pokemonList[i];
		}
	}
}

/**
 * Intent: Set the player's current Pokemon by name
 * Pre: name is a string
 * Post: None
 */
void Player::setCurrentPokemon(string name)
{
	for (int i = 0; i < pokemonList.size(); i++)
	{
		if (pokemonList[i].getName() == name)
		{
			currentPokemon = i;
			break;
		}
	}
}

/**
 * Intent: Player's Pokemon fainted and switch to the next Pokemon
 * Pre: isOpposing is a boolean
 * Post: None
 */
void Player::pokemonFainted(bool isOpposing)
{
	string log;
	Pokemon& pokemon = getCurrentPokemon();

	if (isOpposing)
		log += OPPOSING_PREFIX;
	log += pokemon.getName() + " fainted!";
	game << log;

	// Find the next Pokemon starting from the current Pokemon
	int nextPokemon = currentPokemon;
	int count = 0;
	do
	{
		nextPokemon = (nextPokemon + 1) % pokemonList.size();
		count++;
	} while (pokemonList[nextPokemon].getHp() <= 0 && nextPokemon != currentPokemon && count < pokemonList.size());
	currentPokemon = nextPokemon;
}

/**
 * Intent: Check if the player is opposing
 * Pre: None
 * Post: Return true if the player is opposing
 */
bool Player::getIsOpposing() const
{
	return isOpposing;
}

/**
 * Intent: Restore the player's Pokemon
 * Pre: None
 * Post: None
 */
void Player::restoreAllPokemon()
{
	for (int i = 0; i < pokemonList.size(); i++)
	{
		pokemonList[i].restore();
	}
}

/**
 * Intent: Is a Pokemon existing in the player's Pokemon list
 * Pre: name is a string
 * Post: Return true if the Pokemon is existing
 */
bool Player::isPokemonExist(string name) const
{
	for (int i = 0; i < pokemonList.size(); i++)
	{
		if (pokemonList[i].getName() == name)
		{
			return true;
		}
	}
	return false;
}
