/******************************************************************************
                    Copyright (c) 2024 Alfredo Godoy <a.k.a aunhaymas> 19:24:17
*******************************************************************************/

#include "cadenas.h"
#include <stdio.h>
/*

*/
void ingresarCadena(char *cadena, size_t tam)
{
	char c;
	int i=0;
	while(i < (tam-1) && (c=getchar())!=EOF &&  c!='\n' ){
	  	cadena[i]=c;
	  	i++; 
  	}
	while(c!='\0' && c!='\n')
		c=getchar();
}
void mostrarCadena(char *cadena, int ml)
{
	int i;
	for(i=0;i<ml;i++)
		printf("%d ",cadena[i]);
}

int ingresarNumero()//Lee solo numeros borrando los demas caracteres en caso de encontrarlos
{
	int numero=0, tam=20, i=0;
	char digito;
	printf("Ingrese un numero: ");
	while( (digito=getchar())!=EOF && i<tam && digito!='\n')
	{
		if(digito>='0' && digito <='9')
			numero*=10 + (digito-'0');
		i++;
	}
	while( (digito=getchar()) != EOF);
	return numero;
}
void vectorAleatorio(int vec, size_t tam, int min, int max); //Relleno el vector con numeros aleatorios

