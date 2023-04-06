// PebasDeCodigo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int largoString(char* cadena) {
    int largo = 0;
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        largo++;
    }
    return largo;
}


bool esMayor(char* s1, char* s2) {
    int largo;
    if (largoString(s1) > largoString(s2)) {
        largo = largoString(s2);
    }
    else {
        largo = largoString(s1);
    }
    bool s1EsMenor = false;
    bool distinto= false;
    for (int i = 0; i < largo && !distinto; i++) {
            if (s1[i] > s2[i]) {
                distinto = true;
                s1EsMenor = true;
            }
            else if (s1[i] < s2[i]) {
                distinto = true;
                s1EsMenor = false;
            }
        
    }
    return s1EsMenor;
}


int main()
{
    cout << "Hello World!\n";
    //int x = 5; 
    //int y = 10;
    //
    //int* ptr = &x;

    //cout << x << endl;
    //cout << y << endl;
    //cout << " La direccion de x es: "<<  ptr << endl;
    //cout << &x << endl;  //Es lo mismo que la linea de arriba
    //cout << "El valor de x es: "<< *ptr << endl;
    //cout <<"El puntero ptr esta almacenado en la direccion: "<< &ptr << endl;
  /*  int vector[5] = { 10,24,3,1,12 };
    for (int i = 0; i < 5; i++)
    {
        cout << vector[i] << endl;
    }*/
    //int largo;
    //cout << "Ingrese el largo del vector: ";
    //cin >> largo;
    //int* vec = new int[largo];
    //for (int i = 0; i < largo; i++) {
    //    cout << "Ingrese el valor de la posicion " << i << ": ";
    //    int num;
    //    cin >> num;
    //    vec[i] = num;
    //}
    //for (int i = 0; i < largo; i++)
    //{
    //    cout << "vec[" <<i<<"] es: " << vec[i] << endl;
    //}
    
    char* cadena = new char [4];
    cadena[0] = 'h';
    cadena[1] = 'o';
    cadena[2] = 'l';
    cadena[3] = 'a';
    cadena[4] = '\0';

    char** vectorS = new char* [1];
    vectorS[0] = cadena;
    
    char* cadena2 = new char[4];
    cadena2[0] = 'c';
    cadena2[1] = 'a';
    cadena2[2] = 's';
    cadena2[3] = 'a';
    cadena2[3] = 'a';
    cadena2[3] = 'a';
    cadena2[4] = '\0';
    
    cout<< largoString(cadena) << endl;
    cout << esMayor(cadena, cadena2)<< endl;



}

