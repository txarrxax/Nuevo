#include <stdio.h>
#include <stdlib.h>

#define MIN 1
#define MAX 128

int* obtenPares (int *tabla, int tam, int *numPares){
    int i, j=0, par=0, *nueva;

    for (i=0; i<tam; i++){
        if (tabla[i]%2 == 0){
            par++;
        }
    }


    nueva = (int*) calloc(par, sizeof(int));

    for (i=0; i<tam; i++){
        if (tabla[i]%2 == 0){
            nueva[j] = tabla[i];
            j++;
        }
    }

    *numPares = par;

    return nueva;
}

int main (){
    int i, tam, *tabla, pares, *nueva;

    do{
        printf("Cuantos numeros quieres leer? ");
        scanf("%d", &tam);

        if (tam < MIN || tam > MAX){
            printf("Error, debes introducir un numero entre %d y %d.\n", MIN, MAX);
        }
    } while (tam < MIN || tam > MAX);

    tabla = (int*) calloc(tam, sizeof(int));

    for (i=0; i<tam; i++){
        printf("Introduce el numero %d: ", i+1);
        scanf("%d", &tabla[i]);
    }

    nueva = obtenPares(tabla, tam, &pares);

    printf("Los numeros pares son: ");

    for (i=0; i<pares; i++){
        printf("%d ", nueva[i]);
    }

    free(nueva);

    return 0;
}