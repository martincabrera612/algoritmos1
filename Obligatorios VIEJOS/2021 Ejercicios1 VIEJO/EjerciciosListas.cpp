#include "EjerciciosListas.h"


NodoLista* copiarLista(NodoLista* l) {
	NodoLista* ret = NULL;
	if (l != NULL) {
		ret = new NodoLista; //creo un struct nuevo
		ret->dato = l->dato; //copio el dato por valor
		ret->sig = copiarLista(l->sig); //copio el puntero al resto recursivamente
	}
	return ret;
}

//void insertarPrincipio(NodoLista *l, int n) {
//	NodoLista* p = l;
//	NodoLista* q = new NodoLista;
//	q->dato = n;
//	q->sig = p;
//	p = q;
//}
void insertarPrincipio(NodoLista*& lista, int dato) {
	NodoLista* aux = new NodoLista(dato);
	aux->sig = lista;
	lista = aux;
}



NodoLista* invertirParcial(NodoLista* l) 
{
	// IMPLEMENTAR SOLUCION
	/*Ejemplo
		Entrada : (1, 2, 3, 4)
		Salida : (3, 2, 1)*/

	NodoLista* nuevaL = new NodoLista;
	nuevaL = NULL;
	while (l->sig != NULL) {
			insertarPrincipio(nuevaL, l->dato);
			l= l->sig;
	}
	return nuevaL;
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
