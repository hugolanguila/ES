#include <stdio.h>
#include "defs.h"
#include "procesamiento.h"

void ordenar( int *datos ){
	register int i, j;
	for( i = 0; i < NDATOS ; i++ ){
		for( j = 0; j  < NDATOS-1; j++){
			if( datos[j] > datos[j+1] ){
				int tmp = datos[j];
				datos[j] = datos[j+1];
				datos[j+1] = tmp;
			}	
		}
	}
}

int promedio( int *datos ){
	int suma = 0;
	register int i;
	for( i = 0; i < NDATOS; i++){
		suma += datos[i];
	}

	return suma / NDATOS;
}

int n_pares( int *datos ){
	int contador;
	register int i;
	for( i = 0; i < NDATOS; i++ ){
		if( !( datos[i] % 2 ))
			contador++;
	}
	return contador;
}

int n_primos( int *datos ){
	int contador = 0;
	int aux = 0;
	printf("\nNumeros primos:\n");
	register int i;
	for( i = 0; i < NDATOS; i++ ){
		if( es_primo( datos[i] )){
			if( !( aux++ % 16 ))
				printf("\n\t");
			printf("%3d ", datos[i]);
			contador ++;
		}
	}
	printf("\n\n");
	return contador;
}

int es_primo( int x ){
	register int i;
	for( i = 2; i < x; i++ ){
		if ( !( x % i ))
			return 0;
	}

	if( x == 1 || x == 0)
		return 0;

	return 1;
}
