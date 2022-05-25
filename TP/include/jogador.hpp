#ifndef JOGADOR
#define JOGADOR

#include "cartaDeBaralho.hpp"

#define NUM_CARTAS 5

using std::endl;

// Classe Jogador. Possui STRING nome, DOUBLE dinheiro e MAODECARTAS mao.
// Caso não receba parâmetros, inicia nome e dinheiro com "" e 0.
class jogador {
	private:
		cartaDeBaralho mao[NUM_CARTAS];
		string nome;
		int dinheiro;
		int apostaADebitar;

	public:
		// Construtor vazio. Inicia nome como "" e dinheiro como '0'.
		jogador() : nome(""), dinheiro(0), apostaADebitar(0) {}
		// Construtor simples
		jogador(string _nome, int _dinheiro) : nome(_nome), dinheiro(_dinheiro) {}
		void addCarta(string const&);

		string getNome() const { return nome; }
		int getDinheiro() const { return dinheiro; }
		int maiorCarta() const;
		void premia(int input) { dinheiro += input; }

		bool isStraight() const;
		bool isFlush() const;
		int *numRepetidas() const;
		int ranqueDaMao() const;

		bool setAposta(int);
		void debitaAposta();
		void limpaMao();
	friend class mesaDePoker;
};

#endif