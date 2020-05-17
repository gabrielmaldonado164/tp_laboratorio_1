#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

/*IsEmpty:

  isEmpty=0 -> Lugar libre
  isEmpty=1 -> Lugar ocupado
  isEmpty=-1 -> Empleado dado de baja logica, lugar libre
*/

/** \brief menu con las opciones principales
 *
 * \param void no recibe parametros
 * \return int retornar el valor de la opcion elejida
 *
 */
int menuPrincipal(void);

/** \brief menu con las opciones principales
 *
 * \param voidno recibe parametros
 * \return int retornar el valor de la opcion elejida
 *
 */
int menuModificar(void);
/** \brief  se encarga de cargar los datos par el menu de informes
 *
 * \param listOfEmployees eEmployee* recibe el array de la estructura
 * \param length int la longitud del array
 * \return int retorna el valor seleccionado
 *
 */
int menuInformes(eEmployee* listOfEmployees, int length);
/** \brief inicializa el array de estructura
 *
 * \param listOfEmployees eEmployee* recibe el array de la estructura
 * \param lenght int    la longitud del array
 * \return no devuelve valor
 *
 */
void initEmployees(eEmployee* listOfEmployees, int lenght);
/** \brief
 *
 * \param listOfEmployees eEmployee*
 * \param length int
 * \param idEmployee int*
 * \return int
 *
 */
int idEmployees(eEmployee* listOfEmployees, int length,int* idEmployee);
/** \brief buscar un lugar libre dentro del array para cargar los datos
 *
 * \param lisOfEmployees eEmployee* recibe el array de la estructura
 * \param length int la longitud del array
 * \return int retorna el indice libre
 *
 */
int findFree(eEmployee* lisOfEmployees, int length);
/** \brief se busca un id con uno que este en el array para poder ver sus datos
 *
 * \param listOfEmployees eEmployee* recibe el array de la estructura
 * \param length int la longitud del array
 * \param id int el id el cual se va a buscar
 * \return int retorna el indice donde esta el id
 *
 */
int findEmployeeById(eEmployee* listOfEmployees, int length, int id);
/** \brief cuenta cuantos empleados hay en el array
 *
 * \param listOfEmployees eEmployee* recibe el array de la estructura
 * \param length int la longitud del array
 * \return int retorna la cantidad de empleados
 *
 */
int contadorEmployees(eEmployee* listOfEmployees, int length);
/** \brief agrega los valores recibido en el array de la estructura en la posicion libre
 *
 * \param listOfEmployees eEmployee* recibe el array de la estructura
 * \param length int la longitud del array
 * \param id int recibe el id que se guarda
 * \param name[] char se ingresan cadenas de caracteres
 * \param lastName[] char se ingresan cadenas de caracteres
 * \param salary float se ingresea un numero flotantes
 * \param sector int     se ingresa un numero entero
 * \param indice int    se ingresa el indice
 * \return int retorna -1 si esta salio bien, 0 si salio mal

 *
 */
int addEmployee(eEmployee* listOfEmployees, int length, int id, char name[],char lastName[],float salary,int sector,int indice);
/** \brief se da de alta valores dentro de una posicion en el array
 *
 * \param listOfEmployees eEmployee* recibe el array de la estructura
 * \param length int la longitud del array
 * \return int retorna los  valores cargados al array y -1 si salio mal
 *
 */
int altaEmpleados(eEmployee* listOfEmployees, int length);
/** \brief  recibe los valores de un array y busca el id para encontrar al empleado
 *
 * \param listOfEmployees eEmployee* recibe el array de la estructura
 * \param length int la longitud del array
 * \param id int id el cual se esta buscando
 * \return int retorna -1 si salio mal,  0 si se pudo realizar correctamente
 *
 */
int removeEmployee(eEmployee* listOfEmployees, int length, int id);
/** \brief  se encarga de dar la baja de los empleados
 *
 * \param listOfEmployees eEmployee* recibe el array de la estructura
 * \param length int la longitud del array
 * \return int
 *
 */
int bajaEmpleado(eEmployee* listOfEmployees, int length);
/** \brief se encarga de ordenar los datos dentro de el array de la estructura
 *
 * \param listOfEmployees eEmployee* recibe el array de la estructura
 * \param lenght int la longitud del array
 * \return int void  retorna -1 si salio mal, 0 si salio bien
 *
 */
int sortEmployees(eEmployee* listOfEmployees, int lenght);
/** \brief se encarga de modificar a los datos del  array de la estructura
 *
 * \param listOfEmployees eEmployee* recibe el array de la estructura
 * \param length int la longitud del array
 * \return void
 *
 */
void modificarEmployees(eEmployee* listOfEmployees, int length);
/** \brief  muestra un dato del array de la estructura
 *
 * \param listOfEmployees eEmployee* recibe el array de la estructura
 * \param i int la longitud del array longitud del array
 * \return void
 *
 */
void printEmployee(eEmployee* listOfEmployees, int i);
/** \brief muestra todos los datos  del array de la estructura
 *
 * \param listOfEmployees eEmployee* recibe el array de la estructura
 * \param length int  longitud del array
 * \return void no devuelve datos
 *
 */
void informeSalario(eEmployee* listOfEmployees,int length);





