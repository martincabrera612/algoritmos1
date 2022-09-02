#include "EjerciciosComienzo.h"

int suma(int a, int b) {
 	
    return a + b;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) {
 	// IMPLEMENTAR SOLUCION
}

void simplificar(int n, int d) {
	// IMPLEMENTAR SOLUCION
}

int ocurrencias123Repetidos(int* vector, int largo) {
    int ocurrencias = 0;
    bool sigue = false;
    for (int i = 1; i < largo-1 ; i++) {
        if (vector[i] == 2){
            if (vector[i-1] == 1 || sigue) {
                if (vector[i+1] ==3) {
                    ocurrencias ++;
                    sigue = false;
                }else if(vector[i+1] == 2) {
                    sigue = true;
                }
            }
        }
    }

	return ocurrencias;
}

int maximoNumero(unsigned int n) {
	
    int max = INT_MIN;
    int num = 0;
    for (int i =0; i < n; i++) {
        cin >> num;
        if (num > max) {
            max = num;
        }
    }
    return max;
}

void ordenarVecInt(int *vec, int largoVec) {
    if (!(largoVec == 0)) {
        for (int i = 0; i< largoVec ; i++){
            for (int j = 0; j< largoVec; j++) {
                if (vec[j] > vec[i]) {
                    int aux = vec[j];
                    vec[j] = vec[i];
                    vec[i] = aux;
                }
            }
        }
    }


}


char* invertirCase(char* str){
    int j=0;
    int largo = 0;
    while (str[j] != '\0') {
        largo++;
        j++;
    }
    
    int consAscii = 32;
    char* nuevoStr = new char[largo+1];
    
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] > 96 && str[i] < 123) {
            nuevoStr[i] = str[i] - consAscii;
        }else if (str[i] > 64 && str[i] < 91) {
            nuevoStr[i] = str[i] + consAscii;
        } else {
            nuevoStr[i] = str[i];
        }
        i++;
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
	// IMPLEMENTAR SOLUCION
	return false;
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
