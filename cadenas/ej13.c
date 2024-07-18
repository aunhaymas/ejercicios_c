#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
 Escribir un programa modular en C, que solicite el ingreso de 3 oraciones, de
no más de 50 caracteres cada una.
Luego informar:
1. Cuál es la oración más larga.
2. Si hay al menos 2 oraciones iguales.
3. Solicitar el ingreso de una palabra o parte de una oración, e indicar si la
misma se encuentra en las oraciones, y en cuales.


*/
#define MF 51
#define VMF 3
typedef char t_oracion[MF];
typedef t_oracion v_oracion[VMF];

void ingresar_oracion(t_oracion oracion);
void ingresar_oraciones(v_oracion oraciones, size_t tam);
void mostrar_oraciones(v_oracion oraciones, size_t tam);

char *oracion_mas_larga(v_oracion oraciones,size_t tam);
bool oracion_duplicada(const v_oracion oraciones);
void oracion_busqueda(const v_oracion oraciones);

int main()
{
  v_oracion oraciones;
  printf("Ingrese 3 oraciones\n");
  ingresar_oraciones(oraciones, VMF);
  printf("Las 3 oraciones son: \n");
  mostrar_oraciones(oraciones,VMF);
  printf("La oracion más larga es: %s \n",oracion_mas_larga(oraciones,VMF));
  return 0;
}

void ingresar_oracion(t_oracion oracion)
{
  char c;
  size_t j = 0;
  while (j < MF - 1 && (c = getchar()) != EOF && c != '\n')
  {
    oracion[j] = c;
    j++;
  }
  oracion[j] = '\0';
}
void ingresar_oraciones(v_oracion oraciones, size_t tam)
{
  size_t j;
  for (j = 0; j < tam; j++)
  {
    printf("Ingrese una oracion: ");
    ingresar_oracion(oraciones[j]);
  }
}
void mostrar_oraciones(v_oracion oraciones,size_t tam)
{
  size_t j;
  for (j = 0; j < tam; j++)
    printf("%s \n", oraciones[j]);
}
char *oracion_mas_larga(v_oracion oraciones,size_t tam){
  size_t tamMaxIndex = 0;
  size_t i;
  for(i=1;i<tam;i++)
    if(strlen(oraciones[i])>strlen(oraciones[tamMaxIndex]))
      tamMaxIndex=i;
  return oraciones[tamMaxIndex];
}