#include <stdio.h>
#include <stdlib.h>

#include "archivos.h"

FILE *fp;
void abrir_archivo( char *datos ){

	printf("Abriendo archivo.\n");
	fp = fopen("datos.txt", "r");
	if(fp == NULL){
		perror("Error al leer archivo.\n");
		exit(EXIT_FAILURE);
	}
}

void cerrar_archivo(){
	printf("Cerrando archivo.\n");
	fclose( fp );
}

int leer_linea( char *datos ){
	return fscanf( fp, "%s[^\n]", datos );
}

void escribir_datos( char *datos ){

}
