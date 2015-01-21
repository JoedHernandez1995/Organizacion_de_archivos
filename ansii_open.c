#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
	FILE *archivo;
	char c;
	archivo = fopen("/Users/joedhernandez/Desktop/file.txt","r");

	while((c=fgetc(archivo))!= EOF){
		printf("%c",c);
	}

	fclose(archivo);
	return 0;
}