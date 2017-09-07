#ifndef SISTEMATEMPLATES_CPP
#define SISTEMATEMPLATES_CPP

#include "Sistema.h"

template <class C, class V>
Puntero<Tabla<C, V>> Sistema::CrearTablaHashAbierto(nat cubetas, Puntero<FuncionHash<C>> fHash, const Comparador<C>& comp)
{
	return NULL;
}

template <class C, class V>
Puntero<Tabla<C, V>> Sistema::CrearTablaHashCerrado(nat cubetas, Puntero<FuncionHash<C>> fHash, const Comparador<C>& comp)
{
	return NULL;
}

bool sonTodosMayores(Puntero<NodoArbol<T>> nodo, const Comparador<T>& comp) {


	// Return maximum of 3 values:
	// 1) Root's data 2) Max in Left Subtree
	// 3) Max in right subtree
	T res = nodo->dato;
	if(nodo->izq!=NULL)
		T lres = maximo(nodo->izq);
	if(nodo->der!=NULL)
	T rres = maximo(root->right);

	if (lres > res)
		res = lres;
	if (rres > res)
		res = rres;
	return res;
}


//Pre: es un abrol binario
//Pos: devuelve true si es abb o false en caso contrario
template <class T>
int esAbb(Puntero<NodoArbol<T>> nodo, const Comparador<T>& comp)
{
	if (nodo == NULL)
		return(true);

	if (nodo->izq != NULL && comp.Compare(maximo(nodo->izq),nodo->dato)==MAYOR)
		return(false);

	if (nodo->der != NULL && comp.Compare(minimo(nodo->der),nodo->dato)==MENOR)
		return(false);

	if (!esAbb(nodo->izq) || !esAbb(nodo->der))
		return(false);

	return(true);
}




//Pre: El arbol es binario
//Pos: Devuelve la altura del nodo
template <class T>
int alturaNodo(Puntero<NodoArbol<T>> nodo, const Comparador<T>& comp) {
	if (nodo == NULL) {
		return -1;
	}
	else {
		if (alturaNodo(nodo->izq,comp) > alturaNodo(nodo->der,comp)) {
			return 1 + alturaNodo(nodo->izq);
		}
		else {
			return 1 + alturaNodo(nodo->der,comp);
		}
	}
}

//Pre: El arbol es binario
//Pos: Devuelve true si el arbol esta balanceado, false en caso contrario
template <class T>
bool Sistema::EsAVL(Puntero<NodoArbol<T>> raiz, const Comparador<T>& comp)
{
	if (raiz == NULL) {
		return true;
	}
	int balance = alturaNodo(raiz->izq,comp) - alturaNodo(raiz->der,comp);
	if ((balance>1)||(balance<-1)) {
		return false;
	}
	else {
		return EsAVL(raiz->izq,comp) && EsAVL(raiz->der,comp);
	}
}

#endif