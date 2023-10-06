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


//PRE: Recibe una lista tipo NodoLista.
//POS: Devuelve una copia de la lista recibida en una nueva Lista.
NodoLista* copia(NodoLista* l) {
	if (!l) {
		return NULL;
	}
	else {
		NodoLista* nueva = new NodoLista;
		nueva->dato = l->dato;
		nueva->sig = copia(l->sig);
		return nueva;
	}
}

//PRE: Recibo una lista y un puntero al final de la lista por referencia y un entero por valor.
//POS: Inserto el dato al final de la lista.
void insertarAlFinal(NodoLista*& l, NodoLista* &fin, int dato) {
	NodoLista* nuevo = new NodoLista;
	nuevo->dato = dato;
	nuevo->sig = NULL;
	if (l == NULL) {
		l = nuevo;
		fin = l;
	}
	else {
		fin->sig = nuevo;
		fin = nuevo;
	}
}

//PRE: Recibo una lista por referencia y un entero por valor.
//POS: Inserto el dato ordenado en la lista.
void insOrd(NodoLista*& l, int x) {
	if (!l || x <= l->dato) {
		insertarPrincipio(l, x);
	}
	else {
		insOrd(l->sig, x);
	}
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
	NodoLista* nueva = NULL;
	while (l) {
		insOrd(nueva, l->dato);
		l = l->sig;
	}
	return nueva;
}

void listaOrdenadaSelectionSort(NodoLista*& l)
{
	if (l) {
		NodoLista* i = l;
		NodoLista* j = NULL;
		NodoLista* min = NULL;
		while (i) {
			min = i;
			j = i->sig;
			while (j) {
				if (j->dato < min->dato) {
					min = j;
				}
				j = j->sig;
			}
			if (min != i) {
				int aux = i->dato;
				i->dato = min->dato;
				min->dato = aux;
			}
			i = i->sig;
		}
	}
}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	NodoLista* nueva = NULL;
	NodoLista* fin = NULL;
	if (!l1 && !l2) {
		return nueva;
	}
	else {
		NodoLista* aux1 = l1;
		NodoLista* aux2 = l2;
		while (aux1 != NULL && aux2 != NULL) {
			if (aux1->dato <= aux2->dato) {
				insertarAlFinal(nueva, fin, aux1->dato);
				aux1 = aux1->sig;
			}
			else {
				insertarAlFinal(nueva, fin, aux2->dato);
				aux2 = aux2->sig;
			}
		}
		while (aux2) {
			insertarAlFinal(nueva, fin, aux2->dato);
			aux2 = aux2->sig;
		}
		while (aux1) {
			insertarAlFinal(nueva, fin, aux1->dato);
			aux1 = aux1->sig;
		}
		return nueva;
	}
	
	
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	NodoLista* nueva = new NodoLista;
	if (!l1 && !l2) {
		return NULL;
	}
	if (!l1 && l2) {
		return copia(l2);
	}
	if (l1 && !l2) {
		return copia(l1);
	}
	if (l1->dato <= l2->dato) {
		nueva->dato = l1->dato;
		nueva->sig = intercalarRec(l1->sig, l2);
	}
	else {
		nueva->dato = l2->dato;
		nueva->sig = intercalarRec(l1, l2->sig);
	}
	return nueva;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	NodoLista* nueva = NULL;
	insertarPrincipio(nueva, x);
	while (l) {
		insertarPrincipio(nueva, l->dato);
		l = l->sig;
	}
	insertarPrincipio(nueva, x);
	return nueva;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{

	if (!l1 && !l2) {
		return NULL;
	}else if (!l1 && l2) {
		return copia(l2);
	}else if (l1 && !l2) {
		return copia(l1);
	}
	else {
		NodoLista* nueva = new NodoLista;
		if (l1->dato < l2->dato) {
			nueva->dato = l1->dato;
			nueva->sig = exor(l1->sig, l2);
		}
		else if (l1->dato > l2->dato) {
			nueva->dato = l2->dato;
			nueva->sig = exor(l1, l2->sig);
			
		}
		else {
			exor(l1->sig, l2->sig);
		}
		return nueva;
	}

	
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	if (l) {
		if (l->sig && l->dato == l->sig->dato) {
			int num = l->dato;
			while (l && l->dato == num) {
				NodoLista* aBorrar = l;
				l= l->sig;
				delete aBorrar;
			}
			eliminarDuplicadosListaOrdenadaDos(l);
		}
		else {
			eliminarDuplicadosListaOrdenadaDos(l->sig);
		}
	}
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
