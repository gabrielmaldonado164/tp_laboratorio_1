#include <stdlib.h>
#include "calculos.h"

int main()
{
    int menu;
    float numeroUno = 0;
    float numeroDos = 0;
    float suma;
    float resta;
    float dividir = 0;
    float multiplicacion;
    int factorialUno;
    int factorialDos;
    int resultadosOperaciones = 0;

    while(!(menu==5)){
        system("cls");
        printf("Menu de Opciones\n");
        printf("1.Ingrese primer operando (A= %0.2f)\n",numeroUno);
        printf("2.Ingrese segundo operando (B= %0.2f)\n",numeroDos);
        printf("3.Hacer todas las operaciones\n");
        printf("4.Mostrar todos los resultados\n");
        printf("5.Salir\n");
        printf("\nSeleccione unas de las siguientes opciones: ");
        fflush(stdin);
        scanf("%d",&menu);

        switch(menu)
        {
        case 1:
                printf("Ingrese el primer numero: ");
                scanf("%f",& numeroUno);
                break;
        case 2:
                printf("Ingrese el segundo numero: ");
                scanf("%f",& numeroDos);
                break;
        case 3:
                suma = sumar(numeroUno,numeroDos);
                resta = restar(numeroUno,numeroDos);
                multiplicacion = multiplicar(numeroUno,numeroDos);
                dividir = division(numeroUno,numeroDos);
                factorialUno = factorial(numeroUno);
                factorialDos = factorial(numeroDos);
                resultadosOperaciones =1;
                break;
        case 4:
            if(resultadosOperaciones == 1)
                {
                printf("El resultado de A+B es:%0.2f\n ",suma);
                printf("El resultado de A-B es:%0.2f\n ",resta);
                printf("El resultado de A*B es:%0.2f\n ",multiplicacion);


                if(numeroDos ==0)
                    {
                        printf("\nOperacion no valida,no se puede dividir por 0\n");
                    }
                else
                {
                    printf("El resultado de A/B es:%0.2f\n",dividir);

                }

                if(numeroUno>=0 && numeroDos>=0)
                    {
                        printf("El factorial del numero A es: %d\n",factorialUno);
                        printf("El factorial del numero B es: %d\n",factorialDos);

                    }
                else
                    {
                        printf("\nNo se pudo calcular el factorial, por favor ingrese un numero positivo entero\n");
                    }
                }else
                {
                    printf("Primero tiene que ingresar datos para mostrar");
                }

                break;
        case 5:
                printf("\nHasta luego\n");
                break;

        default:
            printf("\nIngrese una opcion valida\a\n");
            break;

        }
        system("pause");
    }

    return 0;
}
