/***********************************************************************
 * File: SkillEffect.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-30
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-30
 * Description: Implementation for SkillEffect
************************************************************************/
#include "SkillEffect.h"
#include "SkillEffectList.h"
#include "json.h"
#include "Player.h"

/**
 * Intent: Default constructor
 * Pre: None
 * Post: A SkillEffect object
 */
SkillEffect::SkillEffect()
	:
	name("none"),
	type(0),
	leftRound(0)
{}

/**
 * Intent: Constructor
 * Pre: skillEffectAttack is an integer, skillEffectName
 * Post: A SkillEffect object
 */
SkillEffect::SkillEffect(int type, string name, double power, int leftRound)
	:
	name(name),
	type(type),
	power(power),
	leftRound(leftRound)
{}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
SkillEffect::~SkillEffect()
{
}

/**
 * Intent: Get the name of the skill effect
 * Pre: None
 * Post: A string
 */
string SkillEffect::getName() const
{
	return name;
}

/**
 * Intent:
 * Pre:
 * Post:
 */
json SkillEffect::toJson()
{
	json j;
	j["name"] = name;
	j["type"] = (type == DOT) ? "DoT" : "Debuff";
	j["power"] = power;
	//j["leftRound"] = leftRound;
	return j;
}

/**
 * Intent: Get the type of the skill effect
 * Pre: None
 * Post: An integer
 */
int SkillEffect::getSkillEffectType() const
{
	return type;
}

/**
 * Intent: Get the left round of the skill effect
 * Pre: None
 * Post: An integer
 */
int SkillEffect::getLeftRound() const
{
	return leftRound;
}

/**
 * Intent: Reduce the left round of the skill effect
 * Pre: None
 * Post: None
 */
void SkillEffect::reduceLeftRound()
{
	leftRound--;
}

/**
 * Intent: Check if pokemon has skill effect
 * Pre: None
 * Post: A boolean
 */
bool SkillEffect::operator==(const SkillEffect& skillEffect) const
{
	return name == skillEffect.name;
}

/**
 * Intent: Get the power of the skill effect
 * Pre: None
 * Post: A double
 */
double SkillEffect::getPower() const
{
	return power;
}

/**
 * Intent: operator overload
 * Pre: effect1 and effect2 are SkillEffect objects
 * Post: A boolean
 */
bool operator==(const SkillEffect& effect1, const SkillEffect& effect2)
{
	return effect1.getName() == effect2.getName();
}

/**
 * Intent: Default constructor
 * Pre: None
 * Post: A Poison object
 */
Poison::Poison()
	:
	SkillEffect(DOT, "psn", SKILL_EFFECT_DAMAGE_POWER[POISON])
{}

/**
 * Intent: Constructor
 * Pre: leftRound is an integer
 * Post: A Poison object
 */
Poison::Poison(int leftRound)
	:
	SkillEffect(DOT, "psn", SKILL_EFFECT_DAMAGE_POWER[POISON], leftRound)
{}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
Poison::~Poison()
{
}

/**
 * Intent: Print message when get skill effect
 * Pre: None
 * Post: None
 */
string Poison::printGotMessage(string pokemonName, bool isOpposing) const
{
	string log = "";
	if (isOpposing)
		log += OPPOSING_PREFIX;

	return log + pokemonName + " was poisoned!";
}

/**
 * Intent: Print message when skill effect affect
 * Pre: None
 * Post: None
 */
string Poison::printAffactMessage(string pokemonName, bool isOpposing) const
{
	string log = "";
	if (isOpposing)
		log += OPPOSING_PREFIX;

	return log + pokemonName + " is hurt by its poisoning!";
}

/**
 * Intent: Default constructor
 * Pre: None
 * Post: A Burn object
 */
Burn::Burn()
	:
	SkillEffect(DOT, "brn", SKILL_EFFECT_DAMAGE_POWER[BURN])
{}

/**
 * Intent: Constructor
 * Pre: leftRound is an integer
 * Post: A Burn object
 */
Burn::Burn(int leftRound)
	:
	SkillEffect(DOT, "brn", SKILL_EFFECT_DAMAGE_POWER[BURN], leftRound)
{}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
Burn::~Burn()
{
}

/**
 * Intent: Print message when get skill effect
 * Pre: None
 * Post: None
 */
string Burn::printGotMessage(string pokemonName, bool isOpposing) const
{
	string log = "";
	if (isOpposing)
		log += OPPOSING_PREFIX;

	return log + pokemonName + " was burned!";
}

/**
 * Intent: Print message when skill effect affect
 * Pre: None
 * Post: None
 */
string Burn::printAffactMessage(string pokemonName, bool isOpposing) const
{
	string log = "";
	if (isOpposing)
		log += OPPOSING_PREFIX;

	return log + pokemonName + " is hurt by its burn!";
}

/**
 * Intent: Default constructor
 * Pre: None
 * Post: A Paralysis object
 */
Paralysis::Paralysis()
	:
	SkillEffect(DEBUFF, "par", SKILL_EFFECT_DAMAGE_POWER[PARALYSIS])
{}

/**
 * Intent: Constructor
 * Pre: leftRound is an integer
 * Post: A Paralysis object
 */
Paralysis::Paralysis(int leftRound)
	:
	SkillEffect(DEBUFF, "par", SKILL_EFFECT_DAMAGE_POWER[PARALYSIS], leftRound)
{}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
Paralysis::~Paralysis()

{
}

/**
 * Intent: Print message when get skill effect
 * Pre: None
 * Post: None
 */
string Paralysis::printGotMessage(string pokemonName, bool isOpposing) const
{
	string log = "";
	if (isOpposing)
		log += OPPOSING_PREFIX;

	return log + pokemonName + " is paralyzed, so it may be unable to move!";
}

/**
 * Intent: Print message when skill effect affect
 * Pre: None
 * Post: None
 */
string Paralysis::printAffactMessage(string pokemonName, bool isOpposing) const
{
	string log = "";
	if (isOpposing)
		log += OPPOSING_PREFIX;

	return log + pokemonName + " is paralyzed!\r\nIt can't move!";
}
