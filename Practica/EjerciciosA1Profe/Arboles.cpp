#include "Arboles.h"
#include "Listas.h"

using namespace std;

struct NodoAB {
	int dato;
	NodoAB* izq;
	NodoAB* der;
	NodoAB() : dato(0), izq(NULL), der(NULL) {}
	NodoAB(int d) : dato(d), izq(NULL), der(NULL) {}
};

void imprimirPreOrder(NodoAB* r) {
	if (r) {
		cout << r->dato << " ";
		imprimirPreOrder(r->izq);
		imprimirPreOrder(r->der);
	}
}

void imprimirInOrder(NodoAB* r) {
	if (r) {
		imprimirInOrder(r->izq);
		cout << r->dato << " ";
		imprimirInOrder(r->der);
	}
}

void imprimirInOrderDer(NodoAB* r) {
	if (r) {
		imprimirInOrderDer(r->der);
		cout << r->dato << " ";
		imprimirInOrderDer(r->izq);
	}
}

void imprimirPosOrder(NodoAB* r) {
	if (r) {
		imprimirPosOrder(r->izq);
		imprimirPosOrder(r->der);
		cout << r->dato << " ";
	}
}

// Pre: r != NULL
int minimoAB(NodoAB* r) {
	assert(r != NULL);
	if (!r->izq && !r->der) { // r->izq == NULL &&  r->der == NULL
		return r->dato;
	}
	else if (r->izq && !r->der) {
		int minIzq = minimoAB(r->izq);
		return r->dato > minIzq ? minIzq : r->dato;
	}
	else if (!r->izq && r->der) {
		int minDer = minimoAB(r->der);
		return r->dato > minDer ? minDer : r->dato;
	}
	else {
		int minIzq = minimoAB(r->izq);
		int minDer = minimoAB(r->der);

		int minRec = minIzq > minDer ? minDer : minIzq;

		return r->dato > minRec ? minRec : r->dato;
	}
}

// Pre: r != NULL
int minimoABB(NodoAB* r) {
	assert(r != NULL);
	if (!r->izq) {
		return r->dato;
	}
	else {
		return minimoABB(r->izq);
	}
}

// Pre: r != NULL
int maximoABB(NodoAB* r) {
	assert(r != NULL);
	if (!r->der) {
		return r->dato;
	}
	else {
		return maximoABB(r->der);
	}
}

void transformarABBAListaOrdenadaAux(NodoAB* r, NodoLista* &l) {
	if (r) {
		transformarABBAListaOrdenadaAux(r->der, l);
		insertarAlPrincipio(l, r->dato);
		transformarABBAListaOrdenadaAux(r->izq, l);
	}
}

NodoLista* transformarABBAListaOrdenada(NodoAB* r) {
	NodoLista* resultado = NULL;
	/*if (r) {
		NodoLista* listaIzq = transformarABBAListaOrdenada(r->izq);
		NodoLista* listaDer = transformarABBAListaOrdenada(r->der);
		insertarAlPrincipio(listaDer, r->dato);
		concatenarListas(listaIzq, listaDer);
		resultado = listaIzq;
	}*/
	transformarABBAListaOrdenadaAux(r, resultado);
	return resultado;
}

bool sonIguales(NodoAB* p, NodoAB* q) {
	if (!p && !q) return true;
	if ((!p && q) || (p && !q)) return false; // (!p || !q) ~ !(p && q)
	return p->dato == q->dato && sonIguales(p->izq, q->izq) && sonIguales(p->der, q->der);
}

void pruebasArboles() {
	//// Op 1
	//NodoAB* nuevo = new NodoAB;
	//nuevo->izq = NULL;
	//nuevo->der = NULL;
	//nuevo->dato = 5;

	// Op 2
	NodoAB* nuevo = new NodoAB(5);

	//// Op 3
	//NodoAB* nuevo = new NodoAB();
	//nuevo->dato = 5;

	nuevo->izq = new NodoAB(6);
	nuevo->izq->izq = new NodoAB(7);
	nuevo->izq->der = new NodoAB(9);

	nuevo->der = new NodoAB(3);
	nuevo->der->izq = new NodoAB(2);
	nuevo->der->der = new NodoAB(1);

	/*
	* Es UN AB pero no un ABB
			5
		  /   \
		 6     3
		/ \   / \
	   7   9 2   1
	*/
	// Op 2
	NodoAB* nuevoABB = new NodoAB(5);

	nuevoABB->izq = new NodoAB(2);
	nuevoABB->izq->izq = new NodoAB(1);
	nuevoABB->izq->der = new NodoAB(3);

	nuevoABB->der = new NodoAB(7);
	nuevoABB->der->izq = new NodoAB(6);
	nuevoABB->der->der = new NodoAB(9);

	/*
		Es UN AB y ABB
			5
		  /   \
		 2     7
		/ \   / \
	   1   3 6   9
	*/
	cout << "imprimirPreOrder" << endl;
	imprimirPreOrder(nuevoABB);

	cout << endl << "imprimirInOrder" << endl;
	imprimirInOrder(nuevoABB);

	cout << endl << "imprimirInOrderDer" << endl;
	imprimirInOrderDer(nuevoABB);

	cout << endl << "imprimirPosOrder" << endl;
	imprimirPosOrder(nuevoABB);

	cout << endl << "MinimoABB: " << minimoABB(nuevoABB) << endl;
	cout << "MaximoABB: " << maximoABB(nuevoABB) << endl;

	cout << "MinimoAB: " << minimoAB(nuevo) << endl;
	cout << "MinimoAB con un ABB: " << minimoAB(nuevoABB) << endl;

	mostrarListaInterativo("transformarABBAListaOrdenada: ", transformarABBAListaOrdenada(nuevoABB));

	cout << "No son iguales: " << (!sonIguales(nuevo, nuevoABB) ? "Si" : "No") << endl;
	cout << "Son iguales: " << (sonIguales(nuevo, nuevo) ? "Si" : "No") << endl;
}