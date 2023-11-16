#include "PilaInt.h"
#include "Definiciones.h"

#ifdef PILA_INT_IMP

struct _cabezalPilaInt {
	NodoListaInt* ppio;
	int largo;
};
                       
PilaInt crearPilaInt(){
	PilaInt p = new _cabezalPilaInt;
	p->largo = 0;
	p->ppio = NULL;
	return p;
}

void push(PilaInt& p, int e) {
	if (p == NULL) {
		p = crearPilaInt();
	}
	NodoListaInt* nuevo = new NodoListaInt;
	nuevo->dato = e;
	nuevo->sig = p->ppio;
	p->ppio = nuevo;
	p->largo++;
}

int top(PilaInt p) {
	assert(!esVacia(p));
	return p->ppio->dato;
}

void pop(PilaInt& p) {
	assert(!esVacia(p));
	NodoListaInt* aux = p->ppio;
	p->ppio = p->ppio->sig;
	delete aux;
	p->largo--;
}

unsigned int cantidadElementos(PilaInt p) {
	return p->largo;
}

bool esVacia(PilaInt p) {
	if (p == NULL) {
		return true;
	}
	return p->largo == 0;
}

PilaInt clon(PilaInt p) {
	PilaInt q = crearPilaInt();
	if (p != NULL) {
		NodoListaInt* iter = p->ppio;
		PilaInt aux = crearPilaInt();
		while (iter != NULL) {
			push(aux, iter->dato);
			iter = iter->sig;
		}

		iter = aux->ppio;
		while (iter != NULL) {
			push(q, iter->dato);
			iter = iter->sig;
		}
		destruir(aux);
	}
	return q;
}

void destruir(PilaInt& p) {
	for (int i = 0; i < p->largo; i++) {
		pop(p);
	}
	delete p;
	p = NULL;
}


#endif