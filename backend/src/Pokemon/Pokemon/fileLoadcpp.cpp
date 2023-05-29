#include "fileLoad.h"
#include <string>
fileLoad::fileLoad(string name) {
	fileName = name;
}
void fileLoad::openFile() {
	ifstream in;
	in.open(fileName);
	in >> creatureName;
	getline(in, type);
	in >> HP >> ATK >> DEF >> SpAtk >> SpDef >> Speed;
	
}