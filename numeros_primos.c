#include <stdio.h>
#include <stdbool.h>

bool isPrime(int);

int main(){
	FILE *archivo;
	archivo = fopen("/Users/joedhernandez/Desktop/numeros.txt","w");
	int userValue;
	printf("Ingrese un numero: ");
	scanf("%d", &userValue);
	int i;
	for(i = 1; i <= userValue; i++){
		if(isPrime(i)){
			fprintf(archivo,"%d\n",i);
		}
		if(i == userValue){
			fprintf(archivo,"%d",-1);
		}
	}
	fclose(archivo);
	return 0;
}

bool isPrime(int num){
	int x = 0;
	int i;
	for(i = 1; i < num+1; i++){
		if(num % i == 0){
			x++;
		}
	}
	if(x != 2){
		return false;
	}else{
		return true;
	}
}