/***********************************************************************
 * File: Pokemon.h
 * Author: 劉耀恩
 * Create Date: 2023/05/30
 * Editor: 劉耀恩, B11115001
 * Update Date: 2023/05/30
 * Description: Definition of Pokemon class
***********************************************************************/
#pragma once
#include <iostream>
#include <vector>
#include <set>
#include "Skill.h"
#include "SkillEffect.h"
#include "json.h"

using namespace std;
enum pokemonStat { hp, attack, defence, spAttack, spDefence, speed };
class Skill;
class SkillEffect;

const int LEVEL = 50;

class Pokemon
{
private:
	string name; // name of pokemon
	int typeNum; // number of types
	set <int> type; // type of pokemon
	int hp; // health points
	int maxHp; // max health points
	int attack; // attack points
	int defence; // defence points
	int spAttack; // special attack points
	int spDefence; // special defence points
	int speed; // speed points
	int level = LEVEL; // level of pokemon
	vector<SkillEffect*> currentStat; // current stats
	vector<Skill> skillList; // list of skills
public:
	// Default Constructor
	Pokemon();

	// Constructor
	Pokemon(string name, int typeNum, set <int> type, int hp, int attack, int defence, int spAttack, int spDefence, int speed);

	// Copy Constructor
	Pokemon(const Pokemon& pokemon);

	// Destructor
	~Pokemon();

	// Getters
	string getName() const;
	int getTypeNum()  const;
	set<int> getType() const;
	int getHp() const;
	int getAttack() const;
	int getDefence() const;
	int getSpAttack() const;
	int getSpDefence() const;
	int getSpeed() const;
	int getMaxHp() const;
	vector<SkillEffect*> getCurrentStats() const;
	int getLevel() const;
	vector<Skill> getSkillList() const;

	// Setters
	void setName(string name);
	void setType(set <int> type);
	void setHp(int hp);
	void setAttack(int attack);
	void setDefence(int defence);
	void setSpAttack(int spAttack);
	void setSpDefence(int spDefence);
	void setSpeed(int speed);

	// Add a type to the type list
	void addType(int type);

	// Check if pokemon is alive
	bool isAlive() const;
	// Heal the pokemon
	void healHp(int points);

	// Restore the pokemon to the original state
	void restore();

	// Add a stat to the current stat list
	void addCurrentStat(SkillEffect* stat);
	// Scan the current stat list and remove the stat if it turns to 0
	void removeCurrentStat();
	// Check if pokemon has skill effect
	bool checkSkillEffect(const SkillEffect* skillEffect) const;
	bool isCanNotMove(bool isOpposing);
	bool isHurtByDot(bool isOpposing);

	// Overload operator [] to get skill by index or name
	Skill& operator[](int index);
	Skill& operator[](string name);
	// Add a skill to the skill list
	void addSkill(Skill skill);

	friend int findPokemonByName(string name);

	// Pokemon actions
	void action(Pokemon& opposing, string skill);

	// To JSON
	json toJson();

	// Check if pokemon has skill
	bool hasSkill(string skillName);
};

extern vector <Pokemon> pokemonList; // list of all pokemon