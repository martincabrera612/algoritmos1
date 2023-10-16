#include "Listas.h"

struct NodoLista {
	int dato;
	int dato2;
	NodoLista* sig;
	NodoLista* ant;
	NodoLista() : dato(0), sig(NULL) {}
	NodoLista(int d) : dato(d), sig(NULL) {}
};
//typedef NodoLista* Lista;


//Pre y pos
void insertarAlPrincipio(NodoLista*& l, int dato) {
	//Forma 1
	NodoLista* nuevo = new NodoLista;
	nuevo->sig = NULL;
	nuevo->dato = dato;

	////Forma 2
	//NodoLista* nuevo = new NodoLista(dato);

	////Forma 3
	//NodoLista* nuevo = new NodoLista();
	//nuevo->dato = dato;

	nuevo->sig = l;
	l = nuevo;

	////Paso 1 (Asumimos q dato == 0)
	//l-> 1-> 2-> 3 -> NULL

	//nuevo -> 0 -> NULL
	//
	////Paso 2
	//nuevo -> 0 -> 1 -> 2-> 3->NULL

	////Paso 3
	//l -> 0 -> 1-> 2-> 3->NULL
}

int largoLista(NodoLista* l) {
	int largo = 0;
	while (l) {
		largo++;
		l = l->sig;
	}
	return largo;
}


void insertarFinalIterativo(NodoLista*& l, int dato) {
	NodoLista* nuevo = new NodoLista(dato);
	if (l == NULL) {
		l = nuevo;
	}
	else {
		NodoLista* aux = l;
		while (aux->sig) { // aux->sig != NULL
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

void insertarFinalRecursiva(NodoLista*& l, int dato) {
	if (l == NULL) {
		NodoLista* nuevo = new NodoLista(dato);
		l = nuevo;
	}
	else {
		insertarFinalRecursiva(l->sig, dato);
	}
}

void insertarFinalConstante(NodoLista*& principio, NodoLista*& final, int dato) {
	// TODO: Homework :D
}

void mostrarListaRec(NodoLista* l) {
	if (l == NULL) {
		return;
	}
	cout << l->dato << " ";
	mostrarListaRec(l->sig);
}

void mostrarListaInterativo(const char* titulo, NodoLista* l) {
	cout << titulo << " ";
	while (l) {
		if (l->sig == NULL) {
			cout << l->dato << " -> NULL" << endl;
		}
		else {
			cout << l->dato << " -> ";
		}
		l = l->sig;
	}
}

void insertarOrdenadoIterativo(NodoLista*& l, int dato) {
	if (!l || l->dato >= dato) {
		insertarAlPrincipio(l, dato);
	}
	else {
		NodoLista* nuevo = new NodoLista(dato);
		NodoLista* aux = l;
		while (aux->sig && aux->sig->dato < dato) { // aux->sig != NULL
			aux = aux->sig;
		}
		nuevo->sig = aux->sig;
		aux->sig = nuevo;
	}
}


void insertarOrdenadoRecursivo(NodoLista*& l, int dato) {
	if (!l || l->dato >= dato) {
		insertarAlPrincipio(l, dato);
	}
	else {
		insertarOrdenadoRecursivo(l->sig, dato);
	}
}

void borrarPrincipio(NodoLista*& l) {
	if (l) {
		NodoLista* borro = l;
		l = l->sig;
		delete borro;
	}
}

void borrarFinIterativo(NodoLista*& l) {
	if (l) {
		if (!l->sig) {
			borrarPrincipio(l);
		}
		else {
			NodoLista* aux = l;
			while (aux->sig->sig) {
				aux = aux->sig;
			}
			NodoLista* borro = aux->sig;
			aux->sig = NULL;
			delete borro;
		}
	}
}

void concatenarListas(NodoLista*& l1, NodoLista*& l2) {
	if (!l1) {
		l1 = l2;
	}
	else {
		concatenarListas(l1->sig, l2);
	}
}

NodoLista* concat(NodoLista*& l1, NodoLista* l2) {
	if (!l1) return l2;
	else {
		NodoLista* aux = l1;
		while (aux->sig) {
			aux = aux->sig;
		}
		aux->sig = l2;
		return l1;
	}
}

void insertarAlFinal(NodoLista*& l, NodoLista*& fin, int dato) {
	NodoLista* nuevo = new NodoLista;
	nuevo->dato = dato;
	nuevo->sig = NULL;
	if (l == NULL) {
		l = nuevo;
		fin = l;
	}
	else {
		fin->sig = nuevo;
		fin = nuevo;
	}
}

void eliminarSecuencia(NodoLista*& l, NodoLista* secuencia)
{
	int largoSec = largoLista(secuencia);
	int cont = 0;
	bool cambiaPos = true;
	if (l && secuencia) {
		NodoLista* lista = l;
		NodoLista* sec = secuencia;
		NodoLista* inicioSec = l; // auxiliar borrar hasta posicion (slice js)
		int pos = 0;
		int empieza = 0;
		while (lista && sec) {
			if (lista->dato == sec->dato) {
				cont++;
				if (cambiaPos) {
					inicioSec = lista;
					empieza = pos;
				}
				cambiaPos = false;
				sec = sec->sig;
			}
			else {
				cont = 0;
				cambiaPos = true;
				sec = secuencia;
			}
			if (cambiaPos) {
				inicioSec = inicioSec->sig;
			}
			lista = lista->sig;
			pos++;
		}
		if (cont == largoSec) {
			sec = secuencia;

		}

	}
}

void pruebasDeListas() {
	NodoLista* miLista = NULL;
	NodoLista* secuencia = NULL;
	NodoLista* miLista2 = NULL;

	insertarFinalIterativo(miLista, 1);
	insertarFinalIterativo(miLista, 3);
	insertarFinalIterativo(miLista, 4);

	mostrarListaInterativo("insertarFinalIterativo", miLista);

	insertarFinalRecursiva(miLista2, 6);
	insertarFinalRecursiva(miLista2, 7);
	insertarFinalRecursiva(miLista2, 10);

	mostrarListaInterativo("Lista: ", miLista2);
	mostrarListaInterativo("Lista: ", concat(miLista, miLista2));


	// insertarFinalIterativo(secuencia, 3);
	// insertarFinalIterativo(secuencia, 4);
	//mostrarListaInterativo("Secuencia: ", secuencia);

	//eliminarSecuencia(miLista, secuencia);
	//mostrarListaInterativo("Lista: ", miLista);

	//insertarOrdenadoIterativo(miLista, 5);
	//insertarOrdenadoIterativo(miLista, 8);

	//mostrarListaInterativo("insertarOrdenadoIterativo", miLista);

	//insertarOrdenadoRecursivo(miLista, 2);
	//insertarOrdenadoRecursivo(miLista, 9);

	//mostrarListaInterativo("insertarOrdenadoRecursivo", miLista);

	//borrarPrincipio(miLista);

	//mostrarListaInterativo("borrarPrincipio", miLista);

	//borrarFinIterativo(miLista);
	//borrarFinIterativo(miLista);

	//mostrarListaInterativo("borrarFinIterativo", miLista);
}