#pragma once


template <class D, class R>
class TablaHashAbierto : public Table<D, R>
{
public:
	~TablaHashAbierto() { }

	/* CONSTRUCTORAS */

	//PRE: T(c) no está definida y la tabla no está llena
	//POS: Define T(c) = v
	void Agregar(const C& c, const V& v) override;

	//PRE: T(c) está definida
	//POS: Borra la asociación ligada a 'c'
	void Borrar(const C& c) override;

	//PRE: - 
	//POS: Borra todas las asociaciones
	void BorrarTodos() override;

	/* PREDICADOS */

	//PRE: - 
	//POS: Retorna true si está vacía, false sino.
	bool EstaVacia() const override;

	//PRE: - 
	//POS: Retorna true si está llena, false sino.
	bool EstaLlena() const override;

	//PRE: - 
	//POS: Retorna true si T(c) está definida, es decir, si la clave c está definida. False sino.
	bool EstaDefinida(const C& c) const override;

	/* SELECTORAS */

	//PRE: T(c) está definida
	//POS: Retorna 'v', tal que T(c) = v
	const V& Obtener(const C& c) const override;

	//PRE: -
	//POS: Retorna el largo de la tabla
	nat Largo() const override;

	//PRE: -
	//POS: Devuelve un clon de la tabla, no comparten memoria
	Puntero<Tabla<C, V>> Clonar() const override;

	Iterador<T> ObtenerIterador() const override;

private:
	Array<Puntero<ListaOrdImp<Asociacion<D, R>>>> laTabla;
	Puntero<FunctionHash<D>> pFunc;
	nat tamano;

};

#include "TablaHashAbierto.cpp"