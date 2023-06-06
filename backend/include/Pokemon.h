﻿/***********************************************************************
 * File: Pokemon.h
 * Author: 劉耀恩
 * Create Date: 2023/05/30
 * Editor: 劉耀恩
 * Update Date: 2023/05/30
 * Description: Definition of Pokemon class
***********************************************************************/
#pragma once
#include <iostream>
#include <vector>
#include <set>
using namespace std;
enum pokemonStat { hp, attack, defence, spAttack, spDefence, speed };
class Pokemon
{
private:
	string name; // name of pokemon
	int typeNum; // number of types
	set <int> type; // type of pokemon
	int hp; // health points
	int attack; // attack points
	int defence; // defence points
	int spAttack; // special attack points
	int spDefence; // special defence points
	int speed; // speed points
	vector <int> currentStat; // current stats
public:
	// Constructor
	Pokemon(string name, int typeNum, set <int> type, int hp, int attack, int defence, int spAttack, int spDefence, int speed);

	// Copy Constructor
	Pokemon(const Pokemon& pokemon);

	// Destructor
	~Pokemon();

	// Getters
	string getName() const;
	int getTypeNum()  const;
	set <int> getType() const;
	int getHp() const;
	int getAttack() const;
	int getDefence() const;
	int getSpAttack() const;
	int getSpDefence() const;
	int getSpeed() const;
	vector <int> getCurrentStat() const;

	// Setters
	void setName(string name);
	void setTypeNum(int typeNum);
	void setType(set <int> type);
	void setHp(int hp);
	void setAttack(int attack);
	void setDefence(int defence);
	void setSpAttack(int spAttack);
	void setSpDefence(int spDefence);
	void setSpeed(int speed);
	void setCurrentStat(vector <int> currentStat);
};

extern vector <Pokemon> pokemonList; // list of all pokemon