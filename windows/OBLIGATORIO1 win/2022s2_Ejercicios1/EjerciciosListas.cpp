#include "EjerciciosListas.h"

//PRE: Recibe una lista simplemente encadenada y un elemento de tipo int. 
//POS: Devuelve la lista con el elemento insertado al principio de la lista.

void insertarPrincipio(NodoLista* &l, int dato) {
	NodoLista* p = new NodoLista;
	p->dato = dato;
	p->sig = l;
	l = p;

}

//PRE: Recibe una lista simplemente encadenada y un elemento de tipo int. 
//POS: Inserta de manera ordenada el elemento en la lista.

void insOrd(int dato, NodoLista*& lista) {
	if (lista == NULL) {
		insertarPrincipio(lista, dato);
	}
	else {
		if (dato <= lista->dato) {
			insertarPrincipio(lista, dato);
		}
		else {
			insOrd(dato, lista->sig);
		}
	}
}


//PRE: Recibe dos nodos de una lista simplemente encadenada.
//POS: Intercambia la posicion de los nodos en la lista.

void swapNodos(NodoLista* nodo1, NodoLista* nodo2) {
	NodoLista* aux = nodo2;
	nodo2->sig = nodo1->sig;
	nodo1->sig = aux->sig;
}

//PRE:
//POST:

NodoLista* copia(NodoLista* l) {
	if (l == NULL) {
		return NULL;
	}
	else {
		NodoLista* res = new NodoLista;
		res->dato = l->dato;
		res->sig = copia(l->sig);
		return res;
	}
}

//PRE:
//POST:

void concat(NodoLista*& l1, NodoLista* l2) {
	if (l1 == NULL) {
		l1 = l2;
	}
	else {
		concat(l1->sig, l2);
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

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &n) 
{
	
	if (lista != NULL) {
		eliminarNesimoDesdeElFinal(lista->sig, n);
		n = n - 1;
			if (n == 0) {
				NodoLista* p = new NodoLista;
				p = lista;
				lista = p->sig;
				delete p;
			}	
	}
}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l) 
{
	NodoLista* nuevaLista = NULL;
	while (l != NULL) {
		insOrd(l->dato, nuevaLista);
		l = l->sig;
	}

	return nuevaLista;
}

void listaOrdenadaSelectionSort(NodoLista*& l)
{
	/*NodoLista* iter = l;
	int min = INT_MAX;
	if (l != NULL) {
		
		while (iter != NULL) {
			if (iter->dato < min) {
				min = iter->dato;
			}
			else {
				int aux = iter->dato;
				iter->dato = min;
				min = aux;
			}


		}
	}*/


}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	NodoLista* nuevaLista = new NodoLista();
	if (l1 == NULL && l2 == NULL) {
		return NULL;
	}
	if (l1 == NULL && l2 != NULL) {
		return copia(l2);
	}
	if (l1 != NULL && l2 == NULL) {
		return copia(l1);
	}
	else {
		if (l1->dato > l2->dato) {
			nuevaLista->dato = l2->dato;
			nuevaLista->sig = intercalarRec(l1, l2->sig);
		}
		else {
			nuevaLista->dato = l1->dato;
			nuevaLista->sig = intercalarRec(l1->sig, l2);
		}
		return nuevaLista;
	}
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
