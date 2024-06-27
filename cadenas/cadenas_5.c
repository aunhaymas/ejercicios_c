/******************************************************************************
                    Copyright (c) 2024 Alfredo Godoy <a.k.a aunhaymas> 15:17:45
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
/*
Escribir una función para validar una nueva clave de acceso.
La función deberá recibir una cadena de caracteres, que contendrá la clave
candidata, que ya fue ingresada previamente por el usuario.
Devolverá true o false, dependiendo de si cumple o no, con las siguientes
condiciones:
- La clave debe estar formada únicamente por, entre 6 y 12 caracteres
numéricos
- La cantidad de dígitos pares debe ser mayor a la de los impares.
A los sumo debe recorrer una vez la cadena.
Evite realizar ciclos innecesarios.
Compruebe el correcto funcionamiento, incluyendo los siguientes casos de
prueba:
validar("j20893") devuevle false
validar("20893a") devuevle false
validar("208X930") devuevle false
validar("20201") devuelve false
validar("23445776") devuelve false
validar("089010") devuelve true
validar("02784532132567") devuelve false
validar("027845320011") devuelve true 
*/

#define MF 20
typedef char t_clave[MF];

bool validar_clave(char *clave, int long_min, int long_max);
bool esPar(char digito);
bool esDigito(char letra);
void ingresarCadena(char *cadena, int ml);

int main(void)
{    
	t_clave clave;
    printf("Ingrese una clave compuesta entre 6 y 12 digitos con mayor prominencia de numeros pares:\n");
	ingresarCadena(clave,MF);
	if(validar_clave(clave,6,12))
		printf("Clave valida");
	else
		printf("Clave invalida");
	printf("\n");
	printf("%s\n",clave);

    return 0;
}
bool esDigito(char digito)
{
	return(digito >= '0' && digito <= '9');
}
bool esPar(char digito)
{
	return( digito=='0' || digito=='2'|| digito=='4'||digito=='6'||digito=='8');
}

bool validar_clave(char *clave, int long_min, int long_max)
{
	bool esValida=true;
	int i=0;
	int long_clave=strlen(clave);
	int cant_par=0, cant_impar=0;

	if(long_clave>long_max || long_clave< long_min)
		esValida=false;
	while(esValida && (i<long_clave) && (clave[i]!='\n'))
	{
		if( esDigito(clave[i]) )
		{
			if (esPar(clave[i]))
				cant_par++;
			else
				cant_impar++;
		}
		else
			esValida=false;
		i++;
	}
	if(cant_impar>=cant_par)
		esValida=false;
	return esValida;
}


void ingresarCadena(char *cadena, int ml)
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








