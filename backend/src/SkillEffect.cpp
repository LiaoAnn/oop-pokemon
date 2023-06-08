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
SkillEffect::SkillEffect(int type, string name, int leftRound)
	:
	name(name),
	type(type),
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
string SkillEffect::getSkillEffectName() const
{
	return name;
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
 * Intent: Print message when get skill effect
 * Pre: None
 * Post: None
 */
string SkillEffect::printGotMessage(string pokemonName) const
{
	return "";
}

/**
 * Intent: Print message when skill effect affect
 * Pre: None
 * Post: None
 */
string SkillEffect::printAffactMessage(string pokemonName) const
{
	return "";
}

/**
 * Intent: Default constructor
 * Pre: None
 * Post: A Poison object
 */
Poison::Poison()
	:
	SkillEffect(DOT, "psn")
{}

/**
 * Intent: Constructor
 * Pre: leftRound is an integer
 * Post: A Poison object
 */
Poison::Poison(int leftRound)
	:
	SkillEffect(DOT, "psn", leftRound)
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
string Poison::printGotMessage(string pokemonName) const
{
	return pokemonName + " was poisoned!";
}

/**
 * Intent: Print message when skill effect affect
 * Pre: None
 * Post: None
 */
string Poison::printAffactMessage(string pokemonName) const
{
	return pokemonName + " is hurt by its poisoning!";
}

/**
 * Intent: Default constructor
 * Pre: None
 * Post: A Burn object
 */
Burn::Burn()
	:
	SkillEffect(DOT, "brn")
{}

/**
 * Intent: Constructor
 * Pre: leftRound is an integer
 * Post: A Burn object
 */
Burn::Burn(int leftRound)
	:
	SkillEffect(DOT, "brn", leftRound)
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
string Burn::printGotMessage(string pokemonName) const
{
	return pokemonName + " was burned!";
}

/**
 * Intent: Print message when skill effect affect
 * Pre: None
 * Post: None
 */
string Burn::printAffactMessage(string pokemonName) const
{
	return pokemonName + " is hurt by its burn!";
}

/**
 * Intent: Default constructor
 * Pre: None
 * Post: A Paralysis object
 */
Paralysis::Paralysis()
	:
	SkillEffect(DEBUFF, "par")
{}

/**
 * Intent: Constructor
 * Pre: leftRound is an integer
 * Post: A Paralysis object
 */
Paralysis::Paralysis(int leftRound)
	:
	SkillEffect(DEBUFF, "par", leftRound)
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
string Paralysis::printGotMessage(string pokemonName) const
{
	return pokemonName + " is paralyzed, so it may be unable to move!";
}

/**
 * Intent: Print message when skill effect affect
 * Pre: None
 * Post: None
 */
string Paralysis::printAffactMessage(string pokemonName) const
{
	return pokemonName + " is paralyzed!\r\nIt can't move!";
}