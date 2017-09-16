#ifndef SISTEMA_CPP
#define SISTEMA_CPP

#include "Sistema.h"
#include <fstream>
#include <string>
#include <algorithm>

//PRE:  - 
//POS: Hace el merge 
template <class T>
void merge(Array<T>& elementos, int l, int m, int r, const Comparador<T>& comp)
{
	int i, j, k;
	int numeroUno = m - l + 1;
	int numeroDos = r - m;

	Array<T> L(numeroUno);
	Array<T> R(numeroDos);

	for (i = 0; i < numeroUno; i++)
		L[i] = elementos[l + i];
	for (j = 0; j < numeroDos; j++)
		R[j] = elementos[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < numeroUno && j < numeroDos)
	{
		if (comp.Comparar(L[i], R[j]) == MENOR || comp.Comparar(L[i], R[j]) == IGUALES)
		{
			elementos[k] = L[i];
			i++;
		}
		else
		{
			elementos[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < numeroUno)
	{
		elementos[k] = L[i];
		i++;
		k++;
	}

	while (j < numeroDos)
	{
		elementos[k] = R[j];
		j++;
		k++;
	}
}


//PRE:  - 
//POS: Hace el merge 
template <class T>
void mergeSortAux(Array<T>& elementos, int l, int r, const Comparador<T>& comp)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSortAux(elementos, l, m, comp);
		mergeSortAux(elementos, m + 1, r, comp);
		merge(elementos, l, m, r, comp);
	}
}

bool esValida(Cadena str) {
	int largoCadena = str.Largo;
	for (int i = 0; i < largoCadena; i++) {
		int valor = (int)str[i];
		if (!(valor > 96 && valor < 123)) {
			return false;
		}
	}
	return true;
}

Sistema::Sistema(const Cadena& nombreArchivoDiccionario)
{
	Puntero<FuncionHashAnagrama> fH = new FuncionHashAnagrama();
	Puntero<Tabla<Cadena, Cadena>> tabla = new TablaHashAbierto<Cadena, Cadena>(0, fH, Comparador<Cadena>::Default);
	hashAbierto = tabla;
	string nombreArchivo = "";
	int largoNombre = nombreArchivoDiccionario.Largo;
	for (int i = 0; i < largoNombre; i++) {
		nombreArchivo += nombreArchivoDiccionario[i];
	}

	string line;

	ifstream miarchivo(nombreArchivo);
	int l = 0;
	if (miarchivo.is_open()) {
		while (getline(miarchivo, line)) {
			std::transform(line.begin(), line.end(), line.begin(), ::tolower);
			Cadena clave(line.c_str());
			Cadena valor(line.c_str());
			if (esValida(clave)) {
				int largo = clave.Largo;
				Array<char> arrChar(largo);
				for (int j = 0; j < largo; j++) {
					arrChar[j] = clave[j];
				}
				mergeSortAux<char>(arrChar, 0, largo-1, Comparador<char>::Default);
				string stringOrdenada("");
				for (int k = 0; k < largo; k++) {
					stringOrdenada +=arrChar[k];
				}
				Cadena claveOrdenada(stringOrdenada.c_str());
				l = l + 1;
				hashAbierto->Agregar(claveOrdenada, valor);
			}
		}
		miarchivo.close();
		// Inicialización de estructuras necesrias para resolver el problema.
	}
}
Sistema::~Sistema()
{
}

// Ejercicio 1: Anagramas
Array<Cadena> Sistema::Anagramas(const Cadena& c)
{
	int largo = c.Largo;
	Array<char> arrChar(largo);
	string stringNoOrdenada("");
	for (int k = 0; k < largo; k++) {
		stringNoOrdenada += c[k];
	}
	std::transform(stringNoOrdenada.begin(), stringNoOrdenada.end(), stringNoOrdenada.begin(), ::tolower);
	Cadena claveMinuscula(stringNoOrdenada.c_str());
	for (int j = 0; j < largo; j++) {
		arrChar[j] = claveMinuscula[j];
	}
	mergeSortAux<char>(arrChar, 0, largo - 1, Comparador<char>::Default);
	string stringOrdenada("");
	for (int k = 0; k < largo; k++) {
		stringOrdenada += arrChar[k];
	}
	Cadena claveOrdenada(stringOrdenada.c_str());
	Comparador<Cadena> comp ;
	Puntero<ListaOrdImp<Tupla<Cadena,Cadena>>> punt = hashAbierto->devuelvoLista(claveOrdenada);
	Puntero<ListaOrdImp<Tupla<Cadena, Cadena>>> aux = punt;
	int contador = 0;
	int agarrarElemento = 0;
	int largoLista = aux->Largo();
	while (agarrarElemento<largoLista) {
		if (comp.Comparar(aux->Obtener(agarrarElemento).Dato1, claveOrdenada) == IGUALES) {
			contador++;
		}
		agarrarElemento++;
	}
	agarrarElemento = 0;
	Array<Cadena> retorno(contador);
	bool encontre = false;
	for (int i = 0; i < contador; i++) {
		while (!encontre) {
			if (comp.Comparar(aux->Obtener(agarrarElemento).Dato1, claveOrdenada) == IGUALES) {
				encontre = true;
				retorno[i] = aux->Obtener(agarrarElemento).Dato2;
			}
			agarrarElemento++;
		}
		encontre = false;
	}
	punt = nullptr;
	aux = nullptr;
	return retorno;
}
#endif