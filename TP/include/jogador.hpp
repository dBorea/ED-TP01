#ifndef JOGADOR
#define JOGADOR

#include "cartaDeBaralho.hpp"

#define NUM_CARTAS 5

enum rankings {
	invalid,
	high_card,
	one_pair,
	two_pairs,
	three_of_a_kind,
	straight,
	flush,
	full_house,
	four_of_a_kind,
	straight_flush,
	royal_straight_flush
};

enum repCounters {
	unica,
	par,
	trinca,
	quadra,
	trincaEPar,
	doisPares
};

using std::endl;

// Classe Jogador. Possui STRING nome, DOUBLE dinheiro e MAODECARTAS mao.
// Caso não receba parâmetros, inicia nome e dinheiro com "" e 0.
class jogador {
	private:
		cartaDeBaralho mao[NUM_CARTAS];
		string nome;
		int dinheiro;
		int id;
		int apostaADebitar;
		int maiorCartaIsolada;
		int maiorCartaDaJogada;
		bool vencedor;
		int cartasIsoladas[NUM_CARTAS];
		int cartasDaJogada[NUM_CARTAS];

	public:
		// Construtor vazio. Inicia nome como "" e dinheiro como '0'.
		jogador() : nome(""), dinheiro(0), id(0), apostaADebitar(0) , maiorCartaIsolada(0), maiorCartaDaJogada(0), vencedor(false), cartasIsoladas(), cartasDaJogada() {}
		// Construtor simples
		jogador(string _nome, int _dinheiro, int _id) : nome(_nome), dinheiro(_dinheiro), id(_id),
											   		   apostaADebitar(0) , maiorCartaIsolada(0), maiorCartaDaJogada(0), vencedor(false), cartasIsoladas(), cartasDaJogada() {}
		jogador& operator=(const jogador& outro);
		void addCarta(string const&);

		string getNome() const { 
			LEMEMLOG((long int)(&nome),sizeof(string),id);
			return nome; 
		}
		int getDinheiro() const { 
			LEMEMLOG((long int)(&dinheiro),sizeof(int),id);
			return dinheiro; 
		}
		int getMaiorCartaIsolada() const { 
			LEMEMLOG((long int)(&maiorCartaIsolada),sizeof(int),id);
			return maiorCartaIsolada; 
		}
		int getMaiorCartaDaJogada() const { 
			LEMEMLOG((long int)(&maiorCartaDaJogada),sizeof(int),id);
			return maiorCartaDaJogada; 
		}

		void setVencedor(bool input) { vencedor = input; }

		bool isVencedor() const {
			LEMEMLOG((long int)(&vencedor),sizeof(bool),id);
			return vencedor;
		}
		int maiorCarta() const;
		void premia(int input) { ESCREVEMEMLOG((long int)(&(dinheiro)),sizeof(int),id); dinheiro += input; }

		bool checkValidPlay();
		bool checkStraight();
		bool checkFlush();
		bool checkRoyal() const;
		repCounters numRepetidas();
		rankings ranqueDaMao();

		bool setAposta(int, int = 0);
		bool cobraPingo(int);
		void debitaAposta();
		void limpaMao();
	friend class mesaDePoker;
};

#endif