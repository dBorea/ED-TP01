#include "jogador.hpp"

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
bool jogador::setAposta(int quantia){
	apostaADebitar = quantia;
	if(dinheiro - quantia >= 0)
		return 1;
	return 0;
}

/// @brief Aplica as apostas do jogador
void jogador::debitaAposta(){
	dinheiro -= apostaADebitar;
	apostaADebitar = 0;
}

/// @brief Retorna o número da maior carta do jogador.
/// 
/// @return int 
int  jogador::maiorCarta() const {
	if(mao[4].getNum() != 0)
		return mao[0].getNum();
	return 0;
}

bool jogador::checkStraight(){
	int cartasAChecar = (mao[0].getNum()==13 && mao[NUM_CARTAS-1].getNum()==1)? NUM_CARTAS-1 : NUM_CARTAS;
	for(int i=0; i<cartasAChecar; i++){
		if(mao[i].getNum() != mao[0].getNum()-i)
			return false;
	}
	if(cartasAChecar==NUM_CARTAS-1)
		maiorCartaDaJogada = 14;
	maiorCartaDaJogada = maiorCarta();
	return true;
}

bool jogador::checkFlush(){
	string naipeCmp = mao[0].getNaipe();
	for(int i=1; i<NUM_CARTAS; i++)
		if(mao[i].getNaipe() != naipeCmp)
			return false;
	maiorCartaDaJogada = maiorCarta();
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
				if((!identificada[j]) && (mao[i].getNum() == mao[j].getNum())){
					identificada[j] = true;
					combo++;
				}
			}
			if(combo==1 && mao[i].getNum() > maiorCartaIsolada) maiorCartaIsolada = mao[i].getNum();
			if(combo!=1 && mao[i].getNum() > maiorCartaDaJogada) maiorCartaDaJogada = mao[i].getNum();
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
	if(mao[0].getNum()==13 &&
	   mao[1].getNum()==12 &&
	   mao[2].getNum()==11 &&
	   mao[3].getNum()==10 &&
	   mao[4].getNum()==1)
	   return true;
	return false;
}

rankings jogador::ranqueDaMao(){

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
		mao[i].setNaipe("");
		mao[i].setNum(0);
	}
	maiorCartaDaJogada = 0;
	maiorCartaIsolada = 0;
}