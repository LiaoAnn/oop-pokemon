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

// All type of skill effect
enum SkillEffectType
{
	DAMAGE,
	STUN,
};

// All category of skill effect
enum SkillEffectCategory
{
	PARALYSIS,
	POISON,
	BURN,
};

// All type of skill effect

SkillEffect SkillEffectList[] = {
	SkillEffect(0, SkillEffectType::STUN, "PAR", "Paralysis"),
	SkillEffect(10, SkillEffectType::DAMAGE, "PSN", "Poison"),
	SkillEffect(10, SkillEffectType::DAMAGE, "BRN", "Burn"),
};
