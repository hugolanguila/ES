#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

#include "seniales.h"

extern int sockfd;

void iniciar_seniales(){
	if( signal( SIGCHLD, manejador ) == SIG_ERR ){
		perror("Error en el manejador.\n");
		exit( EXIT_FAILURE );
	}
	if( signal( SIGINT, manejador ) == SIG_ERR ){
		perror("Error en el manejador.\n");
		exit( EXIT_FAILURE );
	}
}

void manejador( int sig ){
	pid_t pid;
	int estado = 0;

	if( sig == SIGCHLD ){
		pid = wait( &estado );
		printf("Proceso hijo con pid: %d, terminado con estado %d.\n", pid, estado);	
	}else if( sig == SIGINT ){
		printf("Senial para detener el servidor recivida.\n");
		close( sockfd );
		exit(0);
	}
}
