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

	//testaCarta();
	return 0;
}