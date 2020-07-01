#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Pais.h"
#include "LinkedList.h"
#include "utn.h"
#include "parser.h"

/** \brief muestra el menu principal
 *
 * \param opcion int* pasa por referencia la opcion elegida por el usuario
 * \return void
 *
 */

void menu(int* option);

int main()
{
    srand(time(NULL));
    char path[128];
    int option;
    ePais* auxPais;
    char confirm = 'n';
    LinkedList* listaPaises = ll_newLinkedList();
    LinkedList* listaPaisesCompleta = NULL;
    LinkedList* listaPaisesExitosos;
    LinkedList* listaPaisesEnElHorno;
    do
    {
        do
        {
            menu(&option);
            switch(option)
            {
            case 1:
                if(ll_isEmpty(listaPaises))
                {
                        printf("Ingrese el nombre del archivo: ");
                        fflush(stdin);
                        scanf("%s",path);
                        cargarTexto(listaPaises,path);
                }
                else
                {
                    printf("\nYa se cargaron los datos\n");
                }
                break;
            case 2:
                if(!ll_isEmpty(listaPaises))
                {
                    mostrarPaises(listaPaises);
                }
                break;
            case 3:
                if(!ll_isEmpty(listaPaises))
                {
                   listaPaisesCompleta = ll_filter(listaPaises,setInfectadosRecuperadosMuertos);
                   printf("Lista filtrada con exito\n");
                }
                break;
            case 4:
                if(!ll_isEmpty(listaPaisesCompleta))
                {
                    mostrarPaises(listaPaisesCompleta);
                }
                break;
            case 5:
                listaPaisesExitosos = ll_filter(listaPaisesCompleta,filtrarPaisesExitosos);
                mostrarPaises(listaPaisesExitosos);
                break;
            case 6:
                listaPaisesEnElHorno = ll_filter(listaPaisesCompleta,filtrarPaisesEnElHorno);
                mostrarPaises(listaPaisesEnElHorno);
                break;
            case 7:
                if(!paisesPorInfeccion(listaPaisesCompleta,1))
                {
                    printf("\nOrdenado con exito\n.");
                }
                else
                {
                    printf("\nNo se pudo ordenar.\n");
                }
                break;
            case 8:
                auxPais = mayorMuertos(listaPaisesCompleta);
                printf("  ID                  PAIS        RECUPERADOS      INFECTADOS    MUERTOS\n\n");
                mostrarPais(auxPais);
                break;
            case 9:
                printf("Confirma salida del programa?: ");
                fflush(stdin);
                scanf("%c",&confirm);
                break;
            }
            printf("\n");
            system("pause");
            system("cls");
        }
        while(confirm != 's');
    }
    while(option != 9);

    ll_deleteLinkedList(listaPaises);
    ll_deleteLinkedList(listaPaisesCompleta);
    ll_deleteLinkedList(listaPaisesEnElHorno);
    ll_deleteLinkedList(listaPaisesExitosos);

    return 0;
}

void menu(int* option)
{
    printf("\n");
    printf("1. Cargar archivo.\n");
    printf("2. Imprimir lista.\n");
    printf("3. Asignar estadisticas.\n");
    printf("4. Mostrar lista completa\n.");
    printf("5. Filtrar por paises exitosos.\n");
    printf("6. Filtrar por paises en el horno.\n");
    printf("7. Orden por nivel de infeccion.\n");
    printf("8. Mostrar mas castigado\n");
    printf("9. Salir.\n");
    fflush(stdin);
    utn_getEntero(option,3,"Ingrese una opcion: ","ERROR. Opcion invalida\n",1,9);
}
