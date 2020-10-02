#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


void ordenarEmpleados(eEmployee x[], eSectores sectores[], int tamSec, int tam)
{
    eEmployee aux;
    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(x[i].sector < x[j].sector)
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;

            }else if(x[i].sector == x[j].sector && (strcmp(x[i].lastName, x[j].lastName)>0)){

                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }



        }


    }




}


int menuAmable()
{
    int opcion;
    printf("\n****Menu de Opciones:****\n\n");
    printf("1---- Altas\n\n");
    printf("2---- Bajas\n\n");
    printf("3---- Modificar\n\n");
    printf("4---- Informes\n\n");
    printf("5---- Salir\n\n");
    printf("elija una opcion: ");
    scanf("%d", &opcion);



    return opcion;
}





void inicializarEmpleados(eEmployee x[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        x[i].isEmpty = 1;
    }

}

int buscarLibre(eEmployee x[], int tam)
{
    int libre = -1;

    for(int i = 0; i < tam; i++)
    {
        if(x[i].isEmpty != 0)
        {
            libre = i;
            break;
        }
    }
    return libre;
}

void mostrarSectores(eSectores sectores[], int tamSec)
{
    printf("\n**** Menu de Sectores: ****\n\n");
    for(int i = 0; i < tamSec; i++)
    {

        printf("%d---- %s\n\n", sectores[i].id, sectores[i].descripcion);
    }
}

int altaEmpleado(int idx, eEmployee x[], int tam, eSectores sectores[], int tamSec)
{
    int altaExitosa = 0;
    int indice;
    eEmployee aux;
    indice = buscarLibre(x, tam);


    system("cls");
    printf("**** Alta Empleado ****\n\n");
    if(indice == -1)
    {
        printf("sistema completo\n\n");

    }
    else
    {
        aux.id = idx;
        printf("\ningrese su nombre: ");
        fflush(stdin);
        gets(aux.name);

        printf("\ningrese apellido: ");
        fflush(stdin);
        gets(aux.lastName);

        printf("\ningrese sueldo: ");
        scanf("%f", &aux.salary);


        mostrarSectores(sectores, tamSec);
        printf("\ningrese sector: ");
        scanf("%d", &aux.sector);

        aux.isEmpty = 0;

        x[indice] = aux;
        altaExitosa = 1;

        printf("alta realizada con exito\n\n");
    }
    return altaExitosa;

}


void bajaEmpleado(eEmployee x[], int tam, eSectores sectores[], int tamSec)
{
    int buscado;
    int existe;
    char confirmar;
    system("cls");
    printf("\n**** Bajas ****\n\n");
    printf("ingrese id:");
    scanf("%d", &buscado);
    existe = buscarEmpleado(buscado, x, tam);
    if(existe == -1 || x[existe].isEmpty != 0)
    {
        system("cls");
        printf("\nNo existe un empleado con ese id\n\n");
    }
    else
    {
        mostrarPlantilla();
        mostrarEmpleado(x[existe], sectores, tamSec, tam);
        printf("\nconfirma la baja? s/n:");
        fflush(stdin);
        scanf("%c", &confirmar);
        if(confirmar == 's')
        {
            x[existe].isEmpty = 1;
            printf("\nOperacion exitosa.\n\n");
        }
        else
        {
            printf("\nOperacion cancelada.\n\n");
        }


    }

}
int buscarEmpleado(int idx, eEmployee x[], int tam)
{
    int existe = -1;
    for(int i = 0; i < tam; i++)
    {
        if(x[i].id == idx)
        {
            existe = i;
            break;
        }
    }

    return existe;
}

void mostrarEmpleado(eEmployee x, eSectores sectores[], int tamSec, int tam)
{
    int idSectorEmpleado = x.sector;
    int indSectorBuscado;
        indSectorBuscado = DescripcionSector(idSectorEmpleado, sectores, tamSec);


        printf("%4d   %s   %10s   %10.2f  %10s\n\n", x.id, x.name, x.lastName, x.salary, sectores[indSectorBuscado].descripcion);


}




int DescripcionSector(int idx, eSectores sectores[], int tamSec)
{

    int idSector;
    for(int i = 0; i < tamSec; i++)
    {
        if(idx == sectores[i].id)
        {
            idSector = i;
            break;
        }
    }

    return idSector;
}


