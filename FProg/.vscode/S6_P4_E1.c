#include <stdio.h>
#include <stdlib.h>

#define DIM 1000

int main () {
    int tabla[DIM], i, j, n;

    for (i=0; i<DIM; i++){
        tabla[i] = rand()%100;
    }

    for (i=0; i<100; i = i+10){
        n=0;
        for (j=0; j<DIM; j++){
            if (i<=tabla[j] && tabla[j]<=i+9){
                n++;
            }
        }
        printf("Numeros enteros en el rango [%d,%d]: %d\n", i, i+9, n);
    }
}