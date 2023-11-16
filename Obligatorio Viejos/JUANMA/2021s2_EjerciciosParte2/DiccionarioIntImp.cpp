#include "DiccionarioInt.h"
#include "Definiciones.h"

#ifdef DICCIONARIO_INT_IMP

struct _cabezalDiccionarioInt {
	NodoListaInt** array;
	int largoDic;
	int cantElemt;
};

int miFuncionHash(int elemento, int capacidad) {
	int resp = elemento % capacidad;
	return abs(resp);
}

void auxBorrar(NodoListaInt*& l, int dato) {
	if (l != NULL) {
		if (l->dato == dato) {
			NodoListaInt* aux = l;
			l = l->sig;
			delete aux;
		}
		else {
			auxBorrar(l->sig, dato);
		}
	}
}

int mayorPrimo(int e) {
	int resp = e;
	bool listo = true;
	while (listo) {
		if ((resp % 2) == 0) {
			resp++;
		}
		else {
			if ((resp % 3) == 0) {
				resp++;
			}
			else {
				listo = false;
			}
		}
	}
	return resp;
}

DiccionarioInt crearDiccionarioInt(unsigned int esperados) {
	DiccionarioInt d = new _cabezalDiccionarioInt;
	d->largoDic = mayorPrimo(esperados);
	d->array = new NodoListaInt * [mayorPrimo(esperados)];
	for (int i = 0; i < mayorPrimo(esperados); i++) {
		d->array[i] = NULL;
	}
	d->cantElemt = 0;
	return d;
}

void agregar(DiccionarioInt& d, int e) {
	if (!pertenece(d, e)) {
		NodoListaInt* nuevo = new NodoListaInt;
		nuevo->dato = e;
		nuevo->sig = d->array[miFuncionHash(e, d->largoDic)];
		d->array[miFuncionHash(e, d->largoDic)] = nuevo;
		d->cantElemt++;
	}
}

void borrar(DiccionarioInt& d, int e) {
	if (!esVacio(d)) {
		if (pertenece(d, e)) {
			auxBorrar(d->array[miFuncionHash(e, d->largoDic)], e);
			d->cantElemt--;
		}
	}
}

bool pertenece(DiccionarioInt d, int e) {
	bool resp = true;
	if (esVacio(d)) {
		return false;
	}
	else {
		NodoListaInt* lista = d->array[miFuncionHash(e, d->largoDic)];
		while (lista != NULL && lista->dato != e) {
			lista = lista->sig;
		}
		if (lista == NULL) {
			resp = false;
		}
	}
	return resp;
}

int elemento(DiccionarioInt d) {
	for (int i = 0; i < d->largoDic; i++) {
		if (d->array[i] != NULL) {
			return d->array[i]->dato;
		}
	}
}

bool esVacio(DiccionarioInt d) {
	if (d == NULL) {
		return true;
	}
	else {
		return d->cantElemt == 0;
	}
}

unsigned int cantidadElementos(DiccionarioInt d) {
	if (d == NULL) {
		return NULL;
	}
	else {
		return d->cantElemt;
	}
}

DiccionarioInt clon(DiccionarioInt d) {
	DiccionarioInt nuevod = crearDiccionarioInt(d->largoDic);
	if (esVacio(d)) {
		return nuevod;
	}
	else {
		for (int i = 0; i < d->largoDic; i++) {
			NodoListaInt* aux = d->array[i];
			while (aux != NULL) {
				agregar(nuevod, aux->dato);
				aux = aux->sig;
			}
		}
	}
	return nuevod;
}

void destruir(DiccionarioInt& d) {
	for (int i = 0; i < d->largoDic; i++) {
		NodoListaInt* aux = d->array[i];
		while (aux != NULL) {
			NodoListaInt* auxBorrar = aux;
			aux = aux->sig;
			delete auxBorrar;
		}
	}
	delete d;
	d = NULL;
}


#endif