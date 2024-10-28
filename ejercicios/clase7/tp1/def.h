#ifndef _DEF
#define _DEF

#include <sys/ipc.h>
#include <sys/sem.h>

#define DEFAULT_PATH "/bin/ls"
#define DEFAULT_KEY 33

#define ROJO 0
#define VERDE 1

#define NUM_CIUDADES 3
#define CHAR_LEN 100

#define CANTIDAD 10
#define CANTIDAD_TOTAL 10
#define DESDE 0
#define HASTA 2

typedef enum {			
	MSG_BANCO,		
	MSG_CAJERO	
}Destinos;

typedef enum {
	EVT_CONSULTA_SALDO,
	EVT_DEPOSITO,
	EVT_EXTRACCION,
	EVT_RTA_SALDO,
	EVT_RTA_SALDO_NOK,
	EVT_RTA_DEPOSITO_OK,
	EVT_RTA_DEPOSITO_NOK,
	EVT_RTA_EXTRACCION_OK,
	EVT_RTA_EXTRACCION_NOK
}Eventos;

typedef struct tipo_mensajes mensaje;
struct tipo_mensajes {
	long	long_dest; 						/* Destinatario */
	int 	int_rte;						/* Remitente */
	int 	int_evento;						/* Numero de nevento */
	char 	char_mensaje[CHAR_LEN];			/* mensaje */
};

#endif