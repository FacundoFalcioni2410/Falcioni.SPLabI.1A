#include "Pais.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int cargarTexto(LinkedList* lista,char* path)
{
    int todoOk = 1;
    char header[5][128];
    char buffer[5][128];
    int cant;
    ePais* newPais;
    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]",header[0],header[1], header[2], header[3],header[4]);

        while(!(feof(pFile)))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]",buffer[0],buffer[1], buffer[2], buffer[3],buffer[4]);

            if(cant == 5)
            {
                todoOk = 0;
                newPais = paisNewParametrosStr(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
                if(newPais != NULL)
                {
                    ll_add(lista,newPais);
                }
            }
            else
            {
                break;
            }
        }
    }
    return todoOk;
}
