#pragma once

// ESPECIFICACION!!!
struct _cabezalLista;
typedef _cabezalLista* Lista;

Lista crearLista();

void insertarPrincipio(Lista& l, int dato);

void insertarFin(Lista& l, int dato);

void borrarPrincipio(Lista& l);

void borrarFin(Lista& l);

int cantidadDeElementos(Lista l);

// Pre: cant > 0
int obtenerPrincipio(Lista l);

// Pre: cant > 0
int obtenerFin(Lista l);

Lista clon(Lista l);

void destruir(Lista& l);


