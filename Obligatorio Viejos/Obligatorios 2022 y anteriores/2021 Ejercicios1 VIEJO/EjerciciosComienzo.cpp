#include "EjerciciosComienzo.h"


int suma(int a, int b) {
    return  a+b;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) {
 	
}

void simplificar(int n, int d) {
	// IMPLEMENTAR SOLUCION
}

int ocurrencias123Repetidos(int* vector, int largo) {

	int cont = 0;
	bool puedeSeguir = false;
	for (int i = 0; i < largo - 2; i++)
	{
		if ((vector[i]) ==  1 || puedeSeguir) {
			if (vector[i + 1] == 2 || puedeSeguir) {
					if (vector[i + 2] == 3) {
						cont++;
						puedeSeguir = false;
					}
					else {
						if (vector[i + 2] == 2) {
							puedeSeguir = true;
						}
						else {
							puedeSeguir = false;
						}
					}
				}
			}
			
		}
		

	return cont;
}


int maximoNumero(unsigned int n) {
	int max = INT_MIN;
	int num;
	for (int j = 0; j < n; j++)
	{
		cin >> num;
		if (num > max) {
			max = num;
		}
	}

    return max;
}


void ordenarVecInt(int *vec, int largoVec) {
	if (largoVec != 0) {
		for (int i = 0; i < largoVec; i++) {
			for (int j = i+1; j < largoVec; j++)
			{
				if (vec[i] > vec[j]) {
					int aux = vec[i];
					vec[i] = vec[j];
					vec[j] = aux;
					
				}
			}
		}

	}
}

char* invertirCase(char* str)
{
	int largo = strlen(str);
	int consASCII = 32;
	char* num = new char[largo+1];
	
	int i = 0;
	while (str[i] != '\0') {
		
		if ((str[i]) > 96 && (str[i] < 123) ) {
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

char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	char** nuevoVec = new char*[largoVecStr+1];
	

	/*for (int i = 0; i < largoVecStr; i++)
	{
		int j = 0;
		while (vecStr[i][j] != '\0')
		{
			nuevoVec[i][j] = vecStr[i][j];
			j++;
		}
		
		 
	}*/

    return NULL;
}




int* intercalarVector(int* v1, int* v2, int l1, int l2){
/*
	Entrada: 
		[1, 3, 5, 6] , [2, 3, 4], 4, 3

	Resultado : 
		[1, 2, 3, 3, 4, 5, 6]

*/	int largo = l1 + l2;
	int* nuevoVec = new int[largo];
	if (largo != 0) {

		int cont = 0;
		for (int i = 0; i < largo ; i++)
		{	
			if (i < l1) {
				nuevoVec[i] = v1[i];
			}
			else {
				nuevoVec[i] = v2[cont];
				cont++;
			}
		}
		ordenarVecInt(nuevoVec, largo);
	}
	else {
		nuevoVec = NULL;
	}

	return nuevoVec;
}

bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	/*
	Prueba Subconjunto Vector 4 -> ERROR salida incorrecta
	Parametros de entrada: [2,2,2,3,54,6,7], [7,6,54,6,3,2]
	Se esperaba: true
	Se recibio:  false 

	*/
	bool resul = true;
	int cont = 0;
	int contEspecifico = 0;
	if (l1 != 0) {
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				if (v1[i] == v2[j]) {
					contEspecifico++;
				}

			}
			if (contEspecifico == 0) {
				resul = false;
			}
			else if (contEspecifico > 1) {
				cont = cont - contEspecifico;
			}
			cont = cont + contEspecifico;
			contEspecifico = 0;
		}
		
		 if (cont == l1) {
			resul = true;
		}
	}
	


	return resul;
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
