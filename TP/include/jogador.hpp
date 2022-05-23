#ifndef JOGADOR
#define JOGADOR

#include "cartaDeBaralho.hpp"

#define NUM_CARTAS 5

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
		jogador() : nome(""), dinheiro(0) {}
		// Construtor simples
		jogador(string _nome, int _dinheiro) : nome(_nome), dinheiro(_dinheiro) {}
		void addCarta(string const&);

		string getNome() const { return nome; }
		int dimensao() const { return dinheiro; }
		int maiorCarta() const;
		int ranqueDaMao() const;

		bool setAposta(int, int);
		void debitaAposta();
		void limpaMao();
	friend class mesaDePoker;
};

/// @brief Adiciona uma carta à mão do jogador, ordenada de maior para menor
/// 
/// @param carta 
void jogador::addCarta(string const& carta){
	cartaDeBaralho novaCarta(carta);
	int i, index, insertPos;

	for(index=0; novaCarta.getNum()<mao[index].getNum(); index++);	// [8] [6] [5] [2] [0] : Itera por mão[] até achar a posição de inserção
	insertPos = index;												// [4]----------^ 	   => index = 3 (exemplo)

	for(index=0; mao[index].getNum()!=0; index++);					// [8] [6] [5] [2] [0] : Itera por mão[] até achar a primeira posição com elemento nulo
																	// [index]----------^  => index = 4 (exemplo)

	for(i=index; i>insertPos; i--)									// [8] [6] [5] [2] [2] : Itera por mão[] entre a primeira posição de elemento nulo 
		mao[i] = mao[i-1];											// 				^--[4] : e a posição de inserção, preparando para a inserção

	mao[insertPos] = novaCarta;										// [8] [6] [5] [4] [2] : Insere o novo elemento
}

/// @brief Define a aposta do jogador
/// 
/// @param quantia 
/// @return true / false
bool jogador::setAposta(int quantia, int pingo){
	if(dinheiro - quantia - pingo >= 0){
		apostaADebitar = quantia;
		return 1;
	}
	return 0;
}

/// @brief Aplica as apostas do jogador
void jogador::debitaAposta(){
	dinheiro -= apostaADebitar;
	apostaADebitar = 0;
}

/// @brief Retorna o número da maior carta do jogador. Caso o jogador não tenha cartas suficientes, retorna -1.
/// 
/// @return int 
int  jogador::maiorCarta() const {
	if(mao[4].getNum() != 0)
		return mao[0].getNum();
	return -1;
}

int  jogador::ranqueDaMao() const {
	
}

/// @brief Limpa as cartas, retornando-as ao estado de criação 
void jogador::limpaMao(){
	for(int i=0; i<NUM_CARTAS; i++){
		mao[i].setNaipe("");
		mao[i].setNum(0);
	}
}

#endif