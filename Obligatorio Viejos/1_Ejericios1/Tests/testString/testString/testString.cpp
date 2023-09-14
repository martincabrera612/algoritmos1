
#include <iostream>
#include <stdio.h>
using namespace std;

void mostrarStr(char* str) {
	int i = 0;
	while (str[i] != '\0') {
		cout << str[i];
		i++;
	}
	cout << endl;

}

unsigned int largoStr(char* str) {
	unsigned int cont = 0;
	while (str[cont] != '\0') {
		cont++;
	}
	return cont;
}

char* copiarStr(char* str) {
	unsigned int largo = largoStr(str) + 1;
	char* nuevoStr = new char[largo];
	for (int i = 0; i < largo; i++) {
		nuevoStr[i] = str[i];
	}
	return nuevoStr;
}

int misterio(char* s, char* t) {
	int i;

	for (i = 0; s[i] == t[i]; i++) {
		if (s[i] == '\0') {
			return 0;
		}
		return s[i] - t[i];
	}
}

void fun(int* px) {
	cout << *px;
	(*px)++;
}


int main()
{

	//char* str = new char[4] {'h', 'o', 'l', 'a'};
	int x = 5; 
	int* px = &x;
	fun(px);

}

