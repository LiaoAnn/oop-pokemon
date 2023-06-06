#include "fileLoad.h"
#include "Pokemon.h"
#include "Move.h"
#include <vector>
#include <string>
#include <sstream>
#include "Type.h"
#include "Gamestatus.h"

fileLoad::fileLoad(string name) {
	fileName = name;
}
void fileLoad::openFile() {
	ifstream in;
	in.open(fileName);
	in >> MonsterLibName;
	//cout << MonsterLibName;
	MonsterLibName += ".txt";
	MonsterLibName = "../../../src/" + MonsterLibName;
	in >> MoveLibName;
	MoveLibName += ".txt";
	MoveLibName = "../../../src/" + MoveLibName;
	in >> GameDataName;
	GameDataName += ".txt";
	GameDataName = "../../../src/" + GameDataName;
	in.close();


}
void fileLoad::PokemonLibfile() {
	
	/*ifstream PokemonLib;
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
	PokemonLib.close();*/
}
void fileLoad::Movesfile() {
	/*ifstream Moves;
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
	Moves.close();*/

}
void fileLoad::Gamedata() {
	//ifstream Game;
	//Game.open(GameDataName);
	//int cnt, skill;
	//Game >> cnt;
	//for (int i = 0; i < cnt; i++) {
	//	string PokemonName;
	//	Game >> PokemonName >> skill;
	//	for (int j = 0; j < Monster.size(); j++) {
	//		if (Monster[j].getName() == PokemonName) {
	//			player1.push_back(Monster[j]);
	//			break;
	//		}
	//	}
	//	vector<string>skillList(skill);
	//	for (int j = 0; j < skill; j++) {
	//		Game >> skillList[j];
	//		for (int k = 0; k < MoveLib.size(); k++) {
	//			if (MoveLib[k].getName() == skillList[j]) {
	//				player1[i].skillMove(MoveLib[k]);//攻擊招式player1函式未寫
	//				break;
	//			}
	//		}
	//	}
	//}
	//Game >> cnt;
	//for (int i = 0; i < cnt; i++) {
	//	string PokemonName;
	//	Game >> PokemonName >> skill;
	//	for (int j = 0; j < Monster.size(); j++) {
	//		if (Monster[j].getName() == PokemonName) {
	//			player2.push_back(Monster[j]);
	//			break;
	//		}
	//	}
	//	vector<string>skillList(skill);
	//	for (int j = 0; j < skill; j++) {
	//		Game >> skillList[j];
	//		for (int k = 0; k < MoveLib.size(); k++) {
	//			if (MoveLib[k].getName() == skillList[j]) {
	//				player2[i].skillMove(MoveLib[k]);//攻擊招式player2函式未寫
	//				break;
	//			}
	//		}
	//	}
	//}
}
void fileLoad::opentest() {
	ifstream in;
	in.open(fileName);
	in >> MonsterLibName;
	cout << MonsterLibName;
	in >> MoveLibName;
	in >> GameDataName;
	string commend;
	bool start = false;
	bool player1creature = false;
	bool medical = false;
	Gamestatus GS(player1,player2);
	while (in >> commend) {
		if (commend == "Test") {
			start = true;
			cout << "Attention: Test start " << endl;
		}
		if (commend == "battle"&&start == true) {
			cout << "Two Pokemon battle" << endl;
			
		}
		if (commend == "Bag") {
			cout << "use medicial" << endl;
			medical = true;
		}
		if (commend == "Potion" && medical == true) {
			GS.Healtime();
		}
	}
}