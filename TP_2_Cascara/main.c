#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define X 20

int main()
{
    char seguir='s';
    int opcion=0;
    eDato personas[X];
    int aux, auxDni;

    iniciaEstructura(personas,X);

    while(seguir=='s')
    {
        printf(" 1- Agregar persona\n 2- Borrar persona\n 3- Modificar personas \n 4- Imprimir lista ordenada por  nombre\n 5- Imprimir grafico de edades\n 6- Salir\n");
        scanf("%d",&opcion);
        opcion=validaInt(opcion,1,6);

        switch(opcion)
        {
        case 1:
            aux=obtenerEspacioLibre(personas,X);
            cargarEstructura(personas,X,aux);
            break;
        case 2:
            printf("ingrese dni a borrar:");
            scanf("%d",&auxDni);
            aux=buscarIntRetornaUbicacion(personas,X,auxDni);
            eliminarEstructura(personas,aux);
            break;
        case 3:
            printf("ingrese dni a modificar:");
            scanf("%d",&auxDni);
            aux=buscarIntRetornaUbicacion(personas,X,auxDni);
            modificarEstructura(personas,aux);
            break;
        case 4:
            ordenaEstructura(personas,X);
            break;
        case 5:
            graficaEdades();
            break;
        case 6:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
