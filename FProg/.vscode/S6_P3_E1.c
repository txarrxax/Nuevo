#include <stdio.h>

#define DIM 10

int main () {
    int tabla[DIM], test, i, j;

    for (i=0; i<DIM; i++){
        if (test == 0){
            printf("Introduce el numero (%d): ", i+1);
            scanf("%d", &tabla[i]);
            for (j=i-1; j>=0; j--){
                if (tabla [i] == tabla[j]){
                    printf("Hasta aqui hemos llegado. Has repetido el numero %d.", tabla[i]);
                    test = 1;
                }
            }
        } 
    }

    if (test == 0){
        printf("Has llegado a introducir los 10 numeros sin repetir ninguno");
    }

    return 0;
}