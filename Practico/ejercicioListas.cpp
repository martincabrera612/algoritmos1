//EJERCICIO ISLAS ALGORITMO 1

#include <iostream>;
using namespace std;



void desocultarIsla (char** mapa, int i, int j, int col, int fil) {
	for (int i = 0; i < col; ++i)
	{
		for (int j = 0; j < fil; ++i)
		{
			if(mapa[i][j] =='X') mapa[i][j] = 'T';
		}
	}
}


void ocultarIsla (char** mapa, int i, int j, int col, int fil) {
	//nos fuimos de los limites o agua
	if ((i<0 || i>=col || j<0 || j>= fil) || mapa[i][j] != 'T' ) {
		return;
	} else {
	//estoy en una posicion valida  y es tierra 
		mapa[i][j] = 'X';
		for (int k = -1 ; k <=1; ++k) {
			for (int l = -1; l <=1; ++l)
			{
				if (k==0 && l==0) continue; //opcional
				ocultarIsla(mapa, i+k,j+l,col, fil);
			}
		}
	}
}


int islas (char** mapa, int col, int fil) {
	int contador = 0;
		for (int i = 0; i < col; i++){
			for (int j = 0; j < count; j+)
			{
				if (mapa[i][j] = 'T') {
					
					ocultarIsla(mapa,i,j,col,fil);
					contador++;
					//aca sigue, no termine
				}
			}
		}
	desocultarIsla(mapa,i,j,col,fil);
	return contador;

}


