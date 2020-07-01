#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "LinkedList.h"
#include "Pais.h"

/** \brief Parsea los datos los datos de los empleados desde un archivo
 *
 * \param nombre del archivo del que se cargaran los datos
 * \param array del LinkedList
 * \return int devuelve 1 si hay errores, 0 esta todo bien
 *
 */

int cargarTexto(LinkedList* lista,char* path);

#endif // PARSER_H_INCLUDED
