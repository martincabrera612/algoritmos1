#include "Ejercicios.h"

ListaOrdInt Enlistar(NodoABInt* a)
{
	//IMPLEMENTAR SOLUCION
	//IMPLEMENTAR SOLUCION
	ListaOrdInt l = crearListaOrdInt();
	auxEnListar(a, l);
	return l;
	
}

ListaOrdInt UnionListaOrd(ListaOrdInt l1, ListaOrdInt l2)
{
	//IMPLEMENTAR SOLUCION
	ListaOrdInt l1Clon = clon(l1);
	ListaOrdInt l2Clon = clon(l2);
	ListaOrdInt listaOrd = crearListaOrdInt();
	while (!esVacia(l2Clon) && !esVacia(l1Clon)) {
		if (maximo(l1Clon) > maximo(l2Clon)) {
			int max = maximo(l1Clon);
			agregar(listaOrd, max);
			borrar(l1Clon, max);
		}
		else {
			if (maximo(l1Clon) <= maximo(l2Clon)) {
				int max = maximo(l2Clon);
				agregar(listaOrd, max);
				borrar(l2Clon, max);
			}
		}

	}
	while (!esVacia(l1Clon)) {
		int max = maximo(l1Clon);
		agregar(listaOrd, max);
		borrar(l1Clon, max);
	}
	while (!esVacia(l2Clon)) {
		int max = maximo(l2Clon);
		agregar(listaOrd, max);
		borrar(l2Clon, max);
	}
	return listaOrd;
}

bool EstaContenida(PilaInt p1, PilaInt p2)
{
	//IMPLEMENTAR SOLUCION
	PilaInt p1Nueva = clon(p1);
	PilaInt p2Nueva = clon(p2);
	ListaOrdInt listaAux = crearListaOrdInt();

	while (!esVacia(p1Nueva)) {
		int cima = top(p1Nueva);
		agregar(listaAux, cima);
		pop(p1Nueva);
	}

	while (!esVacia(p2Nueva)) {
		int cima = top(p2Nueva);
		if (existe(listaAux, cima)) {
			borrar(listaAux, cima);
			pop(p2Nueva);
		}
		else {
			pop(p2Nueva);
		}
	}

	if (esVacia(listaAux)) {
		return true;
	}
	else {
		return false;
	}
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

