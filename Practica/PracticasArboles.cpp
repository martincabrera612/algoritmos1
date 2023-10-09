#include<iostream>;
using namespace std;

struct NodoAB {
	int dato;
	NodoAB* izq;
	NodoAB* der;
};


struct NodoAG {
	int dato;
	NodoAG* ph;
	NodoAG* sh;
};


int cantHojas (NodoAB* r){
	if (r == NULL) {
		retrun 0;
	}else if (r->izq == NULL && r->der == NULL) {
		return 1;
	}else {
		return cantHojas(r->izq) + cantHojas (r->der);
	}
}


NodoAB* espejo(NodoAB* r) {
	if (r == NULL) {
		return NULL;
	}else {
		NodoAB* resultado = new NodoAB(r->dato);
		resultado->izq = espejo(r->der);
		resultado->der = espejo(r->izq);

		return resultado;
	}
	
}


//SUPONIENDO QUE YA TENGO LA FUNCION CONCAT
NodoLista* arbolEnLista (NodoAB* r) {
	if (r == NULL){
		return NULL;
	}
	NodoLista* nuevo = new NodoLista (r->dato);
	nuevo->sig = arbolEnLista(r->izq);
	NodoLista*  listaDer = arbolEnLista(r->der);

	return concat(nuevo, listaDer);
}

//Buscar un dato en el arbol
bool buscar(NodoAB* r, int dato) {
	if (!r){     //r == NULL
		return false;
	}
	if (r->dato == dato) {
		return true;
	}
	return buscar((r->izq, dato) || buscar(r->der, dato));
}

//Si es un ABB , si es un arbol binario (ordenado: menor a la izquierda y mayor a la derecha).
//Peor caso Orden N = O(n)
bool buscar(NodoAB* r, int dato){
	bool resultado = false;
	if (r){ 		//r != NULL

		if (r->dato == dato) {
			resultado = true;
		}else if (r->dato > dato) {
			resultado = buscar(r->izq, dato);
		}else {
			resultado = buscar(r->der, dato);
		}
	}    
	return resultado;                  
}


//PRE: Es un arbol ABB
bool buscarItr (NodoAB* r, int dato) {
	bool resultado = false;
	NodoAB* aux = r;
	while (aux != NULL && !resultado){
		if (aux->dato == dato){
			resultado = true;
		}else if (aux->dato > dato){
			aux = aux->izq;
		}else{
			aux = aux->der;
		}
	}
	return resultado;
}


//PRE: Si es un ABB
int minimo (NodoAB* r){
	while (r->izq){
		r = r->izq;
	}
	return r->dato;
}

void eliminar (NodoAB* &r, int dato){
	if (!r) return;   // r == NULL
	if (r->dato == dato) {
		if (!r->izq && !r->der) {   //Caso si es hoja
			NodoAB* borro = r;
			r = NULL;
			delete borro;
		}else if (!r->izq && r->der) {
			NodoAB* borro = r;
			r = r->der;
			delete borro;
		}else if (r->izq && !r->der) {
			NodoAB* borro = r;
			r = r->izq;
			delete borro;
		}else {
			NodoAB* rDer = r;
			while (rDer->der->der) {
				rDer = rDer->der;
			}
			r->dato = rDer->der->dato;   //Intercambio los datos
			NodoAB* borro = rDer->der;
			rDer->der = rDer->der->izq;  //Puede no existir ->izq pero igual apunta a NULL.
			delete borro;
		}
	}else {
		eliminar(r->izq, dato);
		eliminar(r->der, dato);
	}
}


// Eliminar en ABB   borrarNodo raiz
void eliminar(NodoAB* &r, int dato){
	if (!r){
		return;
	}
	if (r->dato == dato){
		if (esHoja(r)){
			eliminarMaximo(r);
		}else if (r->izq && r->der){           
			int maximo = maximo(r->izq);
			r->dato = maximo;
			eliminarMaximo(r->izq);
		}
	}else if(r->dato > dato){
		eliminar(r->izq, dato);
	}else {
		eliminar(r->der, dato);
	}
}



