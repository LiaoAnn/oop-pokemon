/***********************************************************************
 * File: Skill.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-30
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-13
 * Description: Implementation for Skill
************************************************************************/
#include "Skill.h"
#include <iostream>
#include "SkillCategory.h"
#include "Map.h"
#include "Type.h"
#include "Chance.h"
#include "Game.h"
#include "GameMode.h"

using namespace std;

vector<Skill> skillList;

/**
 * Intent: Default Constructor
 * Pre: None
 * Post: Skill object
 */
Skill::Skill()
	: name(""),
	type(0),
	category(0),
	power(0),
	accuracy(0),
	pp(0),
	effect()
{}

/**
 * Intent: Constructor
 * Pre: name is a string, type is an integer, power is an integer, accuracy is an integer, pp is an integer
 * Post: Skill object
 */
Skill::Skill(string name, int type, int category, int power, int accuracy, int pp)
	:
	name(name),
	type(type),
	category(category),
	power(power),
	accuracy(accuracy),
	pp(pp),
	maxPP(pp),
	effect()
{}

/**
 * Intent: Constructor
 * Pre: name is a string, type is an integer, power is an integer, accuracy is an integer, pp is an integer, effect is an integer
 * Post: Skill object
 */
Skill::Skill(string name, int type, int category, int power, int accuracy, int pp, SkillEffect* effect)
	:
	name(name),
	type(type),
	category(category),
	power(power),
	accuracy(accuracy),
	pp(pp),
	maxPP(pp),
	effect(effect)
{}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
Skill::~Skill()
{
	//dtor
}

/**
 * Intent: Get the name of the skill
 * Pre: None
 * Post: Return the name of the skill
 */
string Skill::getName() const
{
	return name;
}

/**
 * Intent: Get the type of the skill
 * Pre: None
 * Post: Return the type of the skill
 */
int Skill::getType() const
{
	return type;
}

/**
 * Intent: Get the category of the skill
 * Pre: None
 * Post: Return the category of the skill
 */
int Skill::getCategory() const
{
	return category;
}

/**
 * Intent: Get the power of the skill
 * Pre: None
 * Post: Return the power of the skill
 */
int Skill::getPower() const
{
	return power;
}

/**
 * Intent: Get the accuracy of the skill
 * Pre: None
 * Post: Return the accuracy of the skill
 */
int Skill::getAccuracy() const
{
	return accuracy;
}

/**
 * Intent: Get the pp of the skill
 * Pre: None
 * Post: Return the pp of the skill
 */
int Skill::getPP() const
{
	return pp;
}

/**
 * Intent: Get the effect of the skill
 * Pre: None
 * Post: Return the effect of the skill
 */
SkillEffect* Skill::getEffect()
{
	return effect;
}

/**
 * Intent: Reduce the pp of the skill
 * Pre: None
 * Post: None
 */
void Skill::reducePP()
{
	pp--;
}

/**
 * Intent: Set the effect of the skill
 * Pre: effect is a SkillEffect object
 * Post: None
 */
void Skill::setEffect(SkillEffect* effect)
{
	this->effect = effect;
}

/**
 * Intent: Find the skill by name
 * Pre: name is a string
 * Post: Return the index of the skill
 */
