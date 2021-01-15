#ifndef SERVIDOR_H
#define SERVIDOR_H

void iniciar_servidor();
void proceso_cliente( int cliente_sockfd );
void init_seniales();
void manejador( int sig );


#endif
