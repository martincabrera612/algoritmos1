#include "Ejercicios.h"

//------------Funciones Auxiliares-------------

//PRE: - 
//POS: Agrega los elementos de l2 en l1

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

	ListaOrdInt nueva = clon(l1);
	ListaOrdInt lista2 = clon(l2);
	while (!esVacia(lista2)) {
		agregar(nueva, minimo(lista2));
		borrarMinimo(lista2);
	}
	destruir(lista2);
	return nueva;
}

bool EstaContenida(PilaInt p1, PilaInt p2)
{
	if (esVacia(p1)) {
		return true;
	}
	else if (!esVacia(p1) && esVacia(p2)) {
		return false;
	}
	else {
		PilaInt aux1 = clon(p1);
		PilaInt aux2 = clon(p2);
		PilaInt resto = crearPilaInt();
		int cont = 0;
		while (!esVacia(aux1) && !esVacia(aux2)) {
			if (top(aux2) == top(aux1)) {
				cont++;
				pop(aux1);
				pop(aux2);
				while (!esVacia(resto)) {
					push(aux2, top(resto));
					pop(resto);
				}
			}
			else {
				push(resto, top(aux2));
				pop(aux2);
			}
		}
		return (cont == cantidadElementos(p1));
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

