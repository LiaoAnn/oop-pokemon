/***********************************************************************
 * File: Map.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-13
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-13
 * Description: Definition of Map
************************************************************************/

#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

/**
 * Intent: Get key from value in map
 * Pre: m is a map, value is a value in the map
 * Post: key of the value
 */
template <typename K, typename V>
K getKeyFromValue(std::map<K, V>& m, V value) {
	for (const auto& kv : m) {
		if (kv.second == value) {
			return kv.first;
		}
	}
	throw NULL;
}

