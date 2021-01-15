#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

//#include "seniales.h"

extern int sockfd;
/*
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
}*/
