#include "EjerciciosListas.h"

//PRE: Recibe por referencia una lista de tipo NodoLista y un valor de int
//POS: Modifica la lista insertando un nodo con el valor pasado al principio de la lista.
void insertarPrincipio(NodoLista* &l, int a) {
	NodoLista* nuevo = new NodoLista;
	nuevo->dato = a;
	nuevo->sig = l;
	l = nuevo;
}


//PRE: Recibe una lista y un dato.
//POS: Devuelve la lista modificada con el dato insertado al final.
void insertarFinal(NodoLista*& l, int dato) {
	if (l == NULL) {
		NodoLista* nuevo = new NodoLista(dato);
		l = nuevo;
	}
	else {
		insertarFinal(l->sig, dato);
	}
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
	// intercambiar aux->dato
}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	NodoLista* nuevo = NULL;
	if (!l1 && !l2) {
		return nuevo;
	}
	NodoLista* aux1 = l1;
	NodoLista* aux2 = l2;
	while (aux1 && aux2) {  //Es lo mismo que poner aux1 != NULL && aux2 != NULL
		if (aux1->dato > aux2->dato) {
			insertarFinal(nuevo, aux2->dato);
			aux2 = aux2->sig;
		}
		else {
			insertarFinal(nuevo, aux1->dato);
			aux1 = aux1->sig;
		}
	}
	while (aux1) { //Si quedo algo
		insertarFinal(nuevo, aux1->dato);
		aux1 = aux1->sig;
	}
	while (aux2) { //Si quedo algo
		insertarFinal(nuevo, aux2->dato);
		aux2 = aux2->sig;
	}
	return nuevo;
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
