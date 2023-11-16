#include "ListaOrdInt.h"
#include "Definiciones.h"

#ifdef LISTA_ORD_INT_IMP_2

struct _cabezalListaOrdInt {
	NodoABIntDobleDato* lista;
	int cantElem;
};

void auxAgregar(NodoABIntDobleDato*& l, int e) {
	if (l == NULL) {
		l = new NodoABIntDobleDato(e,1);
	}
	else {
		if (l->dato1 > e) {
			if (l->izq == NULL || l->izq->dato1 < e) {
				NodoABIntDobleDato* nuevo = new NodoABIntDobleDato;
				nuevo->dato1 = e;
				nuevo->dato2 = 1;
				NodoABIntDobleDato* aux = l->izq;
				l->izq = nuevo;
				nuevo->izq = aux;
			}
			else {
				auxAgregar(l->izq, e);
			}
		}
		else {
			if (l->dato1 < e) {
				if (l->der == NULL || l->der->dato1 > e) {
					NodoABIntDobleDato* nuevo = new NodoABIntDobleDato;
					nuevo->dato1 = e;
					nuevo->dato2 = 1;
					NodoABIntDobleDato* aux = l->der;
					l->der = nuevo;
					nuevo->der = aux;
				}
				else {
					auxAgregar(l->der, e);
				}
			}
			else {
				if (l->dato1 == e) {
					l->dato2++;
				}
			}
		}
	}
}

bool auxExiste(NodoABIntDobleDato* l, int e) {
	if (l == NULL) {
		return false;
	}
	else {
		if (l->dato1 == e) {
			return true;
		}
		else {
			if (l->dato1 > e) {
				return auxExiste(l->izq, e);
			}
			if (l->dato1 < e) {
				return auxExiste(l->der, e);
			}
		}
	}
}

NodoABIntDobleDato*& auxBuscarNodoMinimo(NodoABIntDobleDato*& l) {
	if (l->izq == NULL) {
		return l;
	}
	else {
		return auxBuscarNodoMinimo(l->izq);
	}
}

void auxBorrar(NodoABIntDobleDato*& l, int e) {
	if (l != NULL) {
		if (l->dato1 < e) {
			auxBorrar(l->der, e);
		}
		else {
			if (l->dato1 > e) {
				auxBorrar(l->izq, e);
			}
			else {
				if (l->dato1 == e) {
					if (l->dato2 > 1) {
						l->dato2--;
					}
					else {
						if (l->der != NULL && l->izq != NULL) {
							NodoABIntDobleDato*& menor = auxBuscarNodoMinimo(l->der);
							l->dato1 = menor->dato1;
							l->dato2 = menor->dato2;
							NodoABIntDobleDato* borrarMenor = menor;
							menor = menor->der;
							delete borrarMenor;
						}
						else {
							NodoABIntDobleDato* auxBorrar = l;
							if (l->der == NULL && l->izq != NULL) {
								l = l->izq;
								delete auxBorrar;
								auxBorrar = NULL;
							}
							else {
								if (l->der != NULL && l->izq == NULL) {
									l = l->der;
									delete auxBorrar;
									auxBorrar = NULL;
								}
								else {
									if (l->der == NULL && l->izq == NULL) {
										l = NULL;
										delete auxBorrar;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

int auxMinimo(NodoABIntDobleDato*& l) {
	if (l->izq == NULL) {
		return l->dato1;
	}
	else {
		auxMinimo(l->izq);
	}
}

int auxMaximo(NodoABIntDobleDato*& l) {
	if (l->der == NULL) {
		return l->dato1;
	}
	else {
		auxMaximo(l->der);
	}
}

void auxClon(NodoABIntDobleDato*& nueval, NodoABIntDobleDato* l) {
	auxAgregar(nueval, l->dato1);
	nueval->dato2 = l->dato2;
	if (l->der != NULL && l->izq == NULL) {
		auxClon(nueval->der, l->der);
	}
	else {
		if (l->der == NULL && l->izq != NULL) {
			auxClon(nueval->izq, l->izq);
		}
		else {
			if (l->der != NULL && l->izq != NULL) {
				auxClon(nueval->der, l->der);
				auxClon(nueval->izq, l->izq);
			}
			else {
				nueval->der = NULL;
				nueval->izq = NULL;
			}
		}
	}
}

ListaOrdInt crearListaOrdInt() {
	ListaOrdInt lista = new _cabezalListaOrdInt;
	lista->lista = NULL;
	lista->cantElem = 0;
	return lista;
}

void agregar(ListaOrdInt& l, int e) {
	auxAgregar(l->lista, e);
	l->cantElem++;
}

void borrarMinimo(ListaOrdInt& l) {
	if (!esVacia(l)) {
		borrar(l, minimo(l));
	}
}

void borrarMaximo(ListaOrdInt& l) {
	if (!esVacia(l)) {
		borrar(l, maximo(l));
	}
}

void borrar(ListaOrdInt& l, int e) {
	if (existe(l, e)) {
		auxBorrar(l->lista, e);
		l->cantElem--;
	}
}

int minimo(ListaOrdInt l) {
	assert(!esVacia(l));
	return auxMinimo(l->lista);
}

int maximo(ListaOrdInt l) {
	assert(!esVacia(l));
	return auxMaximo(l->lista);
}

bool existe(ListaOrdInt l, int e) {
	return auxExiste(l->lista, e);;
}

bool esVacia(ListaOrdInt l) {
	return l->cantElem == 0;
}

unsigned int cantidadElementos(ListaOrdInt l) {
	return l->cantElem;
}

ListaOrdInt clon(ListaOrdInt l) {
	ListaOrdInt nueval = crearListaOrdInt();
	if (l->lista == NULL) {
		return nueval;
	}
	else {
		auxClon(nueval->lista, l->lista);
		nueval->cantElem = l->cantElem;
		return nueval;
	}
}

void destruir(ListaOrdInt& l) {
	for (int i = 0; i < l->cantElem; i++) {
		borrarMinimo(l);
	}
	delete l;
	l = NULL;
}



#endif