#include <iostream>
#include <cassert>
#include "Arboles.h"
#include "Listas.h"
#include "Lista.h"
#include "Cola.h"

using namespace std;
// APLICACION
//SOLO UTILIZANDO LISTA
// RECIBO 1 - 2 - 3, tiene que retornar
// la lista uno como se recibio y imprimir la lista 
// inversa 3 - 2 - 1

Lista invertirLista() {
	cout << endl << "INICIO invertirLista" << endl;
	int cant;
	cin >> cant;

	Lista listaUno = crearLista();
	for (int i = 0; i < cant; i++)
	{
		int dato;
		cin >> dato;
		insertarFin(listaUno, dato);
	}

	Lista listaUnoAux = clon(listaUno);
	while (cantidadDeElementos(listaUnoAux) != 0) {
		int dato = obtenerFin(listaUnoAux);
		borrarFin(listaUnoAux);
		if (cantidadDeElementos(listaUnoAux) == 0) {
			cout << dato << endl;
		}
		else {
			cout << dato << " - ";
		}
	}

	return listaUno;
}

void almacenoEnterosDesordenadosEnLaColaYImprimoOrdenadoSinModificarLaColaRecibida(Cola& c) {
	cout << endl << "INICIO almacenoDatosEnLaColaYImprimoOrdenadoSinModificarLaColaRecibida" << endl;
	int cant;
	cin >> cant;

	Cola c = crearCola();
	for (int i = 0; i < cant; i++)
	{
		int dato;
		cin >> dato;
		encolar(c, dato);
	}

	// Imprimir ordenados solo utilizando una cola y sin modificar la cola recibida.
	Cola copia = Clon(c);
	while (!esVacia(copia)){
			//Busco el minimo
			Cola cp = clon(copia);
			int minimo = INT_MAX;
			while(!esVacia(cp)){
				if (principio(cp) < minimo){
					minimo = principio(cp);
				}
				desencolar(cp);
			}
			cout << "=> " << minimo << endl;
			destruir(cp);

		
		//Crear una cola sin ese minimo
		Cola aux = crearCola();
		while(!esVacia(copia)){
			if(principio(copia) !=  minimo){
				encolar(aux, principio(copia));
			}
			desencolar(copia);
		}
		// Volver a meter los elemntos en la copia que no contiene al minimo
		while(!esVacia(aux)){
			encolar(copia, principio(aux));
			desencolar(aux);
		}
		destruir(aux);
	}
	destruir(copia);
}

invertirYimprimirLaColaInvertida(Cola c){
		//ver clase grabada practico 26 oct
}

int main() {
	/*pruebasDeListas();
	pruebasArboles();

	invertirLista();*/
	invertirYimprimirLaColaInvertida();



	return 0;
}