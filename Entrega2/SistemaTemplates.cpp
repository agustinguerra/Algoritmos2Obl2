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

template <class T>
bool Sistema::EsAVL(Puntero<NodoArbol<T>> raiz, const Comparador<T>& comp)
{
	return false;
}

#endif