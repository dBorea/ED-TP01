#include "listaEncadeada.hpp"
#include "msgassert.hpp"

template <>
int Celula<int>::dimensao(){
	return elem;
}
 
/// @brief Retorna o endereço do elemento da posição informada.
/// 
/// @tparam tipoT
/// @param id Número da célula na qual o elemento será buscado
template <typename tipoT>
tipoT *LinkedList<tipoT>::getElemento(int id){
	// Checagem de erro. Impede que a função rode caso 'id' seja maior que o permitido.
	erroAssert(id > 0, "Tentativa de procurar por um elemento de identificador menor ou igual a zero");
	erroAssert(id <= tamanho, "Tentativa de procurar por um elemento de identificador maior que o tamanho da lista");

	Celula<tipoT> *aux = cabeca;
	// Procura a célula número 'id'.
	for(int i = 0; i < id; ++i){
		// Checagem de erro. Impede que haja uma tentativa de acesso de elementos de um ponteiro nulo caso o primeiro assert tenha falhado.
		erroAssert(aux != nullptr, "Tentativa de acessar elemento com identificador maior que o tamanho da lista.");
		aux = aux->prox;
	}
	// Retorna o elemento tipoT elem encontrado.
	return &aux->elem;
}
		
/// @brief Adiciona um novo elemento à lista na última posição
/// 
/// @tparam tipoT 
/// @param novoElem 
template <typename tipoT>
void LinkedList<tipoT>::addElemento(tipoT novoElem){
	Celula<tipoT> *nova = new Celula<tipoT>();	// Aloca a nova célula
	nova->elem = novoElem;						// Atribui o novo elemento à célula
	ultima->prox = nova;						// Conecta a nova célula à (atual) última célula
	ultima = nova;								// Define a nova célula como última
	tamanho++;									// Aumenta o tamanho da lista
}

/// @brief Adiciona um novo elemento à lista de acordo com sua dimensão. Todos os elementos devem ter sido ordenados para a utilização dessa função.
/// @tparam tipoT 
/// @param novoElem 
template <typename tipoT>
void LinkedList<tipoT>::addElementoOrdenado(tipoT novoElem){
	if(tamanho == 0) return addElemento(novoElem);

	Celula<tipoT> *nova = new Celula<tipoT>();	// Aloca a nova célula
	nova->elem = novoElem;			// Atribui o novo elemento à célula

	Celula<tipoT> *aux = cabeca;
	for(;aux->prox!=nullptr;){
		if(nova->dimensao() < aux->prox->dimensao()){	// Verifica se a dimensão do novo elemento é menor que do elemento auxiliar atual
			nova->prox = aux->prox;
			aux->prox = nova;
			ultima = nova;
			tamanho++;
			return;
		}
		aux = aux->prox;
	}

	addElemento(novoElem);
}

/// @brief Limpa todos os elementos da lista, deixando apenas a cabeça.
/// 
/// @tparam  
template <typename tipoT>
void LinkedList<tipoT>::limpaLista(){
	Celula<tipoT> *aux = cabeca->prox;
	for(;aux!=nullptr;){			// Enquanto a primeira célula não for nula (exceto a cabeça)
		cabeca->prox = aux->prox;	// Conecta a cabeça à segunda célula
		delete aux;					// Deleta a primeira célula
		aux = cabeca->prox;			// Muda aux para a nova primeira célula
	}
	ultima = cabeca;				// A última célula restante é a cabeça
	tamanho = 0;
}


template <typename tipoT>
void LinkedList<tipoT>::rmvElemento(){
	return;
}

template class LinkedList<int>;