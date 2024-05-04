/******************************************************************************
                    Copyright (c) 2024 Alfredo Godoy <a.k.a aunhaymas> 11:24:57
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
/*
Se tiene un registro de la temperatura por hora (0 a 23) por día (1 a n) de
un mes, ordenada cronológicamente. Se pide: 
a) Ingresar el número de mes
para conocer la cantidad de días registrados. 
b) Cargar el listado en una matriz
e informarla en forma bidimensional. 
c) Informar además la máxima y la mínima temperatura por día, 
la máxima y la mínima temperatura del mes
*/

#define MFD 31	//Días máximos
#define MFH 24	//Horas
typedef float t_mat[MFD][MFH];

int my_atoi(const char *string);
int cuantos_dias(int mes);
void validar_mes(int *mes)
{
	int valor;
	char s_valor[3];
	printf("Ingrese número de mes (1 a 12): ");
	fgets(s_valor,3,stdin);
	fflush(stdin);
	valor = my_atoi(s_valor);
	while(valor < 1 || valor >12)
	{
		printf("Ingrese número de mes (1 a 12): ");
		fgets(s_valor,3,stdin);
		fflush(stdin);
		valor = my_atoi(s_valor);
	}
	*mes = valor;
}

void mostrar_mat(t_mat mat, int mes, float dia_max[MFD],float dia_min[MFD],float *mes_max,float *mes_min)
{
	*mes_max=0.0f;
	*mes_min=99999.0f;
	int horas = 24;
	int d,h;
	int dias = cuantos_dias(mes);
	for(d=0;d<dias;d++)
	{
		dia_max[d]=0.0f;
		dia_min[d]=99999.0f;
		printf("   Dia %d\nHora\tTemperatura\n",d+1);
		for(h=0;h<horas;h++)
		{
			printf("%d\t%.2f\n",h,mat[d][h]);
			if (dia_max[d]<mat[d][h])
				dia_max[d]=mat[d][h];
			if(dia_min[d]>mat[d][h])
				dia_min[d]=mat[d][h];
		}
		printf("Temperatura maxima del dia: %.2f\n",dia_max[d]);
		printf("Temperatura minima del dia: %.2f\n",dia_min[d]);
		if(*mes_max<dia_max[d])
			*mes_max=dia_max[d];
		if(*mes_min>dia_min[d])
			*mes_min=dia_min[d];
		printf("\n");
	}
	printf("Temperatura maxima del mes: %.2f\n",*mes_max);
	printf("Temperatura minima del mes: %.2f\n",*mes_min);

}
float fgenerar_temp(float tmin, float tmax)
{
	return tmin + ((float)rand()/RAND_MAX) * (tmax - tmin);
}
void cargar_mat(t_mat mat,int mes)
{
	srand(time(NULL));
	int d,h;
	int dias = cuantos_dias(mes);
	for(d=0;d<dias;d++)
	{
		for(h=0;h<24;h++)
		{
			mat[d][h] = fgenerar_temp(2.0f,37.1f);
		}
	}
}

int my_atoi(const char *string)
{
	//48
	int numero = 0;
	while(*string!='\n' && *string!='\0')
	{
		if(*string>='0' && *string<='9')
		{
			numero= numero*10 + *string - '0';
		}
		string++;
	}
	return numero;
}
int cuantos_dias(int mes)
{
	int mlf_dias = 0;//depende del mes
	//[31,28,31,30,31,30,31,31,30,31,30,31]
	//[en,fe,ma,ab,my,jn,jl,ag,sp,oc,nv,dc]
	//31 Enero Marzo Mayo Julio Agosto Octubre Diciembre 	1 3 5 7 8 10 12
	//30 Abril Junio Septiembre Noviembre					4 6 9 11
	//28 Febrero											2
	switch (mes)
	{
		case 2:
			mlf_dias = 28;
			break;
		case 1:
		case 3: 
		case 5: 
		case 7:
		case 8: 
		case 10:
		case 12: 
			mlf_dias = 31;
			break;
		default:
			mlf_dias = 30;
			break;
	}
	return mlf_dias;
}
int main(void)
{    
	/* *nombre_mes 		en lugar de 
	 *  nombre_mes[12][]
	 *			   |  |
	 *		 	mes  longitud del nombre

		*nombre_mes[12] ó *nombre_mes[]
	las dimensiones de un array multidimensional deben especificarse
	completamente, excepto la primera dimensión.
	*/
	const char *nombre_mes[12]= {"Enero","Febrero","Marzo","Abril","Mayo",
		"Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
	char numero[100];
	t_mat temperatura;
	int mes;
	float temp_mes_max,temp_mes_min;
	float temp_dia_max[MFD];
	float temp_dia_min[MFD];
	validar_mes(&mes);
	printf("el mes ingresado es: %s y tiene %d dias\n",nombre_mes[mes-1],cuantos_dias(mes));
	cargar_mat(temperatura,mes);
	mostrar_mat(temperatura,mes,temp_dia_max,temp_dia_min,&temp_mes_max,&temp_mes_min);
    return 0;
}

