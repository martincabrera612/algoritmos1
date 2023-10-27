//
//  ColaImp.cpp
//  PracticaCola
//  Created by Martin Cabrera on 25/10/23.
//
#pragma once
#include "ColaImp.h"
#include "Cola.h"
struct nodoLista {
    int dato;
    nodoLista *sig;
};

struct _representacionCola {
    nodoLista* ppio;
    nodoLista* fin;
    unsigned int cantidadElementos;
    unsigned int cota;
};



Cola crearVacio(unsigned int n){
    Cola c = new _representacionCola;
    c->ppio = NULL;
    c->fin = NULL;
    c->cantidadElementos = 0;
    c->cota = n;
    return c;
}

Cola Crear();

void encolar(Cola &c, int e){
    assert(!estaLlena(c));
    nodoLista* nodo = new nodoLista;
    nodo->dato = e;
    nodo->sig = NULL;
    if (c->fin == NULL){
        c->ppio = nodo;
        c->fin = nodo;
    }else {
        c->fin->sig = nodo;
        c->fin = nodo;
    }
    c->cantidadElementos++;
}

Cola clon(Cola c){
    Cola nueva = crearVacio(10);
    nodoLista* aux = c->ppio;
    while (aux) {
        encolar(nueva, aux->dato);
    }
    return nueva;
}

void desencolar(Cola &c){
    if (c->ppio != NULL){
        nodoLista* aBorrar = c->ppio;
        c->ppio = c->ppio->sig;
        if (c->ppio == NULL){
            c->fin = NULL;
        }
        delete aBorrar;
    }
}

int frente(Cola c) {
    assert(!esVacia(c));
    return c->ppio->dato;
}

bool esVacia(Cola c){
    return c->cantidadElementos == 0;
}

bool estaLlena(Cola c){
    return c->cantidadElementos == c->cota;
}

void destruir(Cola &c){
    while (!esVacia(c)){
        desencolar(c);
    }
    delete c;
    c = NULL;
}
