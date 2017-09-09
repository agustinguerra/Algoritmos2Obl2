#ifndef SISTEMATEMPLATES_CPP
#define SISTEMATEMPLATES_CPP

#include "Sistema.h"
#include "TablaHashAbierto.h"

template <class C, class V>
Puntero<Tabla<C, V>> Sistema::CrearTablaHashAbierto(nat cubetas, Puntero<FuncionHash<C>> fHash, const Comparador<C>& comp)
{
	Puntero<Tabla<C,V>> tabla = new TablaHashAbierto<C,V>(cubetas, fHash, comp);
	return tabla;
}

template <class C, class V>
Puntero<Tabla<C, V>> Sistema::CrearTablaHashCerrado(nat cubetas, Puntero<FuncionHash<C>> fHash, const Comparador<C>& comp)
{
	return NULL;
}


//Pre: es un arbol binario
//Pos: devuelve true si todos los elementos son menores al a comparar
template <class T>
bool sonTodosMenores(Puntero<NodoArbol<T>> nodo, const Comparador<T>& comp, const T& dato) {
	if (nodo != NULL) {
		if (comp.Comparar(dato, nodo->dato) == MAYOR) {
			return sonTodosMenores(nodo->izq, comp, dato) && sonTodosMenores(nodo->der, comp, dato);
		}
		else {
			return false;
		}
	}
	else {
		return true;
	}
}


//Pre: es un arbol binario
//Pos: devuelve true si todos los elementos son mayores al a comparar
template <class T>
bool sonTodosMayores(Puntero<NodoArbol<T>> nodo, const Comparador<T>& comp,const T& dato) {
	if (nodo != NULL) {
		if (comp.Comparar(dato, nodo->dato) == MENOR) {
			return sonTodosMayores(nodo->izq, comp, dato) && sonTodosMayores(nodo->der, comp, dato);
		}
		else {
			return false;
		}
	}
	else {
		return true;
	}
}


//Pre: es un abrol binario
//Pos: devuelve true si es abb o false en caso contrario
template <class T>
bool esAbb(Puntero<NodoArbol<T>> nodo, const Comparador<T>& comp)
{
	if (nodo == NULL)
		return(true);
	bool izq = true;
	bool der = true;
	if (nodo->izq != NULL) {
		izq = sonTodosMenores(nodo->izq, comp, nodo->dato);
	}
	if (nodo->der != NULL) {
		der = sonTodosMayores(nodo->der, comp, nodo->dato);
	}
	return izq && der;
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
			return 1 + alturaNodo(nodo->izq,comp);
		}
		else {
			return 1 + alturaNodo(nodo->der,comp);
		}
	}
}

//Pre: El arbol es binario
//Pos: Devuelve true si el arbol esta balanceado, false en caso contrario
template <class T>
bool EsAVLAux(Puntero<NodoArbol<T>> raiz, const Comparador<T>& comp) {
	if (raiz == NULL) {
		return true;
	}
	int balance = alturaNodo(raiz->izq, comp) - alturaNodo(raiz->der, comp);
	if ((balance>1) || (balance<-1)) {
		return false;
	}
	else {
		return EsAVLAux(raiz->izq, comp) && EsAVLAux(raiz->der, comp);
	}
}

//Pre: El arbol es binario
//Pos: Devuelve true si el arbol esta balanceado, false en caso contrario
template <class T>
bool Sistema::EsAVL(Puntero<NodoArbol<T>> raiz, const Comparador<T>& comp)
{
	if (esAbb(raiz, comp)) {
		bool ret;
		ret = EsAVLAux(raiz, comp);
		return ret;
	}
	else {
		return false;
	}
}

#endif