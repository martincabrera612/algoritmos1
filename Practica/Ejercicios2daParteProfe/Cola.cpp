#include "Cola.h";
#include "Listas.h";
#include <cassert>

struct _cabezalCola {
	NodoLista* ppio;
};

//PRE Y POS (HWK :D )
Cola crearCola() {
	Cola nueva = new _cabezalCola;
	nueva->ppio = NULL;

	return nueva;
}

void insertarAlFinalRec(NodoLista*& nuevo, int dato) {
	if (!nuevo)
	{
		nuevo = new NodoLista(dato);
	}
	else {
		insertarAlFinalRec(nuevo->sig, dato);
	}
}

void encolar(Cola& c, int dato) {
	insertarAlFinalRec(c->ppio, dato);
}

void desencolar(Cola& c) {
	assert(!esVacia(c));
	NodoLista* borro = c->ppio;
	c->ppio = c->ppio->sig;
	delete borro;
}

int principio(Cola c) {
	assert(!esVacia(c));
	return c->ppio->dato;
}

bool esVacia(Cola c) {
	return c->ppio == NULL;
}

int cantidadDeElementos(Cola c) {
	NodoLista* aux = c->ppio;
	int cant = 0;
	while (aux) { // aux != NULL
		aux = aux->sig;
		cant++;
	}
	return cant;
}

Cola clon(Cola c) {
	Cola nueva = crearCola();
	NodoLista* aux = c->ppio;
	while (aux) { // aux != NULL
		encolar(nueva, aux->dato);
		aux = aux->sig;
	}
	return nueva;
}

void destruir(Cola& c) {
	while (!esVacia(c)) {
		desencolar(c);
	}
	delete c;
	c = NULL;
}