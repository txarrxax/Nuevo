#include <stdio.h>
#include <stdlib.h>

void free_matriz_int (int **matriz, int m){
    int i;

    for (i=0; i<m; i++){
        free(matriz[i]);
    }

    free(matriz);
}

int** calloc_matriz_int (int m, int n){
    int i;
    int **matriz;

    if ((matriz = (int**) calloc(m, sizeof(int))) == NULL){
        return NULL;
    }

    for (i=0; i<m; i++){
        if ((matriz[i] = (int*) calloc(n, sizeof(int))) == NULL){
            free_matriz_int(matriz, i);
            return NULL;
        }
    }

    return matriz;
}

int main (){
    int i, j, filas, columnas;
    int **matriz;

    printf("Introduce el numero de filas: ");
    scanf("%d", &filas);

    printf("Introduce el numero de columnas: ");
    scanf("%d", &columnas);

    if ((matriz =calloc_matriz_int(filas, columnas)) == NULL){
        printf("No se ha podido generar la matriz.");
        return 1;
    }

    for (i=0; i<filas; i++){
        for (j=0; j<columnas; j++){
            printf("Introduce el valor de la celda (%d, %d) (filas, columna): ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (i=0; i<filas; i++){
        for (j=0; j<columnas; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    free(matriz);

    return 0;
}