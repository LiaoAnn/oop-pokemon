/***********************************************************************
 * File: Type.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-13
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-13
 * Description: Implementation for Type
************************************************************************/
#include "Type.h"

map<string, int>typeMap =
{
	{"normal", normal},
	{"fire", fire},
	{"water", water},
	{"electric", electric},
	{"grass", grass},
	{"ice", ice},
	{"fighting", fighting},
	{"poison", poison},
	{"ground", ground},
	{"flying", flying},
	{"psychic", psychic},
	{"bug", bug},
	{"rock", rock},
	{"ghost", ghost},
	{"dragon", dragon},
	{"dark", dark},
	{"steel", steel},
	{"fairy", fairy}
};

map<double, int> typeEffectMap =
{
	{0.0, NO_EFFECT},
	{0.5, NOT_VERY_EFFECTIVE},
	{1.0, NORMALLY_EFFECTIVE},
	{2.0, SUPER_EFFECTIVE}
};
