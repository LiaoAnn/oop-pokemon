#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class fileLoad {
private:
	string fileName;
	string creatureName, type;
	int HP, ATK,DEF, SpAtk, SpDef, Speed;
public:
	fileLoad(string file);
	void openFile();
	void setfile();
};