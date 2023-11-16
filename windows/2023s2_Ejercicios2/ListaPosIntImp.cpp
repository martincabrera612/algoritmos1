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
ListaPosInt agrandarArray(ListaPosInt l) {
	ListaPosInt nueva = crearListaPosInt();
	int* nuevoArr = new int[l->capacidad * 2];
	nueva->capacidad = (l->capacidad * 2);
	nueva->array = nuevoArr;
	for (int i = 0; i < l->cantidadElementos; i++)
	{
		nueva->array[i] = l->array[i];
		nueva->cantidadElementos++;
	}
	return nueva;
}

//PRE:
//POS:
void hacerEspacio(ListaPosInt& l, unsigned int pos) {
	for (int i = l->cantidadElementos; i > pos; i--)
	{
		l->array[i] = l->array[i - 1];
	}
}

//PRE:
//POS:
void reducirEspacio(ListaPosInt& l, unsigned int pos) {
	for (int i = pos; i < l->cantidadElementos; i++)
	{
		l->array[i] = l->array[i + 1];
	}
}


//---------------------------------------------------

ListaPosInt crearListaPosInt()
{
	ListaPosInt lista = new _cabezalListaPosInt;
	lista->capacidad = 50;
	lista->array = new int[50];
	lista->array = NULL;
	lista->cantidadElementos = 0;
	return lista;
}

void agregar(ListaPosInt& l, int e, unsigned int pos)
{
	if (pos < l->capacidad) {
		if (l->cantidadElementos == 0) {
			l->array[pos] = e;
			l->cantidadElementos++;
		}
		else if (l->cantidadElementos < l->capacidad) {
			hacerEspacio(l, pos);
			/*for (int i = l->cantidadElementos; i > pos; i--)
			{
				l->array[i] = l->array[i - 1];
			}*/
			l->array[pos] = e;
			l->cantidadElementos++;
		}
	}
	else if (l->capacidad == pos) {
		l->array[l->capacidad] = e;
		l->cantidadElementos++;
	}
	else {
		ListaPosInt aBorrar = l;
		l = agrandarArray(l);
		delete aBorrar;
		agregar(l, e, pos);
	}
}

void borrar(ListaPosInt& l, unsigned int pos)
{
	//IMPLEMENTAR SOLUCION
}

int elemento(ListaPosInt l, unsigned int pos)
{
	assert(0 <= pos <= l->cantidadElementos);
	return l->array[pos];
}

bool esVacia(ListaPosInt l)
{
	if (l) {
		return l->cantidadElementos == 0;
	}
	else {
		return true;
	}
}

unsigned int cantidadElementos(ListaPosInt l)
{
	if (l) {
		return l->cantidadElementos;
	}
}

ListaPosInt clon(ListaPosInt l)
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

void destruir(ListaPosInt& l)
{
	//IMPLEMENTAR SOLUCION
}


#endif