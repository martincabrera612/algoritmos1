#include <iostream>
#include <stdio.h>
using namespace std;

int largoStr(char* str) {
    unsigned int largo = 0;
    while (*str != '\0') {
        largo++;
        str++;
    }
    //Se le suma 1 por el caracter '\0'
    return largo + 1;
}

char* copiarStr(char* palabra) {
    int largo = largoStr(palabra);
    char* nuevo = new char[largo];
    for (int i = 0; i < largo; i++)
    {
        nuevo[i] = palabra[i];
    }
    nuevo[largo] = '\0';
    return nuevo;
}

char** copiaVectorStr(char** original, int largo) {
    char** nuevoVec = new char* [largo];
    for (int i = 0; i < largo; i++)
    {
        nuevoVec[i] = copiarStr(original[i]);
    }
    return nuevoVec;
}


void intercambiar(char*& a, char*& b) {
    char* aux = a;
    a = b;
    b = aux;
}


int main() {

    char* cadena = new char[5];
    cadena[0] = 'H';
    cadena[1] = 'O';
    cadena[2] = 'L';
    cadena[3] = 'A';
    cadena[4] = '\0';
    char* nuevo = copiarStr(cadena);

    char* cadena2 = new char[7];
    cadena2[0] = 'T';
    cadena2[1] = 'I';
    cadena2[2] = 'E';
    cadena2[3] = 'R';
    cadena2[4] = 'R';
    cadena2[5] = 'A';
    cadena2[6] = '\0';

    char* cadena3 = new char[7];
    cadena3[0] = 'A';
    cadena3[1] = 'R';
    cadena3[2] = 'R';
    cadena3[3] = 'I';
    cadena3[4] = 'B';
    cadena3[5] = 'A';
    cadena3[6] = '\0';


    char** vectorStr = new char*[3];
    vectorStr[0] = cadena;
    vectorStr[1] = cadena2;
    vectorStr[2] = cadena3;
    cout << "Esta es la original: ";
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        cout << cadena[i];
    }
    cout << "\n";


    cout << "Esta es la copia: ";
    for (int i = 0; nuevo[i] != '\0'; i++)
    {
        cout << nuevo[i];
    }
    cout << '\n';


    cout << "Vector Original: <" << &vectorStr << endl;
    for (int i = 0; i< 3; i++)
    {
        int largoPalabra = largoStr(vectorStr[i]);
        for (int j = 0; j < largoPalabra; j++)
        {
            cout << vectorStr[i][j];
        }
        cout << "-> " << &vectorStr[i] << ", ";
         
    }
    cout << "| \n";

    char** nuevoVec = copiaVectorStr(vectorStr, 3);


    cout << "Esta es la copia del vectorStr: " << &nuevoVec << endl;
    for (int i = 0; i < 3; i++)
    {
        int largoPalabra = largoStr(nuevoVec[i]);
        for (int j = 0; j < largoPalabra; j++)
        {
            cout << nuevoVec[i][j];
        }
        cout << "-> "<< &nuevoVec[i] << ", ";

    }
    cout << "| \n";
   

}