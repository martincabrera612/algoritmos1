int cantHojas (NodoAB* r){
	if (r == NULL) {
		retrun 0;
	}else if (r->izq == NULL && r->der == NULL) {
		return 1;
	}else {
		return cantHojas(r->izq) + cantHojas (r->der);
	}
}


NodoAB* espejo(NodoAB* r) {
	if (r == NULL) {
		return NULL;
	}else {
		NodoAB* resultado = new NodoAB(r->dato);
		resultado->izq = espejo(r->der);
		resultado->der = espejo(r->izq);

		return resultado;
	}
	
}


//SUPONIENDO QUE YA TENGO LA FUNCION CONCAT
NodoLista* arbolEnLista (NodoAB* r) {
	if (r == NULL){
		return NULL;
	}
	NodoLista* nuevo = new NodoLista (r->dato);
	nuevo->sig = arbolEnLista(r->izq);
	NodoLista*  listaDer = arbolEnLista(r->der);

	return concat(nuevo, listaDer);
}

//Buscar un dato en el arbol
bool buscar(NodoAB* r, int dato) {
	if (!r){     //r == NULL
		return false;
	}
	if (r->dato == dato) {
		return true;
	}
	return buscar((r->izq, dato || buscar(r->der, dato));
}

//Si es un ABB , si es un arbol binario (ordenado: menor a la izquierda y mayor a la derecha).
//Peor caso Orden N = O(n)
bool buscar(NodoAB* r, int dato){
	bool resultado = false;
	if (r){ 		//r != NULL

		if (r->dato == dato) {
			resultado = true;
		}else if (r->dato > dato) {
			resultado = buscar(r->izq, dato);
		}else {
			resultado = buscar(r->der, dato);
		}
	}    
	return resultado;                  
}


//PRE: Es un arbol ABB
bool buscarItr (NodoAB* r, int dato) {
	bool resultado = false;
	NodoAB* aux = r;
	while (aux != NULL && !resultado){
		if (aux->dato == dato){
			resultado = true;
		}else if (aux->dato > dato){
			aux = aux->izq;
		}else{
			aux = aux->der;
		}
	}
	return resultado;
}


//PRE: Si es un ABB
int minimo (NodoAB* r){
	while (r->izq){
		r = r->izq;
	}
	return r->dato;
}

void eliminar (NodoAB* &r, int dato){
	if (!r) return;   // r == NULL
	if (r->dato == dato) {
		if (!r->izq && !r->der) {   //Caso si es hoja
			NodoAB* borro = r;
			r = NULL;
			delete borro;
		}else if (!r->izq && r->der) {
			NodoAB* borro = r;
			r = r->der;
			delete borro;
		}else if (r->izq && !r->der) {
			NodoAB* borro = r;
			r = r->izq;
			delete borro;
		}else {
			NodoAB* rDer = r;
			while (rDer->der->der) {
				rDer = rDer->der;
			}
			r->dato = rDer->der->dato;   //Intercambio los datos
			NodoAB* borro = rDer->der;
			rDer->der = rDer->der->izq;  //Puede no existir ->izq pero igual apunta a NULL.
			delete borro;
		}
	}else {
		eliminar(r->izq, dato);
		eliminar(r->der, dato);
	}
}


// Eliminar en ABB   borrarNodo raiz
void eliminar(NodoAB* &r, int dato){
	if (!r){
		return;
	}
	if (r->dato == dato){
		if (esHoja(r)){
			eliminarMaximo(r);
		}else if (r->izq && r->der){           
			int maximo = maximo(r->izq);
			r->dato = maximo;
			eliminarMaximo(r->izq);
		}
	}else if(r->dato > dato){
		eliminar(r->izq, dato);
	}else {
		eliminar(r->der, dato);
	}
}




