#ifndef	CARTA
#define	CARTA

#include <string>

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
			naipe = input.substr(input.size());
		}
		string getNaipe() { return naipe; }
		int dimensao() { return numero; }
		int getNum() { return numero; }
		///Altera o valor da carta.
		///@param string:input Deve ser no formato '1X'~'13X' 
		void setCarta(string input){ *this = CartaDeBaralho(input); }
};

#endif