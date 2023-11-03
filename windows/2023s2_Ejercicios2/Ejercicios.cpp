#include "Ejercicios.h"

//------------Funciones Auxiliares-------------

//PRE:
//POS:

void concatenar(ListaOrdInt& l1, ListaOrdInt& l2) {
	while (!esVacia(l2)) {
		int elemento = minimo(l2);
		agregar(l1, elemento);
		borrarMinimo(l2);
	}
}



//------------FIN Funciones Auxiliares-------------

ListaOrdInt Enlistar(NodoABInt* a)
{
	ListaOrdInt resul = crearListaOrdInt();
	if (a) {
		agregar(resul, a->dato);
		ListaOrdInt izq = Enlistar(a->izq);
		ListaOrdInt der = Enlistar(a->der);
		concatenar(resul, izq);
		destruir(izq);
		concatenar(resul, der);
		destruir(der);
	}
	return resul;


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

