/***********************************************************************
 * File: Command.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-14
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-14
 * Description: Header file for Command
************************************************************************/

#include "json.h"
#include "Pokemon.h"
#include "Skill.h"

// attach command result to json
json attactCommandResult
(
	Pokemon& firstPokemon, Pokemon& secondPokemon,
	Skill& firstSkill, Skill& secondSkill,
	int firstDamage, int secondDamage,
	int firstPlayerIndex
);

// Player Pokemon fainted result
json playerPokemonFainted(bool isOpposing);
