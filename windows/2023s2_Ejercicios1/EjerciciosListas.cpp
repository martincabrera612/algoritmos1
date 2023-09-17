#include "EjerciciosListas.h"

//---------------------------- FUNCIONES AUXILIARES-------------------

//PRE: Recibe una lista por referencia y un entero
//POS: Modifica la lista insertando el dato al comienzo de la misma.
void insertarPrincipio(NodoLista*& l, int dato) {
	NodoLista* nuevo = new NodoLista;
	nuevo->dato = dato;
	nuevo->sig = l;
	l = nuevo;
}

int largoLista(NodoLista* l) {
	int largo = 0;
	while (l) {
		largo++;
		l = l->sig;
	}
	return largo;
}


//----------------------------- FIN FUNCIONES--------------------------

NodoLista* invertirParcial(NodoLista* l) 
{
	if (!l) {
		return NULL;
	}
	else {
		NodoLista* nueva = NULL;
		while (l->sig != NULL) {
			insertarPrincipio(nueva, l->dato);
			l = l->sig;
		}
		return nueva;
	}
}

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int& n)
{	
	if (lista) {
		eliminarNesimoDesdeElFinal(lista->sig,n);
		n--;
		if (n == 0) {
			NodoLista* aBorrar = lista;
			lista = lista->sig;
			delete aBorrar;
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
