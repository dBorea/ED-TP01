#ifndef	CARTA
#define	CARTA

#include <string>
#include <iostream>

using std::string;
using std::stoi;
	
///@brief Classe para cartas de baralho
///@param void Inicializa naipe("") e numero(0)
///@param string Deve ser no formato '1X'~'13X'
class CartaDeBaralho {
	private:
		string naipe;
		int numero;
	public:
		CartaDeBaralho() : naipe(""), numero(0) {}
		CartaDeBaralho(string input){
			numero = stoi(input.substr(0, input.size() - 1));		// Divide o input entre 'número' e 'naipe' usando substr
			naipe = input.substr(input.size() - 1);
		}
		string getNaipe() { return naipe; }
		int getNum() { return numero; }
		void setNaipe(string input) { naipe = input; }
		void setNum(int num) { numero = num; }
		int dimensao() { return numero; }
		void printCarta() {
			std::cout << std::endl << "Carta inserida:" << std::endl
				 << "\t Naipe: " << getNaipe() << std::endl
				 << "\t Numero: " << getNum() << std::endl;
		}
		void setCarta(string input){ *this = CartaDeBaralho(input); }
};

#endif