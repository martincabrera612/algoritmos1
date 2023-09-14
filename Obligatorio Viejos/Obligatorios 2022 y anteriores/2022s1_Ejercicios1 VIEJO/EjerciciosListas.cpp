#include "EjerciciosListas.h"

NodoLista* invertirParcial(NodoLista* l) 
{
	NodoLista* p = copiarLista(l);
	NodoLista* nuevaLista = NULL;
	bool terminar = false; 
	while (p->sig != NULL ) {
		insertarPrincipio(nuevaLista, p->dato);
		p = p ->sig;	
	}
	return nuevaLista;
}

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &n) 
{
	// IMPLEMENTAR SOLUCION
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



//--------------------------------------------------------------------------
//------------------------------Funciones Auxiliares------------------------

NodoLista* copiarLista(NodoLista* lista) {
	if (lista == NULL) {
		return NULL;
	}
	else {
		NodoLista* nuevaLista = new NodoLista;
		nuevaLista->dato = lista->dato;
		nuevaLista->sig = copiarLista(lista->sig);
		return nuevaLista;
	}
}

void insertarPrincipio(NodoLista*  &l, int e) {
	NodoLista* q = new NodoLista;
	q->dato = e;
	q->sig = l;
	l = q;
}