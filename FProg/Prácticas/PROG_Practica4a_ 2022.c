#include <stdio.h>
#include <stdlib.h>

int cuantosMayores (int *tabla, int tam){
    int i, j, num=0;

    if (tabla == NULL || tam < 1){
        return -1;
    }

    for (i=0; i<tam; i++){
        for (j=i+1; j<tam; j++){
            if (tabla[i] < tabla[j]){
                num++;
            }
        }
    }

    return num;
}

int main (){
    int *tabla, tam, i, mayores;

    do{
        printf("Introduce cuantos numeros vas a escribir: ");
        scanf("%d", &tam);

        if (tam < 1){
            printf("Error. Debe introducir un numero positivo.\n");
        }
    } while (tam < 1);

    tabla = (int*) calloc(tam, sizeof(int));

    for (i=0; i<tam; i++){
        printf("Introduce el numero %d de %d: ", i+1, tam);
        scanf("%d", &tabla[i]);
    }

    mayores = cuantosMayores(tabla, tam);

    if (mayores < 0){
        printf("Ha ocurrido un error.");
    }
    else{
        printf("El total de numeros mayores a la derecha de cada numero es %d.", mayores);
    }

    free(tabla);

    return 0;
}