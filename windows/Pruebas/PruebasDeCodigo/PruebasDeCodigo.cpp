// PruebasDeCodigo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

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
    int largo;
    cout << "Ingrese el largo del vector: ";
    cin >> largo;
    int* vec = new int[largo];
    for (int i = 0; i < largo; i++) {
        cout << "Ingrese el valor de la posicion " << i << ": ";
        int num;
        cin >> num;
        vec[i] = num;
    }
    for (int i = 0; i < largo; i++)
    {
        cout << "vec[" <<i<<"] es: " << vec[i] << endl;
    }
   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
