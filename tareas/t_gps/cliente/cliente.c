#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "defs.h"
#include "servidor.h"

int sockfd;

int main(int argc, char **argv)
{
	char mensaje[TAM_BUFFER];

	init();

	printf ("Solicitando parametros al servidor ...\n");
	if( write(sockfd, "Soy el Cliente", 15) < 0 )
	{
		perror("Ocurrio un problema en el envio de un mensaje al cliente");
		exit(1);
	}

	printf ("Recibiendo parametros del servidor ...\n\n");
	if (read (sockfd, &mensaje, TAM_BUFFER) < 0)
	{	
		perror ("Ocurrio algun problema al recibir datos del cliente");
		exit(1);
	}
	
	printf ("Parametros recividos: \n%s\n", mensaje);
	printf ("\nCerrando la aplicacion cliente\n");
	close(sockfd);

	return 0;
}
	
