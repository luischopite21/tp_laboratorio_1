#include <stdio.h>
#include <stdlib.h>

int menuDeOpciones(){
    int opcion;
    system("cls");
printf("****Calculadora****\n\n\n");
printf("1. ingresar primer operando\n\n");
printf("2. ingresar segundo operando\n\n");
printf("3. calcular todas las operaciones\n\n");
printf("4. informar resultados\n\n");
printf("5. salir\n\n");
scanf("%d", &opcion);
return opcion;

}



int sumar(int a, int b){
int respuesta;
respuesta = a + b;
return respuesta;
}

int restar(int a, int b){
int respuesta;
respuesta = a - b;
return respuesta;}

int multiplicar(int a, int b){
int respuesta;
respuesta = a * b;
return respuesta;
}

float dividir(float a, float b){
float respuesta;
respuesta = a / b;
return respuesta;
}

int factorial(int a){
    int fact = 1;
for(int i = 1; i <= a; i++){
    fact = fact * i;
}
return fact;
}

