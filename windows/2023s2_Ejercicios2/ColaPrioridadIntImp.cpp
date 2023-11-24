#include "ColaPrioridadInt.h"

#ifdef COLAPRIORIDAD_INT_IMP

struct _cabezalColaPrioridadInt {
	NodoListaIntDobleDato* cola;
	int cantidadElementos;
	int cota;
};

//------ Funciones Auxiliares-------------------------

//PRE:
//POS:

void encolarAux(NodoListaIntDobleDato*& l, int e, int p) {
	if (l) {
		if (l->dato2 >= p) {
			if (l->sig) {
				if (l->sig->dato2 < p) {
					NodoListaIntDobleDato* nodo = new NodoListaIntDobleDato;
					nodo->dato1 = e;
					nodo->dato2 = p;
					nodo->sig = l->sig;
					l->sig = nodo;
				}
				else {
					encolarAux(l->sig, e, p);
				}
			}
			else {
				encolarAux(l->sig, e, p);
			}
		}
		else {
			NodoListaIntDobleDato* nodo = new NodoListaIntDobleDato;
			nodo->dato1 = e;
			nodo->dato2 = p;
			nodo->sig = l;
			l = nodo;
		}
	}
	else {
		l = new NodoListaIntDobleDato;
		l->dato1 = e;
		l->dato2 = p;
	}
}


//PRE:
//POS:
void clonAux(NodoListaIntDobleDato*& nueva, NodoListaIntDobleDato* l) {
	encolarAux(nueva, l->dato1, l->dato2);
	if (l->sig) {
		clonAux(nueva->sig, l->sig);
	}
	else {
		nueva->sig = NULL;
	}
}


ColaPrioridadInt crearColaPrioridadInt(unsigned int cota) {
	ColaPrioridadInt cola = new _cabezalColaPrioridadInt;
	cola->cola = NULL;
	cola->cantidadElementos = 0;
	cola->cota = cota;
	return cola;
}

void encolar(ColaPrioridadInt& c, int e, int p) {
	if (!esLlena(c)) {
		encolarAux(c->cola, e, p);
		c->cantidadElementos++;
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
	NodoListaIntDobleDato* aBorrar = c->cola;
	c->cola = c->cola->sig;
	aBorrar = NULL;
	delete aBorrar;
	c->cantidadElementos--;

}

bool esVacia(ColaPrioridadInt c) {
	return c->cola == NULL;
}

bool esLlena(ColaPrioridadInt c) {

	return c->cantidadElementos == c->cota;
}

unsigned int cantidadElementos(ColaPrioridadInt c) {
	return c->cantidadElementos;
}

ColaPrioridadInt clon(ColaPrioridadInt c) {
	ColaPrioridadInt nueva = crearColaPrioridadInt(c->cota);
	if (c->cola) {
		clonAux(nueva->cola, c->cola);
		nueva->cantidadElementos = c->cantidadElementos;
	}
	return nueva;
}

void destruir(ColaPrioridadInt& c) {
	while (c->cantidadElementos != 0) {
		desencolar(c);
	}
	c = NULL;
	delete c;
}

#endif