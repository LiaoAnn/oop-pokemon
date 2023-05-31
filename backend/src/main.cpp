#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "fileLoad.h"

using namespace std;
int main()
{
	string filename;
	filename = "../../../src/case.txt";
	fileLoad filetest(filename);
	filetest.openFile();
	filetest.PokemonLibfile();
	filetest.Movesfile();
}
