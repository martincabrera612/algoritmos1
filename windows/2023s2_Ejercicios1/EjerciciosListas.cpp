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

//PRE: Recibe una lista tipo NodoLista.
//POS: Devuelve un entero con el largo de la lista.
int largoLista(NodoLista* l) {
	int largo = 0;
	while (l) {
		largo++;
		l = l->sig;
	}
	return largo;
}


//PRE: Recibe una lista tipo NodoLista.
//POS : Devuelve una copia de la lista recibida en una nueva Lista.
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
void insertarAlFinal(NodoLista*& l, NodoLista*& fin, int dato) {
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

//PRE:Recibe una lista por referencia y otra por valor.
//POS: Modifica la lista pasada por referencia, borrando los elementos en comun con la otra lista.
void diferencia(NodoLista*& l1, NodoLista* l2) {
	if (!l1 || !l2) {
		return;
	}
	while (l1 && l2 && l1->dato >= l2->dato) {
		if (l1->dato == l2->dato) {
			NodoLista* aBorrar = l1;
			l1 = l1->sig;
			delete aBorrar;
		}
		l2 = l2->sig;
	}
	if (l1) {
		NodoLista* aux = l1;
		while (aux->sig && l2) {
			if (aux->sig->dato == l2->dato) {
				NodoLista* aBorrar = aux->sig;
				aux->sig = aBorrar->sig;
				delete aBorrar;
				l2 = l2->sig;
			}
			else if (aux->sig->dato < l2->dato) {
				aux = aux->sig;
			}
			else {
				l2 = l2->sig;
			}
		}
	}
}


//PRE: Recibo una lista por referencia.
//POS: Modifico la lista eliminando los elementos repetidos.
void eliminarRepetidos(NodoLista*& l) {
	if (l) {
		if (l->sig && l->dato == l->sig->dato) {
			NodoLista* aBorrar = l;
			l = l->sig;
			delete aBorrar;
			eliminarRepetidos(l);
		}
		else {
			eliminarRepetidos(l->sig);
		}
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
		eliminarNesimoDesdeElFinal(lista->sig, n);
		n--;
		if (n == 0) {
			NodoLista* aBorrar = lista;
			lista = lista->sig;
			delete aBorrar;
		}
	}
}

void eliminarNesimoDesdeElFinal2(NodoLista*& lista, int n)
{
	if (lista) {
		eliminarNesimoDesdeElFinal(lista->sig, n);
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
	NodoLista* nueva = copia(l1);
	NodoLista* aux = copia(l2);
	eliminarRepetidos(nueva);
	eliminarRepetidos(aux);
	diferencia(nueva, l2);
	diferencia(aux, l1);
	NodoLista* resul = intercalarRec(nueva, aux);
	delete nueva;
	delete aux;
	return resul;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l)
{
	if (l) {
		if (l->sig && l->dato == l->sig->dato) {
			int num = l->dato;
			while (l && l->dato == num) {
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



void eliminarSecuencia(NodoLista*& l, NodoLista* secuencia)
{
	int largoSec = largoLista(secuencia);
	int cont = 0;
	bool cambiaPos = true;
	if (l && secuencia) {
		NodoLista* lista = l;
		NodoLista* sec = secuencia;
		int pos = 0;
		int empieza = 0;
		while (lista && sec) {
			if (lista->dato == sec->dato) {
				cont++;
				if (cambiaPos) {
					empieza = pos;
				}
				cambiaPos = false;
				sec = sec->sig;
			}
			else {
				cont = 0;
				cambiaPos = true;
				sec = secuencia;
			}
			lista = lista->sig;
			pos++;
		}
		if (cont == largoSec) {
			int largoL = largoLista(l);
			while (cont != 0) {
				eliminarNesimoDesdeElFinal2(l, largoL - empieza);
				empieza++;
				cont--;
			}
		}
	}
}

void moverNodo(NodoLista*& lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}
