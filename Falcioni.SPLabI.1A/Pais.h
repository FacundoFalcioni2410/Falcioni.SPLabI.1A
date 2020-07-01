#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char pais[128];
    int infectados;
    int recuperados;
    int muertos;

}ePais;

/** \brief reserva un espacio en memoria para un nuevo pais
 *
 * \return devuelve un puntero de pais al espacio de memoria creado
 *
 */
ePais* paisNew();

/** \brief elimina un pais de memoria
 *
 * \param pais a eliminar
 * \return void
 *
 */

void paisDelete(ePais* x);


/** \brief crea un pais y llama a distintas funciones para asignarle los campos al pais
 *
 * \param id del pais
 * \param nombre del pais
 * \param recuperados del pais
 * \param infectados del pais
 * \param muertos del pais
 * \return devuelve puntero al pais creado y con los datos cargados
 *
 */
ePais* paisNewParametrosStr(char* idStr,char* nombreStr,char* recuperadosStr, char* infectadosStr,char* muertosStr);


/** \brief se encarga de asignar un valor random con la funcion getRandom y con los setters los inserta en el pais
 *
 * \param pais a insertar los datos
 * \return devuelve 1 si pudo hacerlo, 0 si no pudo
 *
 */


int setInfectadosRecuperadosMuertos(void* pais);

/** \brief busca el pais con mayor muertos
 *
 * \param lista de paises
 * \return devuelve el pais con mayor muertos
 *
 */

ePais* mayorMuertos(LinkedList* lista);

/** \brief pasa a ll_filter los paises con muertos menores a 5000 o iguales a 5000
 *
 * \param pais donde se va a verificar que tenga menos de 5000 muertos
 * \return retorna 1 si tiene 5000 muertos o menos, 0 si tiene mas
 *
 */
int filtrarPaisesExitosos(void* unPais);

int paisesPorInfeccion(LinkedList* lista, int order);

int ordenarPaisesPorInfeccion(void* a, void* b);

/** \brief muestra los paises que la cantidad de infectados triplicen el numero de recuperados
 *
 * \param pais a evaluar
 * \return retorna 1 si lo triplica, 0 si no
 *
 */

int filtrarPaisesEnElHorno(void* x);

/** \brief Listar pais

 * \param elemento de la lista de paises
 * \return int devuelve 1 si no pudo mostrar el pais, 0 si pudo hacerlo
 *
 */
int mostrarPais(ePais* x);

/** \brief Listar paises

 * \param lista de paises
 * \return int devuelve 1 si no pudo mostrar los paises, 0 si pudo hacerlo
 *
 */
int mostrarPaises(LinkedList* lista);

/** \brief obtiene un numero random
 *
 * \param hasta que numero
 * \param desde que numero
 * \return retorna el numero random
 *
 */
int getRandom(int a,int b);

/** \brief obtiene el id de pais en concreto
 *
 * \param pais en el que se encuentra el dato a obtener
 * \param lugar donde se va a cargar el dato a obtener
 * \return retorna 0 si se pudo obtener el dato, 1 si no se pudo
 *
 */
int paisSetId(ePais* x, int id);

/** \brief se encarga de obtener el id en el pais
 *
 * \param pais en el que se procedera a obtener el dato
 * \param id donde se va a cargar el dato obtenido
 * \return retorna 0 si se pudo obtener, 1 si no se pudo
 *
 */
int paisGetId(ePais* x,int* id);

/** \brief se encarga de cargar el nombre en el pais
 *
 * \param pais en el que se procedera a cargar el dato
 * \param nombre que se le va a cargar al pais
 * \return retorna 0 si se pudo cargar, 1 si no se pudo
 *
 */
int paisSetPais(ePais* x, char* pais);

/** \brief se encarga de obtener el nombre en el pais
 *
 * \param pais en el que se procedera a obtener el dato
 * \param nombre donde se va a cargar el dato obtenido
 * \return retorna 0 si se pudo obtener, 1 si no se pudo
 *
 */
int paisGetPais(ePais* x, char* pais);


/** \brief se encarga de cargar los recuperados en el pais
 *
 * \param pais en el que se procedera a cargar el dato
 * \param numero de recuperados que se le va a cargar al pais
 * \return retorna 0 si se pudo cargar, 1 si no se pudo
 *
 */
int paisSetRecuperados(ePais* x, int recuperados);


/** \brief se encarga de obtener los recuperados en el pais
 *
 * \param pais en el que se procedera a obtener el dato
 * \param numero de recuperados donde se va a cargar el dato obtenido
 * \return retorna 0 si se pudo obtener, 1 si no se pudo
 *
 */
int paisGetRecuperados(ePais* x,int* recuperados);

/** \brief se encarga de cargar los recuperados en el pais
 *
 * \param pais en el que se procedera a cargar el dato
 * \param numero de infectados que se le va a cargar al pais
 * \return retorna 0 si se pudo cargar, 1 si no se pudo
 *
 */
int paisSetInfectados(ePais* x, int infectados);

/** \brief se encarga de cargar los recuperados en el pais
 *
 * \param pais en el que se procedera a cargar el dato
 * \param numero de infectados donde se va a cargar el dato obtenido
 * \return retorna 0 si se pudo cargar, 1 si no se pudo
 *
 */
int paisGetInfectados(ePais* x,int* infectados);



/** \brief se encarga de cargar los muertos en el pais
 *
 * \param pais en el que se procedera a cargar el dato
 * \param numero de muertos que se le va a cargar al pais
 * \return retorna 0 si se pudo cargar, 1 si no se pudo
 *
 */
int paisSetMuertos(ePais* x, int muertos);


/** \brief se encarga de cargar los muertos en el pais
 *
 * \param pais en el que se procedera a cargar el dato
 * \param numero de muertos donde se va a cargar el dato obtenido
 * \return retorna 0 si se pudo cargar, 1 si no se pudo
 *
 */
int paisGetMuertos(ePais* x,int* muertos);
#endif // PAIS_H_INCLUDED
