#include "ListaOrdInt.h"
#include "Definiciones.h"
#ifdef LISTA_ORD_INT_IMP_2

struct _cabezalListaOrdInt {
	NodoABIntDobleDato* r;
	int cantidadElementos;
};

ListaOrdInt crearListaOrdInt() {
	ListaOrdInt lista = new _cabezalListaOrdInt;
	lista->r = NULL;
	lista->cantidadElementos = 0;
	return lista;
}

void agregar(ListaOrdInt& l, int e) {
	// NO IMPLEMENTADO
}

void borrarMinimo(ListaOrdInt& l) {
	// NO IMPLEMENTADO
}

void borrarMaximo(ListaOrdInt& l) {
	// NO IMPLEMENTADO
}

void borrar(ListaOrdInt& l, int e) {
	// NO IMPLEMENTADO
}

int minimo(ListaOrdInt l) {
	assert(!esVacia(l));
	while (l->r->izq) {
		l->r = l->r->izq;
	}
	return l->r->dato1;
}

int maximo(ListaOrdInt l) {
	assert(!esVacia(l));
	while (l->r->der) {
		l->r = l->r->der;
	}
	return l->r->dato1;
}

bool existe(ListaOrdInt l, int e) {
	// NO IMPLEMENTADO
	return false;
}

bool esVacia(ListaOrdInt l) {
	if (l) {
		return l->cantidadElementos == 0;
	}
}

unsigned int cantidadElementos(ListaOrdInt l) {
	return l->cantidadElementos;
}

ListaOrdInt clon(ListaOrdInt l) {
	// NO IMPLEMENTADO
	return NULL;
}

void destruir(ListaOrdInt& l) {
	// NO IMPLEMENTADO
}



#endif