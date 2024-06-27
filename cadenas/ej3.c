/******************************************************************************
                    Copyright (c) 2024 Alfredo Godoy <a.k.a aunhaymas> 21:11:37
*******************************************************************************/
#include <complex.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
Escribir una función en C, que reciba como parámetro una cadena de tipo
t_cadena, y devuelva la cantidad de palabras que hay en la cadena.
Considerar que una palabra está separada de otra, por uno ó más blancos.
No recorrer la cadena más de una vez.
Declare un tipo t_cadena acorde.
Escribir el programa que incluya a la función y las invocaciones con los
siguientes caso de prueba:
cant_palabras("El sol es amarillo.") devuevle 4
cant_palabras(" Hoy es 30 de Junio de 2021 ") devuevle 7
cant_palabras("30/06/2021") devuelve 1
cant_palabras("El precio es $2.000.- ") devuelve 4
cant_palabras(" ") devuelve 0 
*/
#define T_MAX 41
typedef char t_cadena[T_MAX];
void ingresar_cadena(t_cadena);
void cantidad_palabras(t_cadena cadena, int *cant);
int main(void){
	t_cadena cadena;
	int cant;
	printf("Cantidad de palabras de una cadena! \n");
	printf("ingresar cadena: ");
	ingresar_cadena(cadena);
	cantidad_palabras(cadena,&cant);
	printf("Cantidad de palabras: %d \n", cant);
 	return 0;
}
void ingresar_cadena(t_cadena cadena){
	char c;
	int j=0;
	while(j < (T_MAX-1) && (c=getchar()) != EOF && c !='\n'){
		cadena[j] = c;
		j++;
	}
	cadena[j] = '\0';
	while(c!=EOF && c!='\n'){
		c=getchar();
	}
}
void cantidad_palabras(t_cadena cadena, int *cant){
	(*cant) = (int)(cadena[0]!=' ');
	size_t tam = strlen(cadena);
	int i;
	for(i=0 ; i <tam-1; i++){
		if(cadena[i] ==' ' && cadena[i+1] != ' ')
			(*cant)++;
	}
}
int cantidad_palabras_oracion(t_cadena cadena){
	int cant=0,i;
	size_t tam = strlen(cadena);
	for(i=0 ; i< tam-1 ; i++){
		if(cadena[i] == ' ' && cadena[i+1] != ' ')
			cant++;
	}
	return cant;
}
