#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
14. Escribir un programa que solicite el ingreso de un texto que será enviado
mediante un telegrama. Luego de ingresado, se deberá informar la cantidad de
palabras que lo componen y el importe a abonar por el solicitante.
El texto sólo puede contener, letras, números y los siguientes signos de
puntuación: . , ; : ()
Para el cálculo de las palabras, considerar que una palabra estará separada de
otra, por uno ó más blancos.

Para el cálculo del importe a abonar, deberá considerar que cada palabra pagará
$10 por cada 3 caracteres. Por las fracciones menores a los 3 caracteres, pagará
$8.
*/
#define MF 101
#define VMF 20
typedef char t_oracion[MF];
bool validar_texto(t_oracion oracion, size_t tam);
bool validar_signo(char *c);
bool validar_letra(char *c);
bool validar_numero(char *c);
float importeAbonar(const t_oracion oracion, size_t tam);

int main()
{
  t_oracion oracion;
  strcpy(oracion,"  Hola que tal");
  size_t tam = strlen(oracion);
  printf("Cadena completa: %s\n", oracion);
  if (validar_texto(oracion,tam))
    printf("Cadena valida\n");  
  else
    printf("Cadena no valida\n");
  
  printf("Importe: %0.2f\n", importeAbonar(oracion,tam));
  return 0;
}
bool validar_texto(t_oracion oracion, size_t tam){
  size_t i=0;
  bool texto_valido = true;
  while (texto_valido && i<tam)
  {
    texto_valido=validar_letra(&oracion[i]) || validar_numero(&oracion[i]) || validar_signo(&oracion[i]);
    i++;
  }
  return texto_valido;
}
bool validar_letra(char *c){
  return(
    ((*c)>='a' &&  (*c)<='z')
    || 
    ((*c)>='A' &&  (*c)<='Z')
  );
}
bool validar_numero(char *c){
  return((*c)>='0' && (*c)<='9');
}
bool validar_signo(char *c){
  return(
    (*c)==' ' ||
    (*c)=='.' ||
    (*c)==',' ||
    (*c)==';' ||
    (*c)==':' ||
    (*c)=='(' ||
    (*c)==')'
    );
}
float importeAbonar(const t_oracion oracion, size_t tam){
  const float tres_caracteres = 10.0f; 
  const float palabra_corta = 8.0f;
  float importe=0;
  int contador=0;
  size_t j=0;
  while (j<tam)
  {
    contador++;
    if(oracion[j]==' '){
      contador=0;
    }
    else if(contador>=3){
      importe += tres_caracteres;
      contador=0;
    }
    
    else if (contador>=2 && (oracion[j+1]==' ' || oracion[j+1] == '\0') )
    {
      importe+=palabra_corta;
      contador=0;
    }
    
    j++;
  }
  return importe;
}