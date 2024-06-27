/******************************************************************************
                    Copyright (c) 2024 Alfredo Godoy <a.k.a aunhaymas> 22:37:37
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
size_t strlen(const char *__str) tamaño de la cadena
char *strcpy(char *__dest, const char * __src) copia  __src a __dest
char *strcat(char *__dest, const char *__src) concatena __src a __dest
int strcmp(const char *__srt1, const char *__str2) compara 2 cadenas
char *strstr(const char *__str, const char *__needle)
size_t strcspn(const char *str1, const char *str2) devuelve longitud antes de
cualquier char que exista en  *str2

 Escribir una función en C que reciba como primer parámetro, una cadena de tipo
t_cadena, y devuelva como segundo parámetro, la misma cadena pero invertida,
sin considerar los blancos.
Sólo se deben invertir las posiciones con caracteres ciertos, y no aquellas
posiciones potenciales a ser utilizadas pero que podrían contener caracteres
inciertos.
Recorrer la cadena a lo sumo una vez.
Declare un tipo t_cadena acorde.
Escribir el programa que incluya a la función y las invocaciones con los
siguientes casos y las impresiones para comprobar que devuelven lo correcto.
Casos:
invertir_cadena("Hola, me llamo Ana.", cad_invertida) ==> cad_invertida: ".anAomallem,aloH"
invertir_cadena("234561", cad_invertida) ==> cad_invertida: "165432"
invertir_cadena(" ", cad_invertida) ==> cad_invertida: ""
invertir_cadena("Somos o No somos", cad_invertida) ==> cad_invertida: "somosoNsomoS"
*/
#define T_MAX 41
typedef char t_cadena[T_MAX];
void invertir_cadena(const t_cadena cadena, t_cadena invertida);

int main(void)
{
  t_cadena cadena_base = "Hola, me llamo Ana.";
  t_cadena cadena_base_2 = "234561";
  t_cadena cadena_base_3 = " ";
  t_cadena cadena_base_4 = "Somos o No somos";
  t_cadena cadena_invertida;
  
  invertir_cadena(cadena_base, cadena_invertida);
  printf("%s \n",cadena_base, cadena_invertida);
  invertir_cadena(cadena_base_2, cadena_invertida);
  printf("%s \n", cadena_invertida);
  invertir_cadena(cadena_base_3, cadena_invertida);
  printf("%s \n", cadena_invertida);
  invertir_cadena(cadena_base_4, cadena_invertida);
  printf("%s \n", cadena_invertida);
  return 0;
}
void invertir_cadena(const t_cadena cadena, t_cadena invertida)
{
  int tam = strlen(cadena);
  int i = tam - 1, j = 0;
  while (i >= 0)
  {
    if (cadena[i] != ' ')
    {
      invertida[j] = cadena[i];
      j++;
    }
    invertida[j] = '\0';
    i--;
  }
}
