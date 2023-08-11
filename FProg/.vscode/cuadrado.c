#include <stdio.h>
#include <stdlib.h>

#define MIN 3
#define MAX 10

void free_matriz_int (int **matriz, int m){
    int i;

    for (i=0; i<m; i++){
        free(matriz[i]);
    }

    free(matriz);
}

int** calloc_matriz_int (int n){
    int i;
    int **matriz;

    if ((matriz = (int**) calloc(n, sizeof(int))) == NULL){
        return NULL;
    }

    for (i=0; i<n; i++){
        if ((matriz[i] = (int*) calloc(n, sizeof(int))) == NULL){
            free_matriz_int(matriz, i);
            return NULL;
        }
    }

    return matriz;
}

void cuadrado_magico (int **matriz, int n){
    int i, j, num, max;

    max = n*n;

    i = 0;
    j = n/2;

    for (num=1; num <=max; n++){
        if (matriz[i][j] != 0){
            i -= 2;
            j--;
        }
        if (i < 0){
            i = n-1;
        }
        if (j > n-1){
            j = 0;
        }
        matriz[i][j] = num;

        i++;
        j++;
    }
}
int main (){
    int n, i, j;
    int **matriz;

    do{
        printf("Introduce el tamano del cuadrado magico: ");
        scanf("%d", &n);

        if (n < MIN || n > MAX || n%2 == 0){
            printf("Error. Debes introducir un entero impar entre %d y %d.\n", MIN, MAX);
        }
    } while (n < MIN || n > MAX || n%2 == 0);

    if ((matriz = calloc_matriz_int (n)) == NULL){
        printf("No se ha podido generar la matriz.");
        return 1;
    }

    matriz[0][0] = 0;

    cuadrado_magico (matriz, n);

    for(i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;

}