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
#include <map>

using namespace std;

// All category of skill effect
enum SKILL_EFFECT_CATEGORY
{
	PARALYSIS,
	POISON,
	BURN,
};
extern const double SKILL_EFFECT_DAMAGE_POWER[3];
extern map<string, int> skillEffectTypeMap;

string getSkillEffectCategoryName(int category);

// All effect
extern SkillEffect* skillEffectList[3];

// All type of skill effect
enum SKILL_EFFECT_TYPE
{
	DOT,
	DEBUFF,
};