#include <stdio.h>

#define DIM 10

int main () {
    int i, j, k;
    int suma = 0;
    int tabla[DIM];

    for (i=0; i<DIM; i++){
        printf("Introduce un numero: ");
        scanf("%d", &tabla[i]);
        if (tabla[i] == 0){
            break;
        }
    }
    k=0;
    for (j=i; j>=0; j--){
        if (tabla[j] >= 0){
            suma = suma + tabla[j];
        }
        else{
            k++;
        }
    }

    printf("Se han introducido %d numeros, de los cuales %d eran negativos, y la suma de los positivos es %d.", i, k, suma);

    return 0;
}