void modificarEmpleado(eEmployee x[], int tam, eSectores sectores[], int tamSec)
{
    int buscado;
    int existe;
    eEmployee aux;
    system("cls");
    printf("\n**** Modificar Empleados ****\n\n");
    printf("ingrese id:");
    scanf("%d", &buscado);
    existe = buscarEmpleado(buscado, x, tam);
    if(existe == -1 || x[existe].isEmpty != 0)
    {
        system("cls");
        printf("\nNo existe un empleado con ese id\n\n");
    }
    else
    {
        mostrarPlantilla();
        mostrarEmpleado(x[existe], sectores, tamSec, tam);
        switch(menuOpciones())
        {
        case 1:
            printf("\n\nIngrese nuevo nombre:\n");
            fflush(stdin);
            gets(aux.name);
            strcpy(x[existe].name, aux.name);
            system("cls");
            printf("\n\nModificacion realizada de manera exitosa\n\n");
            break;
        case 2:
            printf("\n\nIngrese nuevo apellido:\n");
            fflush(stdin);
            gets(aux.lastName);
            strcpy(x[existe].lastName, aux.lastName);
            system("cls");
            printf("\n\nModificacion realizada de manera exitosa\n\n");
            break;
        case 3:
            printf("\n\nIngrese nuevo sueldo:\n");
            scanf("%f", &aux.salary);
            x[existe].salary = aux.salary;
            system("cls");
            printf("\n\nModificacion realizada de manera exitosa\n\n");
            break;
        case 4:
            system("cls");
            mostrarSectores(sectores, tamSec);
            printf("\n\nIngrese nuevo sector:\n");
            scanf("%d", &aux.sector);
            x[existe].sector = aux.sector;
            system("cls");
            printf("\n\nModificacion realizada de manera exitosa\n\n");
            break;


        }


    }
}
int menuOpciones()
{
    int opcion;
    printf("\nque desea modificar?: \n\n");
    printf("1---- Nombre\n\n");
    printf("2---- Apellido\n\n");
    printf("3---- Sueldo\n\n");
    printf("4---- Sector\n\n");
    scanf("%d", &opcion);



    return opcion;




}

void informarEmpleados(eEmployee x[], eSectores sectores[], int tam, int tamSec)
{
    switch(menuInformes())
    {
    case 1:
        ordenarEmpleados(x, sectores, tamSec, tam);
        mostrarEmpleados(x, sectores, tamSec, tam);
        break;
    case 2:
        totalSalarios(x, tam, sectores, tamSec);
        break;

    }


}

int menuInformes()
{
    int opcion;
    system("cls");
    printf("\n****Menu Informes**** \n\n");
    printf("\n1---- Listar Empleados\n\n");
    printf("2---- Mostrar total de salarios y promedio\n\n");
    printf("indique una opcion: ");
    scanf("%d", &opcion);



    return opcion;


}

void mostrarEmpleados(eEmployee x[], eSectores sectores[], int tamSec, int tam)
{
    int flag = 0;
    mostrarPlantilla();
    for(int i = 0; i < tam; i++)
    {
        if(x[i].isEmpty == 0)
        {
            mostrarEmpleado(x[i], sectores, tamSec, tam);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\n\nNo hay empleados que listar.\n\n");
    }

}



void mostrarPlantilla()
{
    printf("\nid      nombre    apellido       sueldo      sector\n\n");

}





void totalSalarios(eEmployee x[], int tam, eSectores sectores[], int tamSec){
float acumulador = 0;
int empleados = 0;
float promedio;
for(int i = 0; i < tam; i++){
    if(x[i].isEmpty == 0){
    acumulador += x[i].salary;
    empleados++;
    }
}


promedio = acumulador / empleados;
printf("\n\nEl total de los salarios es: %.2f\n\n", acumulador);
printf("\n\nEl promedio de los salarios es: %.2f\n\n", promedio);
printf("los empleados que superan el promedio en salario son: \n\n");
for(int i = 0; i < tam; i++){
    if(x[i].salary > promedio && x[i].isEmpty == 0){
        mostrarEmpleado(x[i], sectores, tamSec, tam);
    }

}


}


