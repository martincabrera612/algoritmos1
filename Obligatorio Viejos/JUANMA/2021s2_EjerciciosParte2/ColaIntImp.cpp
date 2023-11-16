#include "ColaInt.h"
#include "Definiciones.h"

#ifdef COLA_INT_IMP

struct _cabezalColaInt {
	NodoListaInt* delante;
	NodoListaInt* ultimo;
	int largo;
};

ColaInt crearColaInt() {
	ColaInt cola = new _cabezalColaInt;
	cola->delante = NULL;
	cola->ultimo = NULL;
	cola->largo = 0;
	return cola;
}

void encolar(ColaInt& c, int e) {
	NodoListaInt* nuevo = new NodoListaInt;
	nuevo->dato = e;
	nuevo->sig = NULL;
	if (c == NULL) {
		c = crearColaInt();
	}
	if (c->delante == NULL) {
		c->delante = nuevo;
		c->ultimo = nuevo;
	}
	else {
		c->ultimo->sig = nuevo;
		c->ultimo = c->ultimo->sig;
	}
	c->largo++;
}

int principio(ColaInt c) {
	assert(!esVacia(c));
	return c->delante->dato;
}

void desencolar(ColaInt& c) {
	assert(!esVacia(c));
	NodoListaInt* aux = c->delante;
	c->delante = c->delante->sig;
	delete aux;
	c->largo--;
}

bool esVacia(ColaInt c) {
	if (c == NULL) {
		return true;
	}
	else {
		return c->largo == 0;
	}
}

unsigned int cantidadElementos(ColaInt c) {
	return c->largo;
}

ColaInt clon(ColaInt c) {
	ColaInt nueva = crearColaInt();
	if (c != NULL) {
		NodoListaInt* aux = c->delante;
		while (aux != NULL) {
			encolar(nueva, aux->dato);
			aux = aux->sig;
		}
	}
	return nueva;
}

void destruir(ColaInt& c) {
	for (int i = 0; i < c->largo; i++) {
		desencolar(c);
	}
	delete c;
	c = NULL;
}

#endif