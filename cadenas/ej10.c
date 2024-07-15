/******************************************************************************
                    Copyright (c) 2024 Alfredo Godoy <a.k.a aunhaymas> 05:43:18
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
/*
0. Escribir un programa modular que solicite el ingreso de dos palabras y luego
muestre las mismas según la longitud de cada una de ellas, mostrando primero
la de menor longitud.

A igualdad de longitud, mostrar primero la menor de las dos, en términos de
orden alfabético.
Las palabras tienen una longitud máxima de 15 caracteres.
*/
#define MF 16
typedef char t_cadena[MF];
typedef t_cadena t_cadenas[2];

void limpiarBuffer();
void ingresarPalabra(t_cadena cadena, int* tam);
void mostrarEnOrden(t_cadenas cadenas);
int main(void){
  int ml1;
  int ml2;
  t_cadena cadena1;
  t_cadena cadena2;
  t_cadena cadenas[2];
  ingresarPalabra(cadena1,&ml1);
  printf("%s\n",cadena1);
  ingresarPalabra(cadena2,&ml2);
  printf("%s\n",cadena2);

  strcpy(cadenas[0],cadena1);
  strcpy(cadenas[1],cadena2);
  printf("\n");
  mostrarEnOrden(cadenas);
  return 0;
}
void ingresarPalabra(t_cadena cadena, int* tam){
  char c;
  int j=0;
  printf("Ingrese palabra: ");
  while (j<MF && (c=getchar())!= '\n' && c!= EOF )
  {
    cadena[j]=c;
    j++;
  }
  cadena[j]='\0';
  (*tam)=(j-1);
}
void mostrarEnOrden(t_cadenas cadenas){
  int diferencia = strlen(cadenas[0])-strlen(cadenas[1]);
  if (diferencia<0){
    printf("%s \n",cadenas[0]);
    printf("%s \n",cadenas[1]);
  }
  else if (diferencia>0){    
    printf("%s \n",cadenas[1]);
    printf("%s \n",cadenas[0]);
  }
  else{
    diferencia = strcmp(cadenas[0],cadenas[1]);
    if(diferencia<0){
      printf("%s \n",cadenas[0]);
      printf("%s \n",cadenas[1]);
    }
    else{
      printf("%s \n",cadenas[1]);
      printf("%s \n",cadenas[0]);
    }
  }
  
}