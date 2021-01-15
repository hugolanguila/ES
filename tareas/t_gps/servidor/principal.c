#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <signal.h>
#include <unistd.h>

//#include "seniales.h"
#include "servidor.h"

int sockfd;
int main(){
	
	int cliente_sockfd;
	init_seniales();
	iniciar_servidor();
	
	printf("Esperando peticiones de servidor.\n");
	while(1){
		if(( cliente_sockfd = accept( sockfd, NULL, NULL )) < 0 ){
			perror("Ocurrio un error al atender a un cliente.\n");
			exit(EXIT_FAILURE);
		}
		pid_t pid = fork();
		if( !pid ){
			proceso_cliente( cliente_sockfd );
		}
	}	
	return 0;
}

