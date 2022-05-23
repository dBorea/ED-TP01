#ifndef MESADEPOKER
#define MESADEPOKER

#include "jogador.hpp"

class mesaDePoker{
	private:
		jogador *jogadores;
		int numJogadores;

		int premioDaRodada;
		int dinheiroBase;
		int pingo;
		int nRodadas;
		int nJogadas;
	
	public:
		mesaDePoker() : numJogadores(0), premioDaRodada(0), dinheiroBase(0), pingo(0), nRodadas(0), nJogadas(0) {}


		void adicionaJogador();

};

void mesaDePoker::adicionaJogador(){
	
}

#endif