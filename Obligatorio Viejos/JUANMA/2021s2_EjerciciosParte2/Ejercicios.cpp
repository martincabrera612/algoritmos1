#include "Ejercicios.h"

void AuxEnlistar(NodoABInt* a, ListaOrdInt& l) {
	if (a != NULL) {
		AuxEnlistar(a->izq, l);
		agregar(l, a->dato);
		AuxEnlistar(a->der, l);
	}
}


ListaOrdInt Enlistar(NodoABInt* a)
{
	ListaOrdInt resp = crearListaOrdInt();
	AuxEnlistar(a, resp);
	return resp;
}

ListaOrdInt UnionListaOrd(ListaOrdInt l1, ListaOrdInt l2)
{
	ListaOrdInt resp = crearListaOrdInt();
	ListaOrdInt l1aux = clon(l1);
	ListaOrdInt l2aux = clon(l2);
	while (!esVacia(l1aux) || !esVacia(l2aux)) {
		if (esVacia(l1aux)) {
			agregar(resp, minimo(l2aux));
			borrarMinimo(l2aux);
		}
		else {
			if (esVacia(l2aux)) {
				agregar(resp, minimo(l1aux));
				borrarMinimo(l1aux);
			}
			else {
				if (minimo(l1aux) == minimo(l2aux)) {
					agregar(resp, minimo(l1aux));
					agregar(resp, minimo(l2aux));
					borrarMinimo(l1aux);
					borrarMinimo(l2aux);
				}
				else {
					if (minimo(l1aux) < minimo(l2aux)) {
						agregar(resp, minimo(l1aux));
						borrarMinimo(l1aux);
					}
					else {
						if (minimo(l1aux) > minimo(l2aux)) {
							agregar(resp, minimo(l2aux));
							borrarMinimo(l2aux);
						}
					}
				}
			}
		}
	}

	return resp;
}

bool EstaContenida(PilaInt p1, PilaInt p2)
{
	PilaInt p1aux = clon(p1);
	PilaInt p2aux = clon(p2);
	bool resp = false;
	if (esVacia(p1)) {
		resp = true;
	}
	else {
		ListaOrdInt p1lista = crearListaOrdInt();
		ListaOrdInt p2lista = crearListaOrdInt();
		while (!esVacia(p1aux) || !esVacia(p2aux)) {
			if (!esVacia(p1aux)) {
				agregar(p1lista, top(p1aux));
				pop(p1aux);
			}
			if (!esVacia(p2aux)) {
				agregar(p2lista, top(p2aux));
				pop(p2aux);
			}
		}
		bool aux = true;
		while ((!esVacia(p1lista) || !esVacia(p2lista)) && aux) {
			if (esVacia(p1lista)) {
				aux = false;
			}
			else {
				if (minimo(p1lista) > minimo(p2lista)) {
					borrarMinimo(p2lista);
				}
				else {
					if (minimo(p1lista) == minimo(p2lista)) {
						borrarMinimo(p2lista);
						borrarMinimo(p1lista);
					}
					else {
						if (minimo(p1lista) < minimo(p2lista)) {
							aux = false;
						}
					}
				}
			}
			if (esVacia(p1lista)) {
				resp = true;
			}
		}

	}
	return resp;
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
	if (esVacia(c)) {
		ColaPrioridadInt aux = crearColaPrioridadInt(0);
		return aux;
	}
	else {
		ColaPrioridadInt clon1 = clon(c);
		int menorp = principioPrioridad(c);
		int cant = 0;
		while (!esVacia(clon1)) {
			if (menorp > principioPrioridad(clon1)) {
				menorp = principioPrioridad(clon1);
				cant = 1;
			}
			else {
				cant++;
			}
			desencolar(clon1);
		}
		ColaPrioridadInt clon2 = clon(c);
		ColaPrioridadInt resp = crearColaPrioridadInt(cant);
		while (!esVacia(clon2)) {
			if (principioPrioridad(clon2) == menorp) {
				encolar(resp, principio(clon2), principioPrioridad(clon2));
				desencolar(clon2);
			}
			else {
				desencolar(clon2);
			}
		}
		return resp;
	}
	
}

