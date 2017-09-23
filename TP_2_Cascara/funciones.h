#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int datoInt1;
    int flag;
    int id;

}eDato;

int obtenerEspacioLibre(eDato lista[], int tam);
int buscarIntRetornaUbicacion(eDato lista[], int tam, int elemento);
int buscarIntRetornaFlag(eDato lista[], int tam, int elemento);
int buscarCadena(eDato lista[], int tam);
int validaInt(int numero, int minimoInt, int maximoInt);
float validaFloat(float numero,float minimoFloat, float maximoFloat);
void iniciaEstructura(eDato lista[], int tam);
void mostrarEstrutura(eDato lista);
void mostrarArrayEstrutura(eDato lista[], int tam);
void modificarEstructura(eDato lista[], int posicion);
void cargarEstructura(eDato lista[],int tam, int posicion);
void eliminarEstructura(eDato lista[],int posicion);
void ordenaEstructura(eDato lista[],int tam);
void graficaEdades();

#endif // FUNCIONES_H_INCLUDED
