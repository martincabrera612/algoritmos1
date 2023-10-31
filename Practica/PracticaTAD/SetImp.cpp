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


int elemento(Set s) {

}

unsigned int cardinalidad(Set s) {
	return s->cardinalidad;
}


Set unionSet(Set s1, Set s2) {

}


Set interseccionSet(Set s1, Set s2) {

}


Set diferenciaSet(Set s1, Set s2) {

}




bool esVacio(Set s) {

}


void destruir(Set& s) {

}


void borrar(Set& s, int e) {

}