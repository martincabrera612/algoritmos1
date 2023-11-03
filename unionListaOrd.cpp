ListaOrdInt nueva = clon(l1);
ListaOrdInt lista2 = clon(l2);
while (!esVacia(lista2)) {
		agregar(nueva, minimo(lista2));
		borrarMinimo(lista2);
}
destruir(lista2);
return nueva;


//PRE:
//POS:
void imprimirListaOrdInt(ListaOrdInt lista) {
	ListaOrdInt l = clon(lista);
	cout << "Prueba Propia Lista: ";
	while (!esVacia(l)) {
		cout << " " << minimo(l);
		borrarMinimo(l);
	}
	cout << endl;
}