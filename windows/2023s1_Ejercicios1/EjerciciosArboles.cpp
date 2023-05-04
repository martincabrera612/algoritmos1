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

//PRE: Paso un arbol tipo NodoAB.
//POS: Devuelve el valor del dato maximo del arbol.
int maximoDato(NodoAB* r) {
	while (r->der) {
		r = r->der;
	}
	return r->dato;
}


void eliminar(NodoAB* &r, int dato) {
	if (!r) return;   // r == NULL
	if (r->dato == dato) {
		if (!r->izq && !r->der) {   //Caso si es hoja
			NodoAB* borro = r;
			r = NULL;
			delete borro;
		}
		else if (!r->izq && r->der) {
			NodoAB* borro = r;
			r = r->der;
			delete borro;
		}
		else if (r->izq && !r->der) {
			NodoAB* borro = r;
			r = r->izq;
			delete borro;
		}
		else {
			NodoAB* rDer = r;
			while (rDer->der->der) {
				rDer = rDer->der;
			}
			r->dato = rDer->der->dato;   //Intercambio los datos
			NodoAB* borro = rDer->der;
			rDer->der = rDer->der->izq;  //Puede no existir ->izq pero igual apunta a NULL.
			delete borro;
		}
	}
	else {
		eliminar(r->izq, dato);
		eliminar(r->der, dato);
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

void borrarNodoRaiz(NodoAB*& A) {
	if (!A->izq && !A->der) {
		NodoAB* borrar = A;
		A = NULL;
		delete borrar;
	}
	else if (!A->izq && A->der) {
		NodoAB* aux = A->der;
		A->dato = aux->dato;
		A->der = aux->der;
		A->izq = aux->izq;

	}else if(A->izq&& !A->der) {
		NodoAB* aux = A->izq;
		A->dato = aux->dato;
		A->izq = aux->izq;
		A->der = aux->der;
		
	}else if (A->izq && A->der){
		int maximo = maximoDato(A->izq);
		A->dato = maximo;
		eliminar(A->izq, maximo);
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
