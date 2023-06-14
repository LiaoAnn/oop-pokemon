/***********************************************************************
 * File: json.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-13
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-13
 * Description: JSON parser
************************************************************************/

#include "json.h"
#include <string>
#include <iostream>

using namespace std;
// Intent: Convert string to json
// Pre: str is a valid json string
// Post: return a json object
json stringToJson(string str) {
	json j;
	try {
		j = json::parse(str);
	}
	catch (json::parse_error& e) {
		cout << "Parse error: " << e.what() << endl;
		return json();
	}
	return j;
}
// Intent: Convert json to string
// Pre: j is a valid json object
// Post: return a string
string jsonToString(json j) {
	return j.dump();
}
