#include "DiccionarioInt.h"
#include "Definiciones.h"

#ifdef DICCIONARIO_INT_IMP

struct _cabezalDiccionarioInt {
	NodoListaInt** hash;
	unsigned int capacidad;
	unsigned int cantidadElementos;
};

//-----------------------Funciones Auxiliares-----------------------
//PRE:- 
//POS:Devuelve el bucket correspondiente a la funcion de hash.
unsigned int funcionHash(unsigned int e, int capacidad) {
	return e % capacidad;
}

//PRE: -
//POS:Si encuentra el elemento lo borra y devuelve true, de lo contrario devuelve false.
bool borrarAux(NodoListaInt*& l, unsigned int e) {
	if (l) {
		if (l->dato == e) {
			NodoListaInt* aBorrar = l;
			l = l->sig;
			delete aBorrar;
			return true;
		}
		else {
			return borrarAux(l->sig, e);
		}
	}
	return false;
}

//PRE:- 
//POS:Vacia la lista
void vaciarLista(NodoListaInt*& l) {
	if (l) {
		vaciarLista(l->sig);
		delete l;
		l = NULL;
	}
}

//----------------------------------------------------------

DiccionarioInt crearDiccionarioInt(unsigned int esperados) {
	DiccionarioInt d = new _cabezalDiccionarioInt;
	d->hash = new NodoListaInt * [esperados];
	d->capacidad = esperados;
	d->cantidadElementos = 0;
	for (int i = 0; i < d->capacidad; i++)
	{
		d->hash[i] = NULL;
	}
	return d;
}

void agregar(DiccionarioInt& d, int e) {
	if (!pertenece(d, e)) {
		unsigned int bucket = funcionHash(e, d->capacidad);
		NodoListaInt* nodo = new NodoListaInt;
		nodo->dato = e;
		nodo->sig = d->hash[bucket];
		d->hash[bucket] = nodo;
		d->cantidadElementos++;
	}
}

void borrar(DiccionarioInt& d, int e) {
	unsigned int bucket = funcionHash(e, d->capacidad);
	if (borrarAux(d->hash[bucket], e)) {
		d->cantidadElementos--;
	}
}

bool pertenece(DiccionarioInt d, int e) {
	unsigned int bucket = funcionHash(e, d->capacidad);
	NodoListaInt* aux = d->hash[bucket];
	while (aux && aux->dato != e) {
		aux = aux->sig;
	}
	return aux != NULL;


}

int elemento(DiccionarioInt d) {
	assert(!esVacio(d));
	unsigned int bucket = 0;
	while (d->hash[bucket] == NULL) {
		bucket++;
	}
	return d->hash[bucket]->dato;
}

bool esVacio(DiccionarioInt d) {
	return d->cantidadElementos == 0;
}

unsigned int cantidadElementos(DiccionarioInt d) {
	return d->cantidadElementos;
}

DiccionarioInt clon(DiccionarioInt d) {
	DiccionarioInt nuevo = crearDiccionarioInt(d->capacidad);
	if (!esVacio(d)) {
		for (int i = 0; i < d->capacidad; i++)
		{
			NodoListaInt* aux = d->hash[i];
			while (aux) {
				agregar(nuevo, aux->dato);
				aux = aux->sig;
			}
		}

	}
	return nuevo;
}

void destruir(DiccionarioInt& d) {
	for (int i = 0; i < d->capacidad; i++)
	{
		vaciarLista(d->hash[i]);
	}
	delete d->hash;
	delete d;
	d = NULL;
}


#endif