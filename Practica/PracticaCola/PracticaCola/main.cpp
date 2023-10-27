//
//  main.cpp
//  PracticaCola
//
//  Created by Martin Cabrera on 25/10/23.
//

#include <iostream>
#include "Cola.h"
using namespace std;

void almacenoDatosEnLaColaEimprimoOrdenados(Cola c){
    cout << endl << "INICIO almacenoDatos e Imprimo" << endl;
    int cant;
    cin >> cant;
    Cola c = crearCola();
    for(int i=0; i<cant; i++){
        int dato;
        cin >> dato;
        encolar(c, dato);
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
