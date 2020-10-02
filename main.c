#include <stdio.h>
#include <stdlib.h>
#include "luis.h"


int main()
{
char continuar = 's';
int x;
int y;
int calcularOperaciones;
int suma;
int resta;
int multiplicacion;
float division;
int factorialDeX;
int factorialDeY;
calcularOperaciones = 0;
x = 0;
y = 0;
do{
switch(menuDeOpciones()){
case 1: printf("\ningrese primer operando: ");
        scanf("%d", &x);
        calcularOperaciones = 0;

break;
case 2: printf("\ningrese segundo operando: ");
        scanf("%d", &y);
        calcularOperaciones = 0;
break;
case 3:
    suma = sumar(x, y);
    resta = restar(x, y);
    multiplicacion = multiplicar(x, y);
    division = dividir(x, y);
    factorialDeX = factorial(x);
    factorialDeY = factorial(y);
    calcularOperaciones = 1;

    printf("\nOperaciones calculadas exitosamente.\n ");
break;
case 4:
    if(calcularOperaciones == 0){
        printf("\n\nPrimero calcule las operaciones...\n\n");
    }else{
    system("cls");
    printf("\n\n******Informes: *******\n\n");
    printf("el resultado de %d + %d es: %d\n\n", x, y, suma);
    printf("el resultado de %d - %d es: %d\n\n", x, y, resta);
    printf("el resultado de %d * %d es: %d\n\n", x, y, multiplicacion);
    printf("el resultado de %.0f / %.0f es: ", (float)x, (float)y);
    if(y == 0){
        printf("No es posible dividir por cero.\n\n");
    }else{
    printf("%.2f\n\n", division);
    }
    printf("el factorial de %d es: ", x);
    if(x > 12){
        printf("error. numero muy grande.\n");
    }else if(x < 0){
        printf("\nerror. ingrese numero positivo\n");
    }else{

    printf("%d", factorialDeX);
    }
     printf(" y el factorial de %d es: ", y);
    if(y > 12){
         printf("error. numero muy grande.\n\n");
    }else if(y < 0){
        printf("\nerror. ingrese numero positivo\n");

    }else{

   printf("%d\n\n", factorialDeY);
    }
    }
break;
case 5: continuar = 'n';
break;
default: printf("opcion no valida \n");

}
system("pause");
printf("presione una tecla para continuar... ");
}while(continuar != 'n');
    return 0;

}


