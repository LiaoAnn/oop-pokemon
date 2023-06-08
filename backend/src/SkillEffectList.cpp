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
SkillEffect skillEffectList[3] =
{
	Paralysis(),
	Poison(),
	Burn(),
};

// All effect name
map<string, int> skillEffectTypeMap =
{
	{ "par", PARALYSIS },
	{ "psn", POISON },
	{ "brn", BURN },
};

/**
 * Intent: Get skill effect category name
 * Pre: category
 * Post: return skill effect category name by skillEffectTypeMap
 */
string getSkillEffectCategoryName(int category)
{
	for (auto it = skillEffectTypeMap.begin(); it != skillEffectTypeMap.end(); it++)
	{
		if (it->second == category)
		{
			return it->first;
		}
	}
	return "";
}
