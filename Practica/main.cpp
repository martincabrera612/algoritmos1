#include <iostream>
using namespace std;


struct NodoLista {
	int dato;
	NodoLista* sig;
};


struct NodoAB {
	int dato;
	NodoAB* izq;
	NodoAB* der;
};

void crearArbol (NodoAB* &a, int n){
	if (n >=0){
		NodoAB* r = new NodoAB;
		r->dato = n;
		r->izq = a->izq;
		r->der = a->der;
		a = r;
	}else {
		crearArbol(a, --n); 
	}
};


int main(){

	NodoAB* r = new NodoAB;
	r->izq = NULL;
	r->der = NULL;
	crearArbol (r, 5);\
	cout << "Hola Mundo" << endl;
	return 0;
}