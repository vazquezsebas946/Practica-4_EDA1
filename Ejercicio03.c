//Creado por Juan Carlos Muñoz Cruz el dia 22/06/2021

#include <stdio.h>  //BIBLIOTECA PARA IMPRIMIR
#include <stdlib.h>     //BIBLIOTECA PARA RESERVAR MEMORIA

typedef struct _dato dato;  //ALIAS DE LA ESTRUCTURA PARA LA INFORMACIÓN DEL NODO
struct _dato    //STRUCTURA PARA LA INFORMACIÓN DEL NODO
{
    int i;  //VARIABLE DE LA INFORMACIÓN DEL NODO
};

typedef struct _nodo nodo;  //ALIAS PARA LA ESTRUCTURA DEL NODO
struct _nodo    //ESTRUCTURA DEL NODO
{
    dato info;  //ESTRUCTURA TIPO dato, INFORMACIÓN DEL NODO
    nodo *siguiente;    //ESTRUCTURA APUNTADOR nodo siguiente
};

void crear_nodo_malloc();   //PROTOTIPO PARA CREAR UN NODO CON MALLOC
void crear_nodo_calloc();   //PROTOTIPO PARA CREAR UN NODO CON CALLOC

void crear_nodo_malloc()
{
    nodo *nuevo=(nodo*)malloc(sizeof(nodo));    //CREA UNA VARIABLE APUNTADOR nodo y RESERVA MEMORIA CON LA FUNCIÓN malloc
    printf("IMPRIMIR NODO CON MALLOC ANTES DE ASIGNAR UN VALOR\n");     //MENSAJE
    printf("valor: %d\t direccion:%p\n\n", nuevo->info, nuevo->siguiente);      //IMPRESIÓN DE LA INFORMACIÓN Y LA DIRECCIÓN ANTES DE ASIGNARLAS
    free(nuevo);    //LIBERACIÓN DE LA MEMORIA RESERVADA
    nuevo=NULL;     //LA VARIABLE APUTNA A NULO

}

void crear_nodo_calloc()
{
    nodo *nuevo=(nodo*)calloc(3,sizeof(nodo));      //CREA UNA VARIABLE APUNTADOR nodo y RESERVA MEMORIA CON LA FUNCIÓN calloc
    printf("IMPRIMIR NODO CON CALLOC ANTES DE ASIGNAR UN VALOR\n");     //MENSAJE
    printf("valor: %d\t direccion:%p\n\n", nuevo->info, nuevo->siguiente);      //IMPRESIÓN DE LA INFORMACIÓN Y LA DIRECCIÓN ANTES DE ASIGNARLAS
    free(nuevo);    //LIBERACIÓN DE LA MEMORIA RESERVADA
    nuevo=NULL;     //LA VARIABLE APUTNA A NULO

}

int main()
{
    crear_nodo_malloc();       //LLAMA A LA FUNCIÓN CREAR NODO CON malloc
    crear_nodo_calloc();    //LLAMA A LA FUNCIÓN CREAR NODO CON calloc

    return 0;   //FIN DEL PROGRAMA
}
