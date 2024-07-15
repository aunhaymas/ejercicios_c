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
Escribir una función en C, que reciba una cadena que representa una palabra o
una frase y devuelva si la misma es o no un palíndromo.
Un palíndromo, es una palabra o frase que se lee igual en ambos sentidos.
Probar la función con los siguientes casos de prueba:
- anilina (Es palíndromo)
- ojo (Es palíndromo)
- radar (Es palíndromo)
- reconocer (Es palíndromo)
- amar a roma (Es palíndromo) MENTIRAS
- ana lava lana (Es palíndromo)
- a ti no, bonita (Es palíndromo)
- algoritmos y programas (No es palíndromo)
- lenguaje C (No es palíndromo)
Evitar realizar ciclos innecesarios.
*/
#define MF 49
typedef char t_cadena[MF];

bool esPalindromo(t_cadena cadena, size_t tam);
bool esLetra(char car);
int main(void)
{
  t_cadena cadena;
  strcpy(cadena, "a ti no, bonita");
  printf("%s es palindromo? %d \n", cadena, esPalindromo(cadena, strlen(cadena)));
  strcpy(cadena, "amar a roma");
  printf("%s es palindromo? %d \n", cadena, esPalindromo(cadena, strlen(cadena)));
  strcpy(cadena, "algoritmos y programas ");
  printf("%s es palindromo? %d \n", cadena, esPalindromo(cadena, strlen(cadena)));
  strcpy(cadena, "ana lava lana");
  printf("%s es palindromo? %d \n", cadena, esPalindromo(cadena, strlen(cadena)));
  
  return 0;
}

bool esPalindromo(t_cadena cadena, size_t tam)
{
  bool validar = true;
  int i = 0, j = tam - 1;
  while (validar && i < j)
  {
    if (!esLetra(cadena[i]))
      i++;
    else if (!esLetra(cadena[j]))
      j--;
    else
    {
      if (cadena[i] != cadena[j])
        validar = false;
      else
      {
        i++;
        j--;
      }
    }
  }
  return validar;
}
bool esLetra(char car)
{
  return (car >= 'a' && car <= 'z' || car >= 'A' && car <= 'Z');
}
