#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int obtenerEspacioLibre(eDato lista[], int tam)
{
    int aux=-1;
    int flag=0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].flag==0)
        {
            aux=i;
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        printf(" \tNo hay espacio libre \n");
    }

    return aux;
}

int buscarIntRetornaUbicacion(eDato lista[], int tam, int elemento)
{
    int aux=-1;
    int auxId;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].id==elemento)
        {
            aux=i;
            break;
        }
    }

    if(aux==-1)
    {
        printf("No hay datos guardados con ese valor \n");
    }

    return aux;
}

int buscarIntRetornaFlag(eDato lista[], int tam, int elemento)
{
    int aux=0;
    int auxId;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].id==elemento)
        {
            aux=1;
            break;
        }
    }

    return aux;
}


int buscarElementoCadena(eDato lista[], int tam)
{
    eDato auxLista;
    int aux=-1;
    char auxCadena[50];
    int i;

    printf("Ingrese CADENA a buscar \n");
    scanf("%s",&auxCadena);

    for(i=0; i<tam; i++)
    {
        if(lista[i].id==auxCadena)
        {
            aux=i;
            auxLista=lista[i];
            mostrarEstrutura(auxLista);
            break;
        }
    }

    if(aux==-1)
    {
        printf("No hay datos guardados con ese valor \n");
    }

    return aux;
}

int validaInt(int numero,int minimoInt, int maximoInt)
{

    while(minimoInt>numero || numero>maximoInt)
    {
        printf("ERROR; dato no valido \n");
        scanf("%d",&numero);
    }

    return numero;
}

float validaFloat(float numero,float minimoFloat, float maximoFloat)
{
    while(minimoFloat>numero || numero>maximoFloat)
    {
        printf("ERROR; Reingrese el dato: ");
        scanf("%f",&numero);
    }

    return numero;
}

void iniciaEstructura(eDato lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].flag=0;
        lista[i].id=0;
        lista[i].datoInt1=0;
    }

    for(i=0; i<tam; i++)
    {
        strcpy(lista[i].nombre,"NADA");
    }

}

void mostrarEstrutura(eDato lista)
{
    printf("dni: %d -- edad: %d -- nombre: %s \n",lista.id,lista.datoInt1,lista.nombre);
}

void mostrarArrayEstrutura(eDato lista[], int tam)
{
    int i;
    int aux=0;
    eDato auxLista;

    for(i=0; i<tam; i++)
    {
        if(lista[i].flag==1)
        {
            auxLista=lista[i];
            mostrarEstrutura(auxLista);
            aux=1;
        }
    }

    if(aux==0)
    {
        printf("\nNo hay nada para mostar\n");
    }
}

void modificarEstructura(eDato lista[], int posicion)
{
    char respuesta;
    eDato auxLista;

    if(posicion!=-1)
    {
    auxLista=lista[posicion];
    mostrarEstrutura(auxLista);

    printf("¿Desea modificar permanentemente este objeto? s/n \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=toupper(respuesta);

    if(respuesta=='S')
    {

        printf("Ingrese nuevo id:");
        scanf("%d",&lista[posicion].id);

        printf("Ingrese nueva edad:");
        scanf("%d",&lista[posicion].datoInt1);

        printf("Ingrese nuevo nombre:");
        fflush(stdin);
        gets(lista[posicion].nombre);
    }

    else
    {
        printf("Accion CANCELADA, no se modifico el objeto \n");
    }

    }

}

void cargarEstructura(eDato lista[], int tam, int posicion)
{
    int i, aux=-1;

    if(posicion!=-1)
    {
       printf("Ingrese DNI: ");
        scanf("%d",&lista[posicion].id);
        lista[posicion].id=validaInt(lista[posicion].id,1,99999999);

        printf("Ingrese edad: ");
        scanf("%d",&lista[posicion].datoInt1);
        lista[posicion].datoInt1=validaInt(lista[posicion].datoInt1,1,99);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[posicion].nombre);

        lista[posicion].flag=1;
    }
}

void eliminarEstructura(eDato lista[],int posicion)
{
    char respuesta;
    eDato auxLista;

    if(posicion!=-1)
    {
        auxLista=lista[posicion];
        mostrarEstrutura(auxLista);

        printf("¿Desea eliminar permanentemente este objeto? s/n \n");
        fflush(stdin);
        scanf("%c",&respuesta);
        respuesta=toupper(respuesta);

        if(respuesta=='S')
        {
            lista[posicion].flag=0;
            lista[posicion].id=0;
            strcpy(lista[posicion].nombre,"NADA");
            printf("Dato eliminado!!!!!!! \n");
        }
        else
        {
            printf("Accion CANCELADA, no se elimino el objeto \n");
        }
    }
}

void ordenaEstructura(eDato lista[],int tam)
{
    int i, j;
    eDato aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmpi(lista[i].nombre,lista[j].nombre)==1)
            {
                aux=lista[j];
                lista[j]=lista[i];
                lista[i]=aux;
            }
        }
    }

    mostrarArrayEstrutura(lista,tam);

}

void graficaEdades()
{
    printf("\t * \t   \t   \t \n");
    printf("\t * \t   \t * \t \n");
    printf("\t * \t * \t * \t \n");
    printf("\t * \t * \t * \t \n");
    printf("\t * \t * \t * \t \n");
    printf("\t * \t * \t * \t \n");
    printf("\t0-18   19-35   36-99 \n");
}
