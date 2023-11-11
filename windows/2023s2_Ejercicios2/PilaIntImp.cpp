#include "PilaInt.h"

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


////////////////////////////////////////////
void insertarPrincipioLista(NodoListaInt*& l, int dato) {
	NodoListaInt* nodo = new NodoListaInt;
	nodo->dato = dato;
	nodo->sig = l;
	l = nodo;
}

//////////////////////////////////////////

PilaInt clon(PilaInt p) {
	PilaInt copia = crearPilaInt();
	NodoListaInt* lista = NULL;
	while (!esVacia(p)) {
		//push(copia, top(p));
		insertarPrincipioLista(lista, top(p));
		/*int elem = top(p);
		nuevo->dato = elem;
		nuevo->sig = copia->top;
		copia->top = nuevo;
		copia->cantidadElementos++;*/
		pop(p);
	}
	while (lista != NULL) {
		push(copia, lista->dato);
		lista = lista->sig;
	}
	return copia;
}

void destruir(PilaInt& p) {
	while (!esVacia(p)) {
		pop(p);
	}
	delete p;
}


#endif