int cantNodos (NodoAG* r){
	if (!r){
		return;
	}else {
		return 1 + cantNodos(r->ph) + cantNodos(r->sh);
	}
}

int altura(NodoAG* r){
	if (!r){
		return 0;
	}
	int alturaHijos = altura(r->ph) + 1 
	int alturaHermanos = altura(r->sh);
	return maximo (alturaHijos, alturaHermanos);
}

bool existe(NodoAG* r, int dato){
	if (!r){
		return false;
	}
	if (r->dato = dato){
		return true;
	}else {
		return existe(r->ph, dato) || existe(r->sh, dato);
	}
}

int cantNodosNivel(NodoAG * r, int nivel){
	if (!r || nivel<1) {
		return 0;
	}
	if (nivel == 1){
		return 1+cantNodosNivel(r->sh,nivel);
	}
	return cantNodosNivel(r->ph, nivel -1 + cantNodosNivel(r->sh, nivel); 
}