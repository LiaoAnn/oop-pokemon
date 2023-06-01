/***********************************************************************
 * File: SkillEffectList.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-30
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-30
 * Description: Definition all type of skill effect
 ************************************************************************/
#pragma once

#include "SkillEffect.h"

 // All effect
extern SkillEffect* SkillEffectList[3];

// All type of skill effect
enum SkillEffectType
{
	DOT,
	DEBUFF,
};

// All category of skill effect
enum SkillEffectCategory
{
	PARALYSIS,
	POISON,
	BURN,
};