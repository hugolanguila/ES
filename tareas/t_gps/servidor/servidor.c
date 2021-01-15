#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "defs.h"
#include "servidor.h"
#include "procesamiento.h"

extern int sockfd;

void init_seniales(){
	if( signal( SIGCHLD, manejador ) == SIG_ERR){
		perror("Error en el manejador.\n");
		exit(EXIT_FAILURE);
	}
	if( signal( SIGINT, manejador ) == SIG_ERR){
		perror("Error en el manejador.\n");
		exit(EXIT_FAILURE);
	}
}

void manejador( int sig ){
	pid_t pid;
	int estado;
	if( sig == SIGCHLD ){
		pid = wait( &estado );
		printf("Proceso hijo con pid %d terminado, con estado %d.\n", pid, estado>>0);
	}else if( sig == SIGINT ){
		printf("Se recibio la senial para detener el servidor.\n");
		close( sockfd );
		exit(0);
	}
}

void iniciar_servidor(){
	struct sockaddr_in direccion_servidor;

	memset( &direccion_servidor, 0, sizeof( direccion_servidor ));
	direccion_servidor.sin_family = AF_INET;
	direccion_servidor.sin_port = htons(PUERTO);
	direccion_servidor.sin_addr.s_addr = INADDR_ANY;	
	
	printf("Creando socket...\n");
	if(( sockfd = socket( AF_INET, SOCK_STREAM, 0 )) < 0){
		perror("Ocurrio un problema en la creacion del socket.\n");
		exit(EXIT_FAILURE);
	}

	printf("Configurando socket...\n");
	if( bind( sockfd, (struct sockaddr*)&direccion_servidor, sizeof(direccion_servidor )) < 0){
		perror("Ocurrio un error al configurar el socket.\n");
		exit(EXIT_FAILURE);
	}

	printf("Estableciendo la aceptacion de clientes...\n");
	if( listen(sockfd, COLA_CLIENTES) < 0){
		perror("Ocurrio un error al crear cola de aceptacion de clientes.\n");
		exit(EXIT_FAILURE);
	}
}

void proceso_cliente( int cliente_sockfd ){
	
	printf("\nCliente solicitando parametros...\n");

	char respuesta[TAM_BUFF];
	extraer_parametros( respuesta );	

	if( write( cliente_sockfd, respuesta, sizeof( respuesta )) < 0 ){
		perror("Ocurrio un error al enviar mensaje al cliente");
		exit(EXIT_FAILURE);
	}
	close( cliente_sockfd );
	exit( 0 );
}
