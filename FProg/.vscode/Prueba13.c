#include <stdio.h>

#define DIM 10

int main() {
    int tabla[DIM];
    int i, j,  num;

    i=0;
    j=0;

    while (i<DIM){
        tabla[i] = i+1;
        i++;
    }

    printf("Introduce el numero de valores que quieres mostrar: ");
    scanf("%d", &num);
    
    while (num<1 || num>DIM){
        printf("Error. Introduce un numero entre 1 y 10.\n");
        printf("Introduce el numero de valores que quieres mostrar: ");
        scanf("%d", &num);
    }

    while (j<num){
        printf("%d ", tabla[j]);
        j++;
    }

    return 0;
}