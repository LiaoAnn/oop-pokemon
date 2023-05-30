/***********************************************************************
 * File: SkillEffect.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-30
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-30
 * Description: Implementation for SkillEffect
************************************************************************/
#include "SkillEffect.h"

/**
 * Intent: Default constructor
 * Pre: None
 * Post: A SkillEffect object
 */
SkillEffect::SkillEffect()
	:
	skillEffectAttack(0),
	skillEffectName(""),
	skillEffectDescription("")
{
}

/**
 * Intent: Constructor
 * Pre: skillEffectAttack is an integer, skillEffectName and skillEffectDescription are strings
 * Post: A SkillEffect object
 */
SkillEffect::SkillEffect(int skillEffectAttack, string skillEffectName, string skillEffectDescription)
	:
	skillEffectAttack(skillEffectAttack),
	skillEffectName(skillEffectName),
	skillEffectDescription(skillEffectDescription)
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
 * Intent: Get the attack of the skill effect
 * Pre: None
 * Post: An integer
 */
int SkillEffect::getSkillEffectAttack() const
{
	return skillEffectAttack;
}

/**
 * Intent: Get the name of the skill effect
 * Pre: None
 * Post: A string
 */
string SkillEffect::getSkillEffectName() const
{
	return skillEffectName;
}

/**
 * Intent: Get the description of the skill effect
 * Pre: None
 * Post: A string
 */
string SkillEffect::getSkillEffectDescription() const
{
	return skillEffectDescription;
}


