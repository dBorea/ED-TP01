#include <iostream>
#include <fstream>
#include <string>
#include <getopt.h>
#include "msgassert.hpp"
#include "mesaDePoker.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

void instrucoes(){
	cout << "||----------PokerSim----------||" << endl;
	cout << "Args:" << endl;
	cout << "\t-h\t\t\t|Ajuda" << endl;
	cout << "\t-l\t\t\t|Opcional: Registrar os acessos de memória em adição aos tempos de execução" << endl;
	cout << "\t-i <arq>\t\t|Opcional: Especializar o nome de entrada do arquivo" << endl;
	cout << "\t-o <arq>\t\t|Opcional: Especializar o nome de saída do arquivo" << endl;
	cout << "\t-p <arq>\t\t|Opcional: Especializar o nome do registro de execução" << endl;
	cout << endl << "Como usar:" << endl;
	cout << "No terminal, acesse a pasta onde o arquivo 'entrada.txt' está localizado." << endl;
	cout << "Execute o programa pelo terminal. Será gerado um arquivo 'saida.txt' completo caso o programa seja executado sem erros." << endl;
	cout << "Se houver uma mensagem de erro, a saída é inválida e deve ser descartada." << endl;
}

bool parseArgs(int argc, char *argv[], char logname[], char inputname[], char outputname[], bool &optReg){
	extern char *optarg;
	//extern int optind;
	logname[0] = 0;
	inputname[0] = 0;
	outputname[0] = 0;
	bool optInput = false;
	bool optOutput = false;
	bool regmem = false;

	for(int opt; (opt=getopt(argc, argv, "p:hi:o:l")) != EOF;){
		switch (opt){
		case 'p':
			strcpy(logname, optarg);
			erroAssert(strlen(logname)>0, "Com a opção -p, o nome do arquivo de log deve ser informado.");
			optReg = true;
			break;
		
		case 'h':
			instrucoes();
			exit(1);

		case 'i':
			strcpy(inputname, optarg);
			erroAssert(strlen(inputname)>0, "Com a opção -i, o nome do arquivo de entrada deve ser informado.");
			optInput = true;
			break;

		case 'o':
			strcpy(outputname, optarg);
			erroAssert(strlen(outputname)>0, "Com a opção -o, o nome do arquivo de saída deve ser informado.");
			optOutput = true;
			break;

		case 'l':
			regmem = true;
			break;

		default:
			break;
		}
	}

	if(optReg == false){
		regmem = false;
	} 
	if(optInput == false) strcpy(inputname, "entrada.txt");
	if(optOutput == false) strcpy(outputname, "saida.txt");
	return regmem;
}

int main(int argc, char *argv[]){
	char logname[100], inputname[100], outputname[100];
	bool optReg;
	bool regmem = parseArgs(argc, argv, logname, inputname, outputname, optReg);
	
	if(optReg)
		iniciaMemLog(logname);
	if(regmem)
		ativaMemLog();
	else 
		desativaMemLog();

	mesaDePoker mesa;
	mesa.processaJogo(inputname, outputname);

	return (optReg)? finalizaMemLog() : 0;
}