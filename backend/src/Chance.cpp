/***********************************************************************
 * File: Chance.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-12
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-12
 * Description: Implementation for Chance
************************************************************************/

#include "Chance.h"
#include <random>
#include <iostream>

// random number generator
// for invoiding keep generating the same random number
random_device rd;
mt19937 gen(rd());

/**
 * Intent: Check if the status infliction is successful or not
 * Pre: probability is between 0 and 1 means the probability of success
 * Post: return true if the status infliction is successful, otherwise return false
 */
bool checkChance(double probability)
{
	// generate random number between 0.0 and 1.0
	uniform_real_distribution<> dis(0.0, 1.0);

	// if the random number is less than or equal to the given probability, then return true
	if (dis(gen) <= probability) {
		return true;
	}
	else {
		return false;
	}
}
