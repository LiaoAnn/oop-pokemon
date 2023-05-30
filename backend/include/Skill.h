/***********************************************************************
 * File: Skill.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-30
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-30
 * Description: Definition of Skill
************************************************************************/
#pragma once
#include <string>
#include "SkillEffect.h"

using namespace std;

class Skill {
public:
	Skill();
	Skill(string name, int type, int category, int power, int accuracy, int pp, SkillEffect* effect);
	~Skill();

	string getName() const;
	int getType() const;
	int getCategory() const;
	int getPower() const;
	int getAccuracy() const;
	int getPP() const;
	SkillEffect* Skill::getEffect() const;

	void reducePP();
private:
	string name;  // Name of the skill
	int type;  // Type of the skill, e.g., Fire, Water, Grass, etc.
	int category;  // Category of the skill, e.g., Physical, Special
	int power;  // Power of the skill
	int accuracy;  // Accuracy of the skill
	int pp;  // PP value of the skill, indicating the number of times it can be used
	SkillEffect* effect;  // Special effects of the skill, e.g. paralysis, Burn, Poison
};
