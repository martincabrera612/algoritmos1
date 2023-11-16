#include "ColaPrioridadInt.h"
#include "Definiciones.h"

#ifdef COLAPRIORIDAD_INT_IMP

struct _cabezalColaPrioridadInt {
	NodoListaIntDobleDato* cola;
	int cantElem;
	int largo;
};

void auxEncolar(NodoListaIntDobleDato*& l, int e, int p) {
	if (l == NULL) {
		l = new NodoListaIntDobleDato(e, p);
	}
	else {
		if (l->dato2 >= p) {
			if (l->sig != NULL) {
				if (l->sig->dato2 < p) {
					NodoListaIntDobleDato* nodo = new NodoListaIntDobleDato(e, p);
					nodo->sig = l->sig;
					l->sig = nodo;
				}
				else {
					auxEncolar(l->sig, e, p);
				}
			}
			else {
				auxEncolar(l->sig, e, p);
			}
		}
		else {
			NodoListaIntDobleDato* nodo = new NodoListaIntDobleDato(e, p);
			nodo->sig = l;
			l = nodo;
		}
	}
}

void cAuxClon(NodoListaIntDobleDato*& nuevacola, NodoListaIntDobleDato* l) {
	auxEncolar(nuevacola, l->dato1, l->dato2);
	if (l->sig != NULL) {
		cAuxClon(nuevacola->sig, l->sig);
	}
	else {
		nuevacola->sig = NULL;
	}
}

ColaPrioridadInt crearColaPrioridadInt(unsigned int cota) {
	ColaPrioridadInt cola = new _cabezalColaPrioridadInt;
	cola->cola = NULL;
	cola->cantElem = 0;
	cola->largo = cota;
	return cola;
}

void encolar(ColaPrioridadInt& c, int e, int p) {
	if (!esLlena(c)) {
		auxEncolar(c->cola, e, p);
		c->cantElem++;
	}
}

int principio(ColaPrioridadInt c) {
	assert(!esVacia(c));
	return c->cola->dato1;
}

int principioPrioridad(ColaPrioridadInt c) {
	assert(!esVacia(c));
	return c->cola->dato2;
}

void desencolar(ColaPrioridadInt& c) {
	assert(!esVacia(c));
	NodoListaIntDobleDato* borrar = c->cola;
	c->cola = c->cola->sig;
	borrar = NULL;
	delete borrar;
	c->cantElem--;
}

bool esVacia(ColaPrioridadInt c) {
	return c->cola == NULL;
}

bool esLlena(ColaPrioridadInt c) {
	return c->cantElem == c->largo;
}

unsigned int cantidadElementos(ColaPrioridadInt c) {
	return c->cantElem;
}

ColaPrioridadInt clon(ColaPrioridadInt c) {
	ColaPrioridadInt nuevacola = crearColaPrioridadInt(c->largo);
	if (c->cola == NULL) {
		return nuevacola;
	}
	else {
		cAuxClon(nuevacola->cola, c->cola);
		nuevacola->cantElem = c->cantElem;
		return nuevacola;
	}
}

void destruir(ColaPrioridadInt& c) {
	int cant = c->cantElem;
	for (int i = 0; i < cant; i++) {
		desencolar(c);
	}
	c = NULL;
	delete c;
}

#endif