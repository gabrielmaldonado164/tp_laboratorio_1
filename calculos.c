#include "calculos.h"
float sumar(float x, float y)
{
    float suma;
    suma = x + y;
    return suma;
}

float restar(float x,float y)
{
    float resta;
    resta = x-y;
    return resta;
}

float multiplicar(float x, float y)
{
    float multiplicacion;
    multiplicacion = x*y;
    return multiplicacion;
}

float division(float x, float y)
{
    float dividir;
    dividir = x/y;
    return dividir;
}

int factorial(int x)
{
    int factoreo;
    int contador;
    factoreo = 1;
    for(contador =1;contador<=x;contador++)
        {
            factoreo = factoreo *contador;
        }
    return factoreo;
}



