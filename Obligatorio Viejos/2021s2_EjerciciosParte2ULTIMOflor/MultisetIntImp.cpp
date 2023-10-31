#include "MultisetInt.h"

#ifdef MULTISET_INT_IMP

struct _cabezalMultisetInt {
	// NO IMPLEMENTADO
	//NodoListaIntDobleDato* lista;
	//unsigned int cantElementos;
};

MultisetInt crearMultisetInt() {
	// NO IMPLEMENTADO
	//MultisetInt nuevo = new _cabezalMultisetInt;
	//nuevo->lista = NULL;
	//nuevo->cantElementos = 0;
	//return nuevo;
	return NULL;
}


void agregar(MultisetInt& s, int e, unsigned int ocurrencias){
	// NO IMPLEMENTADO
	/*NodoListaIntDobleDato* nuevo = s->lista;
		while (nuevo != NULL) {
			if (nuevo->dato1 == e) {
				nuevo->dato2 = nuevo->dato2 + ocurrencias;
				s->cantElementos = s->cantElementos + ocurrencias;
				return;
			}
			nuevo = nuevo->sig;
		}

		NodoListaIntDobleDato* nuevo2 = new NodoListaIntDobleDato;
		nuevo2->dato2 = ocurrencias;
		nuevo2->dato1 = e;
		nuevo2->sig = s->lista;
		s->lista = nuevo2;
		s->cantElementos += ocurrencias;*/
}

void borrar(MultisetInt& s, int e) {
	// NO IMPLEMENTADO
	/*NodoListaIntDobleDato* nuevo = s->lista;
	while (nuevo != NULL) {
		if (nuevo->dato1 == e && nuevo->dato2 > 1) {
			nuevo->dato2 -= 1;
			s->cantElementos -= 1;
			return;
		}
		else if (nuevo->dato1 == e && nuevo->dato2 == 1) {
			NodoListaIntDobleDato* aux = nuevo;
			nuevo = nuevo->sig;
			delete aux;
			s->cantElementos -= 1;
			return;
		}
		nuevo = nuevo->sig;
	}*/
}

bool pertenece(MultisetInt s, int e) {
	// NO IMPLEMENTADO
	/*MultisetInt auxiliar = crearMultisetInt();
	while (auxiliar->lista != NULL) {
		if (auxiliar->lista->dato1 == e) {
			return true;
		}
	}
	return false;*/
	return false;
}

MultisetInt unionConjuntos(MultisetInt s1, MultisetInt s2) {
	// NO IMPLEMENTADO
	/*NodoListaIntDobleDato* auxiliarS1 = s1->lista;
	NodoListaIntDobleDato* auxiliarS2 = s2->lista;
	MultisetInt nuevo = crearMultisetInt();

	while (auxiliarS1 != NULL)
	{
		agregar(nuevo, auxiliarS1->dato1, auxiliarS1->dato2);
		auxiliarS1 = auxiliarS1->sig;
	}

	while (s2->lista != NULL) {
		if (pertenece(nuevo, auxiliarS2->dato1)) {
			NodoListaIntDobleDato* nuevoAux = nuevo->lista;
			while (nuevoAux != NULL) {
				if (nuevoAux->dato1 == auxiliarS2->dato1 && nuevoAux->dato2 < auxiliarS2->dato2) {
					agregar(nuevo, nuevoAux->dato1, (auxiliarS2->dato2 - nuevoAux->dato2));
					auxiliarS2 = auxiliarS2->sig;
				}
				nuevoAux = nuevoAux->sig;
			}

		}
		else {
			agregar(nuevo, auxiliarS2->dato1, auxiliarS2->dato2);
		}
		auxiliarS2 = auxiliarS2->sig;
	}
	return nuevo;*/
	return NULL;
}

