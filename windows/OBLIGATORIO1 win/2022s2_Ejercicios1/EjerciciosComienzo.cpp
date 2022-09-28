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

//PRE: Recibo un array, recibo 3 enteros, donde empieza, su medio y donde termina.
//POS: Devuelvo las mitades del array mezcladas.


// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
	int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne
		= 0, // Initial index of first sub-array
		indexOfSubArrayTwo
		= 0; // Initial index of second sub-array
	int indexOfMergedArray
		= left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
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

//PRE: Recibo un vector y su largo int* vec, int largo).
//POS: Devuelvo un nuevo Vector con los elementos del vector recibido sin compartir memoria.

int* copiarVector(int* vec, int largo) {
	int* nuevoVector = new int[largo];
	for (int i = 0; i < largo; i++){
		nuevoVector[i] = vec[i];
	}
	return nuevoVector;
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
	//char** nuevoVec = new char* [largoVecStr];
	//for (int i = 0; i < largoVecStr; i++)
	//{
	//	//Tengo que dar memoria para el nuevoStr que tengo que meter.
	//	char* nuevoStr = new char[largoStr(vecStr[i])];

	//	for (int j = 0; vecStr[i][j] != '\0'; j++) {
	//		
	//	}
	//}
	
    return NULL;
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){
	int largo = l1 + l2;
		int* nuevoVector = new int[largo];

		if (largo != 0 ) {
			int cont = 0;
			for (int i = 0; i < largo; i++) {
				if (i < l1) {
					nuevoVector[i] = v1[i];
				}
				else {
					nuevoVector[i] = v2[cont];
					cont++;
				}
			}
			//mergeSort(nuevoVector, 0, largo - 1);
			ordenarVecIntMergeSort(nuevoVector, largo);
		}
		else {
			nuevoVector = NULL;
		}
		
		return nuevoVector;
}
	


bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	bool esSub = true; 
	bool* check = new bool[l1];
	if (l1 == 0) {
		esSub = true;
	}
	else {
		for (int i = 0; i < l1; i++)
		{
			check[i] = false;
			for (int j = 0; j < l2; j++) {
				if (v1[i] == v2[j]) {
					check[i] = true;
				}
			}
		}
		for (int i = 0; i < l1 ; i++) {
			if (check[i] == false) {
				esSub = false;
			}
			
		}
		
	}
	delete (check);

	return esSub;
}

char** splitStr(char* str, char separador, int &largoRet)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
	mergeSort(vector, 0, largo - 1);
}
