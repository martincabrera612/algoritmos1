void merge(int array[], int const izq, int const med, int const der) {
	int largoArrayUno = med - izq + 1;
	int largoArrayDos = der - med;
	//Creo arrays temporales
	int* arrayIzq = new int[largoArrayUno];
	int* arrayDer = new int[largoArrayDos];

	//Copio arrays
	for (int i = 0; i < largoArrayUno; i++) {
		arrayIzq[i] = array[izq + i];
	}

	for (int j = 0; j < largoArrayDos; j++) {
		arrayDer[j] = array[med + 1 + j];
	}
	int indexArrayUno = 0;
	int indexArrayDos = 0;
	int indexMergedArray = izq;

	while ((indexArrayUno < largoArrayUno) && (indexArrayDos < largoArrayDos)) {
		if (arrayIzq[indexArrayUno] <= arrayDer[indexArrayDos]) {
			array[indexMergedArray] = arrayIzq[indexArrayUno];
			indexArrayUno++;
		}
		else {
			array[indexMergedArray] = arrayDer[indexArrayDos];
			indexArrayDos++;
		}
		indexMergedArray++;
	}

	while(indexArrayUno < largoArrayUno) {
		array[indexMergedArray] = arrayIzq[indexArrayUno];
		indexArrayUno++;
		indexMergedArray++;

	}

	while(indexArrayDos < largoArrayDos) {
		array[indexMergedArray] = arrayDer[indexArrayDos];
		indexArrayDos++;
		indexMergedArray++;
	}

	delete[] arrayIzq;
	delete[] arrayDer;
}

  while (indexArrayDos < largoArrayDos ) {
    array[indexMergedArray] = arrayDer[indexArrayDos];
    indexArrayDos++;
    indexMergedArray++;
  }

  delete[] arrayIzq;
  delete[] arrayDer;
}

// of arr to be sorted */
void mergeSort(int array[], int const inicio, int const final)
{
	if (inicio >= final)
		return mergeSort(array[], inicio,final); // Returns recursively

	auto mid = inicio + (final - inicio) / 2;
	mergeSort(array, inicio, mid);
	mergeSort(array, mid + 1, final);
	merge(array, inicio, mid, final);
}
