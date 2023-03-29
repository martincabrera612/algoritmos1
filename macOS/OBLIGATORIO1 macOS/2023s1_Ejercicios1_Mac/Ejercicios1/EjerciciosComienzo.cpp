#include "EjerciciosComienzo.h"
//PRE: Recibe una cadena de char* str
//POST: Devuelve el largo de esa cadena
int largoStr (char * str) {
    int largo = 0;
    while (*str != '\0') {
        largo ++;
        str++;
    }
    return largo;
}

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
    bool sigue =false;
    for (int i = 0; i< largo; i++) {
        if (vector[i]==1 || sigue) {
            
            if (vector[i+1] == 2 || sigue) {
                
                if (vector[i+2] == 3) {
                    ocurrencias++;
                    sigue =false;
                }else if (vector[i+2] ==2) {
                    sigue = true;
                }else {
                    sigue = false;
                }
                
            }else if (sigue) {
               if (vector[i+1] == 3){
                   ocurrencias++;
                   sigue = false;
               }sigue = false;
            }
        }
    }
    
    return ocurrencias;
}

int maximoNumero(unsigned int n) {
    int max = INT_MIN;
    for (int i = 0 ; i< n ; i++) {
        int num;
        cin >> num;
        if (num > max) {
            max = num;
        }
    }
    return max;
}

void ordenarVecInt(int *vec, int largoVec) {
	// IMPLEMENTAR SOLUCION
}


char* invertirCase(char* str)
{
    int largo = largoStr(str);
    char* nuevoStr = new char[largo];
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] > 64 && str[i] < 91) {
            nuevoStr[i] = str[i] + 32;
        }else if (str[i] > 96 && str[i] < 123) {
            nuevoStr[i] = str[i] - 32;
        }else {
            nuevoStr[i] = str[i];
        }
        i++;
    }
    nuevoStr[i] = '\0';
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
    char** nuevoVec = new char*[largoVecStr];
    
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
