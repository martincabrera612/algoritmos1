#include "MultisetInt.h"
#include "Definiciones.h"

#ifdef MULTISET_INT_IMP

struct _cabezalMultisetInt {
	NodoListaIntDobleDato* lista;
	int cantElem;
};

void msAuxAgregar(NodoListaIntDobleDato*& l, int e, unsigned int oc) {
	if (l == NULL) {
		l = new NodoListaIntDobleDato(e, oc);
	}
	else {
		if (l->dato1 == e) {
			l->dato2 = l->dato2 + oc;
		}
		else {
			if (l->dato1 > e) {
				NodoListaIntDobleDato* nodo = new NodoListaIntDobleDato(e, oc);
				nodo->sig = l;
				l = nodo;
			}
			else {
				msAuxAgregar(l->sig, e, oc);
			}
		}
	}
}

void msAuxBorrar(NodoListaIntDobleDato*& l, int e) {
	if (l->dato1 == e) {
		if (l->dato2 > 1) {
			l->dato2--;
		}
		else {
			NodoListaIntDobleDato* borrar = l;
			l = l->sig;
			borrar = NULL;
			delete borrar;
		}
	}
	else {
		if (l->sig->dato1 == e) {
			if (l->sig->dato2 > 1) {
				msAuxBorrar(l->sig, e);
			}
			else {
				NodoListaIntDobleDato* borrar = l->sig;
				l->sig = l->sig->sig;
				borrar = NULL;
				delete borrar;
			}
		}
		else {
			msAuxBorrar(l->sig, e);
		}
	}
}

bool auxPertenece(NodoListaIntDobleDato* l, int e) {
	if (l == NULL) {
		return false;
	}
	else {
		if (l->dato1 == e) {
			return true;
		}
		else {
			return auxPertenece(l->sig, e);
		}
	}
}

void msAuxClon(NodoListaIntDobleDato*& nuevams, NodoListaIntDobleDato* l) {
	msAuxAgregar(nuevams, l->dato1, l->dato2);
	if (l->sig != NULL) {
		msAuxClon(nuevams->sig, l->sig);
	}
	else {
		nuevams->sig = NULL;
	}
}

MultisetInt crearMultisetInt() {
	MultisetInt multiset = new _cabezalMultisetInt;
	multiset->lista = NULL;
	multiset->cantElem = 0;
	return multiset;
}


void agregar(MultisetInt& s, int e, unsigned int ocurrencias){
	msAuxAgregar(s->lista, e, ocurrencias);
	s->cantElem = s->cantElem + ocurrencias;
}

void borrar(MultisetInt& s, int e) {
	if (pertenece(s, e)) {
		msAuxBorrar(s->lista, e);
		s->cantElem--;
	}
}

bool pertenece(MultisetInt s, int e) {
	return auxPertenece(s->lista, e);
}

void agregarBorrar(MultisetInt& resp, MultisetInt& auxs1)
{
	agregar(resp, auxs1->lista->dato1, auxs1->lista->dato2);
	int oc = auxs1->lista->dato2;
	for (int j = 0; j < oc; j++) {
		borrar(auxs1, auxs1->lista->dato1);
	}
}

void agregarBorrar2(MultisetInt& resp, MultisetInt& auxs1, MultisetInt& auxs2)
{
	agregar(resp, auxs1->lista->dato1, auxs1->lista->dato2);
	int oc1 = auxs1->lista->dato2;
	for (int x = 0; x < oc1; x++) {
		borrar(auxs1, auxs1->lista->dato1);
	}
	int oc2 = auxs2->lista->dato2;
	for (int y = 0; y < oc2; y++) {
		borrar(auxs2, auxs2->lista->dato1);
	}
}

MultisetInt unionConjuntos(MultisetInt s1, MultisetInt s2) {
	MultisetInt resp = crearMultisetInt();
	if (esVacio(s1) && esVacio(s2)) {
		return resp;
	}
	else {
		MultisetInt auxs1 = clon(s1);
		if (!esVacio(s1) && esVacio(s2)) {
			return auxs1;
		}
		else {
			MultisetInt auxs2 = clon(s2);
			if (esVacio(s1) && !esVacio(s2)) {
				return auxs2;
			}
			else {
				while (!esVacio(auxs1) || !esVacio(auxs2)) {
					if (esVacio(auxs1)) {
						agregarBorrar(resp, auxs2);
					}
					else {
						if (esVacio(auxs2)) {
							agregarBorrar(resp, auxs1);
						}
						else {
							if (auxs1->lista->dato1 < auxs2->lista->dato1) {
								agregarBorrar(resp, auxs1);
							}
							else {
								if (auxs1->lista->dato1 > auxs2->lista->dato1) {
									agregarBorrar(resp, auxs2);
								}
								else {
									if (auxs1->lista->dato2 > auxs2->lista->dato2) {
										agregarBorrar2(resp, auxs1, auxs2);
									}
									else {
										agregarBorrar2(resp, auxs2, auxs1);
									}
								}
							}
						}
					}
				}
				return resp;
			}
		}
	}
}

