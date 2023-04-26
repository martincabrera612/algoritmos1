#include "EjerciciosComienzo.h"
// Martin Cabrera Nro. Est: 185091


//PRE: Recibe una cadena de tipo char*.
//POS: Devuelve un int con el largo de la cadena.
int largoString(char* cadena) {
	int largo = 0;
	for (int i = 0; cadena[i] != '\0'; i++)
	{
		largo++;
	}
	return largo;
}

//PRE:Recibe un vector tipo char*.
//POS: Devuelve una nueva copia de ese vector.
char* copiarStr(char * str) {
	int largo = largoString(str);
	char* copia = new char[largo+1];
	for (int i = 0; i < largo; i++)
	{
		copia[i] = str[i];
	}
	copia[largo + 1] = '\0';
	return copia;
}


//PRE: Recibe un vector de vectores de tipo char**.
//POS: Devuelve una nueva copia del vector de vectores.
char** copiarVecStr(char** vecStr, int largo) {
	char** nuevoVector = new char* [largo];
	for (int i = 0; i < largo; i++)
	{
		nuevoVector[i] = copiarStr(vecStr[i]);
	}


	return nuevoVector;
}



//PRE: Recibe dos cadenas de tipo char*.
//POS: Devuelve un valor de tipo bool, segun la comparacion de las cadenas por criterio de la tabla ASCII. 
bool esMenor(char* s1, char* s2) {
	int largo;
	if (largoString(s1) > largoString(s2)) {
		largo = largoString(s2);
	}
	else {
		largo = largoString(s1);
	}
	bool s1EsMenor = false;
	bool distinto = false;
	for (int i = 0; i < largo && !distinto; i++) {
		if (s1[i] > s2[i]) {
			distinto = true;
			s1EsMenor = true;
		}
		else if (s1[i] < s2[i]) {
			distinto = true;
			s1EsMenor = false;
		}

	}
	return s1EsMenor;
}

//PRE: Se pasa por referencia dos variables de tipo int.
//POS: Intercambia los valores de las variables recibidas.
void intercambiar(int &v1, int &v2) {
	int aux = v1;
	v1 = v2;
	v2 = aux;
}

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


void desocultarIsla(char** mapa, int col, int fil) {
	for (int i = 0; i < col; i++){
		for (int j = 0; j < fil; j++){
			if (mapa[i][j] == 'X') { 
				mapa[i][j] = 'T'; 
			}
		}
	}
}


void ocultarIsla(char** mapa, int i, int j, int col, int fil) {
	//nos fuimos de los limites o agua
	if (i < 0 || i >= col || j < 0 || j >= fil || mapa[i][j] != 'T') return;
		//estoy en una posicion valida  y es tierra 
		mapa[i][j] = 'X';

		for (int k = -1; k <= 1; k++) {
			for (int l = -1; l <= 1; l++)
			{
				if (k == 0 && l == 0) continue; //opcional
				ocultarIsla(mapa, i + k, j + l, col, fil);
			}
		}
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
	//Algoritmo BubbleSort
	for (int i = 0; i < largoVec - 1; i++) {
		for (int j = 0; j < largoVec-i-1; j++)
		{
			if (vec[j] > vec[j + 1]) {
				intercambiar(vec[j], vec[j + 1]);
			}
		}
	}
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
	int contador = 0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < fil; j++){
			if (mapa[i][j] == 'T') {

				ocultarIsla(mapa, i, j, col, fil);
				contador++;
				//aca sigue, no termine
			}
		}
	}
	desocultarIsla(mapa, col, fil);
	return contador;

}

unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{
	// IMPLEMENTAR SOLUCION
    return 0;
}

char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	char** nuevoVector = new char* [largoVecStr];
	for (int i = 0; i < largoVecStr; ++i)
	{
		for (int j = 0; i < largoVecStr; ++i)
		{
			if (esMenor(vecStr[i], vecStr[j])) {
				nuevoVector[i] = vecStr[i];
			}
			
		}
	}
	
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
	int contador = 0;
	bool yaEncontro = false;
	if (l1 == 0) return true;
	for (int i = 0; i < l1; i++)
	{
		for (int j = 0; j < l2; j++)
		{
			if (v1[i] == v2[j] && !yaEncontro) {
				contador++;
				yaEncontro = true;
			}
		}
		yaEncontro = false;
	}
	if (contador == l1) {
		return true;
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
