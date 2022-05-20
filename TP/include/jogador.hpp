/* EXEMPLO DE ENTRADA:
3 1000 								-- Rodadas, dinheiro inicial dos participantes
5 50								-- Jogadas da rodada, pingo da rodada
Giovanni 100 6O 3P 10E 11O 1O		-- Jogador, aposta do jogador, mão do jogador (5 cartas)
John 200 3P 4E 3E 13C 13O
Thiago 100 12O 7P 12C 1O 13C
Gisele 300 12E 10C 11C 9C 13E
Wagner 50 5P 12P 5E 2E 1P
2 50
Wagner 200 2P 13E 9E 12C 2O
Gisele 350 11P 9P 2E 6E 4P
3 100
Thiago 250 1O 4P 1E 3O 8O
Gisele 100 9C 8C 8C 2C 6C
Giovanni 150 4P 12P 8E 12E 2P */

/* EXEMPLO DE SAÍDA:
1 1000 S
Gisele
1 200 OP
Wagner
1 1000 F
Gisele
####
Gisele 2050
Clodoveu 1350
John Holiver 600
Giovanni 550
Thiago 450 */

#ifndef JOGADOR
#define JOGADOR

#include "listaEncadeada.hpp"
#include "cartaDeBaralho.hpp"

// Classe Jogador. Possui STRING nome, DOUBLE dinheiro e MAODECARTAS mao.
// Caso não receba parâmetros, inicia nome e dinheiro com "" e 0.
class jogador {
	private:
		int ID;
		string nome;
		double dinheiro;
		LinkedList<CartaDeBaralho> mao;
	public:
		// Construtor vazio. Inicia nome como "" e dinheiro como '0'.
		jogador() : nome(""), dinheiro(0) {}
		// Construtor simples
		jogador(string _nome, double _dinheiro) : nome(_nome), dinheiro(_dinheiro) {}
		int getID() { return ID; }
		int maiorCarta();
		int aposta(double);
		double dimensao();
		string getNome() { return nome; }
		string ranqueDaMao();
		void addCarta(string carta);
		void limpaMao();
};

int jogador::aposta(double quantia){
	if(dinheiro - quantia >= 0){
		dinheiro -= quantia;
		return 1;
	}
	return 0;
}

double jogador::dimensao(){
	return dinheiro;
}

void jogador::addCarta(string carta){
	mao.addElementoOrdenado(CartaDeBaralho(carta));
}

void jogador::limpaMao(){
	mao.limpaLista();
}


#endif