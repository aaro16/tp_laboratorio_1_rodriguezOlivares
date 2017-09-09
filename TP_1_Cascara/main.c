#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float dato1=0, dato2=0;
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf(" 1- Ingresar 1er operando (A=x)\n 2- Ingresar 2do operando (B=y)\n 3- Calcular la suma (A+B)\n 4- Calcular la resta (A-B)\n 5- Calcular la division (A/B)                 Dato A-> %.2f Dato B-> %.2f  \n 6- Calcular la multiplicacion (A*B)\n 7- Calcular el factorial (A!)\n 8- Calcular todas las operacione\n 9- Salir\n",dato1,dato2);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                dato1= cargaFloat();
                break;
            case 2:
                dato2= cargaFloat();
                break;
            case 3:
                sumaFuncion(dato1,dato2);
                break;
            case 4:
                restaFuncion(dato1,dato2);
                break;
            case 5:
                divisionFuncion(dato1,dato2);
                break;
            case 6:
                multiplicacionFuncion(dato1,dato2);
                break;
            case 7:
                factorialFuncion(dato1,dato2);
                break;
            case 8:
                todasFunciones(dato1,dato2);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
