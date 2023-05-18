#include "Ejercicios.h"

ListaOrdInt Enlistar(NodoABInt* a)
{
    if (!a) return crearListaOrdInt(); //CB
    
    ListaOrdInt retorno = Enlistar(a->der);
    agregar(retorno, a->dato);
    
    ListaOrdInt listaIzq = Enlistar(a->izq);
    while (!esVacia(listaIzq)){
        agregar(retorno, maximo(listaIzq));
        borrarMaximo(listaIzq);
    }
    destruir(listaIzq);
	return retorno;
}

ListaOrdInt UnionListaOrd(ListaOrdInt l1, ListaOrdInt l2)
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

bool EstaContenida(PilaInt p1, PilaInt p2)
{
	//IMPLEMENTAR SOLUCION
	return false;
}


ListaOrdInt ObtenerRepetidos(MultisetInt m) 
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

MultisetInt Xor(MultisetInt m1, MultisetInt m2)
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

ColaPrioridadInt MenorPrioridad(ColaPrioridadInt c) {
	//IMPLEMENTAR SOLUCION
	return NULL;
}

