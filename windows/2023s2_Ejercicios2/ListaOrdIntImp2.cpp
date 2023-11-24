#include "ListaOrdInt.h"
#include "Definiciones.h"
#ifdef LISTA_ORD_INT_IMP_2

struct _cabezalListaOrdInt {
	NodoABIntDobleDato* r;
	int cantidadElementos;
};


//---------------------Funciones Auxiliares---------------

//PRE: -
//POS: Agrega un nuevo elemento al arbol, si ya existe, aumenta su ocurrencia.
void agregarAux(NodoABIntDobleDato*& r, int e) {
	if (r) {
		if (e < r->dato1) {
			if (!r->izq || e > r->izq->dato1) {
				NodoABIntDobleDato* nuevo = new NodoABIntDobleDato;
				nuevo->dato1 = e;
				nuevo->dato2 = 1;
				NodoABIntDobleDato* aux = r->izq;
				r->izq = nuevo;
				nuevo->izq = aux;
			}
			else {
				agregarAux(r->izq, e);
			}
		}
		else if (e > r->dato1) {
			if (!r->der || e < r->der->dato1) {
				NodoABIntDobleDato* nuevo = new NodoABIntDobleDato;
				nuevo->dato1 = e;
				nuevo->dato2 = 1;
				NodoABIntDobleDato* aux = r->der;
				r->der = nuevo;
				nuevo->der = aux;
			}
			else {
				agregarAux(r->der, e);
			}
		}
		else {
			r->dato2++;
		}
	}
	else {
		r = new NodoABIntDobleDato;
		r->dato1 = e;
		r->dato2 = 1;
	}
}

//PRE: -
//POS: Devuelve el NodoAB con el menor dato.
NodoABIntDobleDato* minimoNodo(NodoABIntDobleDato* r) {
	if (!r->izq) {
		return r;
	}
	else {
		return minimoNodo(r->izq);
	}
}

//PRE: -
//POS: Borra el elemento que coincida con e, si no lo encuentra no tiene efecto
void borrarAux(NodoABIntDobleDato*& r, int e) {
	if (r) {
		if (e < r->dato1) {
			borrarAux(r->izq, e);
		}
		else if (e > r->dato1) {
			borrarAux(r->der, e);
		}
		else {
			if (r->dato2 == 1) {
				if (!r->izq && !r->der) {
					NodoABIntDobleDato* aBorrar = r;
					r = NULL;
					delete aBorrar;
				}
				else if (!r->izq && r->der) {
					NodoABIntDobleDato* aBorrar = r;
					r = r->der;
					delete aBorrar;
					r = NULL;
				}
				else if (r->izq && !r->der) {
					NodoABIntDobleDato* aBorrar = r;
					r = r->izq;
					delete aBorrar;
					r = NULL;
				}
				else {
					NodoABIntDobleDato* menor = minimoNodo(r->der);
					r->dato1 = menor->dato1;
					r->dato2 = menor->dato2;
					NodoABIntDobleDato* aBorrar = menor;
					menor = menor->der;
					delete aBorrar;
				}
			}
			else {
				r->dato2--;
			}
		}
	}

}

//PRE: - 
//POS: Devuelve el minimo dato del arbol.

int minimoAux(NodoABIntDobleDato* r) {
	if (r) {
		if (!r->izq) {
			return r->dato1;
		}
		return minimoAux(r->izq);
	}
}

//PRE: - 
//POS: Devuelve el maximo dato del arbol.

int maximoAux(NodoABIntDobleDato* r) {
	if (r) {
		if (!r->der) {
			return r->dato1;
		}
		return maximoAux(r->der);
	}
}

//PRE: - 
//POS: Devuelve true si encuentra una ocurrencia del dato e en el arbol.
bool existeAux(NodoABIntDobleDato* r, int e) {
	if (r) {
		if (r->dato1 == e) {
			return true;
		}
		else {
			if (e < r->dato1) {
				return existeAux(r->izq, e);
			}
			if (e > r->dato1) {
				return existeAux(r->der, e);
			}
		}
	}
	else {
		return false;
	}
}

//PRE:
//POS:
void clonAux(NodoABIntDobleDato*& nueva, NodoABIntDobleDato* l) {
	agregarAux(nueva, l->dato1);
	nueva->dato2 = l->dato2;
	if (l->izq && l->der) {
		clonAux(nueva->izq, l->izq);
		clonAux(nueva->der, l->der);
	}
	else if (!l->izq && l->der) {
		clonAux(nueva->der, l->der);
	}
	else if (l->izq && !l->der) {
		clonAux(nueva->izq, l->izq);
	}
	else {
		nueva->izq = NULL;
		nueva->der = NULL;
	}
}
//------------------------------------------------------------------


ListaOrdInt crearListaOrdInt() {
	ListaOrdInt lista = new _cabezalListaOrdInt;
	lista->r = NULL;
	lista->cantidadElementos = 0;
	return lista;
}

void agregar(ListaOrdInt& l, int e) {
	agregarAux(l->r, e);
	l->cantidadElementos++;
}

void borrarMinimo(ListaOrdInt& l) {
	if (l) {
		borrar(l, minimo(l));
	}
}

void borrarMaximo(ListaOrdInt& l) {
	if (l) {
		borrar(l, maximo(l));
	}
}

void borrar(ListaOrdInt& l, int e) {
	borrarAux(l->r, e);
	l->cantidadElementos--;
}

int minimo(ListaOrdInt l) {
	assert(!esVacia(l));
	return minimoAux(l->r);
}

int maximo(ListaOrdInt l) {
	assert(!esVacia(l));
	return maximoAux(l->r);
}

bool existe(ListaOrdInt l, int e) {
	return existeAux(l->r, e);
}

bool esVacia(ListaOrdInt l) {
	return l->cantidadElementos;
}

unsigned int cantidadElementos(ListaOrdInt l) {
	return l->cantidadElementos;
}

ListaOrdInt clon(ListaOrdInt l) {
	ListaOrdInt nueva = crearListaOrdInt();
	if (l->r) {
		clonAux(nueva->r, l->r);
		nueva->cantidadElementos = l->cantidadElementos;
	}
	return nueva;
}

void destruir(ListaOrdInt& l) {
	while (l->cantidadElementos != 0) {
		borrarMinimo(l);
	}
	delete l;
	l = NULL;
}



#endif