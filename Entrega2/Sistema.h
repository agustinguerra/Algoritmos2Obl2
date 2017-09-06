#ifndef SISTEMA_H
#define SISTEMA_H

#include "Cadena.h"
#include "Puntero.h"
#include "Tupla.h"
#include "NodoArbol.h"
#include "Tabla.h"
#include "FuncionHash.h"

class Sistema
{
public:
	Sistema(const Cadena& nombreArchivoDiccionario);
	~Sistema();

	// Ejercicio 1: Anagramas, TablaHash abierta y cerrada
	Array<Cadena> Anagramas(const Cadena& c);
	
	template <class C, class V>
	Puntero<Tabla<C, V>> CrearTablaHashAbierto(nat cubetas, Puntero<FuncionHash<C>> fHash, const Comparador<C>& comp);
	
	template <class C, class V>
	Puntero<Tabla<C, V>> CrearTablaHashCerrado(nat cubetas, Puntero<FuncionHash<C>> fHash, const Comparador<C>& comp);

	// Ejercicio 2: AVL
	//Pre: El arbol es binario
	//Pos: Devuelve true si el arbol esta balanceado, false en caso contrario
	template <class T>
	bool EsAVL(Puntero<NodoArbol<T>> raiz, const Comparador<T>& comp);

private:
	//Atributos necesarios para cumplir con las operaciones.

};


#include "SistemaTemplates.cpp"

#endif
