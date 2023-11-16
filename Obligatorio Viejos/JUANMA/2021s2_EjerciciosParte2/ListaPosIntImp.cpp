1996#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

struct _cabezalListaPosInt {
	int* vector;
	int cantElem;
	int largoVec;
};

ListaPosInt crearListaPosInt()
{
	ListaPosInt lp = new _cabezalListaPosInt;
	lp->cantElem = 0;
	lp->largoVec = 10;
	lp->vector = new int[lp->largoVec];
	return lp;
}

void agregar(ListaPosInt& l, int e, unsigned int pos)
{
	if (l == NULL) {
		l = crearListaPosInt();
	}
	if (l->largoVec == l->cantElem) {
		int nuevolargo = l->largoVec * 2;
		int* nuevovec = new int[nuevolargo];
		for (int i = 0; i < l->cantElem; i++) {
			nuevovec[i] = l->vector[i];
		}
		int* aux = l->vector;
		l->vector = nuevovec;
		delete aux;
		l->largoVec = nuevolargo;
	}

	if (pos > l->cantElem) {
		pos = l->cantElem;
	}
	else if (pos < l->cantElem) {
		for (int i = l->cantElem; i >= pos; i--) {

			l->vector[i + 1] = l->vector[i];
		}
	}
	l->vector[pos] = e;
	l->cantElem++;
}

void borrar(ListaPosInt& l, unsigned int pos)
{
	if (pos < l->cantElem) {
		for (int i = 0; i < l->cantElem; i++) {
			if (i > pos) {
				l->vector[i - 1] = l->vector[i];
			}
		}
		l->vector[l->cantElem - 1] = NULL;
		l->cantElem--;
	}
}

int elemento(ListaPosInt l, unsigned int pos)
{
	return l->vector[pos];
}

bool esVacia(ListaPosInt l)
{
	if (l == NULL) {
		return true;
	}
	else {
		return l->cantElem == 0;
	}
}

unsigned int cantidadElementos(ListaPosInt l)
{
	return l->cantElem;
}

ListaPosInt clon(ListaPosInt l)
{
	ListaPosInt nueval = crearListaPosInt();
	if (l != NULL) {
		for (int i = 0; i < l->cantElem; i++) {
			agregar(nueval, l->vector[i], i);
		}

	}
	return nueval;
}

void destruir(ListaPosInt& l)
{
	for (int i = 0; i < l->cantElem; i++) {
		borrar(l, i);
	}
	delete l;
	l = NULL;
}


#endif