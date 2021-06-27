//Creado por Juan Carlos Mu�oz Cruz el dia 22/06/2021

#include "Ejercicio04.h"    //ARCGIVO DE CABECERA
#include <stdlib.h>     //BIBLIOTECA PARA RESERVAR MEMORIA
#include <stdio.h>      //BIBLIOTECA PARA IMPRIMIR

NODE *new_node(DATA info)
{
    NODE *t=NULL;   //CREAR UN APUNTADOR TIPO NODO
    t=(NODE*)malloc(sizeof(NODE));  //RESERVAR MEMORIA PARA UN NODO
    t->info=info;   //COLOCAR LA INFORMACI�N DENTRO DEL NODO
    t->siguiente=NULL;  //APUNTADOR SIGUIENTE APUNTA A NULO
    return t;   //RETORNAR LA VARIABLE TIPO APUNTADOR
}

void free_node(NODE *n){
    if(n->siguiente==NULL)  //CONDICI�N PARA LIBERA MEMORIA DEL NODO
    {
        free(n);    //LIBERAR LA MEMORIA DEL NODO
        n=NULL;     //LA VARIABLE APUNTA A NULO
    }
}

LIST* new_list(){
    LIST *l=NULL;   //CREAR UNA VARIABLE TIPO APUNTADOR LIST
    l=(LIST*)malloc(sizeof(LIST));  //RESERVAR MEMORIA PARA LA VARIABLE l
    l->head=l->tail=NULL;   //CABEZA Y COLA APUNTAN A NULO
    l->num=0;   //CONTADOR INICIA EN CERO
    return l;   //RETORNAR LA VARIABLE l
}

void free_list(LIST *l){
    if(es_vacia(l))     //CONDICI�N PARA LIBERAR LA VARIABLE APUNTADOR LIST
    {
        free(l);    //LERAR MEMORIA
        l=NULL;     //LA VARIABLE APUNTA A NULO
    }
}

bool es_vacia(LIST *l){
    if(l->head == l->tail && l->head == NULL) return true;  //CONDICI�N PARA DETERMINAR QUE LA LISA ES VACIA
    return false;   //LA LISTA NO CUMPLE LA CONDI�N, NO ESTA VACIA
}


bool insertar_inicio(LIST *l, DATA info){
    NODE* nuevo;    //CREAR UNA VARIABLE TIPO APUNTADOR NODE

    if(es_vacia(l)){    //CONDICI�N PARA INSETAR AL INCIO SI ESTA VACIA
        nuevo=new_node(info);    //INSERTAR LA INFORMACI�N EN EL NODO
        l->head=l->tail=nuevo;      //HEAD Y TAIL APUNTAN AL �NICO NODO
        l->num=1;   //INCIAL CONTADOR EN 1
        return true;    //RETORNAR VERDADERO, SE INSERTO EL NODO
    }
        nuevo=new_node(info);   //INSERTAR LA INFORMACI�N EN EL NODO
        nuevo->siguiente=l->head;   //EL APUNTADOR SIGUIENTE DE NUEVO APUNTA A LA CABEZA
        l->head=nuevo;  //EL APUNTADOR HEAD SE ACTUALIZA Y APUNTA A NUEVO
        l->num++;   //SE ACTUALIZA EL CONTADOR SUMANDO 1
        return true;    //RETORNAR VERDADERO, SE INSERTO EL NODO
}

void empty_list(LIST *l){
    NODE *temp;     //VARIABLE AUXILIAR TEMP TIPO APUNTADOR NODE

    while(l->head != NULL){     //ESTRUCTUTA DE REPETICI�N, EL APUNTADOR HEAD NO DEBE APUNTAR A NULO PARA ENTRAR
    temp=l->head;   //TEMP APUNTA A HEAD
    l->head=l->head->siguiente;     //RECORE HEAD AL SIGUIENTE NODO
    temp->siguiente=NULL;   //DESAPUTA EL APUNTADOR SIGUIENTE DEL NODO PARA PODER LIBERAR MEMORIA
    free_node(temp);    //LIBERA MEMORIA DEL NODO
    }
    l->head=l->tail=NULL;   //HEAD Y TAIL APUNTAN A NULO

}

void imprimir_lista(LIST *l){

    if(es_vacia(l)==false){ //CONDICI�N PARA IMPRIMIR LA LISTA, NO DEBE ESTAR VACIA
        NODE *temp=l->head;     //VARIABLE AUXILIAR APUNTADOR NODE

        while(temp != NULL){    //ESTRUCTURA DE REPETICI�N, TEMP NO DEBE APUNTAR A NULO PARA ENTRAR AL CICLO
        printf("info x:%d  direc:%p  direcEntera:%d\n",temp->info, temp->siguiente, temp->siguiente);   //IMPRESI�N DE LA INFORMACI�N DEL NODO Y DIRECCI�N CON FORMATO Y EN ENTERO
        temp=temp->siguiente;   //RECORRE EL APUNTADOR TEMPORAL AL SIGUIENTE
        }
    }

}

int main(){

    int i;  // DECLARACI�N UNA VARIABLE AUXILIAR PARA EL CILO FOR TIPO ENTERA
    LIST* l=new_list();     //CREA UNA VARIABLE TIPO APUTNADOR LIST, CREA UNA LISTA
    DATA valores;   //CREA UN ESTRUCTURA DATA PARA GUARDAR LA INFORMACI�N DEL NODO

    for(i=0; i<4; i++){     //ESTRUCTUR DE REPETICI�N FOR, ENTRA AL CICLO 4 VECES
    printf("DAME VALOR ENTERO:");   //MENSAJE PARA INSERTAR UN VALOR ENTERO DESDE EL TECLADO
    scanf("%d", &valores.x);    //GUARDA EL VALOR ENTERO EN LA ESTRUCTURA
    insertar_inicio(l, valores);    //LLAMADA DE LA FUCI�N INSETAR AL INICIO
    }

    imprimir_lista(l);      //LLAMADA A LA FUNCI�N PARA IMPRIMIR LA LISTA
    empty_list(l);       //LLAMADA A LA FUNCI�N PARA VACIAR LA LISTA
    free_list(l);   //LLAMADA A LA FUCI�N PARA LIBERAR LA MEMORIA RESERVADA PARA l TIPO LIST

    return 0;   //FIN DE LA EJECICI�N
}
