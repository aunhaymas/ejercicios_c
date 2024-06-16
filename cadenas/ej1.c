/******************************************************************************
                    Copyright (c) 2024 Alfredo Godoy <a.k.a aunhaymas> 17:45:20
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
Escribir una función que reciba como parámetro una cadena de caracteres y
devuelva la cantidad de dígitos numéricos que hay en la cadena.
*/
#define T_MAX 41
typedef char t_cadena [T_MAX];

void leer_cadena(t_cadena cadena);
int digitos_en_cadena(t_cadena cadena);
int main(void){
	int cant;
	t_cadena cadena;
	printf("Contador de digitos en cadena\n");
	printf("Ingrese una cadena[maximo 40 elementos]: ");
	leer_cadena(cadena);
	cant=digitos_en_cadena(cadena);
	printf("Cantidad de digitos en cadena [%s]: %i \n", cadena,cant);
  return 0;
}
void leer_cadena(t_cadena cadena){
	char c;
	int j=0;
	while( j < (T_MAX-1) && (c=getchar()) != EOF && c!= '\n'){
		cadena[j] = c;
		j++;
	}
	cadena[j]='\0';
	while( c != EOF && c!='\n')
		c=getchar();
}
int digitos_en_cadena(t_cadena cadena){
	int cant=0,i;
	for(i=0 ; i < strlen(cadena) ; i++){
		if(cadena[i]>='0' && cadena[i] <='9')
			cant++;
	}
	return cant;
}
