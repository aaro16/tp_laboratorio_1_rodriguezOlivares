#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int duracion;
    int puntaje;
    int estado;
    int id;
    char nombre[20];
    char genero[10];
    char descripcion[500];
    char linkImagen[500];
}eDato;

/** \brief muestra una menu de opciones
 * \param no recibe nada
 * \return retorna un int que es la opcion seleccionada
 */
int menu();


/** \brief valida un numero entre un menor y un mayor
 * \param numero es el numero a validar
 * \param minimoInt es el numero minimo a validar
 * \param maximoInt es el numero maximo a validar
 * \return retorna un int que es el numero ya validado
 */
int validaInt(int numero, int minimoInt, int maximoInt);


/** \brief valida un numero entre un menor y un mayor
 * \param numero es el numero a validar
 * \param minimoFloat es el numero minimo a validar
 * \param maximoFloat es el numero maximo a validar
 * \return retorna un Float que es el numero ya validado
 */
float validaFloat(float numero,float minimoFloat, float maximoFloat);


/** \brief valida el tamaño de una cadena
 * \param cadena es la cadena a validar
 * \param minimo es el numero minimo de debe tener la cadena
 * \param maximo es el numero maximo de debe tener la cadena
 * \return retorna un puntero a char con la cadena ya validada
 */
char* validaCadena(char cadena[],int minimo,int maximo);

/** \brief busca un id en la estructura eDato
 * \param listaDato es la estructura donde buscara el id
 * \param tamDato es el tamaño de la estructura
 * \return retorna la posicion donde esta el id o -1 sino lo consigue
 */
int buscarIdDato(eDato*, int);

/** \brief libera los campos de la estructura eDato
 * \param listaDato es la estructura que se liberara
 * \param tamDato es el tamaño de la estructura
 * \return nada
 */
void iniciaEstructuraDato(eDato*, int);


/** \brief muestra los campos de la estructura eDato
 * \param listaDato es la estructura que se va a mostrar
 * \return nada
 */
void mostrarUnDato(eDato unDato);


/** \brief muestra los campos del array de estructura eDato
 * \param listaDato es el array de estructura que se va a mostrar
 * \param tamDato es el tamaño del array de la estructura
 * \return nada
 */
void mostrarArrayEstruturaDato(eDato*, int);


/** \brief modifica los campos del array de estructura eDato
 * \param listaDato es el array de estructura que se va a modificar
 * \param tamDato es el tamaño del array de la estructura
 * \return nada
 */
void modificarEstructuraDato(eDato*, int);


/** \brief carga los campos del array de estructura eDato
 * \param listaDato es el array de estructura que se va a cargar
 * \param posicion es la ubicacion donde se cargara la array de la estructura
 * \return nada
 */
eDato cargarEstructuraDato();


/** \brief elimina los campos del array de estructura eDato
 * \param listaDato es el array de estructura que se va a eliminar
 * \param posicion es la ubicacion que se eliminara de la array de la estructura
 * \return nada
 */
void eliminarEstructuraDato(eDato*,int);


/** \brief da de alta una posicion de la array de estructura eDato
 * \param listaDato es el array de estructura que se va a dar de alta
 * \param tamDato es el tamaño del array de la estructura
 * \return nada
 */
void altaEstructuraDato(eDato listaDato[],int tamDato);


/** \brief se da de baja a una posicion del array de estructura eDato
 * \param listaDato es el array de estructura que se va a dar de baja
 * \param tamDato es el tamaño del array de la estructura
 * \return nada
 */
void bajaEstructuraDato(eDato listaDato[],int tamDato);


/** \brief ordena la estructura array de estructura eOtro por doble criterio, 1ero Hora , 2do Patente
 * \param listaOtro es el array de estructura que se va a ordenar
 * \param tamOtro es el tamaño del array de la estructura
 * \return nada
 */
void ordenaEstructuraDato(eDato listaDato[],int tamDato);

void leeArchivo(FILE* archivoBin, eDato* listaDato, int tamDato);

void escribeArchivo(FILE*, eDato*, int);

void iniciaArchivoHtml(eDato*, int);

eDato* creaLista(int);

#endif // FUNCIONES_H_INCLUDED
