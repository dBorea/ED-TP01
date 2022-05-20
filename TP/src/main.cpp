#include <iostream>
#include <fstream>
#include <string>
#include "listaEncadeada.hpp"
#include "cartaDeBaralho.hpp"
#include "msgassert.hpp"
#include "jogador.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

void testaLista(){
	LinkedList<int> *listaDeInts = new LinkedList<int>();
	int intInput[5];
	for(int i=0; i<5; i++){
		cin >> intInput[i];
	}
	cout << "Lista criada." << endl;
	for(int i=0; i<5; i++){
		listaDeInts->addElementoOrdenado(intInput[i]);
	}
	for(int i=0; i<5; i++){
		cout << "Elemento " << i+1 << ": " 
			 << *listaDeInts->getElemento(i+1) << endl;
	}
	cout << "Limpando lista" << endl;
	listaDeInts->limpaLista();
	cout << "Lista vazia: " 
		 << std::boolalpha << listaDeInts->estaVazia() << endl;
}

void testaCarta(){
	CartaDeBaralho cartaTeste("13C");
	cartaTeste.printCarta();
	cartaTeste.setCarta("1S");
	cartaTeste.printCarta();
}

void instrucoes(){
	cout << "PokerSim" << endl;
}

int main(){
	LinkedList<jogador> mesa;

	int input_nRodadas = 0, input_nJogadas = 0;
	double input_pingo = 0, input_aposta = 0, input_dinheiroBase = 0, input_premioDaRodada = 0;
	string input_nome, input_carta;

	ifstream inputFile("entrada.txt");
	erroAssert(!inputFile.fail(), "Arquivo de entrada não pôde ser aberto");
	ofstream outputFile("saida.txt");

	inputFile >> input_nRodadas >> input_dinheiroBase;		// Recebe o número de rodadas totais e o dinheiro inicial de todos os jogadores

	for(int i=0; i < input_nRodadas; i++){					// Itera por cada rodada
		inputFile >> input_nJogadas >> input_pingo;			// Recebe o número de jogadas da rodada e a aposta mínima de cada jogador

		for(int j=0; j < input_nJogadas; j++){				// Itera por cada linha(jogador) da rodada
			inputFile >> input_nome >> input_aposta;		// Recebe o nome do jogador e sua aposta individual
			if(mesa.possuiElemento(input_nome)){			// Verifica se o jogador já está na lista
				if(!mesa.getJogador(input_nome)->aposta(input_aposta + input_pingo))	// Desconta a aposta total do jogador
					continue;															// Invalida a rodada caso a aposta do jogador seja inválida // NÃO FUNCIONA!
			} else {										// Adiciona o jogador e seu dinheiro inicial, descontando as apostas
				mesa.addElemento(jogador(input_nome, input_dinheiroBase));
				mesa.getJogador(input_nome)->aposta(input_aposta + input_pingo);
			}
			mesa.getJogador(input_nome)->limpaMao();			// Limpa as cartas do jogador
			for(int k=0; k<5; k++){								// Itera pelas cinco cartas do jogador
				inputFile >> input_carta;						// Recebe a carta atual
				mesa.getJogador(input_nome)->addCarta(input_carta);	// Adiciona a carta lida ao jogador atual
			}
		}
	}

	//testaLista();
	//testaCarta();
	return 0;
}