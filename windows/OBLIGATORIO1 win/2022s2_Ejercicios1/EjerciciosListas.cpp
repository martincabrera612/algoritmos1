#include "EjerciciosListas.h"

//PRE: Recibe una lista y un elemento de tipo int. 
//POS: Devuelve la lista con el elemento insertado al principio de la lista.

NodoLista* insertarPrincipio(NodoLista* &l, int dato) {
	NodoLista* p = new NodoLista;
	p->dato = dato;
	p->sig = l;
	l = p;

	return l;
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
