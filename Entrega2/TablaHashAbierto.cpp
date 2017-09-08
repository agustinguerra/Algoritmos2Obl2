#ifndef TABLAHASHABIERTO_CPP
#define TABLAHASHABIERTO_CPP

#include "TablaHashAbierto.h"

/* CONSTRUCTORAS */

//PRE: T(c) no está definida y la tabla no está llena
//POS: Define T(c) = v
void Agregar(const C& c, const V& v) {

}

//PRE: T(c) está definida
//POS: Borra la asociación ligada a 'c'
void Borrar(const C& c) {

}

//PRE: - 
//POS: Borra todas las asociaciones
void BorrarTodos() {

}

/* PREDICADOS */

//PRE: - 
//POS: Retorna true si está vacía, false sino.
bool EstaVacia() const {

}

//PRE: - 
//POS: Retorna true si está llena, false sino.
bool EstaLlena() const {

}

//PRE: - 
//POS: Retorna true si T(c) está definida, es decir, si la clave c está definida. False sino.
bool EstaDefinida(const C& c) const {

}

/* SELECTORAS */

//Pre: -
//Pos: Devuelve el siguiente numero primo
int sigPrimo(int num) {
	
}

//PRE: T(c) está definida
//POS: Retorna 'v', tal que T(c) = v
const V& Obtener(const C& c) const {

}

//PRE: -
//POS: Retorna el largo de la tabla
nat Largo() const {

}

//PRE: -
//POS: Devuelve un clon de la tabla, no comparten memoria
Puntero<Tabla<C, V>> Clonar() const {

}

Iterador<T> ObtenerIterador() const {

}

#endif