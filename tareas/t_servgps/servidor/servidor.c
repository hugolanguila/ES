#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "defs.h"
#include "seniales.h"
#include "servidor.h"

int sockfd;
void proceso_servidor(){
	iniciar_seniales();
	iniciar_servidor();
	aceptar_conexiones();
}

void iniciar_servidor(){

	struct sockaddr_in direccion_servidor;
	memset( &direccion_servidor, 0, sizeof( direccion_servidor ) );
	direccion_servidor.sin_family = AF_INET;
	direccion_servidor.sin_port = htons( PUERTO );
	direccion_servidor.sin_addr.s_addr = INADDR_ANY;

	printf("Creando Socket.\n");
	if( ( sockfd = socket(AF_INET, SOCK_STREAM, 0) ) < 0 ){
		perror("Ocurrio un error al crear socket.\n");
		exit(EXIT_FAILURE);
	}

	printf("Configurando socket.\n");
	if( ( bind( sockfd, (struct sockaddr*)&direccion_servidor, sizeof( direccion_servidor ) ) ) < 0){
		perror("Ocurrio un error al configurar socket.\n");
		exit(EXIT_FAILURE);
	}

	printf("Estableciendo aceptacion de clientes.\n");
	if( ( listen( sockfd, COLA_CLIENTES ) ) < 0 ){
		perror("Ocurrio un error al crear cola de clientes.\n");
		exit(EXIT_FAILURE);
	}
}

void aceptar_conexiones(){
	int cliente_sockfd;
	int pipefd[2];
	printf("Aceptando conexiones en el puerto: %d.\n", PUERTO);	
	while(1){
		if( ( cliente_sockfd = accept( sockfd, NULL, NULL ) ) < 0 ){
			perror("Ocurrio un error al aceptar conexion.\n");
			exit(EXIT_FAILURE);
		}

		if(	pipe( pipefd ) < 1){
			perror("Error al crear pipe.\n");
			exit(EXIT_FAILURE);
		}

		pid_t pid = fork();
		if( !pid ){
			proceso_cliente( cliente_sockfd, pipefd );
		}
	}
} 

void proceso_cliente( int cliente_sockfd ){
	char respuesta[TAM_MENSAJE];
	strcpy( respuesta, "Bienvenido cliente" );

	if( ( write( cliente_sockfd, respuesta, sizeof( respuesta ) ) ) < 0 ){
		perror("Ocurrio un error al enviar respuesta al cliente.\n");
		exit(EXIT_FAILURE);
	}
	
	close( cliente_sockfd );
	exit( 0 );
}
