#ifndef SERIAL_H
#define SERIAL_H

void leer_datos_uart();
int config_serial ( char *, speed_t );
void guardaDatos( unsigned char datos[] );

#endif
