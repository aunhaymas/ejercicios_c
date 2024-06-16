#include <stdio.h>
#include <stdbool.h>


// Estructura
typedef struct  { 
	float Real;
	float Imaginaria;
} T_Complejo;


/***************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  pre : variable de tipo COMPLEJO creado en el modulo invocante
  post: asinga los valores recibidos por parametro a T_Complejo

  real : float a asignar a la parte real del complejo que retorna
  imag : float a asignar a la parte imaginaria del complejo que retorna
*/
T_Complejo Cargar(float real, float imag);

/*--------------------------*/

/*
  pre : variable de tipo COMPLEJO creado en el modulo invocante
  post: retorna la parte real del complejo que retorna del numero complejo recibido 
*/
float Real(T_Complejo C);

/*--------------------------*/

/*
  pre : variable de tipo COMPLEJO creado en el modulo invocante
  post: retorna la parte imaginaria del numero complejo recibido 
*/
float Imag(T_Complejo C);
/*--------------------------*/

/*
  pre : dos variables de tipo COMPLEJO s  creados en el modulo invocante
  post: retorna la suma de ambos números COMPLEJO recibidos
*/
T_Complejo Sumar(T_Complejo A, T_Complejo B);
/*--------------------------*/

/*
  pre : dos variables de tipo COMPLEJO s  creados en el modulo invocante
  post: retorna el producto de ambos números COMPLEJO s recibidos
*/
T_Complejo Multiplicar(T_Complejo A, T_Complejo B);
/*--------------------------*/

/*
  pre : dos variables de tipo COMPLEJO  creados en el modulo invocante
  post: retorna si ambos números COMPLEJO recibidos son iguales
*/
bool Igual(T_Complejo A, T_Complejo B);
/*--------------------------*/

// funciones auxiliares

/*
  pre : una variable de tipo COMPLEJO creado en el modulo invocante
  post: muestra los campos de la variable
*/
void Mostrar(T_Complejo C);
  
int main() 
{ 
    T_Complejo A,B,C,D;
    float real, imag;

 	printf("**Introduzca el primer numero COMPLEJO\n");
	printf("Parte real:\n");
	scanf("%f",&real);
	printf("Parte Imaginaria:\n");
	scanf("%f",&imag);
	A = Cargar(real,imag);

  	printf("**Introduzca el segundo numero COMPLEJO\n");
	printf("Parte real:\n");
	scanf("%f",&real);
	printf("Parte Imaginaria:\n");
	scanf("%f",&imag);
	B = Cargar(real,imag);
    
    Mostrar (Sumar(A,B));
    Mostrar (Multiplicar(A,B));
    
    if (Igual(Sumar(A,B),Multiplicar(A,B))){
        printf("\nLa suma y multiplicación de los numeros complejos son iguales:\n");
    } else { 
	    printf("\nLa suma y multiplicación de los numeros complejos NO son iguales\n");
    } 
 	
    return 0;
}




// Implementacion de las funciones

T_Complejo Cargar(float real, float imag){
    T_Complejo C;
    
    C.Real=real;
    C.Imaginaria=imag;

    return C;
}
float Real(T_Complejo C){
  return C.Real;
}
float Imag(T_Complejo C){
  return C.Imaginaria;
}
T_Complejo Sumar(T_Complejo A, T_Complejo B){
  T_Complejo suma;
  suma.Real = A.Real + B.Real;
  suma.Imaginaria = A.Imaginaria + B.Imaginaria;
  return suma;
}
T_Complejo Multiplicar(T_Complejo A, T_Complejo B){
  T_Complejo mult;
  mult.Real = A.Real * B.Real;
  mult.Imaginaria = A.Imaginaria * B.Imaginaria;
  return mult;
}
bool Igual(T_Complejo A, T_Complejo B){
  return (A.Real==B.Real && A.Imaginaria==B.Imaginaria);
}
void Mostrar(T_Complejo C){
  printf("Parte real: %f \n", C.Real);
  printf("Parte imaginaria: %f \n", C.Imaginaria);
}