void borrarCompleto(MultisetInt& auxs1)
{
	int oc = auxs1->lista->dato2;
	for (int i = 0; i < oc; i++) {
		borrar(auxs1, auxs1->lista->dato1);
	}
}

MultisetInt interseccionConjuntos(MultisetInt s1, MultisetInt s2) {
	MultisetInt resp = crearMultisetInt();
	if (esVacio(s1) || esVacio(s2)) {
		return resp;
	}
	else {
		MultisetInt auxs1 = clon(s1);
		MultisetInt auxs2 = clon(s2);
		while (!esVacio(auxs1) && !esVacio(auxs2)) {
			if (auxs1->lista->dato1 < auxs2->lista->dato1) {
				borrarCompleto(auxs1);
			}
			else {
				if (auxs1->lista->dato1 > auxs2->lista->dato1) {
					borrarCompleto(auxs2);
				}
				else {
					if (auxs1->lista->dato2 < auxs2->lista->dato2) {
						agregarBorrar2(resp, auxs1, auxs2);
					}
					else {
						agregarBorrar2(resp, auxs2, auxs1);
					}
				}
			}
		}
		return resp;
	}
}


void agregarBorrar2Cant(MultisetInt& auxs1, MultisetInt& auxs2, MultisetInt& resp)
{
	int cant = auxs1->lista->dato2 - auxs2->lista->dato2;
	agregar(resp, auxs1->lista->dato1, cant);
	int oc1 = auxs1->lista->dato2;
	for (int a = 0; a < oc1; a++) {
		borrar(auxs1, auxs1->lista->dato1);
	}
	int oc2 = auxs2->lista->dato2;
	for (int b = 0; b < oc2; b++) {
		borrar(auxs2, auxs2->lista->dato1);
	}
}

MultisetInt diferenciaConjuntos(MultisetInt s1, MultisetInt s2) {
	MultisetInt resp = crearMultisetInt();
	if (esVacio(s1) && esVacio(s2)) {
		return resp;
	}
	else {
		MultisetInt auxs1 = clon(s1);
		if (!esVacio(s1) && esVacio(s2)) {
			return auxs1;
		}
		else {
			MultisetInt auxs2 = clon(s2);
			if (esVacio(s1) && !esVacio(s2)) {
				return auxs2;
			}
			else {
				while (!esVacio(auxs1) || !esVacio(auxs2)) {
					if (esVacio(auxs1)) {
						borrarCompleto(auxs2);
					}
					else {
						if (esVacio(auxs2)) {
							agregarBorrar(resp, auxs1);
						}
						else {
							if (auxs1->lista->dato1 < auxs2->lista->dato1) {
								agregarBorrar(resp, auxs1);
							}
							else {
								if (auxs1->lista->dato1 > auxs2->lista->dato1) {
									borrarCompleto(auxs2);
								}
								else {
									if (auxs1->lista->dato2 > auxs2->lista->dato2) {
										agregarBorrar2Cant(auxs1, auxs2, resp);
									}
									else {
										if (auxs1->lista->dato2 < auxs2->lista->dato2) {
											borrarCompleto(auxs2);
											borrarCompleto(auxs1);
										}
										else {
											borrarCompleto(auxs1);
											borrarCompleto(auxs2);
										}
									}
								}
							}
						}
					}
				}
				return resp;
			}
		}
	}
}

bool contenidoEn(MultisetInt s1, MultisetInt s2) {
	if (esVacio(s1)) {
		return true;
	}
	else {
		if (esVacio(s2) || (s1->cantElem > s2->cantElem)) {
			return false;
		}
		else {
			MultisetInt auxs1 = clon(s1);
			MultisetInt auxs2 = clon(s2);
			int cant = 0;
			while (!esVacio(auxs1) && !esVacio(auxs2)) {
				if (auxs1->lista->dato1 > auxs2->lista->dato1) {
					borrarCompleto(auxs2);
				}
				else {
					if (auxs1->lista->dato1 < auxs2->lista->dato1) {
						borrarCompleto(auxs1);
					}
					else {
						if (auxs1->lista->dato2 <= auxs2->lista->dato2) {
							cant = cant + auxs1->lista->dato2;
							borrarCompleto(auxs2);
							borrarCompleto(auxs1);
						}
						else {
							break;
						}
					}
				}
			}
			if (cant == s1->cantElem) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

int elemento(MultisetInt s) {
	assert(!esVacio(s));
	return s->lista->dato1;
}

bool esVacio(MultisetInt s) {
	return s->lista == NULL;
}

unsigned int cantidadElementos(MultisetInt s) {
	return s->cantElem;
}

void destruir(MultisetInt& s) {
	for (int i = 0; i < s->cantElem; i++) {
		borrar(s, elemento(s));
	}
	s = NULL;
	delete s;
}

MultisetInt clon(MultisetInt s) {
	MultisetInt nuevams = crearMultisetInt();
	if (s->lista == NULL) {
		return nuevams;
	}
	else {
		msAuxClon(nuevams->lista, s->lista);
		nuevams->cantElem = s->cantElem;
		return nuevams;
	}
}

#endif