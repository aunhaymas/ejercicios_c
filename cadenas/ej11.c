#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
11. Escribir un programa modular en C, que solicite el ingreso de no más de 20
palabras. C
Cada palabra no tendrá más de 20 caracteres. Informar:
1. Mostrar las palabras ingresadas.
2. Cuál es la palabra más larga.
3. Solictar el ingreso de una palabra, e indicar si la misma se encuentra entre
las ingresadas. 
*/
#define MF 21
#define VMF 20
typedef char t_cadena[MF];
typedef t_cadena v_cadenas[VMF];

void ingresarPalabra(t_cadena cadena);
void vecIngresarPalabras(v_cadenas cadenas,int *ml);

void mostrarPalabras(v_cadenas cadenas, const int ml);
int palabraMasLarga(v_cadenas cadenas,const int ml);
bool existePalabra(const t_cadena,const v_cadenas,const int ml);
////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
  v_cadenas cadenas;
  t_cadena existe;
  int ml;
  vecIngresarPalabras(cadenas,&ml);
  mostrarPalabras(cadenas,ml);
  printf("La palabra más larga es: %s \n", cadenas[palabraMasLarga(cadenas,ml)]);
  
  printf("Ingrese una palabra: ");

  ingresarPalabra(existe);
  if (existePalabra(existe,cadenas,ml))
    printf("La palabra [%s] existe en la lista\n",existe);
  else
    printf("No existe [%s] en la lista\n",existe);
  return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void ingresarPalabra(t_cadena cadena){
  char c;
  int j=0;
  c=getchar();
  while (j<MF-1 && c!=EOF && c!='\n'){
    cadena[j]=c;
    c=getchar();
    j++;
  }
  cadena[j]='\0';
  fflush(stdin);
}
void vecIngresarPalabras(v_cadenas cadenas, int *ml){
  int j=0;
  char continuar='S';
  *ml=0;
  while (j<VMF && (continuar=='S' || continuar=='\n'))
  {
    printf("Ingrese una palabra: ");
    ingresarPalabra(cadenas[j]);
    printf("Continuar(S/n): ");
    continuar = getchar();
    j++;
    (*ml) ++;
  }
  getchar();
}
void mostrarPalabras(v_cadenas cadenas, const int ml){
  int i;
  printf("Lista de palabras: \n");
  for(i=0;i<ml;i++)
    printf("%s \n", cadenas[i]);
}
int palabraMasLarga(v_cadenas cadenas, const int ml){
  size_t i;
  int mayorId=0;

  t_cadena *cadenaMayor = cadenas;

  for (i = 1; i < ml-1; i++)
  {
    if (strlen(*cadenaMayor)<strlen(cadenas[i])){
      cadenaMayor=&cadenas[i];
      mayorId = i;
    }
  }
  return mayorId; 
}
bool existePalabra(const t_cadena cadena,const v_cadenas cadenas, const int ml){
  size_t i=0;
  bool encontrado = false;
    while (!encontrado && i<ml)
    {
      if(strcmp(cadena,cadenas[i]) == 0){
        encontrado=true;
      }
      i++;
    }
    return encontrado;
}