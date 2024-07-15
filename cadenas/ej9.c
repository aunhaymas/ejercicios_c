#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
/*
HIJOS DE PUTA COMO MIERDA VOY A OPERAR CON VOCALES ACENTUADAS SI NO ME DAN LAS LIBRERIAS #include <wchar.h>
#include <wctype.h>


CHUPENLA

Escribir una función que recibirá por parámetro, una palabra, que representa un
sustantivo en singular.
La función deberá devolver, el plural de dicho sustantivo, aplicando las
siguientes reglas:
a. Agregar una “s” al final, si la palabra termina en vocal sin acento.
b. Agregar una “s” al final, si la palabra termina con una é (acentuada).

c. reemplazamos por “ces”, Si la palabra termina en “z”.

d. Agregamos “es” al final, si la palabra termina en una consonante (a excepción
de la “s”, la “z”, y la “x”), ó si la palabra termina con las vocales acentuadas: á,
í, ó, ú.

e. Si el sustantivo termina en “s” ó “x”, entonces el plural es igual al singular,
por lo tanto la función deberá devolver lo mismo que recibió.
*/
#define MF 49
typedef char t_cadena[MF];

bool esVocal(char c);
bool esZ(char c);
bool esVocalAcentuada(const char *c);

bool esSoX(char c);

void pasarAPlurar(t_cadena cadena);

int main(void)
{

  t_cadena palabra = "perroáó";
  printf("%s \n", palabra);
  pasarAPlurar(palabra);
  return 0;
}
/////////////////////////////////////////////////////////////////////////////////
void pasarAPlurar(t_cadena cadena)
{
  const char *CES = "ces";
  const char *letrae="é";
  int logitudCadena = strlen(cadena);
  char *ultima = strrchr(cadena, '\0');  // Apunta al final de la cadena
  ultima--; // me voy a la ultima letra
  printf("%s \n",ultima);
  printf("%s \n",ultima);
  printf("%d \n",*ultima);
  char ultimoChar = ultima[0];
  if (ultimoChar == 's' || ultimoChar == 'x')
  {
    printf("%s ya está en plural \n", cadena);
  }
  else if (esVocal(ultimoChar) || strcmp(ultima,"é") )
  {
    /*agregar a s*/
    strcat(cadena,"s");
  }
  else if (esZ(ultimoChar))
  {
    /*cambiar a ces*/
  }
  else if (!esVocal(ultimoChar))
  {
    /*agregar a es*/
    strcat(cadena,"es");
  }
  else
  {
    /*No sé, pa*/
    printf("ay no se");
  }
  printf("el ultimo caracter es %c \n", ultimoChar);
  
}

bool esVocal(char c)
{
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
bool esZ(char c)
{
  return (c == 'z');
}
bool esVocalAcentuada(const char *c) {
    // Consideramos que las vocales acentuadas ocupan 2 bytes en UTF-8
    if (strcmp(c, "á") == 0 || strcmp(c, "é") == 0 || strcmp(c, "í") == 0 ||
        strcmp(c, "ó") == 0 || strcmp(c, "ú") == 0 || strcmp(c, "Á") == 0 ||
        strcmp(c, "É") == 0 || strcmp(c, "Í") == 0 || strcmp(c, "Ó") == 0 ||
        strcmp(c, "Ú") == 0) {
        return 1;
    }
    return 0;
}
bool esSoX(char c)
{
  return (c == 's' || c == 'x');
}