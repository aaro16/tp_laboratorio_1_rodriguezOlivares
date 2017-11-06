#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    FILE* archivo=NULL;
    eDato* lista=NULL;
    eDato auxLista;
    int i, respuesta, TAM=10;

    lista=creaLista(TAM);

    iniciaEstructuraDato(lista,TAM);
    leeArchivo(archivo,lista,TAM);

     do
    {
        switch(menu())
        {
        case 1:
        auxLista=cargarEstructuraDato();

        for(i=0;i<TAM;i++)
        {
            if((lista+i)->estado==0)
            {
                    lista[i]=auxLista;
                    break;
            }
        }
            break;
        case 2:
            eliminarEstructuraDato(lista,TAM);
            break;
        case 3:
            modificarEstructuraDato(lista,TAM);
            break;
        case 4:
            iniciaArchivoHtml(lista,TAM);
            break;
        case 5:
            respuesta=0;
            mostrarArrayEstruturaDato(lista,TAM);
            escribeArchivo(archivo,lista,TAM);
            break;
        }

    }while(respuesta);

    return 0;
}
