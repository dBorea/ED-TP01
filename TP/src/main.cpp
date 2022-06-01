#include <iostream>
#include <fstream>
#include <string>
#include "msgassert.hpp"
#include "mesaDePoker.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

void instrucoes(){
	cout << "PokerSim" << endl;
}

int main(){

	iniciaMemLog("pokerSimLog.out");
	ativaMemLog();

	mesaDePoker mesa;
	mesa.processaJogo();

	return finalizaMemLog();
}