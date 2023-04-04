#include "EjerciciosListas.h"

//PRE: Recibe por referencia una lista de tipo NodoLista y un valor de int/
//POS: Modifica la lista insertando un nodo con el valor pasado al principio de la lista.
void insertarPrincipio(NodoLista* &l, int a) {
	NodoLista* nuevo = new NodoLista;
	nuevo->dato = a;
	nuevo->sig = l;
	l = nuevo;
}


NodoLista* invertirParcial(NodoLista* l) 
{
	NodoLista* nuevaLista = new NodoLista;
	nuevaLista = NULL;
	while (l->sig != NULL) {
		insertarPrincipio(nuevaLista, l->dato);
		l = l->sig;
	}
	
	return nuevaLista;
}

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int& n)
{
	if (lista != NULL) {
		eliminarNesimoDesdeElFinal(lista->sig, n);
		n--;
		if (n == 0) {
			NodoLista* aux = lista;
			lista = lista->sig;
			delete aux;

		}

	}
}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l) 
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void listaOrdenadaSelectionSort(NodoLista*& l)
{
	// IMPLEMENTAR SOLUCION
}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	// IMPLEMENTAR SOLUCION
}

bool palindromo(NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	// IMPLEMENTAR SOLUCION
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}
