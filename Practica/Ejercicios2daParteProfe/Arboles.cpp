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

void transformarABBAListaOrdenadaAux(NodoAB* r, NodoLista*& l) {
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

bool buscarAB(NodoAB* r, int valor) {
	if (!r) return false;
	if (r->dato == valor) return true;

	return buscarAB(r->izq, valor) || buscarAB(r->der, valor);
}

bool buscarABB(NodoAB* r, int valor) {
	if (!r) return false;

	while (r) {
		if (r->dato == valor) return true;
		if (r->dato > valor) r = r->izq;
		if (r->dato < valor) r = r->der;
	}

	return false;
}

// Hwk modificar la funcion para que me devuelva un booleano en caso de que borre o no
void borrarEnAB(NodoAB*& r, int valor) {
	if (!r) return; // r == NULL
	if (r->dato == valor)
	{
		if (!r->izq && !r->der) {
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
		else { // r->der && r->izq
			NodoAB* aux = r;
			while (aux->izq->izq) {
				aux = aux->izq;
			}
			NodoAB* borro = aux->izq;
			int datoQueNoQueremosBorrar = aux->izq->dato;
			aux->izq = aux->izq->der;
			delete borro;

			r->dato = datoQueNoQueremosBorrar;
		}
	}
	else {
		borrarEnAB(r->der, valor);
		borrarEnAB(r->izq, valor);
	}
}

// Hwk modificar la funcion para que me devuelva un booleano en caso de que borre o no
void borrarEnABB(NodoAB*& r, int valor) {
	if (!r) return; // r == NULL
	if (r->dato == valor)
	{
		if (!r->izq && !r->der) {
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
		else { // r->der && r->izq
			NodoAB* aux = r->der;
			if (!r->der->izq)
			{
				int datoQueNoQueremosBorrar = aux->dato;
				NodoAB* borro = r->der;
				r->der = r->der->der;
				delete borro;
				r->dato = datoQueNoQueremosBorrar;
			}
			else {
				while (aux->izq->izq) {
					aux = aux->izq;
				}
				NodoAB* borro = aux->izq;
				int datoQueNoQueremosBorrar = aux->izq->dato;
				aux->izq = aux->izq->der;
				delete borro;

				r->dato = datoQueNoQueremosBorrar;
			}
		}
	}
	else if (r->dato > valor)
	{
		borrarEnABB(r->izq, valor);
	}
	else { // r->dato < valor
		borrarEnABB(r->der, valor);
	}
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

	cout << "Existe en AB?" << (buscarAB(nuevo, 6) ? "Si" : "No") << endl;
	cout << "Existe en AB?" << (buscarAB(nuevo, 20) ? "Si" : "No") << endl;
	cout << "Existe en ABB?" << (buscarAB(nuevoABB, 6) ? "Si" : "No") << endl;
	cout << "Existe en ABB?" << (buscarAB(nuevoABB, 20) ? "Si" : "No") << endl;

	/*
	* Es UN AB pero no un ABB
			5
		  /   \
		 6     3
		/ \   / \
	   7   9 2   1
	*/
	cout << "imprimirInOrder luego de borrar AB" << endl;
	imprimirInOrder(nuevo);
	cout << endl;
	borrarEnAB(nuevo, 6);
	imprimirInOrder(nuevo);
	cout << endl;
	borrarEnAB(nuevo, 5);
	imprimirInOrder(nuevo);
	cout << endl;
	borrarEnAB(nuevo, 1);
	imprimirInOrder(nuevo);

	/*
		Es UN AB y ABB
			5
		  /   \
		 2     7
		/ \   / \
	   1   3 6   9
	*/
	cout << endl << "imprimirInOrder luego de borrar ABB" << endl;
	imprimirInOrder(nuevoABB);
	cout << endl;
	borrarEnABB(nuevoABB, 6);
	imprimirInOrder(nuevoABB);
	cout << endl;
	borrarEnABB(nuevoABB, 5);
	imprimirInOrder(nuevoABB);
	cout << endl;
	borrarEnABB(nuevoABB, 1);
	imprimirInOrder(nuevoABB);
}