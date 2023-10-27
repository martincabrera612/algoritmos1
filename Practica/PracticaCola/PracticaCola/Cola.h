//
//  Cola.h
//  PracticaCola
//
//  Created by Martin Cabrera on 25/10/23.
//
#pragma once
#ifndef Cola_h
#define Cola_h


#pragma once


struct _representacionCola;
typedef struct _representacionCola* Cola;

//IMPLEMENTACION COLA
//Definicion de metodos

//CONSTRUCTORAS

//PRE: -
//POS: Crea una nueva cola vacia que puede contener como maximo n elementos
Cola crearVacio(unsigned int n);

//PRE:La cola no es vacia
//POS:Inserta el elemento e al final de la cola

void encolar(Cola &cm, int e);


//PRE: -
//POS: Devuelve una copia de la cola sin compartir memoria.
Cola clon(Cola c);

//SELECTORAS

//PRE:La cola no es vacia
//POS: Retorna el elemento que se encuentra al frente de la cola

int frente(Cola c);

//PREDICADOS

//PRE: -
//POS: Retorna true si la cola es vacia, en caso contrario retorna false
bool esVacia(Cola c);

//PRE: -
//POS: Retorna true si la cola esta llena , en caso contrario retorna false
bool estaLlena(Cola c);


//DESTRUCTORAS

//PRE: -
//POS: Elimina el elemento que se encuentra en el frente de la cola. Si la cola
//es vacia la operacion no tiene efecto.
void desencolar(Cola &c);


//PRE: -
//POS: Libera memoria ocupada por la cola.
void destruir(Cola &c);



#endif
