#include <stdlib.h>
#include <stdio.h>
//Hecho por Vazquez Reyes Sebastian el 22/06/2021
int main (int argc, char **argv)
{
    int *array = NULL, num, cont;
    printf("¿Cuantos elementos tiene el arreglo?");
    scanf("%d", &num);
    array = (int*) realloc(array, num * sizeof(int));//Con realloc, redimensionamos el tamaño del bloque de memoria
    if(array != NULL)
    {
        for(cont = 0; cont < num; cont++)
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

    num*= 2;
    array= (int*)realloc(array, num * sizeof(int));//Al usar el segundo realloc, el tamaño de memoria aumenta o fisminuye, en este caso aumenta x2
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
