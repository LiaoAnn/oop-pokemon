/***********************************************************************
 * File: SkillEffect.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-30
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-30
 * Description: Definition of SkillEffect
************************************************************************/
#pragma once

#include <string>
using namespace std;

class SkillEffect
{
private:
	int type;
	string name;
	int leftRound;
	double power;
public:
	// Default Constructor
	SkillEffect();
	// Constructor
	SkillEffect(int type, string name, double power, int leftRound = 5);
	// Destructor
	~SkillEffect();

	// Get type of skill effect
	int getSkillEffectType() const;
	// Get name of skill effect
	string getName() const;
	// Get left round of skill effect
	int getLeftRound() const;

	// Get Power of skill effect
	double getPower() const;

	// Reduce left round of skill effect
	void reduceLeftRound();

	// Print message when get skill effect
	virtual string printGotMessage(string pokemonName) const;
	// Print message when skill effect affect
	virtual string printAffactMessage(string pokemonName) const;
	// To JSON
	json toJson();

	// Check if pokemon has skill effect
	bool operator==(const SkillEffect& skillEffect) const;
	friend bool operator==(const SkillEffect& effect1, const SkillEffect& effect2);
};

// Posion skill effect
class Poison : public SkillEffect
{
public:
	// Default Constructor
	Poison();
	// Constructor
	Poison(int leftRound);
	// Destructor
	~Poison();

	// Print message when get skill effect
	string printGotMessage(string pokemonName) const override;
	// Print message when skill effect affect
	string printAffactMessage(string pokemonName) const override;
};

// Burn skill effect
class Burn : public SkillEffect
{
public:
	// Default Constructor
	Burn();
	// Constructor
	Burn(int leftRound);
	// Destructor
	~Burn();

	// Print message when get skill effect
	string printGotMessage(string pokemonName) const override;
	// Print message when skill effect affect
	string printAffactMessage(string pokemonName) const override;
};

// Paralysis skill effect
class Paralysis : public SkillEffect
{
public:
	// Default Constructor
	Paralysis();
	// Constructor
	Paralysis(int leftRound);
	// Destructor
	~Paralysis();

	// Print message when get skill effect
	string printGotMessage(string pokemonName) const override;
	// Print message when skill effect affect
	string printAffactMessage(string pokemonName) const override;
};


