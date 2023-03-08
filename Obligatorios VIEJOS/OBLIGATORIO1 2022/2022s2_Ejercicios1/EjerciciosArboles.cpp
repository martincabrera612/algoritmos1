#include "EjerciciosArboles.h"

//PRE: Recibe un nodo de un arbol y su nivel.
//POS: Devuelve la suma por niveles.

int sumNiveles(NodoAG* raiz, int nivel) {
	if (raiz == NULL) return 0;
	if (nivel % 2 == 0) {
		return sumNiveles(raiz->ph, nivel + 1) + raiz->dato + sumNiveles(raiz->sh, nivel);
	}
	else {
		return sumNiveles(raiz->ph, nivel + 1) - raiz->dato + sumNiveles(raiz->sh, nivel);
	}
}

int altura(NodoAB* raiz){
	if (raiz == NULL) return 0;
	else {
		return 1 + max(altura(raiz->izq), altura(raiz->der));
	}
}

bool sonIguales(NodoAB* p, NodoAB* q) {
	// IMPLEMENTAR SOLUCION
	return false;
}

bool existeCaminoConSuma(NodoAB* raiz, int sum) {
	if (raiz != NULL) {
		if (raiz->izq == NULL && raiz->der != NULL) {
			existeCaminoConSuma(raiz->der, sum - raiz->dato);
		}
		else if (raiz->izq != NULL && raiz->der == NULL) {
			existeCaminoConSuma(raiz->izq, sum - raiz->dato);
		}
		else {
			return existeCaminoConSuma(raiz->der, sum - raiz->dato) || existeCaminoConSuma(raiz->izq, sum - raiz->dato);

		}
	}
	else {
		return sum == 0;
	}
	
}

bool esArbolBalanceado(NodoAB *raiz) {
	if (raiz == NULL) {
		return true;
	} 
	int diferencia = altura(raiz->izq) - altura(raiz->der);
	if (abs(diferencia) > 1) {
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
	if (arbol == NULL) return NULL; 
	NodoLista* l = NULL;
	if (arbol->dato > x) {
		l = camino(arbol->izq, x);
	}
	else if (arbol->dato < x) {
		l = camino(arbol->der, x);
	}
	NodoLista* nodo = new NodoLista;
	nodo->dato = arbol->dato;
	nodo->sig = l;
	l = nodo;
	
}

NodoAB* invertirHastak(NodoAB* a, int k){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void borrarNodoRaiz(NodoAB * & A) {
	// IMPLEMENTAR SOLUCION
}

bool sumaABB(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

int sucesor(NodoAB* a, int n)
{

	return 0;
}

int nivelMasNodos(NodoAB* raiz, int nivelHasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

void borrarPares(NodoAB* & a){
	// IMPLEMENTAR SOLUCION
}

int alturaAG(NodoAG* raiz)
{
	// IMPLEMENTAR SOLUCION
	return 0;
}



int sumaPorNiveles(NodoAG* raiz){
	int nivel = 1;
	if (raiz == NULL) return 0;
	return sumNiveles(raiz, nivel);
	
}

bool esPrefijo(NodoAG *a, NodoLista *l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

NodoLista* caminoAG(NodoAG *arbolGeneral, int dato) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int nivelConMasNodosAG(NodoAG * arbolGeneral) {
	// IMPLEMENTAR SOLUCION
	return 0;
}
