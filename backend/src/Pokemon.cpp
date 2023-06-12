/***********************************************************************
 * File: Pokemon.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-06
 * Editor: BING-JIA TAN (B11115001), Alan
 * Update Date: 2023-06-06
 * Description: Implementation for Pokemon class
************************************************************************/
#include "Pokemon.h"
#include "SkillEffectList.h"
#include "Game.h"
#include "Chance.h"
#include "GameMode.h"
//Pokemon::Pokemon(string name, set<int> typeList,
//	int HP, float atk, float def, float sPatk, float sPdef, float speed) {
//	atkList.push_back(atk);
//	atkList.push_back(sPatk);
//	defList.push_back(def);
//	defList.push_back(sPdef);
//}
//void Pokemon::battle(string play1, string play2) {
//
//}
//string Pokemon::getName() {
//	return name;
//}
//void Pokemon::skillMove(Move skill) {
//
//}

vector<Pokemon> pokemonList;

/**
 * Intent: Default Constructor
 * Pre: None
 * Post: A Pokemon object
 */
Pokemon::Pokemon()
	:
	name(""),
	type(set <int>()),
	hp(0),
	attack(0),
	defence(0),
	spAttack(0),
	spDefence(0),
	speed(0),
	maxHp(0),
	typeNum(0),
	skillList(vector <Skill>())
{}

/**
 * Intent: Constructor
 * Pre: name is a string,
		typeNum is an integer,
		type is a set of integers,
		hp, attack, defence, spAttack, spDefence, speed are integers
 * Post: A Pokemon object
 */
Pokemon::Pokemon
(
	string name,
	int typeNum,
	set <int> type,
	int hp,
	int attack,
	int defence,
	int spAttack,
	int spDefence,
	int speed
)
	:
	name(name),
	typeNum(typeNum),
	type(type),
	hp(hp),
	maxHp(hp),
	attack(attack), defence(defence),
	spAttack(spAttack), spDefence(spDefence),
	speed(speed),
	skillList(vector <Skill>())
{}

/**
 * Intent: Copy Constructor
 * Pre: Pokemon object
 * Post: None
 */
Pokemon::Pokemon(const Pokemon& pokemon)
	:
	name(pokemon.name),
	type(pokemon.type),
	hp(pokemon.hp),
	maxHp(pokemon.maxHp),
	attack(pokemon.attack),
	defence(pokemon.defence),
	spAttack(pokemon.spAttack),
	spDefence(pokemon.spDefence),
	speed(pokemon.speed)
{
	for (int i = 0; i < pokemon.skillList.size(); i++)
	{
		skillList.push_back(pokemon.skillList[i]);
	}
}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
Pokemon::~Pokemon()
{}

/**
 * Intent: Get the name of the Pokemon
 * Pre: None
 * Post: Return the name of the Pokemon
 */
string Pokemon::getName() const
{
	return name;
}

/**
 * Intent: Get the type of the Pokemon
 * Pre: None
 * Post: Return the type of the Pokemon
 */
set <int> Pokemon::getType() const
{
	return type;
}

/**
 * Intent: Get the HP of the Pokemon
 * Pre: None
 * Post: Return the HP of the Pokemon
 */
int Pokemon::getHp() const
{
	return hp;
}

/**
 * Intent: Get the attack of the Pokemon
 * Pre: None
 * Post: Return the attack of the Pokemon
 */
int Pokemon::getAttack() const
{
	return attack;
}

/**
 * Intent: Get the defence of the Pokemon
 * Pre: None
 * Post: Return the defence of the Pokemon
 */
int Pokemon::getDefence() const
{
	return defence;
}

/**
 * Intent: Get the special attack of the Pokemon
 * Pre: None
 * Post: Return the special attack of the Pokemon
 */
int Pokemon::getSpAttack() const
{
	return spAttack;
}

