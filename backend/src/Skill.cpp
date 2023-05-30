/***********************************************************************
 * File: Skill.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-30
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-30
 * Description: Implementation for Skill
************************************************************************/
#include "Skill.h"
#include <iostream>

using namespace std;

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
	effect(0)
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
SkillEffect* Skill::getEffect() const
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
