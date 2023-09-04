#include "EjerciciosComienzo.h"

//--------------------INICIO Funciones Auxiliares-----------------------------------

//PRE: Recibe un vector de char
//POS: Devuelve el largo de la cadena recibida
int largoStr(char* str) {
	unsigned int largo = 0;
	while(*str != '\0') {
		largo++;
		str++;
	}
	//Se le suma 1 por el caracter '\0'
	return largo + 1;
}


//--------------------FIN de Funciones Auxiliares-----------------------------------

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
	int largo = largoStr(str);
	char* nuevo = new char[largo];
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] > 64 && str[i] < 91) {
			nuevo[i] = str[i] + 32;
		}
		else if (str[i] > 96 && str[i] < 123) {
			nuevo[i] = str[i] - 32;
		}
		else {
			nuevo[i] = str[i];  
		}
		i++;
	}
	nuevo[i] = '\0';
	return nuevo;
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
	
	//int i = 0;
	//if (v1[i] < v2[i]) {
	//	nuevo[i] = v1;
	//	v1[i++];   //se avanze en el vector q se puso el numero;
	//}
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
