#pragma once
#include <iostream>
#include <cassert>

struct NodoAB;

void imprimirPreOrder(NodoAB* r);

void imprimirInOrder(NodoAB* r);

void imprimirInOrderDer(NodoAB* r);

void imprimirPosOrder(NodoAB* r);

// Pre: r != NULL
int minimoAB(NodoAB* r);

// Pre: r != NULL
int minimoABB(NodoAB* r);

// Pre: r != NULL
int maximoABB(NodoAB* r);

bool sonIguales(NodoAB* p, NodoAB* q);

void pruebasArboles();
