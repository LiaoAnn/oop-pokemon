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
 * Pre: user is a Pokemon object, target is a Pokemon object
 * Post: None
 */

void Skill::useSkill(Pokemon& user, Pokemon& target)
{
	srand(time(NULL));
	float critical = 1, stab = 1;
	int level = 50;
	int userhp = user.getHp(), targethp = target.getHp();
	int useratk = user.getAttack(), userspatk = user.getSpAttack(), userdef = user.getDefence(), userspdef = user.getSpDefence();
	int targetatk = target.getAttack(), targetspatk = target.getSpAttack(), targetdef = target.getDefence(), targetspdef = target.getSpDefence();
	int userdamage, targetdamage;
	bool userfirst, sametype = false, escape;
	if (user.getSpeed() >= target.getSpeed()) {
		userfirst = true;
	}
	else {
		userfirst = false;
	}
	set<int>usertype = user.getType();
	set<int>targettype = target.getType();


	for (auto i : usertype) {
		for (auto j : targettype) {
			if (i == j) {
				stab = 1.5;
				sametype = true;
				break;
			}
		}
		if (sametype)break;
	}
	while (userhp <= 0 || targethp <= 0) {

		if (userfirst) {
			if (criticalchance(critical)) {
				critical = 1.5;
			}
			else {
				critical = 1;
			}
			if (escapechance(escape)) {
				escape = true;
			}
			else {
				escape = false;
			}
			userdamage = ((2 * level + 10) / 250 * useratk * (userspatk / targetdef) + 2) * critical * stab * type;
			if (!escape) {
				targethp -= userdamage;
			}

		}
		else {
			if (criticalchance(critical)) {
				critical = 1.5;
			}
			else {
				critical = 1;
			}
			if (escapechance(escape)) {
				escape = true;
			}
			else {
				escape = false;
			}
			targetdamage = (2 * level + 10) / 250 * targetatk * ((targetspatk / userdef) + 2) * critical * stab * type;
			if (!escape) {
				userhp -= targetdamage;
			}
		}
	}
	//userdamage = ((2 * level + 10) / 250 * useratk * (userspatk / targetdef) + 2) * critical * stab * type;

}
/**
 * Intent: add bool
 * Pre: critical chances
 * Post: None
 */
bool criticalchance(int criticalhit) {
	int criticalhit = rand() % 4;
	if (criticalhit == 1) {
		return true;
	}
	else {
		return false;
	}
}
/**
 * Intent: add bool
 * Pre: escape chances
 * Post: None
 */
bool escapechance(int escape) {
	int escapechance = rand() % 5;
	if (escapechance == 1) {
		return true;
	}
	else {
		return false;
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
