void invertirLista(){
	int cant;
	cin >> cant;
	Lista lista = crearLista();
	for (int i =0; i< cant; i++){
		int dato;
		cin >> dato;
		insertarFin(lista, dato);
	}

	Lista listaInvertida = crearLista();
	Lista aux = clon(lista);
	while(cantElementos(aux) != 0){
		int dato = obtenerPrincipio(aux);
		borrarPrincipio(aux);
		if (cantidadDeElementos(aux) == 0){
		cout << dato<< endl;
		}else {
			cout << dato<< " - ";
		}

	}
	return lista;
}