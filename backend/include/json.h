/***********************************************************************
 * File: json.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-13
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-13
 * Description: Definition of json
************************************************************************/

#include "json.hpp"
#include <string>

using namespace std;
using namespace nlohmann;

json stringToJson(string str);
string jsonToString(json j);
