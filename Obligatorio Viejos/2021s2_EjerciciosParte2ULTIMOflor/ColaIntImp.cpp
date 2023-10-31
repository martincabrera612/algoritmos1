#include "ColaInt.h"

#ifdef COLA_INT_IMP

struct _cabezalColaInt {
	NodoListaInt* ppio;
	NodoListaInt* final;
	unsigned int cantElementos;
};

ColaInt crearColaInt() {
	// NO IMPLEMENTADO
	ColaInt nuevaCola = new _cabezalColaInt;
	nuevaCola->ppio = NULL;
	nuevaCola->final = NULL;
	nuevaCola->cantElementos = 0;
	return nuevaCola;
}

void encolar(ColaInt& c, int e) {
	// NO IMPLEMENTADO
	NodoListaInt* aux = new NodoListaInt;
	aux->dato = e;
	aux->sig = NULL;
	if (c->ppio == NULL) {
		c->ppio = aux;
		c->final = aux;

	}
	else {
		c->final->sig = aux;
		c->final = c->final->sig;
	}
	c->cantElementos = c->cantElementos + 1;
}

int principio(ColaInt c) {
	// NO IMPLEMENTADO
	return c->ppio->dato;
}

void desencolar(ColaInt& c) {
	// NO IMPLEMENTADO
	NodoListaInt* aux = c->ppio;
	c->ppio = c->ppio->sig;
	//if (c->ppio == NULL) {
		//c->final = NULL;
	//}
	delete aux;
	c->cantElementos = c->cantElementos - 1;
}

bool esVacia(ColaInt c) {
	// NO IMPLEMENTADO
	if (c->cantElementos == 0) {
		return true;
	}
	return false;
}

unsigned int cantidadElementos(ColaInt c) {
	// NO IMPLEMENTADO
	return c->cantElementos;
}

ColaInt clon(ColaInt c) {
	// NO IMPLEMENTADO

	ColaInt colaNueva = crearColaInt();
	NodoListaInt* listaAux = c->ppio;

	for (int i = 0; i < c->cantElementos; i++)
	{
		int datoInsert = listaAux->dato;
		encolar(colaNueva, datoInsert);
		listaAux = listaAux->sig;
	}
	return colaNueva;
}

void destruir(ColaInt& c) {
	// NO IMPLEMENTADO
	while (!esVacia(c)) {
		desencolar(c);
	}
	delete c;
}

#endif