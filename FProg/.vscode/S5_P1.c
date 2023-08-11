#include <stdio.h>

#define DIM 10

int main() {
    int num, i;
    float tabla[DIM];

    i=0;

    printf("¿Cuantos numeros quieres leer? (entre 2 y 10)");
    scanf("%d", &num);

    while (num<2 || num>10){
        printf("Error, debes introducir un numero entre 2 y 10.\n");
        printf("¿Cuantos numeros quieres leer? ");
        scanf("%d", &num);
    }

    while (i<num){
        printf("Introduce el numero %d de %d: ", i+1, num);
        scanf("%f", &tabla[i]);
        i++;
    }

    while (i>0){
        if (tabla[i-1]<tabla[num-1]){
            printf("El numero %.2f es menor que el numero %.2f.\n", tabla[i-1], tabla[num-1]);
        }
        i--;
    }
    return 0;
}