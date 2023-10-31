#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

struct _cabezalListaPosInt {
	//IMPLEMENTAR SOLUCION
	int* vector;
	unsigned int cantElementos;
};

ListaPosInt crearListaPosInt()
{
	//IMPLEMENTAR SOLUCION
	ListaPosInt nuevaLista = new _cabezalListaPosInt;
	nuevaLista->cantElementos = 0;
	nuevaLista->vector = new int[0];
	return nuevaLista;
}

void agregar(ListaPosInt& l, int e, unsigned int pos)
{
	//IMPLEMENTAR SOLUCION
	l->cantElementos = l->cantElementos + 1;
	int largo = l->cantElementos;
	int* nuevo = new int[largo];

	if (pos > l->cantElementos - 1) {
		for (int i = 0; i < l->cantElementos; i++)
		{
			nuevo[i] = l->vector[i];
		}
		nuevo[largo - 1] = e;
		int* aux = l->vector;
		l->vector = nuevo;
		delete aux;
	}
	else {
		for (int i = 0; i < l->cantElementos; i++)
		{
			if (i < pos) {
				nuevo[i] = l->vector[i];
			}
			else if (i == pos) {
				nuevo[i] = e;
			}
			else {
				nuevo[i] = l->vector[i - 1];
			}
		}
		int* aux = l->vector;
		l->vector = nuevo;
		delete aux;
	}



}

void borrar(ListaPosInt& l, unsigned int pos)
{
	//IMPLEMENTAR SOLUCION
	if (pos < l->cantElementos && pos >= 0) {
		int largo = l->cantElementos - 1;
		int* nuevo = new int[largo];

		for (int i = 0; i < l->cantElementos; i++)
		{
			if (i < pos) {
				nuevo[i] = l->vector[i];
			}
			else if (i > pos) {
				nuevo[i - 1] = l->vector[i];
			}
		}
		int* aux = l->vector;
		l->vector = nuevo;
		l->cantElementos = l->cantElementos - 1;
		delete aux;
	}
}

int elemento(ListaPosInt l, unsigned int pos)
{
	//IMPLEMENTAR SOLUCION
	return l->vector[pos];
}

bool esVacia(ListaPosInt l)
{
	//IMPLEMENTAR SOLUCION
	if (l->cantElementos == 0) {
		return true;
	}
	return false;
}

unsigned int cantidadElementos(ListaPosInt l)
{
	//IMPLEMENTAR SOLUCION
	return l->cantElementos;
}

ListaPosInt clon(ListaPosInt l)
{
	//IMPLEMENTAR SOLUCION
	ListaPosInt nuevo = crearListaPosInt();

	for (int i = 0; i < l->cantElementos; i++)
	{
		agregar(nuevo, l->vector[i], i);
	}
	return nuevo;
}

void destruir(ListaPosInt& l)
{
	//IMPLEMENTAR SOLUCION
	int* aux = l->vector;
	l->cantElementos = 0;
	l->vector = new int[0];
	delete aux;
}


#endif