#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#include "defs.h"
#include "archivos.h"
#include "procesamiento.h"

int match(regex_t *re, char *cadena, int *inicio, int *fin);

void extraer_parametros(char *respuesta){
	abrir_archivo();
	printf("Leyendo archivo.\n");
	
	regex_t gpgga;
	if( regcomp( &gpgga, gpgga_regex, 0)  != 0 ){
		perror("Error al compilar expresion regular.\n");
		exit(0);
	}

	regex_t tiemp;
	if( regcomp( &tiemp, tiempo_regex, REG_EXTENDED) != 0){
		perror("Error al compilar expresion regular.\n");
		exit(0);
	}

	regex_t lat;
	if(regcomp( &lat, latitud_regex, REG_EXTENDED) != 0){
		perror("Error al compilar expresion regular.\n");
		exit(0);
	}

	regex_t lon;
	if(regcomp( &lon, longitud_regex, REG_EXTENDED) != 0){
		perror("Error al compilar expresion regular.\n");
		exit(0);
	}

	char tiempo[9];
	char latitud[15];
	char longitud[15];

	int inicio = 0, fin = 0;	
	char linea[TAM_BUFF];
	char aux[80];
	char *tmp;

	strcpy(respuesta, "");

	register int i = 0, j = 0;
	while( leer_linea( linea ) != EOF && (j+80) < TAM_BUFF ){
		
		if( !match( &gpgga, linea, &inicio, &fin ) )
			continue;
		
		strcpy(aux, "");
		tmp = linea + 8;
		if( match( &tiemp, tmp, &inicio, &fin) ){ // TIEMPO
			for( i = 0; i < fin; i++)
				tiempo[i] = *(tmp+i);
			tiempo[i] = '\0';
			tmp += fin + 1;
		}

		if( match( &lat, tmp, &inicio, &fin ) ){ // LATITUD
			for( i = 0; i < fin; i++)
				latitud[i] = *(tmp+i);
			longitud[i] = '\0';
			tmp += fin + 1;
		}

		if( match( &lon, tmp, &inicio, &fin ) ){ // LONGITUD
			for( i = 0; i < fin; i++)
				longitud[i] = *(tmp+i);
			longitud[i] = '\0';
			tmp += fin + 1;
		}

		sprintf( aux, "{ Tiempo: %s, Latitud: %s, Longitud: %s }\n", tiempo, latitud, longitud);
		strcat( respuesta, aux );
		j += 80;
	}

	cerrar_archivo();
	regfree( &gpgga );
	regfree( &tiemp );
	regfree( &lat );
	regfree( &lon );
}

int match( regex_t *re, char *cadena, int *inicio, int *fin){
	regmatch_t matches[MAX_MATCHES];
	if( regexec(re, cadena, MAX_MATCHES, matches, 0) == 0){
		*inicio = matches[0].rm_so;
		*fin = matches[0].rm_eo;
		return 1;
	}
	return 0;
}
