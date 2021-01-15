#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "defs.h"
#include "cliente.h"

int sockfd;
int main( int argc, char **argv ){
	char mensaje[TAM_MENSAJE];
	iniciar_cliente();

	printf("Enviando mensaje al servidor.\n");
	if( write( sockfd, "Soy el cliente", 15 ) < 0 ){
		perror("Error al enviar mensaje al servidor.\n");
		exit(EXIT_FAILURE);
	}

	printf("Esperando respuesta del servidor.\n");
	if( read( sockfd, &mensaje, TAM_MENSAJE ) < 0 ){
		perror("Error al recibir mensaje del servidor.\n");
		exit(EXIT_FAILURE);
	}

	printf("Mensaje recibido: %s\n", mensaje);
	printf("Terminando aplicacion cliente.\n");
	close( sockfd );
	return 0;
}
