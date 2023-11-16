#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

struct _cabezalListaPosInt {
	int* array;
	unsigned int capacidad;
	unsigned int cantidadElementos;
};


//--------------- Funciones-Auxiliares -------------------
//PRE:- 
//POS: Devuelve una nueva lista con los mismos elementos que la lista original pero con el doble de capacidad.
void agrandarArray(ListaPosInt l) {
	int* nuevoArr = new int[l->capacidad * 2];
	l->capacidad = l->capacidad * 2;
	for (int i = 0; i < l->cantidadElementos; i++)
	{
		nuevoArr[i] = l->array[i];
	}
	int* aBorrar = l->array;
	l->array = nuevoArr;
	delete aBorrar;
}

//---------------------------------------------------

ListaPosInt crearListaPosInt()
{
	ListaPosInt lista = new _cabezalListaPosInt;
	lista->capacidad = 50;
	lista->array = new int[lista->capacidad];
	lista->cantidadElementos = 0;
	return lista;
}

void agregar(ListaPosInt& l, int e, unsigned int pos)
{
	if (l == NULL) {
		l = crearListaPosInt();
	}
	if (l->cantidadElementos == l->capacidad) {
		agrandarArray(l);
	}
	if (pos <= l->cantidadElementos) {
		if (pos != 0) {
			for (int i = l->cantidadElementos; i >= pos; i--)
			{
				l->array[i + 1] = l->array[i];
			}
		}
		l->array[pos] = e;
		l->cantidadElementos++;
	}
	else if (pos > l->cantidadElementos){
		l->array[l->cantidadElementos] = e;
		l->cantidadElementos++;
	}
}

void borrar(ListaPosInt& l, unsigned int pos)
{
	if (pos < l->cantidadElementos) {
		for (int i = pos+1; i < l->cantidadElementos; i++) {
			l->array[i - 1] = l->array[i];
		}
		l->cantidadElementos--;
	}
}

int elemento(ListaPosInt l, unsigned int pos)
{
	assert(0 <= pos <= l->cantidadElementos);
	return l->array[pos];
}

bool esVacia(ListaPosInt l)
{
	return l->cantidadElementos == 0;
}

unsigned int cantidadElementos(ListaPosInt l)
{
	return l->cantidadElementos;
}

ListaPosInt clon(ListaPosInt l)
{
	ListaPosInt nueva = crearListaPosInt();
		//nueva->capacidad = l->capacidad
		for (int i = 0; i < l->cantidadElementos; i++)
		{
			agregar(nueva, l->array[i], i);
			//nueva->array[i] = l->array[i];
			//nueva->cantidadElementos++;
		}
	return nueva;
}

void destruir(ListaPosInt& l)
{
	for (int i = 0; i < l->cantidadElementos; i++)
	{
		borrar(l, i);
	}
	delete l;
	l = NULL;
}


#endif