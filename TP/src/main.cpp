
#include <iostream>
#include "listaEncadeada.hpp"

using std::cout;
using std::endl;
 
int main(){
	LinkedList<int> *listaDeInts = new LinkedList<int>();
	cout << "Lista criada." << endl;
	listaDeInts->addElemento(20);
	cout << *listaDeInts->getElemento(1) << endl;
	return 0;
}