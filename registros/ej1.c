/******************************************************************************
                    Copyright (c) 2024 Alfredo Godoy <a.k.a aunhaymas> 23:49:46
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <threads.h>
#include <time.h>
/*
1) Se tienen los siguientes datos de los empleados de una empresa:
Apellido y Nombre (35 caracteres)
Fecha de Nacimiento (día, mes y año)
Fecha de Ingreso (día, mes y año)
Sueldo Básico
Se conoce la cantidad N de empleados y la fecha de procesamiento.
Se pide: Imprimir un listado con los apellidos y nombres de las personas
que cumplan años en el mes y calcular e informar una suma de regalo
equivalente al uno por mil del sueldo por cada año cumplido. 
*/
#define MAX_EMPLEADOS 100
#define FACTOR_SUELDO 0.001f
#define C_MAX 36


/*Estructura para nombres y apellidos*/
typedef char t_cadena[C_MAX];
/*Fecha*/
typedef struct{
	unsigned int dia;
	unsigned int mes;
	unsigned int anio;
}t_fecha;
/*Estructura para empleado*/
typedef struct{
	t_cadena nombre;
	t_fecha nacimiento;
	t_fecha fecha_ingreso;
	float sueldo;
}t_empleado;
/*Estructura para lista de empleados*/
typedef t_empleado t_vec_empleados[MAX_EMPLEADOS];

void ingresar_empleado(t_empleado *empleado);
t_fecha ingresar_fecha();
void ingresar_nombre(t_empleado *empleado);
void mostrar_empleado(const t_empleado *empleado);
bool cumple_anios(t_empleado empleado, int mes);
float suma_regalo(t_empleado empleado, t_fecha fecha);

int main(void){    
	unsigned int i, ml;
	float suma_de_regalo;
	t_fecha fecha_actual;
	t_empleado empleado;
	t_vec_empleados vec_empleado;
	printf("Ingrese empleados: \n");
	for(i=0;i<1;i++)
	{
		ingresar_empleado(&empleado);
		vec_empleado[i] = empleado;
	}
	ml = i;
	printf("fecha_actual: ");
	fecha_actual = ingresar_fecha();

	for(i=0; i < ml ; i++)
	{
		if(cumple_anios(empleado,fecha_actual.mes)){
			suma_de_regalo = suma_regalo(empleado,fecha_actual);
			mostrar_empleado(&empleado);
			printf("\nSuma de regalo! : $%.2f\n",suma_de_regalo);
		}
	}
	return 0;
}
bool cumple_anios(t_empleado empleado, int mes){
/* 	return (empleado->nacimiento.mes == mes); //equivalente*/
	return (empleado.nacimiento.mes == mes);
}
void mostrar_empleado(const t_empleado *empleado){
	printf("Nombre: %s\n",empleado->nombre);
	printf("Nacimiento: %d/",empleado->nacimiento.dia);
	printf("%d/",empleado->nacimiento.mes);
	printf("%d\n",empleado->nacimiento.anio);
	printf("Fecha de ingreso: %d/",empleado->fecha_ingreso.dia);
	printf("%d/",empleado->fecha_ingreso.mes);
	printf("%d\n",empleado->fecha_ingreso.anio);
	printf("Sueldo: %.2f\n",empleado->sueldo);

}
float suma_regalo(t_empleado empleado, t_fecha fecha){
	float suma;
	/*No se necesita verificar nada más en anios*/
	unsigned int anios = fecha.anio - empleado.nacimiento.anio;
	suma = (float)anios * empleado.sueldo * FACTOR_SUELDO;
	return suma;
}
void ingresar_empleado(t_empleado *empleado){
	printf("Nombre Completo: ");
	ingresar_nombre(empleado);
	printf("Nacimiento\n");
	empleado->nacimiento = ingresar_fecha();
	printf("Fecha de ingreso\n");
	empleado->fecha_ingreso = ingresar_fecha();
	printf("Sueldo: ");
	scanf("%f", &empleado->sueldo);
	while(getchar()!='\n');
}
t_fecha ingresar_fecha(){
	t_fecha fecha = {1,1,2000};
	do{
	printf("Ingrese dia: ");
	scanf("%u",&fecha.dia);
	}while(fecha.dia <1 & fecha.dia >31);

	while(getchar() != '\n');/*Limpieza de buffer*/
	do{
	printf("Ingrese mes: ");
	scanf("%u",&fecha.mes);
	}while(fecha.mes<1 && fecha.mes > 12);

	while(getchar() != '\n');
	do{
	printf("Ingrese anio: ");
	scanf("%u",&fecha.anio);
	}while(fecha.anio <1900);

	while(getchar() != '\n');
	return fecha;
}

void ingresar_nombre(t_empleado *empleado){
	char c;
	t_cadena nombre;
	unsigned int i=0;

	while(	(c=getchar()) != EOF && i< C_MAX && c!='\n')
	{
		nombre[i]=c;
		i++;
	}
	nombre[i]='\0';
	/*Limpieza de buffer*/
	while(c!=EOF && c!='\n')
		c=getchar();
	strcpy(empleado->nombre,nombre);
}
