
#include <iostream>
#include "listaEncadeada.hpp"

using std::cout;
using std::cin;
using std::endl;
 
int main(){
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
	return 0;
}