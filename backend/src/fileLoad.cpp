#include "fileLoad.h"
#include "Pokemon.h"
#include "Move.h"
#include <vector>
#include <string>
#include <sstream>
#include "Type.h"

fileLoad::fileLoad(string name) {
	fileName = name;
}
void fileLoad::openFile() {
	ifstream in;
	in.open(fileName);
	in >> MonsterLibName;
	//cout << MonsterLibName;
	in >> MoveLibName;
	in >> GameDataName;
	in.close();


}
void fileLoad::PokemonLibfile() {
	vector<Pokemon> Monster;
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
			
			typelist.insert(TypeMap[typeName]);
		}
		PokemonLib >> hp >> attack >> defence >> spAttack >> spDefence >> speed;
		Monster.push_back(Pokemon(Pname, typelist, hp, attack, defence, spAttack, spDefence, speed));
	}
	PokemonLib.close();

}
void fileLoad::Movesfile() {
	vector<Move> MoveLib;
	ifstream Moves;
	Moves.open(MoveLibName);
	string describe;
	AdditionalEffect effect;
	effect = NOR;
	vector<string>properList;
	type movetype;
	while (getline(Moves, describe)) {
		effect = NOR;
		stringstream ss(describe);
		string movename, propertys, ATKtype;
		int power1, power2, power3;
		ss >> movename >> propertys >> ATKtype >> power1 >> power2 >> power3;
		movetype = type(TypeMap[propertys]);
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
		MoveLib.push_back(Move(movename, movetype, propertys, power1, power2, power3, effect));
	}
	Moves.close();
}
void fileLoad::test() {
	ifstream in;
	in.open(fileName);
	in >> MonsterLibName;
	//cout << MonsterLibName;
	in >> MoveLibName;
	in >> GameDataName;
	string commend;
	in >> commend;
	if (commend == "test") {
		in >> commend;
		if (commend == "battle") {
			string play1, play2;
			in >> play1;
			in >> play2;

		}

	}
}