/***********************************************************************
 * File: Move.h
 * Author: 劉耀恩
 * Create Date: 2023/06/15
 * Editor: 劉耀恩
 * Update Date: 2023/06/15
 * Description: Definition of Move
 ************************************************************************/
#pragma once
#include <iostream>
#include "Type.h"
using namespace std;
class Move {
private:
	string moveName, phs;
	int power1, power2, power3;
	type typeList;
	//AdditionalEffect effect;
public:
	/*Move(string name, type typeList, string phs, int power1, int power2, int power3,
		AdditionalEffect effect) :moveName(name), typeList(typeList), phs(phs),
		power1(power1), power2(power2), power3(power3), effect(effect) {};*/
	string getName();
};