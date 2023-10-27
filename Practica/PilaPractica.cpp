//Pila 

bool estanBalanceados(char* str) {
	Pila p = crearVacia(100); // Deberia ser una pila no acotada
	bool estanOk = true;
	while (*str != '\0'){
		if (*str == '(' || *str == '[' || *str == '{' ){
			push(p, *str);
		}
		else if (*str == ')' || *str == ']' || *str == '}' ){
			if (!esVacia(p)){
				int tope = top(p);
				if (tope == '(' && *str != ')' 
					|| (tope == '[' && *str != ']') 
					|| (tope == '{' && *str != '}'){
					estanOk = false;
				}else {
					pop(p);
						
				}	
			}else {
				estanOk= false;
			}
		}
		*str++;
	}
	if (!esVacia(p) {
		estanOk = false;
	}
	destruir(p);
	return estanOk;
}