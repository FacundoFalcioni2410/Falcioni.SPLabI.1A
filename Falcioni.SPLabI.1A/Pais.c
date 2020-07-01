#include "Pais.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ePais* paisNew()
{
    return (ePais*) malloc(sizeof(ePais));
}

void paisDelete(ePais* x)
{
    free(x);
    x = NULL;
}

int paisSetId(ePais* x, int id)
{
    int todoOk = 1;

    if(x != NULL && id > 0)
    {
        x->id = id;
        todoOk = 0;
    }
    return todoOk;
}

int paisGetId(ePais* x,int* id)
{
    int todoOk = 1;

    if(x != NULL && id != NULL)
    {
        *id = x->id;
        todoOk = 0;
    }

    return todoOk;
}

int paisSetPais(ePais* x, char* pais)
{
    int todoOk = 1;

    if(x != NULL && pais != NULL)
    {
        strcpy(x->pais,pais);
        todoOk = 0;
    }

    return todoOk;
}

int paisGetPais(ePais* x, char* pais)
{
    int todoOk = 1;

    if(x != NULL && pais !=NULL)
    {
        strcpy(pais,x->pais);
        todoOk = 0;
    }

    return todoOk;
}

int paisSetInfectados(ePais* x, int infectados)
{
    int todoOk = 1;

    if(x != NULL)
    {
        x->infectados = infectados;
        todoOk = 0;
    }

    return todoOk;
}

int paisGetInfectados(ePais* x,int* infectados)
{
    int todoOk = 1;

    if(x != NULL && infectados != NULL)
    {
        *infectados = x->infectados;
        todoOk = 0;
    }

    return todoOk;
}

int paisSetRecuperados(ePais* x, int recuperados)
{
    int todoOk = 1;

    if(x != NULL)
    {
        x->recuperados = recuperados;
        todoOk = 0;
    }

    return todoOk;
}

int paisGetRecuperados(ePais* x,int* recuperados)
{
    int todoOk = 1;

    if(x != NULL && recuperados != NULL)
    {
        *recuperados = x->recuperados;
        todoOk = 0;
    }

    return todoOk;
}

int paisSetMuertos(ePais* x, int muertos)
{
    int todoOk = 1;

    if(x != NULL)
    {
        x->muertos = muertos;
        todoOk = 0;
    }

    return todoOk;
}

int paisGetMuertos(ePais* x,int* muertos)
{
    int todoOk = 1;

    if(x != NULL && muertos != NULL)
    {
        *muertos = x->muertos;
        todoOk = 0;
    }

    return todoOk;
}



ePais* paisNewParametrosStr(char* idStr,char* nombreStr,char* recuperadosStr, char* infectadosStr,char* muertosStr)
{
    ePais* newPais = NULL;
    newPais = paisNew();

    if(newPais != NULL)
    {
        if(paisSetId(newPais,atoi(idStr))
                || paisSetPais(newPais,nombreStr)
                || paisSetRecuperados(newPais,atoi(recuperadosStr))
                || paisSetInfectados(newPais,atoi(infectadosStr))
                || paisSetMuertos(newPais,atoi(muertosStr)))
        {
            paisDelete(newPais);
        }
    }

    return newPais;
}

int mostrarPais(ePais* x)
{
    int todoOk;
    int id;
    char pais[128];
    int recuperados;
    int infectados;
    int muertos;

    if(x != NULL)
    {
        paisGetId(x,&id);
        paisGetPais(x,pais);
        paisGetRecuperados(x,&recuperados);
        paisGetInfectados(x,&infectados);
        paisGetMuertos(x,&muertos);
        printf("%4d   %20s      %8d     %8d      %8d\n",id,pais,recuperados,infectados,muertos);
        todoOk = 0;
    }
    return todoOk;
}


int mostrarPaises(LinkedList* lista)
{
    int todoOk = 1;

    int len = ll_len(lista);

    ePais* auxPais;
    system("cls");
    printf("  ID                  PAIS        RECUPERADOS      INFECTADOS    MUERTOS\n\n");

    for(int i = 0; i < len; i++)
    {
        auxPais = (ePais*) ll_get(lista,i);
        if(auxPais != NULL)
        {
            mostrarPais(auxPais);
            todoOk = 0;
        }
    }
    if(todoOk == 1)
    {
        printf("No hay paises para mostrar\n");
    }
    return todoOk;
}

int getRandom(int a,int b)
{
    int aleatorio;

    aleatorio = rand()%a+b;

    return aleatorio;
}

int setInfectadosRecuperadosMuertos(void* pais)
{
    int todoOk;
    ePais* auxPais;
    int aleatorioInfectados;
    int aleatorioMuertos;
    int AleatorioRecuperados;

    if(pais != NULL)
    {
        auxPais = (ePais*) pais;
        AleatorioRecuperados = getRandom(150000,50000);
        aleatorioInfectados = getRandom(1600000,40000);
        aleatorioMuertos = getRandom(49000,1000);

        if(paisSetRecuperados(auxPais,AleatorioRecuperados)
           || paisSetInfectados(auxPais,aleatorioInfectados)
           || paisSetMuertos(auxPais,aleatorioMuertos))
        {
            todoOk = 0;
        }
        else
        {
            todoOk = 1;
        }
    }

    return todoOk;
}

int ordenarPaisesPorInfeccion(void* a, void* b)
{
    int retorno;
    ePais* pais1;
    ePais* pais2;
    int infectadosP1;
    int infectadosP2;

    if(a != NULL && b != NULL)
    {
        pais1 = (ePais*) a;
        pais2 = (ePais*) b;

        paisGetInfectados(pais1,&infectadosP1);
        paisGetInfectados(pais2,&infectadosP2);

        if(infectadosP1 > infectadosP2)
        {
            retorno = 0;
        }
        else
        {
            retorno = 1;
        }
    }

    return retorno;
}

int paisesPorInfeccion(LinkedList* lista, int order)
{
    int todoOk = 1;

    if(lista != NULL)
    {
        if(!ll_sort(lista,ordenarPaisesPorInfeccion,order))
        {
            todoOk = 0;
        }
    }

    return todoOk;
}

int filtrarPaisesExitosos(void* unPais)
{
    int returnAux = 0;
    int muertos;
    ePais* x;
    if(unPais != NULL)
    {
        x = (ePais*) unPais;
        paisGetMuertos(x,&muertos);
        if(muertos <= 5000)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

ePais* mayorMuertos(LinkedList* lista)
{
    ePais* auxPais;
    ePais* auxPaisMayor = NULL;
    int muertos;
    int muertosMax;
    int flag = 0;
    int len = ll_len(lista);
    if(lista != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            auxPais = (ePais*) ll_get(lista,i);
            if(auxPais != NULL)
            {
                paisGetMuertos(auxPais,&muertos);
                if(!flag || muertos > muertosMax)
                {
                    muertosMax = muertos;
                    auxPaisMayor = auxPais;
                    flag = 1;
                }
            }
        }
    }

    return auxPaisMayor;
}

int filtrarPaisesEnElHorno(void* x)
{
    int returnAux = 0;
    ePais* auxPais;
    int infectados;
    int recuperados;

    if(x != NULL)
    {
        auxPais = (ePais*) x;
        paisGetInfectados(auxPais,&infectados);
        paisGetRecuperados(auxPais,&recuperados);
        if(infectados >= (recuperados * 3))
        {
            returnAux = 1;
        }
    }

    return returnAux;
}
