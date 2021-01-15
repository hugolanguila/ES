#ifndef PROCESAMIENTO_H
#define PROCESAMIENTO_H

#define gpgga_regex "$GPGGA,"
#define tiempo_regex "[0-9]+(\\.[0-9]+)?"
#define latitud_regex "-?[0-9]+(\\.[0-9]+)?,[NS]?"
#define longitud_regex "-?[0-9]+(\\.[0-9]+)?,[WE]?"

void extraer_parametros( char *respuesta );

#endif
