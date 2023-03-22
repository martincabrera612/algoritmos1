#include "EjerciciosComienzo.h"

//PRE: Recibe una cadena de char str != NULL
//POS: Retorna el largo de la cadena + 1 para el \0
int largoStr(char* str) {
	int largo = 0;
	while (*str != '\0') {
		largo++;
		str++;
	}
	return largo + 1;
}

int suma(int a, int b) {
 	
    return a+b;
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
	for (int i = 0; i < largo; i++) {
		if (vector[i] == 1 || sigue) {

			if (vector[i + 1] == 2 || sigue) {

				if (vector[i + 2] == 3) {
					ocurrencias++;
					sigue = false;
				}
				else if (vector[i + 2] == 2) {
					sigue = true;
				}
				else {
					sigue = false;
				}

			}
			else if (sigue) {
				if (vector[i + 1] == 3) {
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
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num >= max) {
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
	char* nuevaPalabra = new char[largo];  //Es una cadena necesita espacio para el caracter '\0'
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 65 && str[i] <= 90) {
			nuevaPalabra[i] = str[i] + 32;
		}
		else if (str[i] >= 97 && str[i] <= 122) {
			nuevaPalabra[i] = str[i]  - 32;
		}
		else {
			nuevaPalabra[i] = str[i];
		}
		i++;
	}
	nuevaPalabra[i] = '\0';
	return nuevaPalabra;
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

int* intercalarVector(int* v1, int* v2, int l1, int l2) {
	int* nuevoVector = l1 != 0 || l2 != 0 ? nuevoVector = new int[l1 + l2] : NULL;
	int posv1 = 0;
	int posv2 = 0;
	int posNuevo = 0;

		while (posv1 < l1 && posv2 < l2) {
			if (v1[posv1] < v2[posv2]) {
				nuevoVector[posNuevo] = v1[posv1];
				posv1++;
			}
			else {
				nuevoVector[posNuevo] = v2[posv2];
				posv2++;
			}
			posNuevo++;
		}

		while (posv1 < l1) {
			nuevoVector[posNuevo] = v1[posv1];
			posv1++;
			posNuevo++;

		}
		while (posv2 < l2) {
			nuevoVector[posNuevo] = v2[posv2];
			posv2++;
			posNuevo++;

		}
		return nuevoVector;
	
	
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
