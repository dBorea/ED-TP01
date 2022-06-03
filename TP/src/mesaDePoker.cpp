#include "mesaDePoker.hpp"

using std::cout;
using std::regex;
using std::regex_match;

const string fileFormat = "^(([1-9][0-9]*) ([1-9][0-9]*)\\n)((([1-9][0-9]*) ([1-9][0-9]*)\\n)(([a-zA-Zà-úÀ-Ú0-9]+ )+([1-9][0-9]*)( ([1-9]|1[0-3])[OCPE]){5}\\n*)+)+$";

bool isValidInput(string nomeArq){
	ifstream input(nomeArq);
	stringstream cmpStream;
	cmpStream << input.rdbuf();
	return regex_match(cmpStream.str(),regex(fileFormat));
}

int numDePalavras(string const& str){
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
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

void mesaDePoker::analisaLinha(string const& linha, bool primeiraRodada){
	istringstream stream(linha);
	string nome("");
	string tempString;
	int tempInt;

	for(int i=0; i<numDePalavras(linha)-NUM_ARGS; i++){		// Recebe o nome completo do jogador
		if(i>0) nome.append(" ");
		stream >> tempString;
		nome.append(tempString);
	}

	if(primeiraRodada)										// Adiciona o jogador na lista caso seja a primeira rodada
		adicionaJogador(nome, dinheiroBase);
	
	jogador *jogadorAtual = getJogador(nome);				// Cria um ponteiro temporário para o jogador atual
	erroAssert(jogadorAtual!=nullptr,"Jogador não encontrado");

	stream >> tempInt;										// Recebe a aposta do jogador
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
		if(vencedores[i]==true)
			*output << jogadores[i].getNome() << endl;
	}
}

void mesaDePoker::processaRodada(ofstream *output){

	if(!rodadaValida){
		*output << 0 << " " << 0 << " " << "I" << endl;
		rankVencedor="";
		premioDaRodada=0;
		return;
	}

	int numVencedores = 0;
	int maiorCartaJogada = 0, maiorCartaSolta = 0;
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
				vencedores[j] = false;
			maiorRank = rankAtual;
			vencedores[i] = true;
			numVencedores = 1;
		} 
		
		else if (rankAtual == maiorRank){
			vencedores[i] = true;
			numVencedores++;
		}
	}
	if(numVencedores>1)
		for(int i=0; i<numJogadores; i++){
			if(vencedores[i]==true){
				if(jogadores[i].getMaiorCartaDaJogada() > maiorCartaJogada){
					for(int j=0; j<i; j++){
						if(vencedores[j]==true){
							vencedores[j] = false;
							numVencedores--;
						}
					}
					maiorCartaJogada = jogadores[i].getMaiorCartaDaJogada();
				} 
				
				else if(jogadores[i].getMaiorCartaDaJogada() < maiorCartaJogada){
					vencedores[i] = false;
					numVencedores --;
				}
			}
		}
	
	if(numVencedores>1)
		for(int i=0; i<numJogadores; i++){
			if(vencedores[i]==true){
				if(jogadores[i].getMaiorCartaIsolada() > maiorCartaSolta){
					for(int j=0; j<i; j++){
						if(vencedores[j]==true){
							vencedores[j] = false;
							numVencedores--;
						}
					}
					maiorCartaSolta = jogadores[i].getMaiorCartaIsolada();
				} 
				
				else if(jogadores[i].getMaiorCartaIsolada() < maiorCartaSolta){
					vencedores[i] = false;
					numVencedores --;
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

		if(vencedores[i]==true){
			jogadores[i].premia(premioDaRodada/numVencedores);
		}
	}
	
	escreveOutputRodada(output, vencedores, numVencedores);

}

void mesaDePoker::ordenaJogadores(){
	for(int i=0; i<numJogadores-1; i++)
		for(int j=0; j<numJogadores-i-1; j++)
			if(jogadores[j].getDinheiro() < jogadores[j+1].getDinheiro()){
				jogador temp = jogadores[j];
				jogadores[j] = jogadores[j+1];
				jogadores[j+1] = temp;
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
	
	//erroAssert(isValidInput(arqEntrada), "Arquivo de entrada inválido.");

	int nRodadas=0, nJogadas=0;
	string linha;
	inputFile >> nRodadas >> dinheiroBase;
	
	for(int i=0; i < nRodadas; i++){
		inputFile >> nJogadas >> pingo;

		if(i==0) {
			numJogadores = nJogadas;
			jogadores = new jogador[numJogadores];
		}

		for(int j=0; j < nJogadas; j++){
			getline(inputFile, linha);
			if(linha=="") getline(inputFile, linha);
			analisaLinha(linha,(i==0));
		}

		for(int j=0; j < numJogadores; j++){
			jogadores[j].cobraPingo(pingo);
			premioDaRodada += pingo;
		}

		processaRodada(&outputFile);
		ordenaJogadores();
		
		limpaMaos();
		rodadaValida = true;
		premioDaRodada = 0;
	}

	escreveOutputFinal(&outputFile);
	delete[] jogadores;
	return;
}