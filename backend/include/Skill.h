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
#include <vector>
#include "SkillEffect.h"
#include "Pokemon.h"

using namespace std;

class Pokemon;

class Skill {
private:
	string name;  // Name of the skill
	int type;  // Type of the skill, e.g., Fire, Water, Grass, etc.
	int category;  // Category of the skill, e.g., Physical, Special
	int power;  // Power of the skill
	int accuracy;  // Accuracy of the skill
	int pp;  // PP value of the skill, indicating the number of times it can be used
	SkillEffect* effect;  // Special effects of the skill, e.g. paralysis, Burn, Poison
public:
	// Default constructor
	Skill();
	// Constructor with parameters
	Skill(string name, int type, int category, int power, int accuracy, int pp);
	Skill(string name, int type, int category, int power, int accuracy, int pp, SkillEffect* effect);
	// Destructor
	~Skill();

	// Get Skill name
	string getName() const;
	// Get Skill type
	int getType() const;
	// Get Skill category
	int getCategory() const;
	// Get Skill power
	int getPower() const;
	// Get Skill accuracy
	int getAccuracy() const;
	// Get Skill PP
	int getPP() const;
	// Get Skill effect
	SkillEffect* Skill::getEffect();

	// Set Skill Effect
	void setEffect(SkillEffect* effect);

	// Reduce PP by 1
	void reducePP();

	// Find Skill index in skillList by name
	friend int findSkillByName(string name);

	// Use skill
	void useSkill(Pokemon& user, Pokemon& target);
};

extern vector<Skill> skillList;  // List of all skills
