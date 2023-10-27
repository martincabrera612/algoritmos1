#pragma once

struct _cabezalCola;
typedef _cabezalCola* Cola;

//PRE Y POS (HWK :D )
Cola crearCola();

void encolar(Cola& c, int dato);

void desencolar(Cola& c);

int principio(Cola c);

bool esVacia(Cola c);

int cantidadDeElementos(Cola c);

Cola clon(Cola c);

void destruir(Cola& c);
