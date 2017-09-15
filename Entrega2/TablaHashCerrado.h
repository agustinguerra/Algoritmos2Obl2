#pragma once


#include "Tupla.h"
#include "Tabla.h"
#include "Array.h"
#include "ListaOrdImp.h"
#include "FuncionHash.h"
#include "ComparadorTupla.h"

enum state {libre,ocupada,baja};

template <class C, class V>
class TablaHashCerrado : public Tabla<C, V> {
public:

	~TablaHashCerrado() { }

	//Pre: n mayor que 1
	//Pos: devuelve true si el numero dado es primo
	bool esPrimo(int n);

	//Pre: -
	//Pos: Devuelve el siguiente numero primo
	int sigPrimo(int num);
	//PRE: -
	//POS: Construye el hash
	TablaHashCerrado(nat cubetas, Puntero<FuncionHash<C>> fHash, const Comparador<C> comp);

	/* CONSTRUCTORAS */

	//PRE: -
	//POS: devuelve la posicion correcta para insertar
	int posInsertar(int lug);

	//PRE: T(c) no está definida y la tabla no está llena
	//POS: Define T(c) = v
	void Agregar(const C& c, const V& v);

	//PRE: T(c) está definida
	//POS: Borra la asociación ligada a 'c'
	void Borrar(const C& c);

	//PRE: - 
	//POS: Borra todas las asociaciones
	void BorrarTodos();

	/* PREDICADOS */

	//PRE: - 
	//POS: Retorna true si está vacía, false sino.
	bool EstaVacia() const;

	//PRE: - 
	//POS: Retorna true si está llena, false sino.
	bool EstaLlena() const;

	//PRE: - 
	//POS: Retorna true si T(c) está definida, es decir, si la clave c está definida. False sino.
	bool EstaDefinida(const C& c) const;

	/* SELECTORAS */

	//PRE: T(c) está definida
	//POS: Retorna 'v', tal que T(c) = v
	const V& Obtener(const C& c) const;

	//PRE: -
	//POS: Retorna el largo de la tabla
	nat Largo() const;

	//PRE: -
	//POS: Devuelve un clon de la tabla, no comparten memoria
	Puntero<Tabla<C, V>> Clonar() const;

	//PRE: -
	//POS: Devuelve el iterador
	Iterador<Tupla<C, V>> ObtenerIterador() const override;


private:
	int tamano;
	int ocupados;
	int largo;
	Array<Tupla<C, V,state>> laTabla;
	Puntero<FuncionHash<C>> pFunc;
	Comparador<C> comparador;
};

#include "TablaHashCerrado.cpp"