/**
 * File: SkillEffectList.cpp
 * Author: BING-JIA TAN (b11115001@gapps.ntust.edu.tw)
 * Create Date: 2023-06-02
 * Editor: BING-JIA TAN (b11115001@gapps.ntust.edu.tw)
 * Update Date: 2023-06-02
 * Description: Implementation for SkillEffectList
 */

#include "SkillEffectList.h"

 // All effect
SkillEffect* SkillEffectList[3] =
{
	new Paralysis(),
	new Poison(),
	new Burn(),
};