#include <iostream>;
using namespace std;


struct NodoLista  {
	int dato;
	NodoLista* sig;
};


void crear(NodoLista* &lista, int cantMultiplo) {
	if (cantMultiplo < 1) { //CASO BASE 
		return;
	}
	NodoLista nuevo = new NodoLista(cantMultiplo * 2);  //Usamos constructor por default nuevo->sig = NULL;


	crear(lista->sig, cantMultiplo - 1);

}

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
}







    void insertarOrdenado(NodoLista*& l, int dato) {
	NodoLista* nuevo = new NodoLista;
	nuevo->dato = dato;
	nuevo->sig = NULL;

	if (l = NULL) {
		l = nuevo;
	}
	else if (dato < l->dato) {
		nuevo-> sig = l;
		l = nuevo;
	}
	else {
		NodoLista* temp = l;
		while (temp->sig != NULL && dato > temp->sig->dato) {
			temp = temp - sig;
		}
		nuevo->sig = temp->sig;
		temp->sig = nuevo;
	}


	// INSERTAR ORDENADO RECURSIVO
	  void insertarOrdenado(NodoLista*& l, int dato) {
	  	if (l == NULL || l->dato = dato){
	  		NodoLista* nuevo = new NodoLista(dato);   
	  		nuevo->sig = l;               //Insertar al principio
	  		l = nuevo;
	  	}else {
	  		insertarOrdenado(l->sig, dato)
	  	}


	void insertarFinal(NodoLista* &l, int dato) {
		if (l==NULL) {
			NodoLista* nuevo = new NodoLista(dato);
			l = nuevo;
		}else {
			insertarFinal(l->sig, dato);
		}
	}


	void insertarAlFinal(NodoLista* &l, NodoLista* fin, int dato) {
		NodoLista* nuevo = new NodoLista(dato);
		if (l==NULL) {
			l = nuevo;
			fin = l;
		}else {
			fin->sig = nuevo;
			fin = nuevo;  
		}
	}

NodoLista* intercIter(NodoLista* l1, NodoLista* l2) {
	 	NodoLista* nuevo = NULL;
	 	if (!l1 && !l2) {
	 		return nuevo;
	 	}
	 	NodoLista* aux1 = l1;
	 	NodoLista aux2 = l2;
	 	while (aux1 && aux2){  //Es lo mismo que poner aux1 != NULL && aux2 != NULL
	 		if (aux1->dato > aux2->dato){
	 			insertarAlFinal(nuevo,fin, aux2->dato);
	 			aux2 = aux2->sig;
	 		}else {
	 			insertarAlFinal(nuevo, fin, aux1->dato);
	 			aux1 = aux1->sig;
	 		}
	 	}
	 	while (aux1){ //Si quedo algo
	 		insertarAlFinal(nuevo,fin, aux1->dato);
	 		aux1 = aux1->sig;
	 	}
	 	while (aux2){ //Si quedo algo
	 		insertarAlFinal(nuevo,fin, aux2->dato);
	 		aux2 = aux2->sig;
	 	}
	 	return nuevo;
 }

//INSERTAR EN POSICION:

 void insertarPos(NodoLista* &l, int dato, int pos) {
 	NodoLista* nuevo = new NodoLista;
 	nuevo->dato;
 	nuevo->sig = NULL;

 	if (pos<= 0 || !l) {             //Si es vacia o pos 0 ,inserto al principio
 		nuevo->sig = l;
 		l = nuevo;
 	}
 	else {
 		NodoLista* temp = l;
 		int contador = 0;
 		while (temp != NULL && contador < pos-1) {   //Avanzo hasta la posicion correcta
 			temp = temp->sig;
 			contador++;
 		}
 		if (temp != NULL) {						//Intercambio los punteros
 			nuevo->sig = temp->sig;
 			temp->sig = nuevo;
 		}
 	}
 }

