#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
. Escribir un programa modular en C, que solicite el ingreso de 1 oración, de no
más de 100 caracteres.
Luego informar la cantidad de vocales minúsculas, no acentuadas, que hay en la
oración.
*/
#define MF 101
#define VMF 20
typedef char t_oracion[MF];

void limpiarBuffer();

bool esVocal(char c);
size_t cantidadVocales(const t_oracion oracion, size_t ml);
void ingresarOracion(t_oracion oracion, size_t *ml);
void mostrarOracion(const t_oracion oracion, const size_t ml);

int main()
{
  t_oracion oracion;
  size_t ml;
  printf("Ingrese una oracion: ");
  ingresarOracion(oracion, &ml);
  printf("La oracion es: ");
  mostrarOracion(oracion,ml);
  printf("La oracion tiene [%zu] vocales.\n",cantidadVocales(oracion,ml));
}

void ingresarOracion(t_oracion oracion, size_t *ml)
{
  char c;
  size_t j = 0;
  while (j < MF && (c = getchar()) != EOF && c != '\n')
  {
    oracion[j] = c;
    j++;
    (*ml)++;
  }
  oracion[j] = '\0';
}
void mostrarOracion(const t_oracion oracion, const size_t ml)
{
  size_t j = 0;
  for (j = 0; j < ml; j++){
    printf("%c", oracion[j]);
  }
  printf("\n");
}
size_t cantidadVocales(const t_oracion oracion, size_t ml){
  size_t j = 0;
  size_t cant=0;
  for (j = 0; j < ml; j++){
    if(esVocal(oracion[j]))
      cant++;
  }
  return cant;
}
bool esVocal(char c){
  const char *vocales = "aeiou";
  return(strchr(vocales,c) != NULL);
}

void limpiarBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF);    
}