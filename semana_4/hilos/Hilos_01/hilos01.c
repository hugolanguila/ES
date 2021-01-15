#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *start_routine_add( void *args );
void *start_routine_sub( void *args );
void *start_routine_mul( void *args );
void *start_routine_div( void *args );

int main( int argc, char **args ){

	printf("\nPrueba de hilos.\n\n");
	pthread_t id_1, id_2, id_3, id_4;

	pthread_create( &id_1, NULL, start_routine_add, NULL );
	pthread_create( &id_2, NULL, start_routine_sub, NULL );
	pthread_create( &id_3, NULL, start_routine_mul, NULL );
	pthread_create( &id_4, NULL, start_routine_div, NULL );

	int *res_add, *res_sub, *res_mul, *res_div; 

	pthread_join( id_1, (void **) &res_add );
	pthread_join( id_2, (void **) &res_sub );
	pthread_join( id_3, (void **) &res_mul );
	pthread_join( id_4, (void **) &res_div );

	printf("El resultado de la suma es:	%d\n", *res_add);
	printf("El resultado de la resta es:	%d\n", *res_sub);
	printf("El resultado de la multiplicacion es:	%d\n", *res_mul);
	printf("El resultado de la division es: 	%d\n\n", *res_div);

	free(res_add);
	free(res_sub);
	free(res_mul);
	free(res_div);

	return 0;
}


void *start_routine_add( void *args ){
	int a = 10, b = 30;

	int *suma = (int *)malloc(sizeof(int));
	*suma = a + b;

	pthread_exit( (void *)suma );
}

void *start_routine_sub( void *args ){
	int a = 10, b = 30;
	
	int *resta = (int *)malloc(sizeof(int));
	
	*resta = a - b;
	pthread_exit( (void *)resta );
}

void *start_routine_mul( void *args ){
	int a = 10, b = 30;

	int *multi = (int *)malloc(sizeof(int));

	*multi = a * b;
	pthread_exit( (void *)multi );
}

void *start_routine_div( void *args ){
	int a = 10, b = 30;
	
	int *div = (int *)malloc(sizeof(int));

	*div = b / a;
	pthread_exit( (void *)div );
}



