#pragma once
#include<iostream>

using namespace std;

struct NodoLista {
	int dato;
	int dato2;
	NodoLista* sig;
	NodoLista* ant;
	NodoLista() : dato(0), sig(NULL) {}
	NodoLista(int d) : dato(d), sig(NULL) {}
};
//typedef NodoLista* Lista;


//Pre y pos
void insertarAlPrincipio(NodoLista*& l, int dato);

void insertarFinalIterativo(NodoLista*& l, int dato);

void insertarFinalRecursiva(NodoLista*& l, int dato);

void insertarFinalConstante(NodoLista*& principio, NodoLista*& final, int dato);

void mostrarListaRec(NodoLista* l);

void mostrarListaInterativo(const char* titulo, NodoLista* l);

void insertarOrdenadoIterativo(NodoLista*& l, int dato);

void insertarOrdenadoRecursivo(NodoLista*& l, int dato);

void borrarPrincipio(NodoLista*& l);

void borrarFinIterativo(NodoLista*& l);

void concatenarListas(NodoLista*& l1, NodoLista*& l2);

void pruebasDeListas();