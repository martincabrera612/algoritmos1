1#include "EjerciciosListas.h"

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

//PRE: Recibe una lista y un dato.
//POS: Modifica la lista eliminando todos los valores iguales al dato.
void elimTodasOcurrencias(NodoLista*& l, int dato) {
	if (l) {
		if (l->dato == dato) {
			NodoLista* borrar = l;
			l = l->sig;
			delete borrar;
			elimTodasOcurrencias(l, dato);
		}
		else {
			elimTodasOcurrencias(l->sig, dato);
		}
	}
}

//PRE: Recibe dos listas, l1 por referencia y l2 por valor;
//POS: Modifica la lista concatendo ambas lista en l1;
void concatenarListas(NodoLista*& l1, NodoLista* l2) {
	if (!l1) {
		l1 = l2;
	}
	else {
		concatenarListas(l1->sig, l2);
	}
}

//PRE: Recibe una lista l1 por referencia y una lista l2 por valor.
//POS: Modifica la lista l1 borrando los elementos que esten tambien en l2.
void diferencia(NodoLista* & l1, NodoLista* l2) {
	//CASO 1: l1 == NULL || l2 == NULL
	//CASO 2: l1 != NULL && l2 != NULL
	//CASO 3: l1 [3,4,5] l2 [1,2,3]

	if (!l1 || !l2 ) {            //CASO 1
		return;
	}
	while (l1 && l2 && l1->dato >= l2->dato) {    //CASO 2 y 3
		if (l1->dato == l2->dato) {
			NodoLista* borro = l1;
			l1 = l1->sig;
			delete borro;
		}
		l2 = l2->sig;
	}
	if (l1) {
		NodoLista* aux = l1;
		while (aux->sig  && l2) {
			if (aux->sig->dato == l2->dato) {
				NodoLista* borro = aux->sig;
				aux->sig = borro->sig;
				delete borro;
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


//PRE: Recibe una lista de tipo NodoLista
//POS: Devuelve la lista sin valores duplicados
void eliminarDuplicados(NodoLista*& l){
	if (l == NULL) {
		return;
	}
	else {
		if (l->sig != NULL && l->dato == l->sig->dato) {
			NodoLista* borrar = l;
			l = l->sig;
			delete borrar;		
			eliminarDuplicados(l);
		}
		else {
			eliminarDuplicados(l->sig);
		}
	}
}

//PRE: Recibe una lista por referencia y un dato tipo int.
//POS: Modifica la lista borrando el dato pasado por parametro.
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


//--------------------------------------------TERMINA FUNCIONES AUXILIARES--------------------------------------------


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
		}
	}
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
	NodoLista* temp = new NodoLista;
	if (!l1 && !l2) {
		return NULL;
	}
	if (!l1 && l2) {
		return copiaLista(l2);
		
	}
	if (!l2 && l1) {
		return copiaLista(l1);
	}
	else {
		if (l1->dato < l2->dato) {
			temp->dato = l1->dato;
			temp->sig = intercalarRec(l1->sig, l2);


		}
		else{
			temp->dato = l2->dato;
			temp->sig = intercalarRec(l1, l2->sig);

		}
	}
	return temp;
}
	

NodoLista* insComFin(NodoLista* l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	//Copia para no compartir memoria
	NodoLista* nueva = copiaLista(l1); 
	NodoLista* aux2 = copiaLista(l2);
	//Elimino duplicados
	eliminarDuplicados(nueva);     
	eliminarDuplicados(aux2);
	//Saco la diferencia
	diferencia(nueva, l2);
	diferencia(aux2, l1);
	//Uno los que quedaron
	concatenarListas(nueva, aux2);
	nueva = listaOrdenadaInsertionSort(nueva);
	delete aux2;         //Libero memoria
	return nueva;
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
	if (l && secuencia) {
		int largoSec = largoLista(secuencia);
		bool sigue = false;
		int cont = 0;
		NodoLista* aux = l;
		NodoLista* auxSec = secuencia;
		NodoLista* prev = aux;
		cont = 0;
		while (aux && auxSec) {
			if (aux->dato == auxSec->dato){
				cont++;
				sigue = true;
			}
			else {
				cont = 0;
				sigue = false;
				auxSec = secuencia;
			}
			if (!sigue) {
				prev = aux;
			}
			aux= aux->sig;
			if (sigue) {
				auxSec = auxSec->sig;
			}
		}
		if (cont == largoSec) {
		NodoLista* borrar = secuencia;
			while (borrar) {
				elim(l, borrar->dato);
				borrar = borrar->sig;
			}
		}
	}
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}
