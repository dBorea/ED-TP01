#ifndef MESADEPOKER
#define MESADEPOKER

#include <sstream>
#include <iterator>
#include "jogador.hpp"

// O número de argumentos representa o número de palavras em uma linha da entrada que não faz parte do nome do jogador.
// Exemplo: na entrada "Giovanni Ferreira 100 6O 3P 10E 11O 1O", existem 8 palavras, 6 delas sendo argumentos.
#define NUM_ARGS 6

using std::ifstream;
using std::stringstream;
using std::istringstream;
using std::istream_iterator;
using std::distance;

class mesaDePoker{
	private:
		jogador *jogadores;
		int numJogadores;

		int premioDaRodada;
		int dinheiroBase;
		int pingo;
		int nRodadas;
		int nJogadas;

		bool rodadaValida;
	
	public:
		mesaDePoker() : jogadores(nullptr), numJogadores(0), premioDaRodada(0), dinheiroBase(0), 
						pingo(0), nRodadas(0), nJogadas(0), rodadaValida(true) {} // talvez transformar construtor para receber istream
		void adicionaJogador(string, int);

		jogador *getJogador(string const&) const;
		bool possuiJogador(string const&) const; // Talvez não use
		bool analisaLinha(string const&, bool);
		void processaRodada();
		void ordenaJogadores();

};

unsigned int numDePalavras(string const& str){
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}

void mesaDePoker::adicionaJogador(string input_nome, int input_dinheiro){
	jogadores = (jogador*) realloc(jogadores, (numJogadores+1) * sizeof(jogador));	// Realoca o tamanho do vetor
	jogadores[numJogadores-1] = jogador(input_nome, input_dinheiro);				// Cria o novo jogador e o coloca na última posição
	numJogadores++;
}

jogador *mesaDePoker::getJogador(string const& nome) const {
	for(int i=0; i<numJogadores; i++)			// Itera sobre os jogadores
		if(jogadores[i].getNome() == nome)		// Verifica o nome
			return &jogadores[i];				// Retorna o jogador com o nome desejado

	erroAssert(false,"Jogador não encontrado");
}

bool mesaDePoker::possuiJogador(string const& nome) const{	// Talvez não use
	for(int i=0; i<numJogadores; i++)			// Itera sobre os jogadores
		if(jogadores[i].getNome() == nome)		// Verifica o nome
			return true;						// Retorna 'true' caso encontrado
	return false;								// E 'false' caso contrário
}

bool mesaDePoker::analisaLinha(string const& linha, bool primeiraRodada){
	istringstream stream(linha);
	string nome("");
	string tempString;
	int tempInt;

	for(int i=0; i<numDePalavras(linha)-NUM_ARGS; i++){		// Recebe o nome completo do jogador
		stream >> tempString;
		nome.append(tempString);
	}

	if(primeiraRodada)										// Adiciona o jogador na lista caso seja a primeira rodada
		adicionaJogador(nome, dinheiroBase);
	
	jogador *jogadorAtual = getJogador(nome);				// Cria um ponteiro temporário para o jogador atual
	
	stream >> tempInt;										// Recebe a aposta do jogador
	if(!jogadorAtual->setAposta(tempInt, pingo))			// Envia a aposta ao jogador e verifica a validez da mesma
		rodadaValida = false;								// Caso a aposta seja inválida, também invalida a rodada
	premioDaRodada += tempInt;

	jogadorAtual->limpaMao();
	for(int i=0; i<NUM_CARTAS; i++){						// Lê e armazena as cartas do jogador atual
		stream >> tempString;
		jogadorAtual->addCarta(tempString);
	}

	return rodadaValida;									// Retorna a validez da rodada
}

void mesaDePoker::processaRodada(){

}

void mesaDePoker::ordenaJogadores(){

}

#endif