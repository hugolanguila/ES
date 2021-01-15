#ifndef SERVIDOR_H
#define SERVIDOR_H

void proceso_servidor();
void iniciar_servidor();
void aceptar_conexiones();
void proceso_cliente( int cliente_sockfd );

#endif
