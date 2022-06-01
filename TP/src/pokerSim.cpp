#include <iostream>
#include <fstream>
#include <string>
#include <getopt.h>
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

bool parseArgs(int argc, char *argv[], char lognome[]){
	extern char *optarg;
	//extern int optind;

	for(int opt; (opt=getopt(argc, argv, "l:h")) != EOF;){
		switch (opt){
		case 'l':
			strcpy(lognome, optarg);
			return 1;
		
		case 'h':
			instrucoes();
			exit(1);

		default:
			break;
		}
	}
	return 0;
}

int main(int argc, char *argv[]){
	char lognome[100];
	bool logRegister = parseArgs(argc, argv, lognome);
	if(logRegister){
		iniciaMemLog(lognome);
		ativaMemLog();
	}

	mesaDePoker mesa;
	mesa.processaJogo();

	if(logRegister) finalizaMemLog();
	return 0;
}