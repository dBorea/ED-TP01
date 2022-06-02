#ifndef	CARTA
#define	CARTA

#include <string>
#include <iostream>
#include "msgassert.hpp"
#include "memlog.hpp"

using std::string;
using std::stoi;
	
///@brief Classe para cartas de baralho
///@param void Inicializa naipe("") e numero(0)
///@param string Deve ser no formato '1X'~'13X'
class cartaDeBaralho {
	private:
		string naipe;
		int numero;
	public:
		cartaDeBaralho() : naipe(""), numero(0) {}
		cartaDeBaralho(string input){
			numero = stoi(input.substr(0, input.size() - 1));		// Divide o input entre 'número' e 'naipe' usando substr
			naipe = input.substr(input.size() - 1);
		}
		string getNaipe() const { return naipe; }
		int getNum() const { return numero; }
		int dimensao() const { return numero; }				// Talvez não use
		void printCarta() const {								// Talvez não use
			std::cout << std::endl << "Carta inserida:" << std::endl
				 << "\t Naipe: " << getNaipe() << std::endl
				 << "\t Numero: " << getNum() << std::endl;
		}
		void setNaipe(string input) { naipe = input; }
		void setNum(int num) { numero = num; }
		void setCarta(string input){ *this = cartaDeBaralho(input); }
	friend class jogador;
	friend class mesaDePoker;
};

#endif