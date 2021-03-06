#ifndef MESADEPOKER
#define MESADEPOKER

#include <fstream>
#include <sstream>
#include <iterator>
#include <regex>
#include "jogador.hpp"

// O número de argumentos representa o número de palavras em uma linha da entrada que não faz parte do nome do jogador.
// Exemplo: na entrada "Giovanni Ferreira 100 6O 3P 10E 11O 1O", existem 8 palavras, 6 delas sendo argumentos.
#define NUM_ARGS 6

enum orderCase{
	orderByDinheiro,
	orderByNome,
	orderByTudo
};

using std::fstream;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::istringstream;
using std::istream_iterator;
using std::distance;

class mesaDePoker{
	private:
		jogador *jogadores;
		int numJogadores;
		int jogadoresAtuais;

		int premioDaRodada;
		int dinheiroBase;
		int pingo;

		string rankVencedor;
		bool rodadaValida;
	
	public:
		mesaDePoker() : jogadores(nullptr), numJogadores(0), jogadoresAtuais(0), premioDaRodada(0),
						dinheiroBase(0), pingo(0), rankVencedor(""), rodadaValida(true) {} // talvez transformar construtor para receber istream
		void adicionaJogador(string, int);

		jogador *getJogador(string const&) const;
		bool possuiJogador(string const&) const; // Talvez não use
		void analisaLinha(string const&, int = 0);
		void processaRodada(ofstream*);
		void ordenaJogadores(orderCase = orderByTudo);

		void escreveOutputRodada(ofstream*, bool[], int);
		void escreveOutputFinal(ofstream*);
		ofstream escreveOutput();
		void limpaMaos();
		void processaJogo(char[], char[]);

};

#endif