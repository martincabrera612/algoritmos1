#include "EjerciciosComienzo.h"

//--------------------INICIO Funciones Auxiliares-----------------------------------

//PRE: Recibe un vector de char.
//POS: Devuelve el largo de la cadena recibida.
int largoStr(char* str) {
	unsigned int largo = 0;
	while(*str != '\0') {
		largo++;
		str++;
	}
	//Se le suma 1 por el caracter '\0'
	return largo + 1;
}

//PRE: Recibe un vector de int y un int largo.
//POS: Devuelve la copia del vector recibido en un nuevo vector.
int* copiaVector(int* vec, int largo) {
	int* copia = new int[largo];
	for (int i = 0; i < largo; i++)
	{
		copia[i] = vec[i];
	}
	return copia;
}


//PRE: Recibe un vector de char.
//POS: Devuelve la copia en un nuevo vector.
char* copiarStr(char* palabra) {
	int largo = largoStr(palabra);
	char* nuevo = new char[largo+1];
	for (int i = 0; i < largo; i++)
	{
		nuevo[i] = palabra[i];
	}
	nuevo[largo] = '\0';
	return nuevo;
}

//PRE:Recibe un vector de strings y su largo.
//POS:Devuelve un nuevo vector de strings siendo la copia del recibido por parametro.
char** copiaVectorStr(char** original, int largo) {
	char** nuevoVec = new char* [largo];
	for (int i = 0; i < largo; i++)
	{
		nuevoVec[i] = copiarStr(original[i]);
	}
	return nuevoVec;

}

//PRE:
//POS:
int compararPalabra(char* palabra1, char* palabra2) {
	while (*palabra1 == *palabra2) {
		if (*palabra1 == '\0') {
			return 0;
		}
		palabra1++;
		palabra2++;
	}
	return *palabra1 - *palabra2;
}


//PRE: Recibe por referencia dos cadenas de char.
//POS: Intercambia los punteros.
void intercambiar(char*& a, char*& b) {
	char* aux = a;
	a = b;
	b = aux;
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


// [2,3,2,3,1,2,3,1,1,2]
int ocurrencias123Repetidos(int* vector, int largo) {
	bool sigue = false;
	int cont = 0;
	for (int i = 0; i < largo-2; i++)
	{
		if (vector[i] == 1 || sigue) {
			if (vector[i + 1] == 2) {
				if (vector[i + 2] == 3) {
					cont++;
					sigue = false;
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
	//Bubble Sort O(n2)
    for (int i=0; i<largoVec ;i++){
        for (int j = 0; j< largoVec - i -1;j++) {
            if (vec[j] > vec[j+1]) {
                int aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }
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

	char** nuevoVector = copiaVectorStr(vecStr, largoVecStr);
	for (int i = 0; i < largoVecStr; i++)
	{
		for (int j = 0; j < largoVecStr; j++)
		{
			if (compararPalabra(nuevoVector[i], nuevoVector[j]) < 0) {
				intercambiar(nuevoVector[i], nuevoVector[j]);
			}
		}
	}

    return nuevoVector;
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){
	int* nuevo = (l1 != 0 || l2 != 0) ? new int[l1 + l2] : NULL;
	if (l1 == 0 && l2 == 0) {
		return NULL;
	}
	if (l1 == 0) {
		nuevo = copiaVector(v2, l2);
	}
	else if (l2 == 0) {
		nuevo = copiaVector(v1, l1);
	}else {
		int pos =  0;
		int i = 0;
		int j = 0;
		while (i<l1 && j<l2){
			if (v1[i] <= v2[j]) {
				nuevo[pos] = v1[i];
				i++;
			}
			else {
				nuevo[pos] = v2[j];
				j++;
			}
			pos++;
		}
		while (i < l1) {
			nuevo[pos] = v1[i];
			pos++;
			i++;
		}
		while (j < l2) {
			nuevo[pos] = v2[j];
			pos++;
			j++;
		}
	}
	return nuevo;
}

bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	int contador = 0;
	if (l1 == 0 && l2 == 0){
		return true;
	}else if (l2 != 0) {
		for (int i = 0; i < l1; i++)
		{
			bool yaEncontro = false;
			for (int j = 0; j < l2 && !yaEncontro; j++)
			{
				if (v1[i] == v2[j]) {
					contador++;
					yaEncontro = true;
				}
			}
		}
		return (l1 == 0 || contador == l1);
	}
	else {
		return false;
	}
	
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
