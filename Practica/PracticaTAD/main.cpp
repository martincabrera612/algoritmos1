// PracticaTAD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <assert.h>
using namespace std;

#include "Set.h"
#include "PilaInt.h"

void imprimirSet(Set s) {
	Set clonSet = clonar(s);
	cout << "{ ";
	while (!esVacio(clonSet)) {
		int elementoSet = elemento(clonSet);
		cout << elementoSet << " ";
		borrar(clonSet, elementoSet);
	}
	cout << " }" << endl;
	destruir(clonSet);
}

void imprimirPila(PilaInt p) {
	PilaInt aux = clon(p);
	if (!esVacia(aux)) {
		while (cantidadElementos(aux) != 0) {
			cout << " " << top(aux);
			pop(aux);
		}
	}
}

int main()
{
	/*Set s1 = crearVacio();
	insertar(s1, 1);
	insertar(s1, 2);
	insertar(s1, 3);
	cout << "S1" << endl;
	imprimirSet(s1);

	Set s2 = crearVacio();
	insertar(s2, 2);
	insertar(s2, 4);
	insertar(s2, 5);
	cout << "S2" << endl;
	imprimirSet(s2);

	cout << "Union: " << endl;
	imprimirSet(unionSet(s1, s2));

	cout << "Interseccion: " << endl;
	imprimirSet(interseccionSet(s1, s2));

	cout << "Diferencia: " << endl;
	imprimirSet(diferenciaSet(s1, s2));*/
	PilaInt nuevo = crearPilaInt();
	push(nuevo, 1);
	push(nuevo, 2);
	push(nuevo, 3);
	//PilaInt copia = clon(nuevo);
	//imprimirPila(copia);
	pop(nuevo);
	imprimirPila(nuevo);

}

