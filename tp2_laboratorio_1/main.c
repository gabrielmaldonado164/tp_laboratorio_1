#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#define SIZE_EMPLOYEES 1000

int main()
{
   eEmployee* list=(eEmployee*)malloc(sizeof(eEmployee)*SIZE_EMPLOYEES);
    char confirma;
    char salir='s';


    if(list == NULL)
        {
            system("cls");
            printf("No se pudo conseguir espacio en el sistema\n");
            system("pause");
            exit(EXIT_FAILURE);
        }

    initEmployees(list,SIZE_EMPLOYEES);


    do
        {
            switch(menuPrincipal())
            {
            case 1:
                    system("cls");
                    altaEmpleados(list,SIZE_EMPLOYEES);


                    break;
            case 2:
                    modificarEmployees(list,SIZE_EMPLOYEES);
                    system("pause");
                    break;
            case 3:
                    bajaEmpleado(list,SIZE_EMPLOYEES);
                    system("pause");
                    break;
            case 4:
                    switch(menuInformes(list,SIZE_EMPLOYEES))
                    {
                        case 1:
                                system("cls");
                                printEmployees(list,SIZE_EMPLOYEES);
                                system("pause");
                                break;
                        case 2:
                                system("cls");
                                informeSalario(list,SIZE_EMPLOYEES);
                                system("pause");
                                break;
                        case 3:
                            printf("Volviendo al menu\n");
                            break;
                        default:
                            printf("Opcion invalida\n");
                            break;

                    }
            case 5:
                    getOptionChar(&confirma,"Desea salir[S/N]:","Letras invalidas\n",'s','n');

                    if(confirma == 'S')
                        {
                            salir='n';
                        }


                    break;
            default:
                system("cls");
                printf("Opcion invalida\n");
                system("pause");
                break;


            }
            system("cls");
            system("pause");
            fflush(stdin);

        }while(salir == 's');

       free(list);

    return 0;
}
