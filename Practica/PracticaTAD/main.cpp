// PracticaTAD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "Set.h"

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

int main()
{
	Set s1 = crearVacio();
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
	imprimirSet(diferenciaSet(s1, s2));
}
