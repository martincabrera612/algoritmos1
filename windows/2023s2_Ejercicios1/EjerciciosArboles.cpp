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


//------------------------ FIN FUNCIONES AUXILIARES----------------------------------


int altura(NodoAB* raiz){
	if (!raiz) return 0;
	else {
		return (altura(raiz->izq) > altura(raiz->der) ? altura(raiz->izq) : altura(raiz->der)) + 1;
	}
}

bool sonIguales(NodoAB* p, NodoAB* q) {
	// IMPLEMENTAR SOLUCION
	return false;
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

bool esArbolBalanceado(NodoAB *raiz) {
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

NodoLista* enNivel(NodoAB *a, int k) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

NodoLista* camino(NodoAB *arbol, int x) {
	NodoLista* l = NULL;
	if (!arbol) return NULL;
	else if (x > arbol->dato ) {
		 l = camino(arbol->der, x);
	}
	else if (x < arbol->dato) {
		l = camino(arbol->izq, x);
	}
	insertarPrincipio2(l, arbol->dato);
	return l; 
	
}

NodoAB* invertirHastak(NodoAB* a, int k){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void borrarNodoRaiz(NodoAB * & A) {
	 
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

void borrarPares(NodoAB* & a){
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

int sumaPorNiveles(NodoAG* raiz){
	return sumaPorNivelesAux(raiz, 1);
}

bool esPrefijo(NodoAG *a, NodoLista *l)
{
	
	return false;
}

NodoLista* caminoAG(NodoAG *arbolGeneral, int dato) {
	
	return NULL;
}

int nivelConMasNodosAG(NodoAG * arbolGeneral) {
	
	return 0;
}
