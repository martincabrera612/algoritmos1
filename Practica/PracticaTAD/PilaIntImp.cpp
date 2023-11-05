#include "PilaInt.h"
#include <assert.h>

struct NodoListaInt {
	int dato;
	NodoListaInt* sig;
};

struct _cabezalPilaInt {
	NodoListaInt* top;
	unsigned int cantidadElementos;
};
typedef struct _cabezalPilaInt* PilaInt;

PilaInt crearPilaInt() {
	PilaInt pila = new _cabezalPilaInt;
	//NodoListaInt* nodo = new NodoListaInt;
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
	assert(!esVacia(p));
	return p->top->dato;
}

void pop(PilaInt& p) {
	assert(!esVacia(p));
	NodoListaInt* aux = p->top;
	p->top = p->top->sig;
	delete aux;
	p->cantidadElementos--;
}


unsigned int cantidadElementos(PilaInt p) {
	assert(!esVacia(p));
	return p->cantidadElementos;


}

bool esVacia(PilaInt p) {
	return (p == 0);
}

PilaInt clon(PilaInt p) {
	// NO IMPLEMENTADO
	return NULL;
}

void destruir(PilaInt& p) {
	while (!esVaciaPila(p)) {
		pop(p);
	}
	delete p;
}