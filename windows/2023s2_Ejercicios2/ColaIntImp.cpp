#include "ColaInt.h"
#include "Definiciones.h"

#ifdef COLA_INT_IMP

struct _cabezalColaInt {
	NodoListaInt* ppio;
	NodoListaInt* final;
	unsigned int cantidadElementos;
};

ColaInt crearColaInt() {
	ColaInt cola = new _cabezalColaInt;
	cola->ppio = NULL;
	cola->final = NULL;
	cola->cantidadElementos = 0;
	return cola;
}

void encolar(ColaInt& c, int e) {
	NodoListaInt* nuevo = new NodoListaInt;
	nuevo->dato = e;
	nuevo->sig = NULL;
	if (!c->ppio) {
		c->ppio = nuevo;
		c->final = nuevo;
	}
	else {
		c->final->sig = nuevo;
		c->final = nuevo;
	}
	c->cantidadElementos++;

}

int principio(ColaInt c) {
	assert(!esVacia(c));
	return c->ppio->dato;
}

void desencolar(ColaInt& c) {
	assert(!esVacia(c));
	NodoListaInt* aBorrar = c->ppio;
	c->ppio = c->ppio->sig;
	delete aBorrar;
	c->cantidadElementos--;
}

bool esVacia(ColaInt c) {
	return c->cantidadElementos == 0;
}

unsigned int cantidadElementos(ColaInt c) {
	return c->cantidadElementos;
}


ColaInt clon(ColaInt c) {
	ColaInt nuevaCola = crearColaInt();
	NodoListaInt* aux = c->ppio;
	while (aux) {
		encolar(nuevaCola, aux->dato);
		aux = aux->sig;
	}
	return nuevaCola;
}

void destruir(ColaInt& c) {
	while (!esVacia(c)) {
		desencolar(c);
	}
	delete c;
	c = NULL;
}

#endif