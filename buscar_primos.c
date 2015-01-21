#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
	FILE *archivo;
	archivo = fopen("/Users/joedhernandez/Desktop/numeros.txt","r");
	int userValue,compare = 1,i;
	printf("Ingrese un numero a buscar: ");
	scanf("%d", &userValue);
	while(fscanf(archivo,"%d",&compare) > 0){
		if(compare == userValue){
			printf("El numero se encuentra en el archivo de texto!\n");
			exit(0);
		}
	}
	printf("El numero no se encuentra en el archivo de texto!\n");
	fclose(archivo);
	return 0;
}