MultisetInt interseccionConjuntos(MultisetInt s1, MultisetInt s2) {
	// NO IMPLEMENTADO
	/*NodoListaIntDobleDato* auxiliarS1 = s1->lista;
	NodoListaIntDobleDato* auxiliarS2 = s2->lista;
	MultisetInt nuevo = crearMultisetInt();
	for (int i = 0; i < s1->cantElementos; i++)
	{
		bool existe = pertenece(s2, auxiliarS2->dato1);
		for (int i = 0; i < s2->cantElementos && existe; i++)
		{
			if (auxiliarS1->dato1 == auxiliarS2->dato1 && auxiliarS1->dato2 > auxiliarS2->dato2) {
				agregar(nuevo, auxiliarS1->dato1, auxiliarS2->dato2);
			}
			else {
				agregar(nuevo, auxiliarS1->dato1, auxiliarS1->dato2);
			}
		}
	}
	return nuevo;*/
	return NULL;
}

MultisetInt diferenciaConjuntos(MultisetInt s1, MultisetInt s2) {
	// NO IMPLEMENTADO
	/*MultisetInt nuevo = crearMultisetInt();
	NodoListaIntDobleDato* auxiliarS1 = s1->lista;

	while (auxiliarS1 != NULL) {
		NodoListaIntDobleDato* auxiliarS2 = s2->lista;


		if (pertenece(s2, auxiliarS1->dato1)) {
			while (auxiliarS2 != NULL)
			{
				if (auxiliarS1->dato1 == auxiliarS2->dato1 && auxiliarS1->dato2 > auxiliarS2->dato2) {
					agregar(nuevo, auxiliarS1->dato1, (auxiliarS1->dato2 - auxiliarS2->dato2));
				}
				auxiliarS2 = auxiliarS2->sig;
			}
		}
		else {
			agregar(nuevo, auxiliarS1->dato1, auxiliarS1->dato2);
		}
		auxiliarS1 = auxiliarS1->sig;
	}
	return nuevo;*/
	return NULL;
}

bool contenidoEn(MultisetInt s1, MultisetInt s2) {
	// NO IMPLEMENTADO
	/*bool esta = false;
	MultisetInt nuevo = crearMultisetInt();
	NodoListaIntDobleDato* auxiliarS1 = s1->lista;

	while (auxiliarS1 != NULL) {
		NodoListaIntDobleDato* auxiliarS2 = s2->lista;
		if (pertenece(s2, auxiliarS1->dato1)) {
			esta = true;
		}
		else {
			while (auxiliarS2 != NULL) {
				if (auxiliarS1->dato1 == auxiliarS2->dato1 && auxiliarS1->dato2 > auxiliarS2->dato2) {
					esta = true;
				}

				auxiliarS2 = auxiliarS2->sig;
			}

		}
		auxiliarS1 = auxiliarS1->sig;

	}
	return esta;*/
	return false;
}

int elemento(MultisetInt s) {
	// NO IMPLEMENTADO
	/*while (s->lista != NULL) {
		if (s->lista->sig == NULL) {
			return s->lista->dato1;
		}
		s->lista = s->lista->sig;
	}

	return 0;*/
	return 0;
}

bool esVacio(MultisetInt s) {
	// NO IMPLEMENTADO
	/*if (s->cantElementos == 0) {
		return true;
	}
	else{
		return false;
	}*/
	return true;
}

unsigned int cantidadElementos(MultisetInt s) {
	// NO IMPLEMENTADO
	//return s->cantElementos;
	return 0;
}

void destruir(MultisetInt& s) {
	// NO IMPLEMENTADO
	/*while (s->lista != NULL) {
		borrar(s, s->lista->dato1);
	}

	delete s;*/
}

MultisetInt clon(MultisetInt s) {
	// NO IMPLEMENTADO
	/*MultisetInt nuevo = crearMultisetInt();
	NodoListaIntDobleDato* nuevoAux = s->lista;
	while (nuevoAux != NULL) {
		agregar(nuevo, nuevoAux->dato1, nuevoAux->dato2);
		nuevoAux = nuevoAux->sig;
	}
	return nuevo;*/
	return NULL;
}

#endif