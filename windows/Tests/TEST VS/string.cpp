#include <iostream>
#include <stdio.h>
using namespace std;

void mostrarStr (char* str) {
	int i = 0;
	while (str[i] != '\0') {
		cout << str[i];
		i++;
	}
	
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

char* str = new char['h','o','l','a'];

   
int main() {
	mostrarStr(str);
	cout << copiarStr(str) << endl;
	cout<< "Hello World" << endl;


}

