#include "EjerciciosComienzo.h"

int suma(int a, int b) {
    return a + b;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) {
    for (int i = desde ; i <= hasta; i++) {
            cout << i << "*" << tablaDel << "=" << i * tablaDel  ;
        if (i != hasta) {
            cout << ';';
        }
        }
}

void simplificar(int n, int d) {
	// IMPLEMENTAR SOLUCION
}

int ocurrencias123Repetidos(int* vector, int largo) {
    

    bool sigue = true;
    int cont = 0;
    for (int i= 0; i < largo-2 ; i++) {
        if (vector[i] == 1 || sigue) {
            if (vector[i+1] == 2 || sigue) {
                if (vector[i+2] == 3) {
                    cont++;
                    sigue = false;
                }else {
                    if (vector[i+2]  == 2){
                        sigue = true;
                    }else {
                        sigue = false;
                    }
                }
            }
        }
    }
        return cont;

}
int maximoNumero(unsigned int n) {
    int num = 0;
    int max = INT_MIN;
    for (int i = 0 ; i < n; i++) {
        cin >> num;
        if (num > max) {
            max = num;
        }
    }
    return max;
}

void ordenarVecInt(int *vec, int largoVec) {
    if (largoVec != 0 ) {
        for (int j = 0;  j< largoVec; j++) {
            for (int i = 0; i < largoVec-1 ; i++) {
                if (vec[i] > vec[i+1]) {
                    int aux= vec[i+1];
                    vec[i+1] = vec[i];
                    vec[i] = aux;
                }
            }
        }
    }
}


char* invertirCase(char* str)
{   int largo = largoStr(str);
    char *nuevoStr = new char[largo+1];
    int constAscii = 32;
    for (int i = 0; str[i] != '\0';  i++) {
        if (str[i] >=65 && str[i] <=90 ) {
            nuevoStr[i] = str[i] + constAscii;
            
    }else if (str[i] >=97 && str[i] <=122) {
        nuevoStr[i] = str[i] - constAscii;
        
    }else {
        nuevoStr[i] = str[i];
    }
    }
    nuevoStr[largo] = '\0';
    
	return nuevoStr;
}

int islas(char** mapa, int col, int fil){
	// IMPLEMENTAR SOLUCION
    return 0;
}

unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{
	// IMPLEMENTAR SOLUCION
    return 0;
}

char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	// IMPLEMENTAR SOLUCION
    return NULL;
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
    bool estanTodos = false;
    int cont = 0;
    bool esta = false;
    for (int i = 0; i < l1 ; i++) {
        for (int j = 0; j< l2 && !esta; j++) {
            if (v1[i] == v2[j]) {
                esta = true;
                cont ++;
            }
        }
        esta = false;
    }
    if (cont == l1) {
        estanTodos = true;
    }
    
    return estanTodos;
	
}

char** splitStr(char* str, char separador, int &largoRet)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
	// IMPLEMENTAR SOLUCION
}


///---------------------------Funciones Auxiliares ----------------------------------------------

int largoStr (char *str) {
    int largo = 0;
    while (*str != '\0' ) {
        largo++;
        str++;
    }
    return largo;
}
