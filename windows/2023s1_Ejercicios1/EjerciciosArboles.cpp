#include "EjerciciosArboles.h"


int cantHojas(NodoAB* r) {
	if (r == NULL) {
		return 0;
	}
	else  if(!r->izq && !r->der ){
		return 1;
	}
	else {
		return cantHojas(r->izq) + cantHojas(r->der);
	}
}


//------------TERMINAN FUNCIONES AUXLIARES------------------------------
int altura(NodoAB* raiz){
	if (!raiz)return 0;
	if (raiz) {
		int altIzq =  altura(raiz->izq);
		int altDer = altura(raiz->der);
		return 1 + max(altIzq, altDer);

	}
}

bool sonIguales(NodoAB* p, NodoAB* q) {
	// IMPLEMENTAR SOLUCION
	return false;
}

bool existeCaminoConSuma(NodoAB* raiz, int sum) {
	bool existe = false;
	int suma = 0;
	if (!raiz) return (0 == sum);
	if (raiz->izq && !raiz->der) {
		existeCaminoConSuma(raiz->izq, sum - raiz->dato);
	}
	else if (!raiz->izq && raiz->der) {
		existeCaminoConSuma(raiz->der, sum - raiz->dato);
	}
	else {
		return existeCaminoConSuma(raiz->der, sum - raiz->dato) || existeCaminoConSuma(raiz->izq, sum - raiz->dato);
	}
}

bool esArbolBalanceado(NodoAB *raiz) {
	if (!raiz) return true;
	int alturaIzq = altura(raiz->izq);
	int alturaDer = altura(raiz->der);
	if ((abs(alturaIzq - alturaDer)) > 1){
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
	if (!arbol) return NULL;
	NodoLista* l = NULL;
	if (x < arbol->dato) {
		l = camino(arbol->izq, x);
	}
	else if (x > arbol->dato) {
		l = camino(arbol->der, x);
	}
	NodoLista* nuevo = new NodoLista(arbol->dato);
	nuevo->sig = l;
	l = nuevo;
		
	
	return l;
}

NodoAB* invertirHastak(NodoAB* a, int k){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void borrarNodoRaiz(NodoAB * & A) {
	if (!A->izq && !A->der) {
		NodoAB* borro = A;
		A = NULL;
		delete borro;
	}
	else if() {

	}
}

bool sumaABB(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

int sucesor(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
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
	// IMPLEMENTAR SOLUCION
	return 0;
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
