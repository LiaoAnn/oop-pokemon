/***********************************************************************
 * File: Command.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-14
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-14
 * Description: Implementation for Command
************************************************************************/

#include "Command.h"


/**
 * Intent: Return the result of attack command
 * Pre:
 * Post:
 */
json attactCommandResult
(
	Pokemon& firstPokemon, Pokemon& secondPokemon,
	Skill& firstSkill, Skill& secondSkill,
	int firstDamage, int secondDamage,
	int firstPlayerIndex
)
{
	json result = json();
	json myMonsterJson = (firstPlayerIndex == 0)
		? firstPokemon.toJson() : secondPokemon.toJson();
	json otherMonsterJson = (firstPlayerIndex == 0)
		? secondPokemon.toJson() : firstPokemon.toJson();
	json myMoveJson = (firstPlayerIndex == 0)
		? firstSkill.toJson() : secondSkill.toJson();
	json otherMoveJson = (firstPlayerIndex == 0)
		? secondSkill.toJson() : firstSkill.toJson();

	int myDamage = (firstPlayerIndex == 0) ? firstDamage : secondDamage;
	int otherDamage = (firstPlayerIndex == 0) ? secondDamage : firstDamage;

	result["type"] = "attack";
	result["success"] = true;
	result["attackFirst"] = (firstPlayerIndex == 0) ? "me" : "other";

	result["myDamage"] = (firstPlayerIndex == 0) ? myDamage : otherDamage;
	result["myMove"] = myMoveJson;
	result["myMonster"] = myMonsterJson;

	result["otherDamage"] = (firstPlayerIndex == 0) ? myDamage : otherDamage;
	result["otherMove"] = otherMoveJson;
	result["otherMonster"] = otherMonsterJson;

	return result;
}