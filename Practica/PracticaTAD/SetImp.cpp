#pragma once
#include "Set.h"
#include "SetImp.h"
#include <assert.h>

struct nodoLista {
	int dato;
	nodoLista* sig;
};

struct  _representacionSet {
	nodoLista* ppio;
	unsigned int cardinalidad;  //CANTIDAD ELEMENTOS
};

Set crearVacio() {
	Set s = new _representacionSet;
	s->ppio = NULL;
	s->cardinalidad = 0;
	return s;
}



void insertar(Set& s, int e) {
	assert(!pertenece(s, e));
	nodoLista* nodo = new nodoLista;
	nodo->dato = e;
	nodo->sig = s->ppio;
	s->ppio = nodo;
	s->cardinalidad++;
}

Set clonar(Set s) {
	Set clon = crearVacio();
	nodoLista* aux = s->ppio;
	while (aux != NULL) {
		insertar(clon, aux->dato);
		aux = aux->sig;
	}
	return clon;

}

bool pertenece(Set s, int e) {
	nodoLista* aux = s->ppio;
	while (aux != NULL) {
		if (aux->dato == e) {
			return true;
		}
		aux = aux->sig;
	}
	return false;
}

unsigned int cardinalidad(Set s) {
	return s->cardinalidad;
}


Set unionSet(Set s1, Set s2) {
	Set nuevoUnion = crearVacio();
	nodoLista* aux1 = s1->ppio;
	while (aux1) {
		insertar(nuevoUnion, aux1->dato);
		aux1 = aux1->sig;
	}
	nodoLista* aux2 = s2->ppio;
	while (aux2) {
		if (!pertenece(nuevoUnion, aux2->dato)) {
			insertar(nuevoUnion, aux2->dato);
		}
		aux2 = aux2->sig;
	}
	return nuevoUnion;
}


Set interseccionSet(Set s1, Set s2) {
	Set inter = crearVacio();
	nodoLista* aux1 = s1->ppio;
	while (aux1) {
		if (pertenece(s2, aux1->dato)) {
			insertar(inter, aux1->dato);
		}
		aux1 = aux1->sig;
	}
	return inter;
}


Set diferenciaSet(Set s1, Set s2) {
	Set diferenciaSet = crearVacio();
	nodoLista* aux = s1->ppio;
	while (aux) {
		if (!pertenece(s2, aux->dato)) {
			insertar(diferenciaSet, aux->dato);
		}
		aux = aux->sig;
	}
	return diferenciaSet;
}

int elemento(Set s) {
	assert(!esVacio(s));
	return s->ppio->dato;
}


bool esVacio(Set s) {
	return s->cardinalidad == 0;
}


void destruir(Set& s) {
	while (!esVacio(s)) {
		borrar(s, s->ppio->dato);
	}
	delete s;
	s = NULL;
}

//funciones auxiliares

//PRE: -
//POS: Borra el elemento e de la lisa l y retrorna true si lo borra.

bool borrarAux(nodoLista*& l, int e) {
	if (l) {
		if (l->dato == e) {
			nodoLista* aBorrar = l;
			l = l->sig;
			delete aBorrar;
			return true;
		}
		else {
			return borrarAux(l->sig, e);
		}
	}
	else {
		return false;
	}
}

void borrar(Set& s, int e) {

	if (borrarAux(s->ppio, e)) {
		s->cardinalidad--;
	}
}

