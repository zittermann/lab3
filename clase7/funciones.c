#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"
#include "archivo.h"

int display_menu() {

	int value;

	printf("Ingrese una opcion: \
		\n\t(1) Leer Panel \
		\n\t(2) Modificar panel\n");
	
	scanf("%d", &value);

	while (value != 1 && value != 2) { 

		printf("\nPor favor seleccione una opcion valida: ");
		scanf("%d", &value);

	}

	return value;
}

void get_filename(int id, char* buffer) {

	memset(buffer, 0x00, sizeof(buffer));
	sprintf(buffer, "panel%d.txt", id);
}

void read_panel(int id, char* str) {

	char filename[CHAR_LEN];
	
	get_filename(id, filename);

	inAbrirArchivo(&fp_read, filename, "r");
	 
	inLeerArchivo(str, CHAR_LEN, &fp_read);  


	inCerrarArchivo(&fp_read);
}

void write_panel(int id, char* message) {

	char filename[CHAR_LEN];
	
	get_filename(id, filename);

	inAbrirArchivo(&fp_write, filename, "w");
	inEscribirArchivo(message, &fp_write);

	printf("Mensaje actualizado en panel NR%d\n", id);

	inCerrarArchivo(&fp_write);
}

int is_same_message(int id, char* str) {

	char buffer[CHAR_LEN];

	memset(buffer, 0x00, sizeof(buffer));
	read_panel(id, buffer); /* Leo mensaje del archivo */

	return strcmp(str, buffer); /* 0 equals TRUE */

}


void update_panel(int id, char* current_message) {

	char new_message[CHAR_LEN];
	
	memset(new_message, 0x00, sizeof(new_message));
	read_panel(id, new_message);

	if (strcmp(current_message, new_message) != 0) {
		
		printf("Panel NR%d says: %s\n", id, new_message);
		sprintf(current_message, "%s", new_message); /* Actualizo para validacion */

	}

}
