#pragma once
#include "SetImp.h"


//CONSTRUCTORAS 
//PRE:
//POS:
Set crearVacio();


//PRE:
//POS:
void insertar(Set& s, int e);

//PREDICADOS

//PRE:
//POS:
bool pertenece(Set s, int e);


//SELECTORAS
//PRE:
//POS:
unsigned int cardinalidad(Set s);

//PRE:
//POS:
int elemento(Set s);

//PRE:
//POS:
Set unionSet(Set s1, Set s2);

//PRE:
//POS:
Set interseccionSet(Set s1, Set s2);

//PRE:
//POS:
Set diferenciaSet(Set s1, Set s2);



//PRE:
//POS:
bool esVacio(Set s);

//PRE:
//POS:
void destruir(Set& s);

//PRE:
//POS:
void borrar(Set& s, int e);