int findSkillByName(string name)
{
	for (int i = 0; i < skillList.size(); i++)
	{
		if (skillList[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

/**
 * Intent: Use the skill
 * Pre: user is a Pokemon object
 * Pre: target is a Pokemon object
 * Pre: isOpposing is a boolean if the userPokemon is opposing
 * Post: None
 */
int Skill::useSkill(Pokemon& userPokemon, Pokemon& targetPokemon, bool isOpposing)
{
	string log;
	int level = userPokemon.getLevel(),
		userPokemonAttack = 0,
		tarketPokemonDefense = 0,
		userDamage = 0;
	double
		accuracyChance = (game.mode == TEST) ? 1 : getAccuracy() / 100.0,
		criticalChance = (game.mode == TEST) ? 0 : CRITICAL_CHANCE,
		typeEffectPower = 1;
	bool
		isHit = false,
		isCritical = false,
		isSTAB = false;

	set<int>userPokemonType = userPokemon.getType();
	set<int>targetPokemonType = targetPokemon.getType();
	int skillType = this->type;

	// Check if the skill type is the same as the userPokemon type
	for (set<int>::iterator it = userPokemonType.begin(); it != userPokemonType.end(); it++)
	{
		if (*it == skillType)
		{
			isSTAB = true;
			break;
		}
	}

	// Check if the skill hits
	isHit = checkChance(accuracyChance);
	// Check if the skill is critical
	isCritical = checkChance(criticalChance);

	// Check for the current atk and def type for calculation
	if (category == PHYSICAL)
	{
		userPokemonAttack = userPokemon.getAttack();
		tarketPokemonDefense = targetPokemon.getDefence();
	}

	if (category == SPECIAL)
	{
		userPokemonAttack = userPokemon.getSpAttack();
		tarketPokemonDefense = targetPokemon.getSpDefence();
	}

	// Calulate the type effect power
	for (set<int>::iterator it = targetPokemonType.begin(); it != targetPokemonType.end(); it++)
	{
		typeEffectPower *= typeEffectiveness[skillType][*it];
	}

	if (category != STATUS)
	{
		float floatPower = 0;
		floatPower = ((float)(2 * level + 10) / 250);
		floatPower *= (float)power;
		floatPower *= ((float)userPokemonAttack / tarketPokemonDefense);
		floatPower += 2;

		floatPower *= isCritical ? CRITICAL_POWER : 1;
		floatPower *= isSTAB ? STAB_POWER : 1;
		floatPower *= typeEffectPower;

		userDamage = (int)floatPower;
	}

	if (isOpposing)
		log += OPPOSING_PREFIX;

	if (isHit)
	{
		game << log + userPokemon.getName() + " used " + name + "!";

		// Check if the skill is a status skill
		if (category == STATUS)
		{
			targetPokemon.addCurrentStat(effect);
			game << effect->printGotMessage(targetPokemon.getName(), !isOpposing);
			return 0;
		}

		targetPokemon.hurtHp(userDamage);

		if (isCritical)
			game << log + "A critical hit!";

		if (typeEffectPower == TYPE_EFFECT_POWER[NO_EFFECT])
			game << "It's not effective...";

		if (typeEffectPower > TYPE_EFFECT_POWER[NO_EFFECT] &&
			typeEffectPower <= TYPE_EFFECT_POWER[NOT_VERY_EFFECTIVE]
			)
			game << "It's not very effective...";

		if (typeEffectPower > TYPE_EFFECT_POWER[NOT_VERY_EFFECTIVE] &&
			typeEffectPower < TYPE_EFFECT_POWER[SUPER_EFFECTIVE])
			game << "It's effective!";

		if (typeEffectPower >= TYPE_EFFECT_POWER[SUPER_EFFECTIVE])
			game << "It's super effective!";

		if (effect != NULL)
		{
			targetPokemon.addCurrentStat(effect);
			game << effect->printGotMessage(targetPokemon.getName(), !isOpposing);
		}
	}
	else
	{
		string log;
		if (isOpposing)
			log = OPPOSING_PREFIX;
		game << log + targetPokemon.getName() + " avoided the attack!";
	}
}

/**
 * Intent: Get skill's max pp
 * Pre: None
 * Post: Return skill's max pp
 */
int Skill::getMaxPP() const
{
	return maxPP;
}

/**
 * Intent: Turn skill into a JSON object
 * Pre: None
 * Post: Return a JSON object
 */
json Skill::toJson()
{
	json j;
	string attackKind = getKeyFromValue<string>(skillCategoryMap, this->category);
	string attribute = getKeyFromValue<string>(typeMap, this->type);

	j["name"] = name;
	j["attribute"] = attribute;
	j["attackKind"] = attackKind;
	j["power"] = power;
	j["accuracy"] = accuracy;
	j["currentPP"] = pp;
	j["totalPP"] = maxPP;
	j["effect"] = effect->toJson();
	return j;
}

/**
 * Intent: Restore the skill to the original state
 * Pre: None
 * Post: None
 */
void Skill::restore()
{
	pp = maxPP;
}
