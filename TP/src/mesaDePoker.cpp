#include "mesaDePoker.hpp"

using std::cout;

bool is_number(const string& s){
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void mesaDePoker::adicionaJogador(string input_nome, int input_dinheiro){
	jogadores[jogadoresAtuais] = jogador(input_nome, input_dinheiro, jogadoresAtuais); // Cria o novo jogador e o coloca na última posição
	jogadoresAtuais++;
}

jogador *mesaDePoker::getJogador(string const& nome) const {
	for(int i=0; i<numJogadores; i++){			// Itera sobre os jogadores
		if(jogadores[i].getNome() == nome)		// Verifica o nome
			return &jogadores[i];				// Retorna o jogador com o nome desejado
	}
	return nullptr;
}

bool mesaDePoker::possuiJogador(string const& nome) const{	// Talvez não use
	for(int i=0; i<numJogadores; i++)			// Itera sobre os jogadores
		if(jogadores[i].getNome() == nome)		// Verifica o nome
			return true;						// Retorna 'true' caso encontrado
	return false;								// E 'false' caso contrário
}

void mesaDePoker::analisaLinha(string const& linha, int rodada){
	istringstream stream(linha);
	string nome("");
	string tempString;
	int tempInt;

	for(int i=0;; i++){		// Recebe o nome completo do jogador
		stream >> tempString;
		if (is_number(tempString)){
			if(i==0){ // Garante que o número de jogadas da rodada foi informado corretamente
				char erro[200] = {"O numero de jogadas da rodada "};
				char intString[10];
				sprintf(intString, "%d", rodada);
				strcat(erro, intString);
				strcat(erro, ((char*)" foi informado incorretamente."));
				erroAssert(false,erro);
			} 
			tempInt = stoi(tempString);
			break;
		}
		else {
			if(i>0) nome.append(" ");
			nome.append(tempString);
		}
	}

	if(rodada == 1)										// Adiciona o jogador na lista caso seja a primeira rodada
		adicionaJogador(nome, dinheiroBase);

	jogador *jogadorAtual = getJogador(nome);				// Cria um ponteiro temporário para o jogador atual
	erroAssert(jogadorAtual!=nullptr,"Jogador não encontrado");
	LEMEMLOG((long int)(jogadorAtual),sizeof(jogador*),jogadorAtual->id);

	jogadorAtual->setAposta(0);
	if(tempInt%50 != 0 || tempInt == 0)
		rodadaValida = false;
	if(!jogadorAtual->setAposta(tempInt, pingo))			// Envia a aposta ao jogador e verifica a validez da mesma
		rodadaValida = false;								// Caso a aposta seja inválida, também invalida a rodada
	premioDaRodada += tempInt;

	for(int i=0; i<NUM_CARTAS; i++){						// Lê e armazena as cartas do jogador atual
		stream >> tempString;
		jogadorAtual->addCarta(tempString);
	}

	return;
}

void mesaDePoker::escreveOutputRodada(ofstream *output, bool vencedores[], int nVencedores){
	
	*output << nVencedores << " "
			<< premioDaRodada/nVencedores << " "
			<< rankVencedor << endl;
	for (int i=0; i<numJogadores; i++){
		if(vencedores[jogadores[i].id]==true)
			*output << jogadores[i].getNome() << endl;
	}
}

void mesaDePoker::processaRodada(ofstream *output){

	if(!rodadaValida){
		*output << "0 0 I" << endl;
		rankVencedor="";
		premioDaRodada=0;
		for(int i=0; i<numJogadores; i++){
			jogadores[i].setAposta(0);
		}
		return;
	}

	int numVencedores = 0;
	bool vencedores[numJogadores] = {false};
	rankings rankAtual = invalid;
	rankings maiorRank = invalid;

	for(int i=0; i<numJogadores; i++){
		jogadores[i].debitaAposta();
		jogadores[i].setAposta(0);
	}

	for(int i=0; i<numJogadores; i++){
		rankAtual = jogadores[i].ranqueDaMao();
		if(rankAtual > maiorRank){
			for(int j=0; j<i; j++)
				vencedores[jogadores[j].id] = false;
			maiorRank = rankAtual;
			vencedores[jogadores[i].id] = true;
			numVencedores = 1;
		} 
		
		else if (rankAtual == maiorRank){
			vencedores[jogadores[i].id] = true;
			numVencedores++;
		}
	}
	
	if(numVencedores>1)
		for(int n=0; n<NUM_CARTAS; n++){
			int cartasVencedores[numJogadores] = {0};
			for(int i=0; i<numJogadores; i++){
				if(vencedores[jogadores[i].id]==true)
					cartasVencedores[jogadores[i].id] = jogadores[i].cartasDaJogada[n];
			}

			int maiorCarta = 0;
			for(int i=0; i<numJogadores; i++){
				if(vencedores[jogadores[i].id]){
					if(cartasVencedores[jogadores[i].id] > maiorCarta){
						for(int j=0; j<i; j++)
							if(vencedores[jogadores[j].id]){
								vencedores[jogadores[j].id] = false;
								numVencedores--;
							}

						maiorCarta = cartasVencedores[jogadores[i].id];
					} else if(cartasVencedores[jogadores[i].id] < maiorCarta){
						vencedores[jogadores[i].id] = false;
						numVencedores--;
					}
				}
			}
		}
	
	if(numVencedores>1)
		for(int n=0; n<NUM_CARTAS; n++){
			int cartasVencedores[numJogadores] = {0};
			for(int i=0; i<numJogadores; i++){
				if(vencedores[jogadores[i].id]==true)
					cartasVencedores[jogadores[i].id] = jogadores[i].cartasIsoladas[n];
			}

			int maiorCarta = 0;
			for(int i=0; i<numJogadores; i++){
				if(vencedores[jogadores[i].id]){
					if(cartasVencedores[jogadores[i].id] > maiorCarta){
						for(int j=0; j<i; j++)
							if(vencedores[jogadores[j].id]){
								vencedores[jogadores[j].id] = false;
								numVencedores--;
							}

						maiorCarta = cartasVencedores[jogadores[i].id];
					} else if(cartasVencedores[jogadores[i].id] < maiorCarta){
						vencedores[jogadores[i].id] = false;
						numVencedores--;
					}
				}
			}
		}

	switch(maiorRank){
		case high_card:
			rankVencedor ="HC";
			break;
		case one_pair:
			rankVencedor ="OP";
			break;
		case two_pairs:
			rankVencedor ="TP";
			break;
		case three_of_a_kind:
			rankVencedor ="TK";
			break;
		case straight:
			rankVencedor ="S";
			break;
		case flush:
			rankVencedor ="F";
			break;
		case full_house:
			rankVencedor ="FH";
			break;
		case four_of_a_kind:
			rankVencedor ="FK";
			break;
		case straight_flush:
			rankVencedor ="SF";
			break;
		case royal_straight_flush:
			rankVencedor ="RSF";
			break;
		default:
			break;
	}

	for(int i=0; i<numJogadores; i++){

		if(vencedores[jogadores[i].id]==true){
			jogadores[i].premia(premioDaRodada/numVencedores);
		}
	}

	ordenaJogadores(orderByNome);
	escreveOutputRodada(output, vencedores, numVencedores);

}

void mesaDePoker::ordenaJogadores(orderCase caso){
	for(int i=0; i<numJogadores-1; i++)
		for(int j=0; j<numJogadores-i-1; j++)
			if(jogadores[j].getDinheiro() < jogadores[j+1].getDinheiro() && caso != orderByNome){
				jogador temp = jogadores[j];
				jogadores[j] = jogadores[j+1];
				jogadores[j+1] = temp;
			} else if(jogadores[j].getDinheiro() == jogadores[j+1].getDinheiro() && caso != orderByDinheiro){
				if(jogadores[j].getNome().compare(jogadores[j+1].getNome()) == 1){
					jogador temp = jogadores[j];
					jogadores[j] = jogadores[j+1];
					jogadores[j+1] = temp;
				}
			}
}

void mesaDePoker::escreveOutputFinal(ofstream *output){
	*output << "####" << endl;
	for(int i=0; i<numJogadores; i++){
		*output << jogadores[i].getNome() << " " 
				<< jogadores[i].getDinheiro() << endl;
	}
			
}

void mesaDePoker::limpaMaos(){
	for(int i=0; i<numJogadores; i++){
		jogadores[i].limpaMao();
	}
}

void mesaDePoker::processaJogo(char inputName[], char outputName[]){
	string arqEntrada(inputName);
	string arqSaida(outputName);
	ifstream inputFile(arqEntrada);
	erroAssert(!inputFile.fail(), "Arquivo de entrada não pôde ser aberto");
	ofstream outputFile(arqSaida);

	int nRodadas=0, nJogadas=0;
	string linha;
	inputFile >> nRodadas >> dinheiroBase;
	
	for(int i=0; i < nRodadas; i++){
		inputFile >> nJogadas >> pingo;
		if(pingo%50 != 0 || pingo == 0)
			rodadaValida = false;
		if(i==0) {
			numJogadores = nJogadas;
			jogadores = new jogador[numJogadores];
		}

		for(int j=0; j < nJogadas; j++){
			getline(inputFile, linha);
			if(linha=="") getline(inputFile, linha);
			analisaLinha(linha,(i+1));
		}

		for(int j=0; j < numJogadores; j++){
			if(jogadores[j].cobraPingo(pingo))
				premioDaRodada += pingo;
			else
				rodadaValida = false;
		}

		processaRodada(&outputFile);
		
		limpaMaos();
		rodadaValida = true;
		premioDaRodada = 0;
	}
	ordenaJogadores();
	escreveOutputFinal(&outputFile);
	delete[] jogadores;
	return;
}