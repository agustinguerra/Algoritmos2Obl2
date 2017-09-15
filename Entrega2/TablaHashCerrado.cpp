#ifndef TABLAHASHCERRADO_CPP
#define TABLAHASHCERRADO_CPP

#include "TablaHashCerrado.h"


/* CONSTRUCTORAS */

//Pre: n mayor que 1
//Pos: devuelve true si el numero dado es primo
template <class C, class V>
bool TablaHashCerrado<C, V>::esPrimo(int n)
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
int TablaHashCerrado<C, V>::sigPrimo(int num) {
	int i = num + 1;
	while (1) {
		if (esPrimo(i)) {
			break;
		}
		i = i + 1;
	}
	return i;
}


//PRE: -
//POS: Construye el hash
template <class C, class V>
TablaHashCerrado<C, V>::TablaHashCerrado(nat cubetas, Puntero<FuncionHash<C>> fHash, const Comparador<C> comp) {
	int cub = cubetas;
	int primerPrimo = sigPrimo(150000);
	this->tamano = primerPrimo;
	this->comparador = comp;
	this->pFunc = fHash;
	this->ocupados = 0;
	this->largo = 0;
	Array<Tupla<C, V,state>> arr(primerPrimo);
	this->laTabla = arr;
	for (int i = 0; i < primerPrimo; i++) {
		this->laTabla[i] = Tupla<C,V,state>(C(),V(),libre);
	}
}

//PRE: -
//POS: devuelve la posicion correcta para insertar

template <class C, class V>
int TablaHashCerrado<C, V>::posInsertar(int lug) {

	while (laTabla[lug].Dato3 == ocupada) {
		lug += 1;
		lug = lug % tamano;
	}

	return lug;
}


//PRE: T(c) no está definida y la tabla no está llena
//POS: Define T(c) = v
template <class C, class V>
void TablaHashCerrado<C, V>::Agregar(const C& c, const V& v) {
	nat clave = this->pFunc->CodigoDeHash(c);
	int lugar = clave;
	lugar = lugar % this->tamano;
	int posParaInsertar = posInsertar(lugar);
	laTabla[posParaInsertar].AsignarDato1(c);
	laTabla[posParaInsertar].AsignarDato2(v);
	laTabla[posParaInsertar].AsignarDato3(ocupada);
	largo += 1;
	ocupados += 1;

}

//PRE: T(c) está definida
//POS: Borra la asociación ligada a 'c'
template <class C, class V>
void TablaHashCerrado<C, V>::Borrar(const C& c) {
	nat clave = this->pFunc->CodigoDeHash(c);
	int lugar = clave;
	lugar = lugar % this->tamano;

	while (comparador.Comparar(c,laTabla[lugar].Dato1)==MAYOR || comparador.Comparar(c, laTabla[lugar].Dato1) == MAYOR)
	{
		lugar = lugar++;
		lugar = lugar % this->tamano;
	}

	laTabla[lugar].AsignarDato3(baja);
	largo--;
	ocupados--;
}

//PRE: - 
//POS: Borra todas las asociaciones
template <class C, class V>
void TablaHashCerrado<C, V>::BorrarTodos() {
	for (int i = 0; i < tamano; i++) {
		laTabla[i].AsignarDato3(libre);
	}
	ocupados = 0;
	largo = 0;
}

/* PREDICADOS */

//PRE: - 
//POS: Retorna true si está vacía, false sino.
template <class C, class V>
bool TablaHashCerrado<C, V>::EstaVacia() const {
	return largo == 0;
}

//PRE: - 
//POS: Retorna true si está llena, false sino.
template <class C, class V>
bool TablaHashCerrado<C, V>::EstaLlena() const {
	return largo == tamano;
}

//PRE: - 
//POS: Retorna true si T(c) está definida, es decir, si la clave c está definida. False sino.
template <class C, class V>
bool TablaHashCerrado<C, V>::EstaDefinida(const C& c) const {
	nat clave = this->pFunc->CodigoDeHash(c);
	int lugar = clave;
	lugar = lugar % this->tamano;
	int iterePor = 0;
	while (laTabla[lugar].Dato3 != libre && comparador.Comparar(c, laTabla[lugar].Dato1) == MAYOR || comparador.Comparar(c, laTabla[lugar].Dato1) == MAYOR && iterePor <= largo)
	{
		lugar = lugar++;
		lugar = lugar % this->tamano;
		iterePor++;
	}

	return laTabla[lugar].Dato3 == ocupada;
}

/* SELECTORAS */

//PRE: T(c) está definida
//POS: Retorna 'v', tal que T(c) = v
template <class C, class V>
const V& TablaHashCerrado<C, V>::Obtener(const C& c) const {
	nat clave = this->pFunc->CodigoDeHash(c);
	int lugar = clave;
	lugar = lugar % this->tamano;
	int iterePor = 0;
	while (laTabla[lugar].Dato3 == libre && iterePor <= largo)
	{
		lugar = lugar++;
		lugar = lugar % this->tamano;
		iterePor++;
	}

	return laTabla[lugar].Dato2;
}

//PRE: -
//POS: Retorna el largo de la tabla
template <class C, class V>
nat TablaHashCerrado<C, V>::Largo() const {
	return largo;
}

//PRE: -
//POS: Devuelve un clon de la tabla, no comparten memoria
template <class C, class V>
Puntero<Tabla<C, V>> TablaHashCerrado<C, V>::Clonar() const {
	return nullptr;
}

//PRE: -
//POS: Devuelve el iterador
template <class C, class V>
Iterador<Tupla<C, V>> TablaHashCerrado<C, V>::ObtenerIterador() const {
	int aux = 0;
	Array<Tupla<C, V>> ret = Array <Tupla<C, V>>(this->largo);

	for (int i = 0; i < tamano; i++) {
		if (laTabla[i].Dato3 == ocupada) {
			ret[aux] = Tupla<C, V>(laTabla[i].Dato1, laTabla[i].Dato2);
			aux++;
		}
	}
	return ret.ObtenerIterador();
}


#endif