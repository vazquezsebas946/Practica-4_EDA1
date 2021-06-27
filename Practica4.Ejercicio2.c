#include <stdlib.h>
#include <stdio.h>
//Hecho por Vazquez Reyes Sebastian el 22/06/2021
int main (int argc, char **argv)
{
    int *array, num, cont;//definimos los datos
    printf("¿Cuantos elementos tiene el arreglo?");
    scanf("%d", &num);//se le pide al usuario el numero de elementos del primer arreglo
    array = (int*) calloc(num, sizeof(int));//calloc recibe el numero de elementos, y el tamaño de uno de ellos
    if(array != NULL)
    {
        for(cont = 0; cont < num; cont++)//se lleva acabo un for que pide el numero de cada elemento
        {
            printf("Ingresa el elemento %d\n", cont+1);
            scanf("%d", (array+cont));
        }
        printf("Vector reservado:\n\t[");
        for(cont = 0; cont < num; cont++)
        {
            printf("\tvalor:%d dir:%d", *(array+cont), array+cont);//se le da un valor al elemento y se imprime su direccion de memoria
        }
    printf("\t]\n");

    num/= 2;
    array= (int*)realloc(array, num * sizeof(int));//con malloc, cambiamos el tamaño de la memoria reservada. Aumentando o disminuyendo el numero de elementos
    if(array != NULL)
    {
        for(cont=0; cont < num; cont++)
        {
            printf("Ingresa el elemento %d\n", cont+1);
            scanf("%d", (array+cont));
        }
        printf("Vector reservado:\n\t[");
        for(cont = 0; cont < num; cont++)
        {
            printf("\tvalor:%d dir:%d", *(array+cont), array+cont);
        }
        printf("\t]\n");

        printf("La memoria sera liberada\n");
        free(array);
    }
    }
    return 0;
}
