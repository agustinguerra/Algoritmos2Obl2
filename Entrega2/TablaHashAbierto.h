#pragma once

#include "Tupla.h"
#include "Array.h"
#include "ListaOrdImp.h"
#include "FuncionHash.h"

template <class C, class V>
class TablaHashAbierto : public Table<C, V>
{
public:
	~TablaHashAbierto() { }

	/* CONSTRUCTORAS */

	//PRE: T(c) no est� definida y la tabla no est� llena
	//POS: Define T(c) = v
	void Agregar(const C& c, const V& v) override;

	//PRE: T(c) est� definida
	//POS: Borra la asociaci�n ligada a 'c'
	void Borrar(const C& c) override;

	//PRE: - 
	//POS: Borra todas las asociaciones
	void BorrarTodos() override;

	/* PREDICADOS */

	//Pre: -
	//Pos: Devuelve el siguiente numero primo
	int sigPrimo(int num);

	//PRE: - 
	//POS: Retorna true si est� vac�a, false sino.
	bool EstaVacia() const override;

	//PRE: - 
	//POS: Retorna true si est� llena, false sino.
	bool EstaLlena() const override;

	//PRE: - 
	//POS: Retorna true si T(c) est� definida, es decir, si la clave c est� definida. False sino.
	bool EstaDefinida(const C& c) const override;

	//Pre: n mayor que 1
	//Pos: devuelve true si el numero dado es primo
	bool esPrimo(int n);

	/* SELECTORAS */

	//PRE: T(c) est� definida
	//POS: Retorna 'v', tal que T(c) = v
	const V& Obtener(const C& c) const override;

	//PRE: -
	//POS: Retorna el largo de la tabla
	nat Largo() const override;

	//PRE: -
	//POS: Devuelve un clon de la tabla, no comparten memoria
	Puntero<Tabla<C, V>> Clonar() const override;

	//PRE: -
	//POS: Devuelve el iterador
	Iterador<T> ObtenerIterador() const override;

private:
	Array<Puntero<ListaOrdImp<Tupla<C, V>>>> laTabla;
	Puntero<FunctionHash<C>> pFunc;
	int tamano;
	int ocupados;

};

#include "TablaHashAbierto.cpp"