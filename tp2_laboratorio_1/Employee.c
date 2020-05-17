#include "Employee.h"



int menuPrincipal(void)
{
    int opcion;

            system("cls");
            printf("Menu de opciones \n");
            printf("1.Alta empleado\n");
            printf("2.Modificar empleado\n");
            printf("3.Baja empleado\n");
            printf("4.Informar\n");
            printf("5.Salir\n");

            printf("\nElija una opcion:");
            fflush(stdin);
            scanf("%d",&opcion);

    return opcion;

}

int menuModificar(void)
{


    int opcion;
    system("cls");
    printf("Menu de opciones \n");
    printf("1.Modificar nombre\n");
    printf("2.Modificar apellido\n");
    printf("3.Modificar salario\n");
    printf("4.Modificar sector\n");
    printf("5.Salir\n\n");

    printf("\nElija una opcion: ");
    scanf("%d", &opcion );

    return opcion;

}

int menuInformes(eEmployee* listOfEmployees, int length)
{
    int opcion;
    system("cls");
    printf("Menu de opciones \n");
    printf("1.Listado de los empleados\n");
    printf("2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
    printf("3.Salir\n\n");

    printf("\nElija una opcion: ");
    scanf("%d", &opcion );

    return opcion;

}

void  initEmployees(eEmployee* listOfEmployees, int lenght)
{
    int error=-1;

    if(listOfEmployees != NULL && lenght >= 1 )
        {
            for(int i=0;i<lenght;i++)
                {
                    (listOfEmployees+i)->isEmpty=LIBRE;
                }
        }
}

int idEmployees(eEmployee* listOfEmployees, int length,int* idEmployee)
{

    int auxId=1;
    int ok=-1;

            for(int i=0;i<length;i++)
                {
                    if((listOfEmployees+i)->isEmpty == 0 )
                        {
                            *idEmployee=auxId;

                            ok=0;
                            break;
                        }
                    else
                        {

                            auxId++;
                            idEmployee=auxId;
                        }
                }
    return auxId;
}


int findFree(eEmployee* lisOfEmployees, int length)
{
    int indice=-1;


    if(lisOfEmployees != NULL)
        {
            for(int i=0;i<length;i++)
                {
                    if((lisOfEmployees+i)->isEmpty == LIBRE || (lisOfEmployees+i)->isEmpty==BAJA)
                        {
                            indice=i;
                            break;
                        }
                }

        }
    return indice;

}

int findEmployeeById(eEmployee* listOfEmployees, int length, int id)
{
    int indice=-1;

    if(listOfEmployees != NULL)
        {
            for(int i=0;i<length;i++)
                {
                    if((listOfEmployees+i)->isEmpty == OCUPADO && (listOfEmployees+i)->id==id)

                        {
                            indice=i;
                            break;
                        }
                }
        }
      return indice;

}
int contadorEmployees(eEmployee* listOfEmployees, int length)
{
    int contador=0;

    for(int i=0;i<length;i++)
        {
            if((listOfEmployees+i)->isEmpty == OCUPADO)
                {
                    contador++;
                }
        }
    return contador;
}

int addEmployee(eEmployee* listOfEmployees, int length, int id, char name[],char lastName[],float salary,int sector,int indice)
{
    int error=-1;


    if(listOfEmployees != NULL)
        {
            if(indice!=-1)
                {
                    system("cls");
                    (listOfEmployees+indice)->id = id;
                    strcpy((listOfEmployees+indice)->name,name);
                    strcpy((listOfEmployees+indice)->lastName,lastName);
                    (listOfEmployees+indice)->salary= salary;
                    (listOfEmployees+indice)->sector= sector;
                    (listOfEmployees+indice)->isEmpty=OCUPADO;
                    printf("Alta de Empleado Exitosa\n\n");
                    system("pause");
                    error=0;
                }
        }
    return error;
}

int altaEmpleados(eEmployee* listOfEmployees, int length)
{
    eEmployee* empleado=(eEmployee*)malloc(sizeof(eEmployee));
    int error=-1;
    int indice;


    if(listOfEmployees != NULL && empleado!= NULL)
        {
             indice=findFree(listOfEmployees,length);


            if(indice!=-1)
                {
                   getInt(&empleado->id,"Ingrese id:","Error, no es un numero\n",1,5000,10);
                    getCharString(&empleado->name,"Ingrese nombre:","Error, no son letras validas[minimo 2 caracteres - maximo 50 caracteres]\n",2,50,10);
                    getCharString(&empleado->lastName,"Ingrese Apellido:","Error, no son letras validas[minimo 2 caracteres - maximo 50 caracteres]\n",2,50,10);
                    getFloat(&empleado->salary,"Ingrese salario:","Error, al cargar [sueldo min: 10000 - sueldo max: 120000]\n",10000,120000,10);
                    getInt(&empleado->sector,"Ingrese sector[1-3]:","Error, sector invalido\n",1,3,10);

                    empleado->isEmpty=OCUPADO;

                }
            else
                {
                    printf("No hay lugar en el sistema\n");
                }
            error=addEmployee(listOfEmployees,length,empleado->id,empleado->name,empleado->lastName,empleado->salary,empleado->sector,indice);

            free(empleado);

        }

    return error;
}


int removeEmployee(eEmployee* listOfEmployees, int length, int id)
{
    int error=-1;

    int system=contadorEmployees(listOfEmployees,length);

        if(listOfEmployees != NULL)
            {
                        int indiceID;
                        char seguir;
                        indiceID=findEmployeeById(listOfEmployees,length,id);

                        if(indiceID != -1)
                            {
                                printEmployee(listOfEmployees,indiceID);
                                getOptionChar(&seguir,"Desea dar de baja el empleado[S/N]:","Error, letra invalida [S/N]\n",'s','n');

                                if(seguir == 'S')
                                    {

                                        (listOfEmployees+indiceID)->isEmpty = BAJA;
                                        printf("Baja exitosa\n");
                                        error=0;

                                    }
                                else
                                    {

                                        printf("Se cancelo la baja\n");
                                    }
                            }
                            else
                                {
                                    printf("No se encontro empleado con ese ID\n");
                                }

            }
        return error;
}

int bajaEmpleado(eEmployee* listOfEmployees, int length)
{
    int error=-1;
    int id;
    int system=contadorEmployees(listOfEmployees,length);

    if(listOfEmployees != NULL)
        {
            if(system>=1)
                {
                    getInt(&id,"Ingrese ID del Empleado:","No se encontro id indicado\n",0,length,10);

                    error=removeEmployee(listOfEmployees,length,id);

                }
                else
                    {
                        printf("No hay empleados cargados\n");
                    }
        }
    return error;
}

int sortEmployees(eEmployee* listOfEmployees, int lenght)
{
    int error=-1;
    eEmployee* auxEmpleado=(eEmployee*)malloc(sizeof(eEmployee));

    if(listOfEmployees != NULL && auxEmpleado != NULL)
        {
            for (int i = 0; i < lenght; i++)
            {
                for (int j = i+1; j < lenght; j++)
                {

                        if ( stricmp((listOfEmployees+i)->lastName,(listOfEmployees+j)->lastName) > 0 )
                        {
                            *auxEmpleado = *(listOfEmployees+i);
                            *(listOfEmployees+i) = *(listOfEmployees+j);
                            *(listOfEmployees+j) = *auxEmpleado;
                        }

                        else if(stricmp((listOfEmployees+i)->lastName,(listOfEmployees+j)->lastName)==0)

                        {
                            if((listOfEmployees+i)->sector > (listOfEmployees+j)->sector)
                            {
                                *auxEmpleado = *(listOfEmployees+i);
                                *(listOfEmployees+i) = *(listOfEmployees+j);
                                *(listOfEmployees+j) = *auxEmpleado;

                            }
                        }
                    }


            }
        }

       error=0;

    return error;
}
void modificarEmployees(eEmployee* listOfEmployees, int length)
{
    int error=-1;
    int system=contadorEmployees(listOfEmployees,length);
    int id;
    char seguir;
    char salida;
    char continuar;
    if(listOfEmployees != NULL)
        {
            if(system>=1)
                {
                    printEmployees(listOfEmployees,length);
                    getInt(&id,"Ingrese ID del empleado","Error, no es un ID valido\n",0,1500,10);

                    id=findEmployeeById(listOfEmployees,length,id);

                    if(id!=-1)
                        {
                            printEmployee(listOfEmployees,id);
                            getOptionChar(&seguir,"Desea dar de baja el empleado[S/N]:","Error, letra invalida [S/N]\n",'s','n');

                            if(seguir == 'S')
                                {
                                    do
                                        {
                                            switch(menuModificar())
                                            {
                                                case 1:
                                                        getCharString(&(listOfEmployees+id)->name,"Ingrese nombre:","No es un nombre valido\n",2,50,10);
                                                        break;
                                                case 2:
                                                        getCharString(&(listOfEmployees+id)->lastName,"Ingrese apellido:","Error, no es un apellido valido\n",1,50,10);
                                                        break;
                                                case 3:
                                                        getFloat(&(listOfEmployees+id)->salary,"Ingrese salario:","Error, no es un salario valido\n",10000,120000,10);
                                                        break;
                                                case 4:
                                                        getInt(&(listOfEmployees+id)->sector,"Ingrese sector:","Sector invalido\n",1,3,10);
                                                        break;
                                                case 5:
                                                        getOptionChar(&salida,"Desea salir [S/N]:","Error, letra invalida\n",'s','n');

                                                        if(salida == 'S')
                                                            {
                                                                continuar='n';
                                                            }
                                                        break;
                                                default:
                                                    printf("Opcion invalida\n");
                                                    break;
                                            }



                                            printf("Empleado modificado correctamente\n\n");
                                            fflush(stdin);


                                        }while(continuar == 's');
                                }
                                else
                                    {
                                        printf("Se cancelo la modificacion\n");
                                    }
                        }
                        else
                            {
                                printf("No se encontro empleado con ese ID\n");
                            }

                }
                else
                    {
                        printf("No hay empleados cargados en el sistema\n");
                    }
        }
}

void printEmployee(eEmployee* listOfEmployees, int i)
{
   if((listOfEmployees+i)->isEmpty== OCUPADO)
    {
        printf("ID: %d   Apellido: %s   Nombre: %s   Sueldo: %.2f   ID Sector: %d \n",(listOfEmployees+i)->id,(listOfEmployees+i)->lastName,(listOfEmployees+i)->name,(listOfEmployees+i)->salary,(listOfEmployees+i)->sector);
    }
}

void printEmployees(eEmployee* listOfEmployees, int length)
{
    int system = contadorEmployees(listOfEmployees,length);

    if(system>=1)
        {
            sortEmployees(listOfEmployees,length);
            for(int i=0;i<length;i++)
                {
                    printEmployee(listOfEmployees,i);
                }

        }
    else
        {
            printf("No hay empleados cargados en el sistema\n");
        }
}

void informeSalario(eEmployee* listOfEmployees, int length)
{
    int error = -1;
    int system =contadorEmployees(listOfEmployees,length);
    float salario = 0;
    int contadorSalarios=0;
    float promedio=0;


    if ( listOfEmployees != NULL )
    {
        if(system>=1)
            {
                    for (int i=0;i<length;i++)
                    {
                        if ((listOfEmployees+i)->isEmpty ==OCUPADO)
                        {
                            contadorSalarios++;
                            salario += (listOfEmployees+i)->salary;
                        }
                    }

                    printf("\nHay %d salarios, que suman un total de $%.f\n",contadorSalarios,salario);
                    promedio = salario / contadorSalarios;
                    printf("el promedio de los salarios es de = %.2f\n\n",promedio);

                    contadorSalarios = 0;

                    for (int i=0;i<length; i++)
                    {
                        if ( (listOfEmployees+i)->salary > promedio && (listOfEmployees+i)->isEmpty ==OCUPADO)
                        {
                            contadorSalarios++;
                        }
                    }

                    printf("la cantidad de salarios que superaron el promedio son: %d salarios...\n\n", contadorSalarios);
                    error = 0;

            }
            else
                {
                    printf("No hay empleados cargados\n");
                }

    }

}
