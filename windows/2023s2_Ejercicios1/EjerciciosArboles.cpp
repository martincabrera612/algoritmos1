#include "EjerciciosArboles.h"

//------------------------ FUNCIONES AUXILIARES----------------------------------

//PRE: Recibe una lista por referencia y un entero
//POS: Modifica la lista insertando el dato al comienzo de la misma.
void insertarPrincipio2(NodoLista*& l, int dato) {
	NodoLista* nuevo = new NodoLista;
	nuevo->dato = dato;
	nuevo->sig = l;
	l = nuevo;
}


//Recibe un nodoAG y un entero.
//Devuelve la suma de los valores de los niveles pares restando los valores de niveles impares.
int sumaPorNivelesAux(NodoAG* raiz, int altura) {
	if (!raiz) return 0;
	int valor = (altura % 2) == 0 ? raiz->dato : raiz->dato * -1;
	int sumaHijo = sumaPorNivelesAux(raiz->ph, altura + 1);
	int sumaHermano = sumaPorNivelesAux(raiz->sh, altura);

	return sumaHijo + sumaHermano + valor;
}

//PRE: Recibe por valor un arbol tipo nodo AB.
//POS: Devuelve el maximo dato del arbol.
int maximoDato(NodoAB* raiz) {
	if (raiz) {
		if (!raiz->der) {
			return raiz->dato;
		}
		return maximoDato(raiz->der);
	}
}

//PRE: Recibe un arbol tipo NodoAB por referencia y un entero dato.
//POS: Modifica el arbol eliminando el dato en caso de ser encontrado.
void eliminarDato(NodoAB*& r, int dato) {
	if (!r) return;
	if (r->dato == dato) {
		if (!r->izq && !r->der) {
			NodoAB* aBorrar = r;
			r = NULL;
			delete aBorrar;
		}
		else if (r->izq && !r->der) {
			NodoAB* aBorrar = r;
			r = r->izq;
			delete aBorrar;
		}
		else if (!r->izq && r->der) {
			NodoAB* aBorrar = r;
			r = r->der;
			delete aBorrar;
		}
		else {
			NodoAB* rDer = r;
			while (rDer = rDer->der->der) {
				rDer = rDer->der;
			}
			r->dato = rDer->der->dato;
			NodoAB* aBorrar = rDer->der;
			rDer->der = rDer->der->izq;
			delete aBorrar;
		}
	}
	else {
		eliminarDato(r->izq, dato);
		eliminarDato(r->der, dato);
	}
}



//PRE: Recibe un NodoAG y un entero.
//POS: Devuelve la cantidad de nodos que hay en ese nivel.
int cantNodosAG(NodoAG* r, int nivel) {
	if (!r || nivel < 1) {
		return 0;
	}
	if (nivel == 1) {
		return 1 + cantNodosAG(r->sh, nivel);
	}
	return cantNodosAG(r->ph, nivel - 1) + cantNodosAG(r->sh, nivel);
}

//------------------------ FIN FUNCIONES AUXILIARES----------------------------------


int altura(NodoAB* raiz) {
	if (!raiz) return 0;
	else {
		return (altura(raiz->izq) > altura(raiz->der) ? altura(raiz->izq) : altura(raiz->der)) + 1;
	}
}

bool sonIguales(NodoAB* p, NodoAB* q) {
	if (!p && !q) {
		return true;
	}
	if ((p && !q) || (!p && q)) {
		return false;
	}
	return p->dato == q->dato && sonIguales(p->izq, q->izq) &&
		sonIguales(p->der, q->der);
}

bool existeCaminoConSuma(NodoAB* raiz, int sum) {
	if (!raiz) return (0 == sum);
	else {
		if (!raiz->izq && raiz->der) {
			existeCaminoConSuma(raiz->der, sum - raiz->dato);
		}
		else if (raiz->izq && !raiz->der) {
			existeCaminoConSuma(raiz->izq, sum - raiz->dato);
		}
		else {
			return existeCaminoConSuma(raiz->izq, sum - raiz->dato) ||
				existeCaminoConSuma(raiz->der, sum - raiz->dato);
		}
	}
}

bool esArbolBalanceado(NodoAB* raiz) {
	if (!raiz) return true;
	int altIzq = altura(raiz->izq);
	int altDer = altura(raiz->der);

	if (abs(altIzq - altDer) > 1) {
		return false;
	}
	else {
		return esArbolBalanceado(raiz->izq) || esArbolBalanceado(raiz->der);
	}

}

NodoLista* enNivel(NodoAB* a, int k) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

NodoLista* camino(NodoAB* arbol, int x) {
	NodoLista* l = NULL;
	if (!arbol) return NULL;
	else if (x > arbol->dato) {
		l = camino(arbol->der, x);
	}
	else if (x < arbol->dato) {
		l = camino(arbol->izq, x);
	}
	insertarPrincipio2(l, arbol->dato);
	return l;

}

NodoAB* invertirHastak(NodoAB* a, int k) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void borrarNodoRaiz(NodoAB*& A) {
	if (!A->izq && !A->der) {
		NodoAB* aBorrar = A;
		A = NULL;
		delete aBorrar;
	}
	else if (A->izq && !A->der) {
		NodoAB* aux = A->izq;
		A->dato = aux->dato;
		A->izq = aux->izq;
		A->der = aux->der;
	}
	else if (!A->izq && A->der) {
		NodoAB* aux = A->der;
		A->dato = aux->dato;
		A->izq = aux->izq;
		A->der = aux->der;
	}
	else if (A->izq && A->der) {
		int max = maximoDato(A->izq);
		A->dato = max;
		eliminarDato(A->izq, max);
	}
}

bool sumaABB(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

int sucesor(NodoAB* a, int n)
{
	if (!a) return -1;
	if (a->dato > n) {
		int r = sucesor(a->izq, n);
		if (r == -1) {
			return a->dato;
		}
		else {
			return r;
		}
	}
	else {
		return sucesor(a->der, n);
	}
}

int nivelMasNodos(NodoAB* raiz, int nivelHasta) {

	return 0;
}

void borrarPares(NodoAB*& a) {
	// IMPLEMENTAR SOLUCION
}

int alturaAG(NodoAG* raiz)
{
	if (!raiz) {
		return 0;
	}
	int alturaHijos = alturaAG(raiz->ph) + 1;
	int alturaHermanos = alturaAG(raiz->sh);
	return alturaHijos > alturaHermanos ? alturaHijos : alturaHermanos;
}

int sumaPorNiveles(NodoAG* raiz) {
	return sumaPorNivelesAux(raiz, 1);
}

bool esPrefijo(NodoAG* a, NodoLista* l)
{

	return false;
}

NodoLista* caminoAG(NodoAG* arbolGeneral, int dato) {

	return NULL;
}

int nivelConMasNodosAG(NodoAG* arbolGeneral) {
	int alturaR = alturaAG(arbolGeneral);
	int nivel = 0;
	int cant = 0;
	if (!arbolGeneral) return 0;
	while (alturaR != 0) {
		int cantNivel = cantNodosAG(arbolGeneral, alturaR);
		if (cant <= cantNivel) {
			cant = cantNivel;
			nivel = alturaR;
		}
		alturaR--;
	}
	return nivel;
}
