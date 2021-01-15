#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "defs.h"
#include "cliente.h"

extern int sockfd;
void iniciar_cliente(){
	struct sockaddr_in direccion_servidor;

	memset( &direccion_servidor, 0, sizeof( direccion_servidor ));
	direccion_servidor.sin_family = AF_INET;
	direccion_servidor.sin_port = htons( PUERTO );

	if(( inet_pton( AF_INET, DIR_IP, &direccion_servidor.sin_addr ) ) < 0){
		perror("Error al asignar direccion IP.\n");
		exit( EXIT_FAILURE );
	}

	printf("Creando socket.\n");
	if(( sockfd = socket( AF_INET, SOCK_STREAM, 0)  ) < 0 ){
		perror("Error al crear socket.\n");
		exit( EXIT_FAILURE );
	}

	printf("Estableciendo conexion.\n");
	if( connect( sockfd, (struct sockaddr *)&direccion_servidor, sizeof( direccion_servidor ) ) < 0){
		perror("Error al establecer conexion.\n");
		exit( EXIT_FAILURE );
	}

}
