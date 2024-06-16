/******************************************************************************
                    Copyright (c) 2024 Alfredo Godoy <a.k.a aunhaymas> 20:24:59
*******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
Escribir una función que reciba como parámetro una cadena de caracteres y
devuelva la cantidad de caracteres no alfabéticos que hay en la cadena.
No tener en cuenta la ñ, ni las vocales acentuadas. 
*/
#define T_MAX 41
typedef char t_cadena[T_MAX];

void ingresar_cadena(t_cadena cadena);
void contar_no_alfabeticos(t_cadena cadena, int *cant);
int main(void){    
	t_cadena cadena;
	int cant;
	printf("Contador de caracteres no alfabeticos:\n");
	printf("Ingrese una cadena: ");
	ingresar_cadena(cadena);
	contar_no_alfabeticos(cadena,&cant);
	printf("Cantidad de caracteres no alfabeticos en [%s]: %d \n", cadena,cant);
  return 0;
}
void ingresar_cadena(t_cadena cadena){
	char c;
	unsigned short j=0;
	while(j < T_MAX-1 && (c=getchar())!= EOF && c != '\n' ){
		cadena[j] = c;
		j++;
	}
	cadena[j] = '\0';
	while(c!= EOF && c != '\n')
		c=getchar();
}
void contar_no_alfabeticos(t_cadena cadena, int *cant){
	*cant=0;
	int j;
	size_t tam = strlen(cadena);
	for(j = 0; j < tam; j++){
		if((cadena[j]<'A' || cadena[j]>'Z') && (cadena[j]< 'a' || cadena[j] >'z'))
			(*cant)++;
	}
}
