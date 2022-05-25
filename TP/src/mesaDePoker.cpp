#include "mesaDePoker.hpp"

using std::cout;

int numDePalavras(string const& str){
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}

void mesaDePoker::adicionaJogador(string input_nome, int input_dinheiro){
	jogadores[jogadoresAtuais] = jogador(input_nome, input_dinheiro);				// Cria o novo jogador e o coloca na última posição
	jogadoresAtuais++;
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

void mesaDePoker::analisaLinha(string const& linha, bool primeiraRodada){
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
	if(!jogadorAtual->setAposta(tempInt + pingo))			// Envia a aposta ao jogador e verifica a validez da mesma
		rodadaValida = false;								// Caso a aposta seja inválida, também invalida a rodada
	premioDaRodada += tempInt + pingo;

	jogadorAtual->limpaMao();
	for(int i=0; i<NUM_CARTAS; i++){						// Lê e armazena as cartas do jogador atual
		stream >> tempString;
		jogadorAtual->addCarta(tempString);
	}

	return;
}

void mesaDePoker::processaRodada(){
	bool vencedores[numJogadores] = {0, 1, 0};
	if(!rodadaValida){
		numVencedores=0;
		rankVencedor="";
		premioDaRodada=0;
		return;
	}

	for(int i=0; i<numJogadores; i++){
		jogadores[i].debitaAposta();
		jogadores[i].setAposta(0);
	}
	//fazer alguma coisa com ranque das maos
	numVencedores = 1; // ?
	rankVencedor = "ablublublu";
	for(int i=0; i<numJogadores; i++){
		if(vencedores[i])
			jogadores[i].premia(premioDaRodada/numVencedores);
	}
	
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

void mesaDePoker::escreveOutputRodada(ofstream *output){
	if(!rodadaValida){
		*output << 0 << " " << 0 << " " << "I" << endl;
		return;
	}

	*output << numVencedores << " "
			<< premioDaRodada/numVencedores << " "
			<< rankVencedor << endl;
	for (int i=0; i<numVencedores; i++){
		*output << jogadores[i].getNome() << endl;
	}
}

void mesaDePoker::escreveOutputFinal(ofstream *output){
	*output << "####" << endl;
	for(int i=0; i<numJogadores; i++){
		*output << jogadores[i].getNome() << " " 
				<< jogadores[i].getDinheiro() << endl;
	}
			
}

void mesaDePoker::processaJogo(){
	ifstream inputFile("entrada.txt");
	erroAssert(!inputFile.fail(), "Arquivo de entrada não pôde ser aberto");
	ofstream outputFile("saida.txt");

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

		processaRodada();
		ordenaJogadores();
		escreveOutputRodada(&outputFile);
		
		rodadaValida = true;
		numVencedores = 0;
		premioDaRodada = 0;
	}

	escreveOutputFinal(&outputFile);
	delete[] jogadores;
	return;
}