#include "EjerciciosListas.h"

//PRE: Recibe por referencia una lista de tipo NodoLista y un valor de int
//POS: Modifica la lista insertando un nodo con el valor pasado al principio de la lista.
void insertarPrincipio(NodoLista* &l, int a) {
	NodoLista* nuevo = new NodoLista;
	nuevo->dato = a;
	nuevo->sig = l;
	l = nuevo;
}


//PRE: Recibe una lista de tipo NodoLista por referencia y un dato tipo int.
//POS: Devuelve la lista modificada con el dato insertado ordenamente en la posicion correcta.
void insOrd( NodoLista*& l, int dato ) {
	if (!l) {
		insertarPrincipio(l, dato);
	}else if (dato <= l->dato) {
		insertarPrincipio(l, dato);
	}else {
		insOrd(l->sig, dato);
	}
}

//PRE: Recibe por valor una lista de tipo NodoLista.
//POS: Devuelve el largo de la lista en int. 
int largoLista(NodoLista* l) {
	int largo = 0;
	while (l != NULL) {
		largo++;
		l = l->sig;
	}
	return largo;
}

//PRE: Recibe por valor una lista de tipo NodoLista
//POS: Devuelve una nueva copia de la lista recibida.
NodoLista* copiaLista(NodoLista* l) {
	if (!l) return NULL;
	NodoLista* nuevaLista = new NodoLista;
	nuevaLista->dato = l->dato;
	nuevaLista->sig = copiaLista(l->sig);
	return nuevaLista;
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

{	//MIRAR PPT DE LISTAS  insOrd
	NodoLista* nueva = NULL;
	while (l) {
		insOrd(nueva, l->dato);
		l = l->sig;
	}
	
	return nueva;
}

void listaOrdenadaSelectionSort(NodoLista*& l)
{	
	if(l) {
		//int largo = largoLista(l);
		//NodoLista* aux = NULL;
		NodoLista* i = l;
		NodoLista* j = NULL;
		NodoLista* posMin = NULL;
		while (i != NULL) {
			posMin = i;
			j = i->sig;
			while (j != NULL) {
				if (j->dato < posMin->dato) {
					//aux = j;
					posMin = j;
				}
				j = j->sig;
			}

			if (posMin != i) {
				int aux = i->dato;
				i->dato = posMin->dato;
				posMin->dato = aux;
			}
			
		i = i->sig;
			//largo--;
		}
	}
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
	int n;
	if (l == NULL) {
		return;
	}
	else {
		if (l->sig != NULL && l->dato == l->sig->dato) {
			n = l->dato;

			while (l != NULL && l->dato == n) {
				NodoLista* borrar = l;
				l = l->sig;
				delete borrar;
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
