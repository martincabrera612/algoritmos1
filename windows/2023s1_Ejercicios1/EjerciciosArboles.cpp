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
	if (r) {
		while (r->der) {
			r = r->der;
		}
		return r->dato;
	}
	
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

int cantNodos(NodoAB* r) {
	if (!r){
		return 0;
	}
	else {
		return 1 + cantNodos(r->izq) + cantNodos(r->der);
	}
}

int cantNodosPorNivel(NodoAB* r, int nivel) {
	int cont = 0;
	if (!r) return 0;
	if (nivel == 1) {
		if (!r->izq && r->der || r->izq && !r->der) {
			cont++;
		}
		else if (r->izq && r->der) {
			cont = cont + 2;
		}
	}
	else {
		cantNodosPorNivel(r->izq, --nivel);
		cantNodosPorNivel(r->der, --nivel);
	}
	return cont;
}

//PRE: Recibe un arbol AG y un n haciendo referencia al nivel del arbol.
//POS: Devuelve la suma por nivel del arbol
int sumaPorNivelesaux(NodoAG* raiz, int n) {
	if (raiz == NULL) {
		return 0;
	}if (n % 2 == 0) {
		return sumaPorNivelesaux(raiz->ph, n + 1) + raiz->dato + sumaPorNivelesaux(raiz->sh, n);
	}
	else {
		return sumaPorNivelesaux(raiz->ph, n + 1) - raiz->dato + sumaPorNivelesaux(raiz->sh, n);
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
	int maximoValor = maximoDato(a);
	if (maximoValor <= n) {
		return -1;
	}
	else {
	
		if (a == NULL) {
			return INT_MAX;
		}
		else if (a->dato <= n) {
			return sucesor(a->der, n);
		}
		else {
			return min(a->dato, sucesor(a->izq, n));
		}
	}
	
	

}

int nivelMasNodos(NodoAB* raiz, int nivelHasta) {
	if (!raiz)return 0;
	if (!raiz->izq && !raiz->der || nivelHasta == 1) {
		return 1;
	}
	int cont = 0;
	int maximo = 0;
	int cantNodosIzq = 0;
	int cantNodosDer = 0;

	if (cont <= nivelHasta) {
		cantNodosIzq = cantNodos(raiz->izq);
		cantNodosDer = cantNodos(raiz->der);
		
	}
	
	else {
		nivelMasNodos(raiz->izq, --nivelHasta);
		nivelMasNodos(raiz->der, --nivelHasta);
	}
	return maximo;
}

void borrarPares(NodoAB* & a){
	// IMPLEMENTAR SOLUCION
}

int alturaAG(NodoAG* raiz)
{
	int ret = 0;
	if (raiz != NULL) {
		int alturaPH = 1 + alturaAG(raiz->ph);
		int alturaSH = alturaAG(raiz->sh);
		if (alturaPH > alturaSH) {
			ret = alturaPH;
		}
		else {
			ret = alturaSH;
		}
	}
	return ret;
	
}

int sumaPorNiveles(NodoAG* raiz){
	int nivel = 1;
	if (raiz == NULL) {
		return 0;
	}
	return sumaPorNivelesaux(raiz, nivel);
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
