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
	PARALYSIS,
	POISON,
	BURN,
};

SkillEffect SkillEffectList[] = {
	SkillEffect(0,"PAR","Paralysis"),
	SkillEffect(10,"PSN","Poison"),
	SkillEffect(10,"BRN","Burn"),
};
