#include <iostream>
using namespace std;

struct NodoLista {
    int dato;
    NodoLista* sig;
};

NodoLista* crearLista (int n){
    NodoLista* l = NULL;
    while (n>0){
        NodoLista* nuevo = new NodoLista;
        nuevo->dato = n;
        nuevo->sig = l;
        l = nuevo;
        n--;
    }
    return l;
};

void imprimirLista (NodoLista* l){
    cout << "(";
    while (l!= NULL){
        cout << l->dato << ",";
        l = l->sig;
    }
    cout << ")";
    cout<< "" << endl; 
};
void eliminar(NodoLista* &l, int cont){
    if (l!= NULL){
        while (cont > 0 ) {
    		NodoLista* borrar = l->sig;
    		l = borrar->sig;
    		delete borrar;
    		cont--;
    	}
    }
}

int main() {
    // Write C++ code here
    
    NodoLista* l = crearLista(10);
    NodoLista* aux = l;
    while (aux->dato != 5){
        aux = aux->sig;
    }
    cout << aux->dato << endl;
    NodoLista* prev = aux;
    cout << prev->dato << endl;
    imprimirLista(l);
    eliminar(l,3);
    imprimirLista(l);
    
    return 0;
}


// ------------OUTPUT--------------
// 5
// 5
// (1,2,3,4,5,6,7,8,9,10,)
// (7,8,9,10,)



//------------2do caso------------------
int main() {
    // Write C++ code here
    
    NodoLista* l = crearLista(10);
    NodoLista* aux = l;
    while (aux->dato != 5){
        aux = aux->sig;
    }
    cout << aux->dato << endl;
    NodoLista* prev = aux;
    cout << prev->dato << endl;
    imprimirLista(l);
    eliminar(prev,3);
    imprimirLista(l);
    
    return 0;
}
// ------------OUTPUT--------------

// 5
// 5
// (1,2,3,4,5,6,7,8,9,10,)
// Segmentation fault


// Read access violation