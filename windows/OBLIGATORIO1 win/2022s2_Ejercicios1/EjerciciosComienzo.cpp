#include "EjerciciosComienzo.h"



//PRE: Recibo una cadena de caracteres (char* str).
//POS: Devuelvo un entero con el largo del string recibido.
unsigned int largoStr(char* str) {
	unsigned int cont = 0;
	while (str[cont] != '\0') {
		cont++;
	}
	return cont;
}


//PRE: Recibo un string (char* str)
//POS: Devuelvo una nueva copia sin compartir memoria del string recibido por parametro.
char* copiarStr(char* str) {
	unsigned int largo = largoStr(str) + 1;
	char* nuevoStr = new char[largo];
	for (int i = 0; i < largo; i++) {
		nuevoStr[i] = str[i];
	}
	return nuevoStr;
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
	for (int i = 1; i < largo - 1; i++) {
		if (vector[i] == 2) {
			if (vector[i - 1] == 1 || sigue) {
				if (vector[i + 1] == 3) {
					ocurrencias++;
					sigue = false;
				}
				else if (vector[i + 1] == 2) {
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
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num > max) {
			max = num;
		}
	}
	return max;
}

void ordenarVecInt(int *vec, int largoVec) {
	if (!(largoVec == 0)) {
		for (int i = 0; i < largoVec; i++) {
			for (int j = 0; j < largoVec; j++) {
				if (vec[j] > vec[i]) {
					int aux = vec[j];
					vec[j] = vec[i];
					vec[i] = aux;
				}
			}
		}
	}
}


char* invertirCase(char* str)
{
	int largo = strlen(str);
	int consASCII = 32;
	char* num = new char[largo + 1];

	int i = 0;
	while (str[i] != '\0') {

		if ((str[i]) > 96 && (str[i] < 123)) {
			num[i] = str[i] - consASCII;
		}
		else if (str[i] > 64 && str[i] < 91) {
			num[i] = str[i] + consASCII;
		}
		else {
			num[i] = str[i];
		}
		i++;
	}
	num[largo] = '\0';

	return num;
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

char** ordenarVecStrings(char** vecStr, int largoVecStr) 
{	
	//Al momento de ordenar tengo que intercambiar los punteros.
	// Usar ordenarVecInt pero cambiar la forma de comparar. Hacer una funcion que comparar strings y dice cual es menor
	//Creo nuevo vector
	char** nuevoVec = new char* [largoVecStr];
	for (int i = 0; i < largoVecStr; i++)
	{
		//Tengo que dar memoria para el nuevoStr que tengo que meter.
		char* nuevoStr = new char[largoStr(vecStr[i])];

		for (int j = 0; vecStr[i][j] != '\0'; j++) {
			
		}
	}
	
    return nuevoVec;
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){
	int* nuevoVector = new int[l1 + l2];
	

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
