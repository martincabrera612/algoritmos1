#pragma once
#include "SetImp.h"


//CONSTRUCTORAS 
// 
//PRE: - 
//POS: Crea un nuevo conjunto vacio.
Set crearVacio();


//PRE: El elemento no pertenece al conjunto
//POS: Agrega el elemento e al conjunto.
void insertar(Set& s, int e);

//PRE:
//POS:
Set clonar(Set s);

//PREDICADOS

//PRE: -  
//POS: Retorna true si el elemento e pertence al conjunto, sino false.
bool pertenece(Set s, int e);


//PRE: - 
//POS: Retorna true si el conjunto es vacio, sino false.
bool esVacio(Set s);

//SELECTORAS

//PRE: -
//POS: Retorna la cardinalidad del conjunto. (Cantidad de elementos)
unsigned int cardinalidad(Set s);

//PRE: No es vacio el set
//POS: Retorna un elemento cualquiera del set.
int elemento(Set s);



//PRE: -
//POS: Retorna un nuevo conjunto union que contiene los elementos de s1 y s2
Set unionSet(Set s1, Set s2);

//PRE: - 
//POS:Retorna un nuevo conjunto interseccion que contiene los elementos en comun de s1 y s2.
Set interseccionSet(Set s1, Set s2);

//PRE: - 
//POS:Retorna un nuevo conjunto diferencia que contiene los elementos que estan s1 pero no estan s2.
Set diferenciaSet(Set s1, Set s2);


//DESTRUCTORAS

//PRE: -
//POS:Libera la memoria que ocupa el conjunto.
void destruir(Set& s);

//PRE: -
//POS: Borra el elemento e del conjunto, si no se encuentra no tiene efecto.
void borrar(Set& s, int e);