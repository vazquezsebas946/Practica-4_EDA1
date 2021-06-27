//Creado por Juan Carlos Mu�oz Cruz el dia 22/06/2021

#include <stdio.h>  //BIBLIOTECA PARA IMPRIMIR
#include <stdlib.h>     //BIBLIOTECA PARA RESERVAR MEMORIA

typedef struct _dato dato;  //ALIAS DE LA ESTRUCTURA PARA LA INFORMACI�N DEL NODO
struct _dato    //STRUCTURA PARA LA INFORMACI�N DEL NODO
{
    int i;  //VARIABLE DE LA INFORMACI�N DEL NODO
};

typedef struct _nodo nodo;  //ALIAS PARA LA ESTRUCTURA DEL NODO
struct _nodo    //ESTRUCTURA DEL NODO
{
    dato info;  //ESTRUCTURA TIPO dato, INFORMACI�N DEL NODO
    nodo *siguiente;    //ESTRUCTURA APUNTADOR nodo siguiente
};

void crear_nodo_malloc();   //PROTOTIPO PARA CREAR UN NODO CON MALLOC
void crear_nodo_calloc();   //PROTOTIPO PARA CREAR UN NODO CON CALLOC

void crear_nodo_malloc()
{
    nodo *nuevo=(nodo*)malloc(sizeof(nodo));    //CREA UNA VARIABLE APUNTADOR nodo y RESERVA MEMORIA CON LA FUNCI�N malloc
    printf("IMPRIMIR NODO CON MALLOC ANTES DE ASIGNAR UN VALOR\n");     //MENSAJE
    printf("valor: %d\t direccion:%p\n\n", nuevo->info, nuevo->siguiente);      //IMPRESI�N DE LA INFORMACI�N Y LA DIRECCI�N ANTES DE ASIGNARLAS
    free(nuevo);    //LIBERACI�N DE LA MEMORIA RESERVADA
    nuevo=NULL;     //LA VARIABLE APUTNA A NULO

}

void crear_nodo_calloc()
{
    nodo *nuevo=(nodo*)calloc(3,sizeof(nodo));      //CREA UNA VARIABLE APUNTADOR nodo y RESERVA MEMORIA CON LA FUNCI�N calloc
    printf("IMPRIMIR NODO CON CALLOC ANTES DE ASIGNAR UN VALOR\n");     //MENSAJE
    printf("valor: %d\t direccion:%p\n\n", nuevo->info, nuevo->siguiente);      //IMPRESI�N DE LA INFORMACI�N Y LA DIRECCI�N ANTES DE ASIGNARLAS
    free(nuevo);    //LIBERACI�N DE LA MEMORIA RESERVADA
    nuevo=NULL;     //LA VARIABLE APUTNA A NULO

}

int main()
{
    crear_nodo_malloc();       //LLAMA A LA FUNCI�N CREAR NODO CON malloc
    crear_nodo_calloc();    //LLAMA A LA FUNCI�N CREAR NODO CON calloc

    return 0;   //FIN DEL PROGRAMA
}
