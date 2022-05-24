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


void testaCarta(){
	cartaDeBaralho cartaTeste("13C");
	cartaTeste.printCarta();
	cartaTeste.setCarta("1S");
	cartaTeste.printCarta();
}

void instrucoes(){
	cout << "PokerSim" << endl;
}

int main(){
	mesaDePoker mesa;

	ifstream inputFile("entrada.txt");
	erroAssert(!inputFile.fail(), "Arquivo de entrada não pôde ser aberto");
	ofstream outputFile("saida.txt");

	mesa.processaJogo(&inputFile);
	//testaCarta();
	return 0;
}