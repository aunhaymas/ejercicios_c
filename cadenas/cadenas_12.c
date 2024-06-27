/******************************************************************************
                    Copyright (c) 2024 Alfredo Godoy <a.k.a aunhaymas> 14:38:55
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
/*
 Escribir un programa modular en C, que solicite el ingreso de 1 oración,
de no más de 100 caracteres.
 Luego informar la cantidad de vocales minúsculas, no acentuadas, 
que hay en la oración. 
*/

#define MF 101
typedef char t_oracion[MF];

int esVocal(char letra);
void ingresarCadena(char *cadena, int ml);
int contarVocales(char *cadena);

int esVocal(char letra)
{
	return (letra=='a'||letra=='e'||letra=='i'||letra=='o'||letra == 'u');
}
void ingresarCadena(t_oracion cadena, int ml)
{
	char c;
	int i=0;
	while( (c=getchar())!=EOF && c!='\n' && i<(ml-1) )
	{
		cadena[i]=c;
		i++;
	}
	cadena[i]='\0';
	while (c!=EOF && c!='\n')	
	{
		c=getchar();//Limpio el buffer
	}
}
int contarVocales(char *cadena)
{
	int cant=0;
	int i=0;
	while(cadena[i]!='\0' && i <MF-1)
	{
		cant+=esVocal(cadena[i]);
		i++;
	}
	return cant;
}
int main(void)
{    
    t_oracion oracion;
	int cant_vocales;

	printf("Ingrese una oracion(Limite 100 caracteres): ");
	ingresarCadena(oracion,MF);
	cant_vocales = contarVocales(oracion);
	printf("Hay %d vocales en la oracion\n",cant_vocales);
	printf("%s \n",oracion);
	
    return 0;
}









