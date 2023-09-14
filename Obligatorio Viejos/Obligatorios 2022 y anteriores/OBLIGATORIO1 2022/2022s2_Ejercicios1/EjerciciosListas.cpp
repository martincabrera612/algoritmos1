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



//PRE: Recibe una lista. 
//POST:Devuelve el largo de la lista.

int largoLista(NodoLista* l) {
	int largo = 0;
	if (l == NULL) {
		return largo;
	}
	else {
		largo = 1 + largoLista(l->sig);
	}
}


//PRE: Recibe una lista y un entero. 
//POST:Modifica la lista eliminando todas las ocurrencias del elemento en la lista.
void elimOcurrencias(NodoLista* & l, int e) {
	bool borro = false;
	if (l != NULL) {
		if (l->dato == e) {
			NodoLista* aBorrar = l;
			l = l->sig;
			delete aBorrar;
			elimOcurrencias(l, e);
			borro = true;
		}
		else {
			elimOcurrencias(l->sig, e);
		}
	}
}

//PRE: Recibe una lista y un entero. 
//POST:Modifica la lista eliminando la primera ocurrencia del elemento en la lista.
void elim(NodoLista*& l, int e) {
	if (l != NULL) {
		if (l->dato == e) {
			NodoLista* aBorrar = l;
			l = l->sig;
			delete aBorrar;
		}
		else {
			elim(l->sig, e);
		}
	}
}


//PRE: Recibe una lista. 
//POST:Devuelve una copia de la lista.

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

//PRE: Recibe dos listas.
//POST: Devuelve una lista con las dos listas concatenadas

void concat(NodoLista* l1, NodoLista* l2) {
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
	if (l1 == NULL && l2 == NULL) {
		return NULL;
	}
	
	int largoL1 = largoLista(l1);
	int largoL2 = largoLista(l2);
	int largoTotal = largoL1 + largoL2;
	NodoLista* l = NULL;
	int i = 0;
	
	while (i < largoTotal ) {
		if (i < largoL1) {
			insertarPrincipio(l, l1->dato);
			l1 = l1->sig;
		}

		if (i >= largoL1) {
			insertarPrincipio(l, l2->dato);
			l2 = l2->sig;
		}
		i++;
	}

	NodoLista* resul = l;
	
	int j = 0;
	while (j < largoTotal ) {
		// Vuelve a apuntar al primer elemento de la lista
		l = resul;
		while (l->sig != NULL ) {
			if (l->dato > l->sig->dato) {
				int aux = l->dato;
				l->dato = l->sig->dato;
				l->sig->dato = aux;
			}
			if (l->sig != NULL) {
				l = l->sig;
			}
		}
		j++;
	}

	return resul;
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
	if (l != NULL) {
		if (l->sig != NULL && l->sig->dato == l->dato) {
			int elem = l->dato;
			while (l != NULL && l->dato == elem) {
				NodoLista* aBorrar = l;
				l = l->sig;
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

//PRE:
//POS:

void borrarNodos(NodoLista*& l) {
	NodoLista* aBorrar = l;
	l = l->sig;
	delete (aBorrar);
}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	if (l == NULL || secuencia == NULL) {
		return;
	}
	else {
		int cont = 0;
		int largoSec = largoLista(secuencia);
		NodoLista* p = l;
		NodoLista* q = secuencia;

		while(p != NULL && q != NULL && cont != largoSec ) {
			if (p->dato == q->dato) {
				cont= cont +1 ;
				 q = q->sig;
			}
			else {
				cont = 0;
			}
			
			p = p->sig;
			
		}
	
		NodoLista* x = secuencia;

		if (cont == largoSec) {
			while (l != NULL && x != NULL ) {
				if  (l->dato == x->dato){
					NodoLista* aBorrar = l;
					l = l->sig;
					delete aBorrar;
					x = x->sig;
				}
				else {
					l = l->sig;
				}
			}
		}
	}
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}