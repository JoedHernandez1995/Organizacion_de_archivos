#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
 
int main(int argc, char** argv) {
	// revisando que el nombre del archivo esté inclido en los parámetros provenientes de la consola
	if (argc != 2) {
		perror("Ingrese la ruta del archivo a lee, solamente un archivo a la vez.\n");
	}
 
	int fd = -1;
	const int BLOCK_SIZE = 4096; // Que no cargue todo el archivo a la vez si no que en bloques de 4096 bytes
	char buff_reader[BLOCK_SIZE + 1]; // POr el caracter \0 de final de cadena
 
	fd = open(argv[1], O_RDONLY);
	
	if (fd == -1) {
		perror("El archivo no puede abrirse.\n");
		return 1;
	}
 
	int bytes_read = 0;
 
	while ((bytes_read = read(fd, buff_reader, BLOCK_SIZE)) > 0) {
		buff_reader[bytes_read + 1] = '\0';
		printf("%s", buff_reader);
	}
 
	close(fd);
 
	return 0;
}