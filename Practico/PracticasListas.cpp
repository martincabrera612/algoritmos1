#include <iostream>;
using namespace std;


struct NodoLista  {
	int dato;
	NodoLista* sig;
};


//INSERTAR AL PRINCIPIO
void insertarPrincipio (NodoLista* &l, int a) {    // Muy importante el & si no, se pasa una copia y no modifica la lista
	NodoLista* nuevo = new NodoLista;
	nuevo->dato = a;
	nuevo->sig = l;
	l = nuevo;
};


//BORRAR EL PRIMERO 
void eliminarPrimero (NodoLista* &l) {
	NodoLista* aux = l;
	l = l->sig;
	delete(aux);
};

//Insertar en un posicion especifica
void insPos (NodoLista* &lm int dato, int pos) {
	if (l==NULL || pos==0) {
		NodoLista* nuevo = new NodoLista;
		nuevo->dato = dato;
		nuevo->sig = l;
		l = nuevo;
		return;
	}
	insPos(l->sig,dato,pos-1);

}



int main () {

	NodoLista* inicio = new NodoLista;
	inicio-> dato = 1;
	inicio-> sig = NULL;

	//Insertar un nuevo elemento

	NodoLista* nuevo = new NodoLista;
	nuevo-> dato = 2;

	inicio-> sig = nuevo;
	nuevo-> sig = NULL;

	//Recorrer una lista correctamente 

	NodoLista* aux = inicio;

	while (aux != NULL) {
		aux = aux ->sig;

	}


	

	return 0;
}




//Ejemplo simple 
struct NodoLista {
    int dato;
    NodoLista* sig;
};

int main() {

    //Creo la lista
    NodoLista* inicio = new NodoLista;
    inicio->dato = 1;
    inicio->sig = NULL;
    
    //Creo el nuevo nodo
    NodoLista* nuevo = new NodoLista;
    nuevo-> dato = 2;
    nuevo->sig = NULL;
    inicio->sig = nuevo; //Inserto el nuevo elemento.
    
    //Recorro la lista
    NodoLista* aux = new NodoLista; //Creo un auxiliar para no perder la referencia de donde inicia la lista
    aux = inicio;
    while (aux != NULL) { 			//Recorro hasta que termine
        cout<< aux->dato << endl;   //Muestro los datos que tiene el nodo.
        aux = aux->sig;				// Avanzo por la lista
    }
  
    cout<< inicio->dato<< endl;  // La lista sigue conteniendo sus datos
    cout<< nuevo->dato<< endl;
    cout<< "OK!"<< endl;

