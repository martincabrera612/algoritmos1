#include "Lista.h"
#include "Listas.h"
#include <cassert>

//IMPLEMENTACION CONCRETA!!!
//ACA SI SE PUEDE PEDIR ORDENES!!!
struct _cabezalLista {
	NodoLista* ppio;
	int cant;
};

Lista crearLista()
{
	Lista nueva = new _cabezalLista;
	nueva->ppio = NULL;
	nueva->cant = 0;

	return nueva;
}

void insertarPrincipio(Lista& l, int dato)
{
	assert(l != NULL);
	insertarAlPrincipio(l->ppio, dato);
	l->cant++;
}

void insertarFin(Lista& l, int dato)
{
	assert(l != NULL);
	insertarFinalRecursiva(l->ppio, dato);
	l->cant++;
}

void borrarPrincipio(Lista& l)
{
	assert(l != NULL);
	borrarPrincipio(l->ppio);
	l->cant--;
}

void borrarFin(Lista& l)
{
	assert(l != NULL);
	borrarFinIterativo(l->ppio);
	l->cant--;
}

int cantidadDeElementos(Lista l)
{
	assert(l != NULL);
	return l->cant;
}

int obtenerPrincipio(Lista l)
{
	assert(l != NULL && l->cant > 0);
	return l->ppio->dato;
}

int obtenerFin(Lista l)
{
	assert(l != NULL && l->cant > 0);
	NodoLista* aux = l->ppio;
	while (aux->sig) {
		aux = aux->sig;
	}
	return aux->dato;
}

Lista clon(Lista l)
{
	Lista clon = crearLista();
	NodoLista* aux = l->ppio;
	while (aux) {
		insertarFin(clon, aux->dato);
		aux = aux->sig;
	}

	return clon;
}

void destruir(Lista& l)
{
	while (cantidadDeElementos(l) != 0) {
		borrarFin(l);
	}

	delete l;
	l = NULL;
}