NodoLista* hAux(AG a){
	if (!a){
		return NULL;
	}
	NodoLista* b = hAux(a->sh);
	NodoLista* n = new NodoLista;
	n->dato = a->dato;
	n->sig = b;
	return n;
}

NodoList* hijos (NodoAG* A, int e){
	if (!A) {
		return NULL;
	}
	if (A->dato == e){
		return hAux(A->ph);
		else {
			NodoLista* bPh = hijos (A->ph, e);
			return bPh != NULL ? bPh : hijos(A->sh,e);
		}
	}
}



int sucesor (NodoAB* a, int n){
	if (!a){
		return INT_MAX;
	}
	if (a->dato > n){
		int r = sucesor(a->izq,n);
		return r != INT_MAX ? r : a->dato;
	}else {
		return sucesor(a->der,n);
	}
}

NodoAG* padre (NodoAG* a, int x){
	if (!a){
		return NULL;
	}
	if (a->dato == x){
		return a;
	}
	NodoAG* bPh = padre(a->ph,x);
	if (!bPh) {
		return padre (a->sh, x);

	}
	if (bPh->dato == x){
		return a;
	}
	return bPh;
}


int cantNodos(NodoAB* r) {
	if (!r) return 0;
	return 1 + cantNodos(r->izq) + cantNodos(r->der);

}


int main(){
	return 0;
}


//sucesor
	if (!a) {
		return -1;
	}
	if (a->dato > n) {
		int r = sucesor(a->izq, n);
			return r != -1 ? r : a->dato;
	}
	else {
		return sucesor(a->der, n);
	}



 // *	EJERCICIO OBLIGATORIO
// PRE: recibe un arbol binario
// POS: Retorna el nivel con mas nodos, desde el nivel 1 hasta nivelHasta.	 
// 	 En caso de que el árbol sea vacio se debera retornar cero.
// 	 Ante un empate debera retornar el número de nivel mas pequeño.
// 	 NOTA: Esta operación se puede realizar en O(n).

///cantNodosPorNivel
	/*int cont = 0;
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
	return cont;*/

intnodos(AG t){
	if (t == NULL) return 0;
	else return nodos(t->pH)+nodos(t->sH)+1;
}

void printNivel (NodoAB* a, unsigned int i){
	if (a && i>0){
		if (i==1) {
			cout << a->dato;
		}else {
			printNivel(a->izq, i-1);
			printNivel(a->der, i-1);
		}
	}
}

int maxAB (NodoAB* a){
	if(!a->izq && !a->der ){
		return a->dato;
	}else if (!a->der ) {
		int maxIzq = maxAB(a->izq);
		return maxIzq > a->dato ? maxIzq : a->dato;
	}else if (!a->izq){
		int maxDer = maxAB(a->der);
		return maxDer > a->dato ? maxDer: a->dato;
	}else {
		int maxIzq = maxAB(a->izq);
		int maxDer = maxAB(a->der);
		return maxIzq > maxDer ? (maxIzq > a->dato ? maxIzq : a->dato) : 
				(maxDer > a->dato ? maxDer : a->dato) ; 
	}
}

NodoLista* caminoAB (NodoAB* a){          //Devuelvo una lista de nodos del camino mas largo
	if (!a) {
		return NULL;
	}else {
		NodoLista* nodo = new NodoLista;
		nodo->dato = a->dato;
		if (!a->izq && !a->der){
			nodo->sig = NULL;
			return nodo;
		}else{
			nodoLista* caminoIzq = caminoAB(a->izq);
			nodoLista* caminoDer = caminoAB(a->der);
			if (largo(caminoIzq) > largo(caminoDer)) { 
				nodo->sig = caminoIzq;
				borrarLista(caminoDer);
			}else {
				nodo->sig = caminoDer;
				borrarLista(caminoIzq);
			}
			return nodo;
	}
}