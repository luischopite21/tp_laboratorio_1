#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];


} eSectores;


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;

#endif // FUNCIONES_H_INCLUDED
/** \brief muestra las opciones a elegir en el programa
 *

 * \return la opcion elegida por el usuario
 *
 */
int menuAmable();




/** \brief cambia a "1" todas las posiciones en isEmpty de un vector del tipo eEmployee
 *
 * \param vector a modificar
 * \param tamaño del vector
 *
 */

void inicializarEmpleados(eEmployee x[], int tam);



/** \brief da de alta un empleado para que pueda ser utilizado por otras funciones
 *
 * \param id a asignar al empleado
 * \param vector donde se guardan los empleados dados de alta
 * \param tamaño del vector de empleados
 * \param sectores a los que puede pertenecer un empleado
 * \param tamaño de los sectores
 * \return 1 si pudo dar el alta con exito o un 0 si la operacion no se culmino de manera exitosa
 *
 */

int altaEmpleado(int idx, eEmployee x[], int tam, eSectores sectores[], int tamSec);





/** \brief busca el indice del primer empleado que no este habilitado
 *
 * \param vector donde busca los empleados
 * \param tamaño del vector
 * \return el indice donde encontro el primer empleado, o devuelve -1 si no consigue un indice libre
 *
 */

int buscarLibre(eEmployee x[], int tam);




/** \brief muestra los sectores a escoger por un empleado
 *
 * \param  vector donde se encuentran los posibles sectores
 * \param  tamaño del veector de sectores
 *
 */

void mostrarSectores(eSectores sectores[], int tamSec);




/** \brief cambia el estado de un empleado a inactivo
 *
 * \param vector de los empleados a buscar
 * \param tamaño del vector de empleados
 * \param vector de sectores donde puede estar un empleado
 * \param tamaño del vector sectores
 *
 */

void bajaEmpleado(eEmployee x[], int tam, eSectores sectores[], int tamSec);




/** \brief busca un empleado en un vector de empleados
 *
 * \param id del empleado a buscar
 * \param vector de empleados en donde buscar
 * \param tamaño del vector de empleados
 * \return devuelve -1 sino consigue el empleado, sino devuelve el indice donde se encuentra en el sector
 *
 */

int buscarEmpleado(int idx, eEmployee x[], int tam);




/** \brief te indica la descripcion del sector del cual le estas pasando el id
 *
 * \param id del sector que buscas
 * \param el vector de sectores donde buscar
 * \param tamaño del vector de sectores
 * \return el indice en donde se encuentra la descripcion buscada por id
 *
 */

int DescripcionSector(int idx, eSectores sectores[], int tamSec);



/** \brief son las opciones del menu para modificar una variable a un empleado
 *
 * \return la opcion elegida por el usuario
 *
 */

int menuOpciones();




/** \brief modifica una variable de un empleado
 *
 * \param vector donde buscar al empleado
 * \param tamaño del vector de empleados
 * \param sectores donde puede estar un empleado
 * \param tamaño del vector sectores
 *
 */

void modificarEmpleado(eEmployee x[], int tam, eSectores sectores[], int tamSec);





/** \brief muestra una variable del tipo eEmployee
 *
 * \param variable a mostrar
 * \param vector de sectores donde puede estar la variable
 * \param tamaño del vector de sectores
 * \param tamaño del vector de empleados
 *
 */

void mostrarEmpleado(eEmployee x, eSectores sectores[], int tamSec, int tam);




/** \brief muestra las opciones de la seccion de informes
 *
 * \return la opcion elegida por el usuario
 *
 */

int menuInformes();




/** \brief entra en la parte de informes y muestra las opciones que te da el menuInformes()
 *
 * \param vector de empleados
 * \param vector de sectores
 * \param tamaño del vector de empleados
 * \param tamaño del vector sectores
 *
 */

void informarEmpleados(eEmployee x[], eSectores sectores[], int tam, int tamSec);



/** \brief muestra los datos que debe mostrar la funcion mostrarEmpleado
 *
 *
 */

void mostrarPlantilla();


/** \brief muestra las variables de un vector de empleados
 *
 * \param vector de empleados a mostrar
 * \param vector de sectores
 * \param tamaño del vector de sectores
 * \param tamaño del vector de empleados
 *
 */

void mostrarEmpleados(eEmployee x[], eSectores sectores[], int tamSec, int tam);




/** \brief ordena un vector de empleados por el criterio establecido en el programa
 *
 * \param vector de empleados a ordenar
 * \param vector de sectores donde puede estar un empleado
 * \param tamaño del vector sectores
 * \param tamaño del vector de empleados
 *
 */

void ordenarEmpleados(eEmployee x[], eSectores sectores[], int tamSec, int tam);




/** \brief muestra el total, el promedio, y los empleados que sobrepasan el promedio de salarios
 *
 * \param vector de empleados
 * \param tamaño del vector de empleados
 * \param vector de sectores
 * \param tamaño del vector sectores
 *
 */

void totalSalarios(eEmployee x[], int tam, eSectores sectores[], int tamSec);


