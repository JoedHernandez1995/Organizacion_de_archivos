#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
 
int main(int argc, char** argv) {

	int fd = -1;
	const int BLOCK_SIZE = 4096; // Que no cargue todo el archivo a la vez si no que en bloques de 4096 bytes
	char buff_reader[BLOCK_SIZE + 1]; // Por el caracter \0 de final de cadena
 
	fd = open("/Users/joedhernandez/Desktop/file.txt", O_RDONLY);
	
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