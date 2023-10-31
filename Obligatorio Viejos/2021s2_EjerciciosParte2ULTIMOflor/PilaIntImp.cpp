#include "PilaInt.h"

#ifdef PILA_INT_IMP

struct _cabezalPilaInt {
	// NO IMPLEMENTADO
	NodoListaInt* cima;
	unsigned int cantElementos;
};


PilaInt crearPilaInt() {
	// NO IMPLEMENTADO
	PilaInt nueva = new _cabezalPilaInt;
	nueva->cima = NULL;
	nueva->cantElementos = 0;
	return nueva;
}

void push(PilaInt& p, int e) {
	// NO IMPLEMENTADO
	NodoListaInt* nuevoNodo = new NodoListaInt(e);
	nuevoNodo->sig = p->cima;
	p->cima = nuevoNodo;
	p->cantElementos = 1 + p->cantElementos;
}

int top(PilaInt p) {
	// NO IMPLEMENTADO
	return p->cima->dato;
}

void pop(PilaInt& p) {
	// NO IMPLEMENTADO
	if (p->cantElementos != 0) {
		NodoListaInt* aux = p->cima;
		p->cima = p->cima->sig;
		delete aux;
		p->cantElementos = p->cantElementos - 1;
	}
}

unsigned int cantidadElementos(PilaInt p) {
	// NO IMPLEMENTADO
	return p->cantElementos;
}

bool esVacia(PilaInt p) {
	// NO IMPLEMENTADO
	if (p->cantElementos == 0) {
		return true;
	}
	return false;
}

NodoListaInt* auxCopiarLista(NodoListaInt* l) {
	NodoListaInt* ret = NULL;
	if (l != NULL) {
		ret = new NodoListaInt;
		ret->dato = l->dato;
		ret->sig = auxCopiarLista(l->sig);
	}
	return ret;
}

PilaInt clon(PilaInt p) {
	// NO IMPLEMENTADO
	NodoListaInt* puntero = p->cima;
	PilaInt clonPila = crearPilaInt();
	clonPila->cima = auxCopiarLista(puntero);
	clonPila->cantElementos = p->cantElementos;
	return clonPila;
}

void destruir(PilaInt& p) {
	// NO IMPLEMENTADO
	while (p->cantElementos > 0) {
		pop(p);
	}
}



#endif