/**
 * Intent: Get the special defence of the Pokemon
 * Pre: None
 * Post: Return the special defence of the Pokemon
 */
int Pokemon::getSpDefence() const
{
	return spDefence;
}

/**
 * Intent: Get the speed of the Pokemon. If the Pokemon is paralyzed, the speed will be halved.
 * Pre: None
 * Post: Return the speed of the Pokemon
 */
int Pokemon::getSpeed() const
{
	if (checkSkillEffect(skillEffectList[PARALYSIS]))
	{
		return speed / 2;
	}
	else
	{
		return speed;
	}
}

/**
 * Intent: Set the name of the Pokemon
 * Pre: name is a string
 * Post: None
 */
void Pokemon::setName(string name)
{
	this->name = name;
}

/**
 * Intent: Set the type of the Pokemon
 * Pre: type is a set of integers
 * Post: None
 */
void Pokemon::setType(set <int> type)
{
	this->type = type;
}

/**
 * Intent: Set the HP of the Pokemon
 * Pre: hp is an integer
 * Post: None
 */
void Pokemon::setHp(int hp)
{
	this->hp = hp;
}

/**
 * Intent: Set the attack of the Pokemon
 * Pre: attack is an integer
 * Post: None
 */
void Pokemon::setAttack(int attack)
{
	this->attack = attack;
}

/**
 * Intent: Set the defence of the Pokemon
 * Pre: defence is an integer
 * Post: None
 */
void Pokemon::setDefence(int defence)
{
	this->defence = defence;
}

/**
 * Intent: Set the special attack of the Pokemon
 * Pre: spAttack is an integer
 * Post: None
 */
void Pokemon::setSpAttack(int spAttack)
{
	this->spAttack = spAttack;
}

/**
 * Intent: Set the special defence of the Pokemon
 * Pre: spDefence is an integer
 * Post: None
 */
void Pokemon::setSpDefence(int spDefence)
{
	this->spDefence = spDefence;
}

/**
 * Intent: Set the speed of the Pokemon
 * Pre: speed is an integer
 * Post: None
 */
void Pokemon::setSpeed(int speed)
{
	this->speed = speed;
}

/**
 * Intent: Add a type to the Pokemon
 * Pre: type is an integer
 * Post: None
*/
void Pokemon::addType(int type)
{
	this->type.insert(type);
}

/**
 * Intent: Find the Pokemon by name
 * Pre: name is a string
 * Post: Return the index of the Pokemon in the vector if found, otherwise return -1
 */
int findPokemonByName(string name)
{
	for (int i = 0; i < pokemonList.size(); i++)
	{
		if (pokemonList[i].name == name)
			return i;
	}
	return -1;
}

/**
 * Intent: Add Skill to the Pokemon
 * Pre: skill is a Skill object
 * Post: None
 */
void Pokemon::addSkill(Skill skill)
{
	skillList.push_back(skill);
}

/**
 * Intent: Get the skill list of the Pokemon
 * Pre: None
 * Post: Return the skill list of the Pokemon
 */
vector<Skill> Pokemon::getSkillList() const
{
	return skillList;
}

/**
 * Intent: Operator overloading []
 * Pre: index is an integer
 * Post: Return the skill of the Pokemon by index
 */
Skill& Pokemon::operator[](int index)
{
	return skillList[index];
}

/**
 * Intent: Operator overloading []
 * Pre: name is a string
 * Post: Return the skill of the Pokemon by name
 */
Skill& Pokemon::operator[](string name)
{
	for (int i = 0; i < skillList.size(); i++)
	{
		if (skillList[i].getName() == name)
			return skillList[i];
	}
}

/**
 * Intent: Get current stat of the Pokemon
 * Pre: None
 * Post: Return the current stat of the Pokemon
 */
vector<SkillEffect*> Pokemon::getCurrentStats() const
{
	return currentStat;
}

