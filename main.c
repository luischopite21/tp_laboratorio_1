#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TAM 1000
#define TAMSEC 4





int main()
{
    int proximoId = 1000;
    eSectores sectores[] = {{1, "sistemas"},{2, "ventas"},{3, "legales"},{4, "contables"}};
    eEmployee empleados[TAM];
    char continuar = 's';
    char confirma;
    int banderaAlta = 0;

    inicializarEmpleados(empleados, TAM);

    do
    {
        system("cls");
        switch(menuAmable())
        {

        case 1:
            if(altaEmpleado(proximoId, empleados, TAM, sectores, TAMSEC))
            {
                proximoId++;
                banderaAlta = 1;
            }

            break;
        case 2:
            if(banderaAlta == 0){
            printf("\nprimero debe dar de alta un empleado\n\n");
            }else{

            bajaEmpleado(empleados, TAM, sectores, TAMSEC);
            }
            break;
        case 3:
            if(banderaAlta == 0){
          printf("\nprimero debe dar de alta un empleado\n\n");
            }else{

            modificarEmpleado(empleados, TAM, sectores, TAMSEC);
            }
            break;
        case 4:
            if(banderaAlta == 0){
            printf("\nprimero debe dar de alta un empleado\n\n");
            }else{

            informarEmpleados(empleados, sectores, TAM, TAMSEC);
            }
            break;
        case 5:
            printf("confirma salida? \n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                continuar = 'n';
            }
            break;


        default:
            printf("\n\nelija una opcion valida\n\n");

        }
        system("pause");

    }
    while(continuar == 's');
    return 0;
}

