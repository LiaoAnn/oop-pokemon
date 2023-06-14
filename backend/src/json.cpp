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

string jsonToString(json j) {
	return j.dump();
}
