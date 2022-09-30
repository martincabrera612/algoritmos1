// TestsAlg1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


struct NodoLista {
    int dato;
    NodoLista* sig;
};

void swapNodos(NodoLista* nodo1, NodoLista* nodo2, NodoLista* &lista) {
	
	NodoLista* aux = nodo2;
	nodo2->sig = nodo1->sig;
	nodo1->sig = aux->sig;
}

// Crea una lista de tamaño n
NodoLista* crearListaN(int n) {
	NodoLista* lista = NULL;
	while (n > 0) {
		NodoLista* q = new NodoLista;
		q->dato = n;
		q->sig = lista;
		lista = q;
		n = n - 1;
	}
	return lista;
}

void imprimirLista(NodoLista* l) {
	while (l != NULL) {
		if (l->sig != NULL) {
			cout << l->dato << ",";
		}
		else {
			cout << l->dato << endl;
		}
		l = l->sig;
	}
	
}


int main()
{
    cout << "Hello World!\n";
	NodoLista* lista = crearListaN(10);
	imprimirLista(lista);
	NodoLista* p = NULL;
	while (lista != NULL) {
		if (p->dato < lista->dato) {
			p->dato = lista->dato;
			cout << p->dato << endl;
		}
		else {
			swapNodos(p, lista, );
		}
	}
	imprimirLista(lista);
	
}