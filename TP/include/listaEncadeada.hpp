#ifndef LISTAENCADEADA
#define LISTAENCADEADA

#include <string>

using std::string;

template <typename tipoT> class Celula;
template <typename tipoT> class LinkedList;

template <typename tipoT>
class Celula{
	private:
		tipoT elem;
		Celula *prox;
	public:
		Celula() { prox = nullptr; }
		int dimensao();
		int getJogadorID();
		string getElemName();
	friend class LinkedList<tipoT>;
};

/// @brief Classe Lista Encadeada.
/// 
/// @tparam tipoT
template <typename tipoT>
class LinkedList{
	private:
		int tamanho;
		Celula<tipoT> *cabeca;
		Celula<tipoT> *ultima;
	public:
		LinkedList() : tamanho(0) { cabeca = new Celula<tipoT>(); ultima = cabeca; }
		~LinkedList() { limpaLista(); delete cabeca; }
		int getTamanho() { return tamanho; }
		bool estaVazia() { return tamanho == 0; }
		bool possuiElemento(string);
		tipoT *getElemento(int);
		tipoT *getJogador(string);
		void addElemento(tipoT);
		void addElementoOrdenado(tipoT);
		void rmvElemento(); 	// Talvez não seja usada. Remover se necessário.
		void limpaLista();
};

#endif