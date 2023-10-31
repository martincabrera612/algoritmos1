#include "DiccionarioInt.h"

#ifdef DICCIONARIO_INT_IMP

struct _cabezalDiccionarioInt {
	// NO IMPLEMENTADO
	NodoListaInt** hash;
	unsigned int cantElementos;
	unsigned int largo;
};


DiccionarioInt crearDiccionarioInt(unsigned int esperados) {
	// NO IMPLEMENTADO
	DiccionarioInt nuevo = new _cabezalDiccionarioInt;
	nuevo->cantElementos = 0;
	nuevo->largo = esperados;
	nuevo->hash = new NodoListaInt * [nuevo->largo];
	for (int i = 0; i < nuevo->largo; i++)
	{
		nuevo->hash[i] = NULL;
	}
	return nuevo;
}

void agregar(DiccionarioInt& d, int e) {
	// NO IMPLEMENTADO

	if (!pertenece(d, e)) {
		int pos = hasheo(e, d);
		agregarLista(d->hash[pos], e);
		d->cantElementos++;
	}

}

void agregarLista(NodoListaInt*& l, int dato) {
	NodoListaInt* nuevo = new NodoListaInt;
	nuevo->dato = dato;
	nuevo->sig = l;
	l = nuevo;
}
int hasheo(int dato, DiccionarioInt d) {
	return dato % d->largo;
}

void borrar(DiccionarioInt& d, int e) {
	// NO IMPLEMENTADO
	int pos = hasheo(e, d);
	if (d->hash[pos] != NULL) {
		if (d->hash[pos]->dato == e) {
			NodoListaInt* aux = d->hash[pos];
			d->hash[pos] = d->hash[pos]->sig;
			delete aux;
			d->cantElementos -= 1;
			return;
		}
		if (pertenece(d, e)) {
			borrarLista(d->hash[pos], e);
			d->cantElementos -= 1;
			return;
		}
	}

}

void borrarLista(NodoListaInt* l, int dato) {
	if (l->sig != NULL) {
		if (l->sig->dato == dato) {
			NodoListaInt* aux = l->sig;
			l->sig = aux->sig;
			delete aux;
		}
		else {
			borrarLista(l->sig, dato);
		}
	}
}
bool pertenece(DiccionarioInt d, int e) {
	// NO IMPLEMENTADO

	int pos = hasheo(e, d);
	NodoListaInt* aux = d->hash[pos];

	while (aux != NULL) {
		if (aux->dato == e) {
			return true;
		}
		aux = aux->sig;
	}
	return false;
}

int elemento(DiccionarioInt d) {
	// NO IMPLEMENTADO
	for (int i = 0; i < d->largo; i++)
	{
		if (d->hash[i] != NULL) {
			return d->hash[i]->dato;
		}
	}
}

bool esVacio(DiccionarioInt d) {
	// NO IMPLEMENTADO
	if (d->cantElementos == 0) {
		return true;
	}
	return false;
}

unsigned int cantidadElementos(DiccionarioInt d) {
	// NO IMPLEMENTADO
	return d->cantElementos;
}

DiccionarioInt clon(DiccionarioInt d) {
	// NO IMPLEMENTADO
	DiccionarioInt dClon = crearDiccionarioInt(d->largo);
	for (int i = 0; i < d->largo; i++)
	{
		NodoListaInt* auxLista = d->hash[i];
		while (auxLista != NULL) {
			agregar(dClon, auxLista->dato);
			auxLista = auxLista->sig;
		}

	}
	return dClon;
}

void destruir(DiccionarioInt& d) {
	// NO IMPLEMENTADO
	for (int i = 0; i < d->cantElementos; i++)
	{
		destruirLista(d->hash[i]);
		delete[] d->hash;

	}
	delete d;
}

void destruirLista(NodoListaInt* l) {
	NodoListaInt* destruir;
	while (l != NULL) {
		destruir = l;
		l = l->sig;
		delete destruir;
	}
}

bool listaVacia(NodoListaInt* l) {
	int cont = 0;
	while (l != NULL) {
		cont++;
		l = l->sig;
	}

	return (cont == 0);
}


#endif