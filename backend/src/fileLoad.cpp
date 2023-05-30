#include "fileLoad.h"
#include "Creature.h"
#include "Move.h"
#include <vector>
#include <string>
#include <sstream>
fileLoad::fileLoad(string name) {
	fileName = name;
}
void fileLoad::openFile() {
	ifstream in;
	in.open(fileName);
	in >> MonsterLibName;
	in >> MoveLibName;
	in >> GameDataName;



}
void fileLoad::PokemonLibfile() {
	vector<PokemonCreature> MonsterLib;
	ifstream PokemonLib;
	PokemonLib.open(MonsterLibName);
	string Pname;
	while (PokemonLib >> Pname) {
		typelist.clear();
		int typeNum;
		PokemonLib >> typeNum;
		int cnt = 0;
		while (cnt < typeNum) {
			cnt++;
			string typeName;
			PokemonLib >> typeName;
			typelist.push_back(Type(TypeMap[typeName]));
		}
		PokemonLib >> HP >> ATK >> DEF >> SPatk >> SPdef >> speed;
		MonsterLib.push_back(PokemonCreature(Pname, typelist, HP, ATK, DEF, SPatk, SPdef, speed));
	}
	PokemonLib.close();

}
void fileLoad::Movesfile() {
	vector<Move> MoveLib;
	ifstream Moves;
	Moves.open(MoveLibName);
	string line;
	Type movetype;
	AdditionalEffect effect;
	//PhysicalSpecial phys;
	while (getline(Moves, line)) {
		effect = NOR;
		stringstream ss(line);
		string movename, phs, ATKtype;
		int power1, power2, power3;
		ss >> movename >> phs >> ATKtype >> power1 >> power2 >> power3;
		movetype = Type(TypeMap[phs]);
		if (ATKtype == "Special") {
			string temp;
			ss >> temp;
			if (temp == "BRN") {
				effect = BRN;
			}
			else if (temp == "PAR") {
				effect = PAR;
			}
			else if (temp == "PSN") {
				effect = PSN;
			}
		}
		MoveLib.push_back(Move(movename, movetype, phs, power1, power2, power3, effect));
	}
	Moves.close();
}