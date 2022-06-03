#include "jogador.hpp"

jogador& jogador::operator=(const jogador& outro){
	if(this == &outro)
		return *this;

	for(int i=0; i<NUM_CARTAS; i++){
		LEMEMLOG((long int)(&(outro.mao[i].numero)),sizeof(int),id);
		LEMEMLOG((long int)(&(outro.mao[i].naipe)),sizeof(string),id);
		ESCREVEMEMLOG((long int)(&(mao[i].numero)),sizeof(int),id);
		ESCREVEMEMLOG((long int)(&(mao[i].naipe)),sizeof(string),id);
		mao[i].numero = outro.mao[i].getNum();
		mao[i].naipe = outro.mao[i].getNaipe();
	}
	LEMEMLOG((long int)(&(outro.nome)),sizeof(string),id);
	LEMEMLOG((long int)(&(outro.dinheiro)),sizeof(int),id);
	LEMEMLOG((long int)(&(outro.id)),sizeof(int),id);
	LEMEMLOG((long int)(&(outro.apostaADebitar)),sizeof(int),id);
	LEMEMLOG((long int)(&(outro.maiorCartaIsolada)),sizeof(int),id);
	LEMEMLOG((long int)(&(outro.maiorCartaDaJogada)),sizeof(int),id);
					  nome = outro.nome;
				  dinheiro = outro.dinheiro;
						id = outro.id;
			apostaADebitar = outro.apostaADebitar;
		 maiorCartaIsolada = outro.maiorCartaIsolada;
		maiorCartaDaJogada = outro.maiorCartaDaJogada;
	ESCREVEMEMLOG((long int)(&(nome)),sizeof(string),id);
	ESCREVEMEMLOG((long int)(&(dinheiro)),sizeof(int),id);
	ESCREVEMEMLOG((long int)(&(id)),sizeof(int),id);
	ESCREVEMEMLOG((long int)(&(apostaADebitar)),sizeof(int),id);
	ESCREVEMEMLOG((long int)(&(maiorCartaIsolada)),sizeof(int),id);
	ESCREVEMEMLOG((long int)(&(maiorCartaDaJogada)),sizeof(int),id);

	return *this;
}

/// @brief Adiciona uma carta à mão do jogador, ordenada de maior para menor
/// 
/// @param carta 
void jogador::addCarta(string const& carta){
	cartaDeBaralho novaCarta(carta);
	int i, index, insertPos;
	
	for(index=0; novaCarta.getNum()<mao[index].getNum(); index++){	// [8] [6] [5] [2] [0] : Itera por mão[] até achar a posição de inserção
		LEMEMLOG((long int)(&(mao[index].numero)),sizeof(int),id);	//
	}																//
	insertPos = index;												// [4]----------^ 	   => index = 3 (exemplo)

	for(index=0; mao[index].getNum()!=0; index++){					// [8] [6] [5] [2] [0] : Itera por mão[] até achar a primeira posição com elemento nulo
		LEMEMLOG((long int)(&(mao[index].numero)),sizeof(int),id);	//
	}																//
																	// [index]----------^  => index = 4 (exemplo)

	for(i=index; i>insertPos; i--){									// [8] [6] [5] [2] [2] : Itera por mão[] entre a primeira posição de elemento nulo 
		LEMEMLOG((long int)(&(mao[i-1].numero)),sizeof(int),id);
		ESCREVEMEMLOG((long int)(&(mao[i].numero)),sizeof(int),id);
		LEMEMLOG((long int)(&(mao[i-1].naipe)),sizeof(string),id);
		ESCREVEMEMLOG((long int)(&(mao[i].naipe)),sizeof(string),id);
		mao[i] = mao[i-1];											// 				^--[4] : e a posição de inserção, preparando para a inserção
	}
	mao[insertPos] = novaCarta;										// [8] [6] [5] [4] [2] : Insere o novo elemento
	ESCREVEMEMLOG((long int)(&(mao[insertPos].numero)),sizeof(int),id);
}

/// @brief Define a aposta do jogador
/// 
/// @param quantia 
/// @return true / false
bool jogador::setAposta(int quantia, int pingo){
	LEMEMLOG((long int)(&(dinheiro)),sizeof(int),id);
	if(dinheiro - quantia + pingo >= 0){
		apostaADebitar = quantia;
		ESCREVEMEMLOG((long int)(&(apostaADebitar)),sizeof(int),id);
		return 1;
	}
	return 0;
}

void jogador::cobraPingo(int pingo){
	LEMEMLOG((long int)(&(dinheiro)),sizeof(int),id);
	if(dinheiro - pingo >= 0){
		ESCREVEMEMLOG((long int)(&(apostaADebitar)),sizeof(int),id);
		apostaADebitar += pingo;
	}
}

/// @brief Aplica as apostas do jogador
void jogador::debitaAposta(){
	LEMEMLOG((long int)(&(apostaADebitar)),sizeof(int),id);
	ESCREVEMEMLOG((long int)(&(dinheiro)),sizeof(int),id);
	ESCREVEMEMLOG((long int)(&(apostaADebitar)),sizeof(int),id);
	dinheiro -= apostaADebitar;
	apostaADebitar = 0;
}

/// @brief Retorna o número da maior carta do jogador.
/// 
/// @return int 
int  jogador::maiorCarta() const {
	LEMEMLOG((long int)(&(mao[4].numero)),sizeof(int),id);
	if(mao[4].getNum() != 0){
		LEMEMLOG((long int)(&(mao[0].numero)),sizeof(int),id);
		return mao[0].getNum();
	}
	return 0;
}

