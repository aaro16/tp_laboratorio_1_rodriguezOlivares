#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int menu()
{
    int opcion;
    system("cls");
    printf("\n******PELICULAS******\n\n\n");
    printf("1- Agregar pelicula\n");
    printf("2- Borrar pelicula\n");
    printf("3- Modificar pelicula\n");
    printf("4- Generar pagina web\n");
    printf("5- Salir\n");
    printf("\n\nIngrese opcion: ");

    scanf("%d", &opcion);
    opcion=validaInt(opcion,1,5);

    return opcion;
}

int buscarIdDato(eDato* listaDato, int tamDato)
{
    int aux=-1;
    int auxId;
    int i;

    scanf("%d",&auxId);

    for(i=0; i<tamDato; i++)
    {
        if((listaDato+i)->id==auxId && (listaDato+i)->estado==1)
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

int validaInt(int numero,int minimoInt, int maximoInt)
{

    while(minimoInt>numero || numero>maximoInt)
    {
        printf("ERROR; Reingrese el dato: ");
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

char* validaCadena(char cadena[],int minimo,int maximo)
{
    char auxCadena[50];
    while(strlen(cadena)<minimo || strlen(cadena)>maximo)
    {
        printf("ERROR, reingrese cadena de caracteres:");
        fflush(stdin);
        gets(cadena);
    }

    strcpy(auxCadena,cadena);

    return auxCadena;
}

void iniciaEstructuraDato(eDato* listaDato, int tamDato)
{
    int i;
    for(i=0; i<tamDato; i++)
    {
        strcpy((listaDato+i)->descripcion,"NADA");
        (listaDato+i)->duracion=0;
        (listaDato+i)->estado=0;
        strcpy((listaDato+i)->genero,"NADA");
        (listaDato+i)->id=99;
        strcpy((listaDato+i)->linkImagen,"NADA");
        strcpy((listaDato+i)->nombre,"NADA");
        (listaDato+i)->puntaje=0;
    }
}

void mostrarUnDato(eDato unDato)
{
    printf("\t ID-->%d, Titulo-->%s, Genero-->%s, Duracion-->%d min, Puntaje-->%d \n",unDato.id,unDato.nombre,unDato.genero,unDato.duracion,unDato.puntaje);
}

void mostrarArrayEstruturaDato(eDato* listaDato, int tamDato)
{
    int i;
    int aux=-1;

    for(i=0; i<tamDato; i++)
    {
        if((listaDato+i)->estado==1)
        {
            printf("\t ID-->%d, Titulo-->%s, Genero-->%s, Duracion-->%d min, Puntaje-->%d \n",(listaDato+i)->id,(listaDato+i)->nombre,(listaDato+i)->genero,(listaDato+i)->duracion,(listaDato+i)->puntaje);
            aux=1;
        }
    }

    if(aux==-1)
    {
        printf("\nNo hay nada para mostar\n");
    }

    getch();
}

void modificarEstructuraDato(eDato* listaDato, int tamDato)
{
    eDato auxLista;
    char buffer[200];
    char respuesta;
    int posicion,aux;

    printf("Ingrese ID a modificar:");
    posicion= buscarIdDato(listaDato,tamDato);

    if(posicion!=-1)
    {
        auxLista=listaDato[posicion];
        mostrarUnDato(auxLista);

        printf("¿Desea modificar permanentemente este objeto? s/n \n");
        fflush(stdin);
        scanf("%c",&respuesta);
        respuesta=toupper(respuesta);

        if(respuesta=='S')
        {
            printf("Ingrese nuevo puntaje: ");
            scanf("%d",&aux);
            (listaDato+posicion)->puntaje=validaInt(aux,0,10);

            printf(" \t Modificacion Exitosa!!");
        }

        else
        {
            printf("Accion CANCELADA, no se modifico el objeto \n");
        }
    }

    getch();
}

eDato cargarEstructuraDato()
{
    char buffer[100];
    eDato unDato;

        printf("Ingrese ID: ");
        scanf("%d",&unDato.id);
        unDato.id=validaInt(unDato.id,0,100);

        printf("Ingrese titulo: ");
        fflush(stdin);
        gets(buffer);
        strcpy(unDato.nombre,validaCadena(buffer,2,20));

        printf("Ingrese genero: ");
        fflush(stdin);
        gets(buffer);
        strcpy(unDato.genero,validaCadena(buffer,2,10));

        printf("Ingrese descripcion: ");
        fflush(stdin);
        gets(unDato.descripcion);

        printf("Ingrese Duracion: ");
        scanf("%d",&unDato.duracion);
        unDato.duracion=validaInt(unDato.duracion,40,240);

        printf("Ingrese link de la imagen: ");
        fflush(stdin);
        gets(unDato.linkImagen);

        printf("Ingrese puntaje: ");
        scanf("%d",&unDato.puntaje);
        unDato.puntaje=validaInt(unDato.puntaje,0,10);

        unDato.estado=1;

        printf("\t Carga Exitosa!!   Su ID es: %d",unDato.id);

        getch();

        free(buffer);

        return unDato;
}

void eliminarEstructuraDato(eDato* listaDato,int tamDato)
{
    char respuesta;
    int i;
    eDato auxLista;

    printf("Ingrese ID a eliminar:");
    i= buscarIdDato(listaDato,tamDato);

    if(i!=-1)
    {
       auxLista=listaDato[i];
       mostrarUnDato(auxLista);

    printf("¿Desea eliminar permanentemente este objeto? s/n \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=toupper(respuesta);

    if(respuesta=='S')
    {
        strcpy((listaDato+i)->descripcion,"NADA");
        (listaDato+i)->duracion=0;
        (listaDato+i)->estado=0;
        strcpy((listaDato+i)->genero,"NADA");
        (listaDato+i)->id=99;
        strcpy((listaDato+i)->linkImagen,"NADA");
        strcpy((listaDato+i)->nombre,"NADA");
        (listaDato+i)->puntaje=0;
        printf(" \t DATO ELIMINADO!!!! \n");
    }
    else
    {
        printf("Accion CANCELADA, no se elimino el objeto \n");
    }
    }

    getch();

}
void altaEstructuraDato(eDato listaDato[], int tamDato)
{
    eDato auxLista;
    char respuesta;
    int aux;

    printf("Ingrese id a darle de alta\n");
    aux=buscarIdDato(listaDato,tamDato);
    auxLista=listaDato[aux];
//    mostrarEstruturaDato(auxLista);

    printf("¿Desea darle de alta a este objeto? s/n \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=toupper(respuesta);

    if(respuesta=='S')
    {
        listaDato[aux].estado=1;
    }
    else
    {
        printf("Accion CANCELADA, no se dio de alta al objeto \n");
    }
}
void bajaEstructuraDato(eDato listaDato[],int tamDato)
{
    eDato auxLista;
    char respuesta;
    int aux;

    printf("Ingrese id a darle de baja\n");
    aux=buscarIdDato(listaDato,tamDato);

    if(aux!=-1)
    {
        auxLista=listaDato[aux];
//        mostrarEstruturaDato(auxLista);

        printf("¿Desea darle de baja a este objeto? s/n \n");
        fflush(stdin);
        scanf("%c",&respuesta);
        respuesta=toupper(respuesta);

        if(respuesta=='S')
        {
            listaDato[aux].estado=0;
            printf("\t Baja exitosa!!! \n");
        }
        else
        {
            printf("Accion CANCELADA, no se dio de baja al objeto \n");
        }
    }
}

void ordenaEstructuraDato(eDato listaDato[],int tamDato)
{
    int i, j;
    eDato auxlistaDato;

    for(i=0; i<tamDato-1; i++)
    {
        for(j=i+1; j<tamDato; j++)
        {
            if(listaDato[i].puntaje>listaDato[j].puntaje)
            {
                auxlistaDato=listaDato[j];
                listaDato[j]=listaDato[i];
                listaDato[i]=auxlistaDato;
            }
            if( listaDato[i].puntaje==listaDato[j].puntaje && strcmpi(listaDato[i].nombre,listaDato[j].nombre)==1)
            {
                auxlistaDato=listaDato[j];
                listaDato[j]=listaDato[i];
                listaDato[i]=auxlistaDato;
            }
        }
    }
}

void leeArchivo(FILE* archivo, eDato* lista, int tamDato)
{
    eDato auxlista;
    int i=0,cantidad;
    archivo= fopen("ListaBinaria.bin","rb");

    if(archivo==NULL)
    {
        archivo= fopen("ListaBinaria.bin","wb");

        if(archivo==NULL)
        {
            printf("ERROR en archivo!!!!!");
            getch();
        }
    }

    else
    {
        rewind(archivo);
        i=0;
        while(!feof(archivo))
        {
            fflush(stdin);
            cantidad= fread(&lista[i], sizeof(eDato), 1, archivo);
            //lista[i]=auxlista;
            i++;
            if(cantidad!=1)
            {
                if(feof(archivo))
                {
                    break;
                }
                else
                {
                    printf("No leyo el ultimo registro");
					break;
                }
            }
        }
    }
    fclose(archivo);
}

void escribeArchivo(FILE* archivo, eDato* lista, int tamDato)
{
    eDato auxlista;
    int i=0;

        archivo= fopen("ListaBinaria.bin","wb");

        if(archivo==NULL)
        {
            printf("ERROR en archivo!!!!!");
            getch();
        }

        else
        {
            for(i=0;i<tamDato;i++)
            {
                if( (lista+i)->estado==1)
                {
                fseek(archivo , 0L, SEEK_END);
                fflush(stdin);
                fwrite(&lista[i], sizeof(eDato), 1, archivo);
                }
            }
        }
        fclose(archivo);
}

void iniciaArchivoHtml(eDato* lista, int tamDato)
{
    FILE* archivoHtml;
    int i;

    archivoHtml= fopen("ListaPeliculas.html","w");

    if (archivoHtml== NULL)
    {
            printf("No se pudo abrir el archivo");
    }
    else
    {
            for(i=0;i<tamDato;i++)
            {
                if( (lista+i)->estado==1)
                {
                    fprintf(archivoHtml,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Género:%s</li><li>Puntaje:%d</li><li>Duración:%d</li></ul>                <p>%s.</p></article>",(lista+i)->linkImagen,(lista+i)->nombre,(lista+i)->genero,(lista+i)->puntaje,(lista+i)->duracion,(lista+i)->descripcion);
                }
            }
    }
    fclose(archivoHtml);

    printf(" \t ARCHIVO HTML GENERADO CON EXITO!!");
    getch();
}

eDato* creaLista(int sizeLista)
{
    eDato* aux=NULL;

    if(aux==NULL)
    {
         aux= (eDato*) malloc(sizeof(eDato)*sizeLista);
    }

    else
    {
    sizeLista= sizeLista+10;
    aux= (eDato*) realloc(aux,sizeof(eDato)*sizeLista);
    }

    return aux;
}
