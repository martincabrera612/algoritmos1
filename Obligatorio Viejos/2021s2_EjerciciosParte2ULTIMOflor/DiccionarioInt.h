#pragma once
// NOTA: Este archivo no debe ser modificado (excepto por los define que eligen la implementacion a usar)

// Elegir la implementacion a usar (solo 1 a la vez):
#define DICCIONARIO_INT_IMP
//#define DICCIONARIO_INT_IMP_2

#if defined(DICCIONARIO_INT_IMP)
#include "DiccionarioIntImp.h"
#elif defined(DICCIONARIO_INT_IMP_2)
#include "DiccionarioIntImp2.h"
#endif

// PRE: -
// POS: retorna una nuevo diccionario vacio
//		Al crear el diccionario se recibe la cantidad esperada de elementos, 
//		aunque puedan insertarse m�s elementos.
DiccionarioInt crearDiccionarioInt(unsigned int esperados);

// PRE: -
// POS: agrega el elemento e en el diccionario
void agregar(DiccionarioInt& d, int e);

// PRE: -
// POS: borra el elemento del diccionario
//        Si no encuentra no tiene efecto
void borrar(DiccionarioInt& d, int e);

// PRE: -
// POS: retorna true sii el elemento e se encuentra en el diccionario
bool pertenece(DiccionarioInt d, int e);

// PRE: !esVacia()
// POS: Retorna un elemento cualquiera del diccionario
int elemento(DiccionarioInt d);

// PRE: -
// POS: retorna true si y solo si el diccionario esta vacio
bool esVacio(DiccionarioInt d);

// PRE: -
// POS: retorna la cantidad de elementos presentes en el diccionario
unsigned int cantidadElementos(DiccionarioInt d);

// PRE: -
// POS: retorna una copia del diccionario d sin compartir memoria
DiccionarioInt clon(DiccionarioInt d);

// PRE: -
// POS: libera la memoria del diccionario
void destruir(DiccionarioInt& d);
//AUXULIARES:
//PRE: -
//POS: libera la memoria de una nodoLista
void destruirLista(NodoListaInt* l);
//PRE: -
//POS: retorna true si y solo si la lista esta vacia
bool listaVacia(NodoListaInt* l);
//PRE:-
//POS:agrega dato a la lista
void agregarLista(NodoListaInt*& l, int dato);
//PRE: -
//POS: retorna la pos buscada
int hasheo(int dato, DiccionarioInt d);
//PRE:-
//POS:borra un dato de una lista
void borrarLista(NodoListaInt* l, int dato);