bool jogador::checkValidPlay(){
	for(int i=0; i<NUM_CARTAS; i++){
		LEMEMLOG((long int)(&(mao[i].naipe)),sizeof(string),id);
		LEMEMLOG((long int)(&(mao[i].numero)),sizeof(int),id);
		LEMEMLOG((long int)(&(mao[i].numero)),sizeof(int),id);
		if(mao[i].getNaipe() == "" || mao[i].getNum() < 1 || mao[i].getNum() > 13)
			return false;
	}
	return true;
}

bool jogador::checkStraight(){
	LEMEMLOG((long int)(&(mao[0].numero)),sizeof(int),id);
	LEMEMLOG((long int)(&(mao[NUM_CARTAS-1].numero)),sizeof(int),id);
	int cartasAChecar = (mao[0].getNum()==13 && mao[NUM_CARTAS-1].getNum()==1)? NUM_CARTAS-1 : NUM_CARTAS;
	for(int i=0; i<cartasAChecar; i++){
		LEMEMLOG((long int)(&(mao[i].numero)),sizeof(int),id);
		LEMEMLOG((long int)(&(mao[0].numero)),sizeof(int),id);
		if(mao[i].getNum() != mao[0].getNum()-i)
			return false;
	}
	if(cartasAChecar==NUM_CARTAS-1)
		maiorCartaDaJogada = 14;
	else maiorCartaDaJogada = maiorCarta();
	ESCREVEMEMLOG((long int)(&(maiorCartaDaJogada)),sizeof(int),id);
	return true;
}

bool jogador::checkFlush(){
	LEMEMLOG((long int)(&(mao[0].naipe)),sizeof(string),id);
	string naipeCmp = mao[0].getNaipe();
	for(int i=1; i<NUM_CARTAS; i++){
		LEMEMLOG((long int)(&(mao[i].naipe)),sizeof(string),id);
		if(mao[i].getNaipe() != naipeCmp)
			return false;
	}
	ESCREVEMEMLOG((long int)(&(maiorCartaDaJogada)),sizeof(int),id);
	if(mao[4].getNum()==1)
		maiorCartaDaJogada = 14;
	else maiorCartaDaJogada = maiorCarta();
	return true;
}

repCounters jogador::numRepetidas(){
	short combo;
	bool identificada[NUM_CARTAS] = {0};
	int combos[NUM_CARTAS] {0};

	for(int i=0; i<NUM_CARTAS; i++){
		combo = 0;
		if(!identificada[i]){
			identificada[i] = true;
			combo = 1;
			for(int j=1; j<NUM_CARTAS; j++){
				LEMEMLOG((long int)(&(mao[i].numero)),sizeof(int),id);
				LEMEMLOG((long int)(&(mao[j].numero)),sizeof(int),id);
				if((!identificada[j]) && (mao[i].getNum() == mao[j].getNum())){
					identificada[j] = true;
					combo++;
				}
			}
			LEMEMLOG((long int)(&(mao[i].numero)),sizeof(int),id);
			if(combo==1){
				if(mao[i].getNum() > maiorCartaIsolada){
					ESCREVEMEMLOG((long int)(&(maiorCartaIsolada)),sizeof(int),id);
					maiorCartaIsolada = mao[i].getNum();
				}
				if(mao[i].getNum() == 1){
					maiorCartaIsolada = 14;
				}
			}
			LEMEMLOG((long int)(&(mao[i].numero)),sizeof(int),id);
			if(combo!=1){
				if(mao[i].getNum() > maiorCartaDaJogada){
					ESCREVEMEMLOG((long int)(&(maiorCartaDaJogada)),sizeof(int),id);
					maiorCartaDaJogada = mao[i].getNum();
				}
				if(mao[i].getNum() == 1){
					maiorCartaDaJogada = 14;
				}
			}
			combos[combo-1]++;
		}
	}

	if(combos[quadra]) return quadra;
	if(combos[par]){ if(combos[trinca]) return trincaEPar;
					 if(combos[par]==2) return doisPares;
										return par;
	}
	return unica;
}

bool jogador::checkRoyal() const {
	for(int i=0; i<5; i++)
		LEMEMLOG((long int)(&(mao[i].numero)),sizeof(int),id);
		
	if(mao[0].getNum()==13 &&
	   mao[1].getNum()==12 &&
	   mao[2].getNum()==11 &&
	   mao[3].getNum()==10 &&
	   mao[4].getNum()==1)
	   return true;
	return false;
}

rankings jogador::ranqueDaMao(){

	if(!checkValidPlay())
		return invalid;

	bool isFlush = checkFlush();
	bool isStraight = checkStraight();

	if(isStraight && isFlush) return (checkRoyal())? royal_straight_flush : straight_flush;
	if(isStraight) 			  return straight;
	if(isFlush)				  return flush;
	switch(numRepetidas()){
		case quadra:
			return four_of_a_kind;
		case trincaEPar:
			return full_house;
		case trinca:
			return three_of_a_kind;
		case doisPares:
			return two_pairs;
		case par:
			return one_pair;
		case unica:
			return high_card;
		default:
			return invalid;
	}
}

/// @brief Limpa as cartas, retornando-as ao estado de criação 
void jogador::limpaMao(){
	for(int i=0; i<NUM_CARTAS; i++){
		ESCREVEMEMLOG((long int)(&(mao[i].naipe)),sizeof(string),id);
		ESCREVEMEMLOG((long int)(&(mao[i].numero)),sizeof(int),id);
		mao[i].setNaipe("");
		mao[i].setNum(0);
	}
	ESCREVEMEMLOG((long int)(&(maiorCartaDaJogada)),sizeof(int),id);
	ESCREVEMEMLOG((long int)(&(maiorCartaIsolada)),sizeof(int),id);
	maiorCartaDaJogada = 0;
	maiorCartaIsolada = 0;
}