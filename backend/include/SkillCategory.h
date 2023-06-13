/***********************************************************************
 * File: SkillCategory.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-06
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-06
 * Description: Definition of SkillCategory
************************************************************************/
#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

enum SkillCategory
{
	PHYSICAL,
	SPECIAL,
	STATUS
};

extern map<string, int> skillCategoryMap;
