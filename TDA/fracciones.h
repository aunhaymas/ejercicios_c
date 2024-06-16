#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int numerador;
    int denominador;
} T_Fraccion;
/*
Pre: recibe dos T_fraccion 
Post: Devuelve un valot T:Fraccion con la suma de las fracciones recibidos desde el modulo invocador
*/
T_Fraccion sumar(T_Fraccion A, T_Fraccion B);
/*
PRE: recibe numerador numero entero y denominador entero no puede ser 0
POST: Crea una variable del tipo fraccion utilizando los numeros recibidos por parametro
*/
T_Fraccion cargar(int numerador, int denominador);

/*
*    PRE: 2 Variables del tipo FRACCION creadas en el modulo invocante.
*    POST: Retorna una variable del mismo tipo con la resta de las 2 variables enviadas.
*/

T_Fraccion resta(T_Fraccion A, T_Fraccion B);

/*
  pre : dos variables de tipo T_Fraccion  creados en el modulo invocante
  post: retorna el producto de ambos números T_Fraccion  recibidos
*/
T_Fraccion multiplicar(T_Fraccion A, T_Fraccion B);

/*
  pre : dos variables de tipo T_Fraccion  creados en el modulo invocante
  post: retorna si ambos números T_Fraccion recibidos son iguales
*/
bool igual(T_Fraccion A, T_Fraccion B);

int numerador(T_Fraccion x);
int denominador(T_Fraccion x); 

/*
*    PRE: 2 Variables del tipo FRACCION creadas en el modulo invocante.
*    POST: Retorna una variable del mismo tipo con la division de las 2 variables enviadas.
*/

T_Fraccion dividir(T_Fraccion A, T_Fraccion B);

/*
*    PRE: 1 Variable del tipo FRACCION creadas en el modulo invocante.
*    POST: Retorna una variable de tipo FRACCION con la division de las 2 variables enviadas.
*/

T_Fraccion simplificar(T_Fraccion F);

