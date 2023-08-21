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
	bool sigue = false;
	int cont = 0;
	for (int i = 0; i < largo-2; i++)
	{
		if (vector[i] == 1 || sigue) {
			if (vector[i + 1] == 2) {
				if (vector[i + 2] == 3) {
					cont++;
				}
				else if (vector[i + 2] == 2) {
					sigue = true;
				}
				else {
					sigue = false;
				}
			}
		}
	}
	
	return cont;
}

int maximoNumero(unsigned int n) {
	int num = 0;
	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
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
	// IMPLEMENTAR SOLUCION
	return NULL;
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
