#include "ColaInt.h"

#ifdef COLA_INT_IMP

struct _cabezalColaInt {
	NodoListaInt* ppio;
	unsigned int cant;
};

ColaInt crearColaInt() {
	ColaInt retorno = new _cabezalColaInt;
	retorno->ppio = NULL;
	retorno->cant = 0;
	return retorno;
}

void encolar(ColaInt& c, int e) {
	//NodoListaInt* nuevo = new NodoListaInt;
	//nuevo->dato = e;
	//nuevo->sig = NULL;

	//if (!c->ppio) {
	//	c->ppio = nuevo;
	//}
	//else {
	//	NodoListaInt* aux = c->ppio;
	//	while (aux->sig) {
	//		aux = aux->sig;
	//	}
	//	aux->sig = nuevo;
	//}
	//c->cant++;
}

int principio(ColaInt c) {
	//assert de puede ser null
	//assert(!c->ppio);
	//return c->ppio->dato;
	return 0;
}

void desencolar(ColaInt& c) {
	// NO IMPLEMENTADO
}

bool esVacia(ColaInt c) {
	return true;
}

unsigned int cantidadElementos(ColaInt c) {
	//return c->cant;
	return 0;
}

ColaInt clon(ColaInt c) {
	// NO IMPLEMENTADO
	return NULL;
}

void destruir(ColaInt& c) {
	// NO IMPLEMENTADO
}

#endif