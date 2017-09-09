#ifndef TABLAHASHABIERTO_CPP
#define TABLAHASHABIERTO_CPP

#include "TablaHashAbierto.h"

/* CONSTRUCTORAS */

//PRE: T(c) no está definida y la tabla no está llena
//POS: Define T(c) = v
template <class C, class V>
void TablaHashAbierto::Agregar(const C& c, const V& v) {
	nat clave = this->pFunc->CodigoDeHash(c);
	int lugar = clave;
	if (laTabla[lugar] == NULL) {
		ocupado = ocupado + 1;
	}
	laTabla[lugar]->InsertarPrincipio(Tupla<C, V>(c, v));
}

//PRE: T(c) está definida
//POS: Borra la asociación ligada a 'c'
template <class C, class V>
void TablaHashAbierto::Borrar(const C& c) {

}

//PRE: - 
//POS: Borra todas las asociaciones
template <class C, class V>
void TablaHashAbierto::BorrarTodos() {
	int tam = this->tamano;
	for (int i = 0; i < tamano; i++) {
		this->laTabla[i] = nullptr;
	}
	this->ocupados = 0;
}

/* PREDICADOS */

//PRE: - 
//POS: Retorna true si está vacía, false sino.
template <class C, class V>
bool TablaHashAbierto::EstaVacia() const {
	if (this->ocupados == 0) {
		return true;
	}
	else {
		return false;
	}
}

//PRE: - 
//POS: Retorna true si está llena, false sino.
template <class C, class V>
bool TablaHashAbierto::EstaLlena() const {
	return ((ocupados * 100) / tamano) > 70;
}

//PRE: - 
//POS: Retorna true si T(c) está definida, es decir, si la clave c está definida. False sino.
template <class C, class V>
bool TablaHashAbierto::EstaDefinida(const C& c) const {
	return false;
}

/* SELECTORAS */

//Pre: n mayor que 1
//Pos: devuelve true si el numero dado es primo
template <class C, class V>
bool TablaHashAbierto::esPrimo(int n)
{
	int i, raiz;

	if (n % 2 == 0 || n % 3 == 0)
		return false;

	raiz = (int)sqrt(n);

	for (i = 5; i <= raiz; i += 6)
	{
		if (n%i == 0)
			return false;
	}

	for (i = 7; i <= raiz; i += 6)
	{
		if (n%i == 0)
			return false;
	}

	return true;
}


//Pre: -
//Pos: Devuelve el siguiente numero primo
template <class C, class V>
int TablaHashAbierto::sigPrimo(int num) {
	i = num + 1;
	while (1) {
		if (esPrimo(i)) {
			break;
		}
		i = i + 1;
	}
	return i;
}

//PRE: T(c) está definida
//POS: Retorna 'v', tal que T(c) = v
template <class C, class V>
const V& TablaHashAbierto::Obtener(const C& c) const {

}

//PRE: -
//POS: Retorna el largo de la tabla
template <class C, class V>
nat TablaHashAbierto::Largo() const {
	return this->tamano;
}

//PRE: -
//POS: Devuelve un clon de la tabla, no comparten memoria
template <class C, class V>
Puntero<Tabla<C, V>> TablaHashAbierto::Clonar() const {
	
}
//PRE: -
//POS: Devuelve el iterador
template <class C, class V>
Iterador<T> TablaHashAbierto::ObtenerIterador() const {

}

#endif