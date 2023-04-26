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
    NodoLista* nueva = NULL;
    if (!l){
        return NULL;
    }
    else {
        while (l->sig != NULL){
            insertarPrincipio(nueva, l->dato);
            l = l->sig;
        }
    }
        
	return nueva;
}

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &n) 
{
    
    if (lista != NULL){
        eliminarNesimoDesdeElFinal(lista->sig, n);
        n--;
        if (n == 0){
            NodoLista* borrar = lista;
            lista = lista->sig;
            delete borrar;
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
