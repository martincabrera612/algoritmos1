#include "TablaIntString.h"
#include "Definiciones.h"

#ifdef TABLA_INT_STRING_IMP

struct NodoHash {
	int clave;
	char* valor;
	NodoHash* sig;
};

struct _cabezalTablaIntString {
	NodoHash** tabla;
	int largoTab;
	int cantElem;
};

void borrarAux(NodoHash*& nodo, int d);

int Hash(int elemento, int capacidad) {
	int resp = elemento % capacidad;
	return abs(resp);
}

TablaIntString crearTablaIntString(unsigned int esperados) {
	TablaIntString tab = new _cabezalTablaIntString();
	tab->tabla = new NodoHash * [esperados];
	for (int i = 0; i < esperados; i++)
	{
		tab->tabla[i] = NULL;
	}
	tab->cantElem = 0;
	tab->largoTab = esperados;
	return tab;
}


void agregar(TablaIntString& t, int d, const char* r) {
	int pos = Hash(d, t->largoTab);
	int largoR = strlen(r) + 1;
	NodoHash* lista = t->tabla[pos];
	while (lista != NULL && lista->clave != d)
	{
		lista = lista->sig;
	}
	if (lista == NULL)
	{
		NodoHash* nuevo = new NodoHash;
		nuevo->clave = d;
		nuevo->valor = new char[largoR];
		strcpy_s(nuevo->valor, largoR, r);
		nuevo->sig = t->tabla[pos];
		t->tabla[pos] = nuevo;
		t->cantElem++;
	}
	else
	{
		lista->valor = new char[largoR];
		strcpy_s(lista->valor, largoR, r); //esto no lo pude corroborar , preguntar
	}
}

bool estaDefinida(TablaIntString t, int d) {
	if (!esVacia(t))
	{
		int pos = Hash(d, t->largoTab);
		NodoHash* lista = t->tabla[pos];

		while (lista != NULL && lista->clave != d)
		{
			lista = lista->sig;
		}
		return lista != NULL;
	}
	else {
		return false;
	}
}

char* recuperar(TablaIntString t, int d) {
	if (!esVacia(t) && estaDefinida(t, d))
	{

		//char* ret = new char[1];
	   // ret[0] = '\0';
		int pos = Hash(d, t->largoTab);
		NodoHash* lista = t->tabla[pos];
		while (d != lista->clave)
		{
			lista = lista->sig;
		}								//preguntar por orden y por  lo comentado para strcopy
		int largoR = strlen(lista->valor) + 1;
		char* ret = new char[largoR];
		strcpy_s(ret, largoR, lista->valor);
		return ret;
	}
}

void borrarString(char*& string) {
	int largoS = strlen(string);
	for (int i = 0; i < largoS; i++) // preguntar si puedo hacer delete[] del string
	{

	}
}

void borrarAux(NodoHash*& nodo, int d) {
	if (nodo->clave != d)
	{
		borrarAux(nodo->sig, d);
	}
	else if (nodo->clave == d)
	{
		delete[] nodo->valor;
		NodoHash* aBorrar = nodo;
		nodo = nodo->sig;
		delete aBorrar;
	}
}

void borrar(TablaIntString& t, int d) {
	if (!esVacia(t) && estaDefinida(t, d))
	{
		int pos = Hash(d, t->largoTab);
		borrarAux(t->tabla[pos], d);
		t->cantElem--;



	}
}

int elemento(TablaIntString t) {
	if (!esVacia(t))
	{
		for (int i = 0; i < t->largoTab; i++)
		{
			if (t->tabla[Hash(i, t->largoTab)] != NULL)
			{
				return t->tabla[Hash(i, t->largoTab)]->clave;
			}
		}

	}
}

bool esVacia(TablaIntString t) {
	return t->cantElem == 0;
}

unsigned int cantidadElementos(TablaIntString t) {
	return t->cantElem;
}

void destruir(TablaIntString& t) {
	// NO IMPLEMENTADO
}

TablaIntString clon(TablaIntString t) {
	TablaIntString resp = crearTablaIntString(t->largoTab);
	for (int i = 0; i < t->largoTab; i++)
	{
		NodoHash* aux = t->tabla[i];
		while (aux != NULL)
		{
			agregar(resp, aux->clave, aux->valor);
			aux = aux->sig;
		}
	}
	return resp;
}

#endif