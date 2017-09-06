#ifndef SISTEMATEMPLATES_CPP
#define SISTEMATEMPLATES_CPP

#include "Sistema.h"
#include <cmath>

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


//Pre: El arbol es binario
//Pos: Devuelve la altura del nodo
template <class T>
int alturaNodo(Puntero<NodoArbol<T>> nodo) {
	if (nodo == NULL) {
		return -1;
	}
	else {
		return 1 + max(alturaNodo(nodo->izq), alturaNodo(nodo->der));
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
	int balance = alturaNodo(raiz->izq) - alturaNodo(raiz->der);
	if (Math.abs(balance) > 1) {
		return false;
	}
	else {
		return EsAVL(raiz->izq,comp) && EsAVL(raiz->der,comp);
	}
}

#endif