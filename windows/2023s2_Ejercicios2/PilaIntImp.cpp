#include "PilaInt.h"
#include "Definiciones.h"

#ifdef PILA_INT_IMP

struct _cabezalPilaInt {
	NodoListaInt* top;
	unsigned int cantidadElementos;
};

PilaInt crearPilaInt() {
	PilaInt pila = new _cabezalPilaInt;
	pila->top = NULL;
	pila->cantidadElementos = 0;
	return pila;
}

void push(PilaInt& p, int e) {
	NodoListaInt* nuevo = new NodoListaInt;
	nuevo->dato = e;
	nuevo->sig = p->top;
	p->top = nuevo;
	p->cantidadElementos++;
}

int top(PilaInt p) {
	if (!esVacia(p)) {
		assert(!esVacia(p));
		return p->top->dato;
	}
}

void pop(PilaInt& p) {
	assert(!esVacia(p));
	NodoListaInt* aux = p->top;
	p->top = p->top->sig;
	delete aux;
	p->cantidadElementos--;
}


unsigned int cantidadElementos(PilaInt p) {
	return p->cantidadElementos;
}

bool esVacia(PilaInt p) {
	return (p->cantidadElementos == 0);
}


PilaInt clon(PilaInt p) {
	PilaInt copia = crearPilaInt();
	NodoListaInt* aux = p->top;
	// invertir
	while (aux) {
		push(copia, aux->dato);
		aux = aux->sig;
	}
	PilaInt clon = crearPilaInt();
	while (!esVacia(copia)) {
		push(clon, top(copia));
		pop(copia);
	}
	return clon;
}

void destruir(PilaInt& p) {
	while (!esVacia(p)) {
		pop(p);
	}
	delete p;
}


#endif