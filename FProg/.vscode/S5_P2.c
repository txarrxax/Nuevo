#include <stdio.h>

#define DIM 10

int main() {
    int num, i;
    int tabla[DIM];

    i=0;

    printf("¿Cuantos numeros quieres leer? (entre 2 y 10) ");
    scanf("%d", &num);

    while (num<2 || num>10){
        printf("Error, debes introducir un numero entre 2 y 10.\n");
        printf("¿Cuantos numeros quieres leer? ");
        scanf("%d", &num);
    }

    while (i<num){
        printf("Introduce el numero %d de %d: ", i+1, num);
        scanf("%d", &tabla[i]);
        i++;
    }

    printf("Los numeros pares son: ");
    while (i>=0){
        if (tabla[i]%2==0){
            printf("%d ", tabla[i]);
        }
        i--;
    }

    i=num-1;
    printf("\nLos numeros impares son: ");
    while (i>=0){
        if (tabla[i]%2==1){
            printf("%d ", tabla[i]);
        }
        i--;
    }

    return 0;
}