/**
 * Intent: Remove a stat from the current stat of the Pokemon and reduce the left round of the stat by 1
 * Pre: stat is a SkillEffect object
 * Post: None
 */
void Pokemon::removeCurrentStat()
{
	for (int i = 0; i < currentStat.size(); i++)
	{
		if (currentStat[i]->getLeftRound() == 0)
		{
			currentStat.erase(currentStat.begin() + i);
			i--;
		}
		else
			currentStat[i]->reduceLeftRound();
	}
}

/**
 * Intent: Heal the Pokemon
 * Pre: points is an integer
 * Post: None
 */
void Pokemon::healHp(int points)
{
	hp += points;
	if (hp > maxHp)
		hp = maxHp;
}

/**
 * Intent: Get the max HP of the Pokemon
 * Pre: None
 * Post: Return the max HP of the Pokemon
 */
int Pokemon::getMaxHp() const
{
	return maxHp;
}

/**
 * Intent: Get the level of the Pokemon
 * Pre: None
 * Post: Return the level of the Pokemon
 */
int Pokemon::getLevel() const
{
	return level;
}

/**
 * Intent: Check if the Pokemon has status effect
 * Pre: statusEffect is a StatusEffect object
 * Post: Return true if the Pokemon has status effect, otherwise return false
 */
bool Pokemon::checkSkillEffect(const SkillEffect* skillEffect) const
{
	for (int i = 0; i < currentStat.size(); i++)
	{
		if (currentStat[i] == skillEffect)
			return true;
	}
	return false;
}

/**
 * Intent: Check if the Pokemon is alive
 * Pre: None
 * Post: Return true if the Pokemon is alive, otherwise return false
 */
bool Pokemon::isAlive() const
{
	return hp > 0;
}

/**
 * Intent: Add a stat to the current stat of the Pokemon
 * Pre: stat is a SkillEffect object
 * Post: None
 */
void Pokemon::addCurrentStat(SkillEffect* stat)
{
	currentStat.push_back(stat);
}

/**
 * Intent: Check if the Pokemon is can't move
 * Pre: isOpposing is a boolean
 * Post: Return true if the Pokemon is can't move, otherwise return false
 */
bool Pokemon::isCanNotMove(bool isOpposing)
{
	double paralysed = (game.mode == TEST) ? 1 : PARALYSIS_CHANCE;

	for (int i = 0; i < this->currentStat.size(); i++)
	{
		string log;
		// Paralysis
		if (this->currentStat[i] == skillEffectList[PARALYSIS])
		{
			if (checkChance(paralysed))
			{
				if (isOpposing)
					log += OPPOSING_PREFIX;

				log += this->name + " is paralysed!";

				game << log;
				game << "It can't move!";
				return true;
			}
		}
	}

	return false;
}

/**
 * Intent: Check if the Pokemon is hurt by dot
 * Pre: isOpposing is a boolean
 * Post: Return true if the Pokemon is hurt by dot, otherwise return false
 */
bool Pokemon::isHurtByDot(bool isOpposing)
{
	bool hasHurt = false;
	for (int i = 0; i < this->currentStat.size(); i++)
	{
		string log;
		bool isHurt = false;
		// Paralysis
		if (this->currentStat[i] == skillEffectList[BURN])
		{
			isHurt = true;
			double power = this->maxHp * this->currentStat[i]->getPower();
			if (power > hp)
				hp = 0;

			if (isOpposing)
				log += OPPOSING_PREFIX;
			log += this->name + " is hurt by its burn!";
		}

		// Poison
		if (this->currentStat[i] == skillEffectList[POISON])
		{
			isHurt = true;
			double power = this->maxHp * this->currentStat[i]->getPower();
			if (power > hp)
				hp = 0;

			if (isOpposing)
				log += OPPOSING_PREFIX;
			log += this->name + " is hurt by its poisoning!";
		}

		if (isHurt) {
			hasHurt = true;
			game << log;
		}
	}

	return hasHurt;
}
