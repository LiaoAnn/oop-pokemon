/***********************************************************************
 * File: SkillEffect.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-30
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-30
 * Description: Definition of SkillEffect
************************************************************************/
#pragma once

#include <string>
using namespace std;

class SkillEffect
{
private:
	int skillEffectAttack;
	string skillEffectName;
	string skillEffectDescription;
public:
	// Default Constructor
	SkillEffect();
	// Constructor
	SkillEffect(int skillEffectAttack, string skillEffectName, string skillEffectDescription);
	// Destructor
	~SkillEffect();

	// Get attack of skill effect
	int getSkillEffectAttack() const;
	// Get name of skill effect
	string getSkillEffectName() const;
	// Get description of skill effect
	string getSkillEffectDescription() const;
};