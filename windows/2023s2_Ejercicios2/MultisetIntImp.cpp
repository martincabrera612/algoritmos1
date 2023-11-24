#include "MultisetInt.h"
#include "Definiciones.h"
#ifdef MULTISET_INT_IMP

struct _cabezalMultisetInt {
	NodoListaIntDobleDato* l;
	int cantidadElementos;
};

//---------------------Funciones Auxiliares-----------------------
//PRE:
//POS:
void agregarAux(NodoListaIntDobleDato*& l, int e, unsigned int ocurrencias) {
	if (l) {
		if (l->dato1 == e) {
			l->dato2 = l->dato2 + ocurrencias;
		}
		else if (l->dato1 > e) {
			NodoListaIntDobleDato* nodo = new NodoListaIntDobleDato;
			nodo->dato1 = e;
			nodo->dato2 = ocurrencias;
			nodo->sig = l;
			l = nodo;
		}
		else {
			agregarAux(l->sig, e, ocurrencias);
		}

	}
	else {
		l = new NodoListaIntDobleDato;
		l->dato1 = e;
		l->dato2 = ocurrencias;
	}
}

//PRE:
//POS:
void borrarAux(NodoListaIntDobleDato*& l, int e) {
	if (l->dato1 == e) {
		if (l->dato2 == 1) {
			NodoListaIntDobleDato* aBorrar = l;
			l = l->sig;
			aBorrar = NULL;
			delete aBorrar;
		}
		else {
			l->dato2--;
		}
	}
	else {
		if (l->sig->dato1 == e) {
			if (l->sig->dato2 == 1) {
				NodoListaIntDobleDato* aBorrar = l->sig;
				l->sig = l->sig->sig;
				aBorrar = NULL;
				delete aBorrar;
			}
			else {
				borrarAux(l->sig, e);
			}
		}
		else {
			borrarAux(l->sig, e);
		}
	}
}

bool perteneceAux(NodoListaIntDobleDato* l, int e) {
	if (l) {
		if (l->dato1 == e) {
			return true;
		}
		else {
			return perteneceAux(l->sig, e);
		}
	}
	else {
		return false;
	}
}

//---------------------------------------------------------------------
MultisetInt crearMultisetInt() {
	MultisetInt nuevo = new _cabezalMultisetInt;
	nuevo->l = NULL;
	nuevo->cantidadElementos = 0;
	return nuevo;
}


void agregar(MultisetInt& s, int e, unsigned int ocurrencias) {
	agregarAux(s->l, e, ocurrencias);
	s->cantidadElementos = s->cantidadElementos + ocurrencias;
}

void borrar(MultisetInt& s, int e) {
	if (pertenece(s, e)) {
		borrarAux(s->l, e);
		s->cantidadElementos--;
	}
}

bool pertenece(MultisetInt s, int e) {
	NodoListaIntDobleDato* aux = s->l;
	while (aux) {
		if (aux->dato1 == e) {
			return true;
		}
		aux = aux->sig;
	}
	return false;
}

MultisetInt unionConjuntos(MultisetInt s1, MultisetInt s2) {
	MultisetInt unionSet = crearMultisetInt();
	NodoListaIntDobleDato* aux1 = s1->l;
	while (aux1) {
		agregar(unionSet, aux1->dato1, aux1->dato2);
		aux1 = aux1->sig;
	}
	NodoListaIntDobleDato* aux2 = s2->l;
	while (aux2) {
		agregar(unionSet, aux2->dato1, aux2->dato2);
		aux2 = aux2->sig;
	}
	return unionSet;
}

MultisetInt interseccionConjuntos(MultisetInt s1, MultisetInt s2) {
	MultisetInt inter = crearMultisetInt();
	NodoListaIntDobleDato* aux1 = s1->l;
	while (aux1) {
		if (pertenece(s2, aux1->dato1)) {
			agregar(inter, aux1->dato1, aux1->dato2);
			NodoListaIntDobleDato* aux2 = s2->l;
			while (aux2) {
				if (aux1->dato1 = aux2->dato1) {
					aux1->dato2 = aux1->dato2 + aux2->dato2;
				}
				aux2 = aux2->sig;
			}
		}
		aux1 = aux1->sig;
	}

	return inter;
}

MultisetInt diferenciaConjuntos(MultisetInt s1, MultisetInt s2) {
	MultisetInt dif = crearMultisetInt();
	NodoListaIntDobleDato* aux = s1->l;
	while (aux) {
		if (!pertenece(s2, aux->dato1)) {
			agregar(dif, aux->dato1, aux->dato2);
		}
		aux = aux->sig;
	}
	return dif;
}

bool contenidoEn(MultisetInt s1, MultisetInt s2) {
	// NO IMPLEMENTADO
	return false;
}

int elemento(MultisetInt s) {
	/*assert(!esVacio(s));
	NodoListaIntDobleDato* aux = s->l;
	while (aux == NULL) {
		aux = aux->sig;
	}
	return aux->dato1;*/
	return 0;
}

bool esVacio(MultisetInt s) {
	/*return s == NULL;*/
	return true;
}

unsigned int cantidadElementos(MultisetInt s) {
	//return s->cantidadElementos;
	return 0;
}

void destruir(MultisetInt& s) {
	/*while (s->cantidadElementos != 0) {
		borrar(s, elemento(s));
	}
	s = NULL;
	delete s;*/
}

MultisetInt clon(MultisetInt s) {
	/*MultisetInt nuevo = crearMultisetInt();
	NodoListaIntDobleDato* aux = s->l;
	while (aux) {
		agregar(nuevo, aux->dato1, aux->dato2);
		aux = aux->sig;
	}
	return nuevo;*/
	return NULL;
}

#endif