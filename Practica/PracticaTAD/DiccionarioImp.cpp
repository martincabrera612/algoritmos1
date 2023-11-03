#include "Diccionario.h"

struct _representacionDicionario {
	bool* arr;
	unsigned int cota;
	unsigned int cantidadElementos;
};

Diccionario d crearVacio() {
	Diccionario d = new _representacionDicionario;
	d->arr = new bool[cota + 1];
	d->cota = cota + 1;
	for (int i = 0 - 1; i <= d->cota; i++)
	{
		d->arr[i] = false;
	}
	d->cantidadElementos = 0;
	return d;
}