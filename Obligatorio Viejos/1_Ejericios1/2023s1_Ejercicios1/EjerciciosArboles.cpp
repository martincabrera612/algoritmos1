#include "EjerciciosArboles.h"

//PRE:Recibe por valor un arbol r de tipo NodoAB*
//POS: Retorna la cantidad de hojas en el arbol.
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

//PRE: Recibe por valor un arbol tipo NodoAB.
//POS: Devuelve el valor del dato maximo del arbol.
int maximoDato(NodoAB* r) {
	if (r) {
		if (!r->der) {
			return r->dato;
		}
		return (maximoDato(r->der));
	}
}

//PRE: Recibe un arbol por referencia tipo NodoAB y un entero dato.
//POS: Modifica el arbol, si encuentra el dato, eliminandolo del arbol.
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

//PRE:Recibe por valor un arbol r de tipo NodoAB*
//POS: Retorn la cantidad total de nodos en ese arbol.
int cantNodos(NodoAB* r) {
	if (!r){
		return 0;
	}
	else {
		return 1 + cantNodos(r->izq) + cantNodos(r->der);
	}
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

//PRE: Recibe un arbol de tipo NodoAB y un entero nivel.
//POS: Devuelve la cantidad de nodos en un nivel n.
int cantNodosPorNivel(NodoAB* r, int nivel) {
	if (r) {
		if (nivel == 0) {
			return cantNodosPorNivel(r->izq, --nivel) + cantNodosPorNivel(r->der, --nivel) + 1;
		}
		else {
			return cantNodosPorNivel(r->izq, --nivel) + cantNodosPorNivel(r->der, --nivel);
		}
	}
	else {
		return 0;
	}

}


//------------TERMINAN-FUNCIONES-AUXILIARES------------------------------
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
		return existeCaminoConSuma(raiz->der, sum - raiz->dato) || 
		existeCaminoConSuma(raiz->izq, sum - raiz->dato);
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
	int cantidad = 0;
	desde--;
	while (desde <= hasta) {
		cantidad = cantidad + cantNodosPorNivel(a, desde);
		desde++;
	}
	return cantidad;
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

int sucesor(NodoAB* a, int n){
	if (!a) {
		return -1;
	}
	if (a->dato > n) {
		int r = sucesor(a->izq, n);
		if (r != -1) {
			return r;
		}else {
			return a->dato;
		}
	}
	else {
		return sucesor(a->der, n);
	}
}



int nivelMasNodos(NodoAB* raiz, int nivelHasta) {
	if (raiz) {
		int cont = 1;
		int cantMaxima = 1;
		int maximoNivel = 1;
		int nivel = 1;
		while (nivel <= nivelHasta) {
			cont = cantNodosPorNivel(raiz, nivel);
			if (cont > cantMaxima) {
				cantMaxima = cont;
				maximoNivel = nivel;
			}
			nivel++;
		}
		return maximoNivel;
	}
	else {
		return 0;
	}
	
	
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
