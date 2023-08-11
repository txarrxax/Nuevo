#include <stdio.h>

#define DIM 10

int main() {
    int tabla[DIM];
    int i=0;

    while (i<10){
        printf("Introduzca un numero entero (0 para terminar): ");
        scanf("%d", &tabla[i]);
        if (tabla[i]==0){
            break;
        }
        else{
            i++;
        }
    }

    if (i==0){
        printf("No se ha introducido ningun numero.");
    }
    else{
        if (i==10){
            printf("Numero maximo de numeros alcanzado. Continuando...\n");
        }
        printf("Los numeros tecleados son: ");
        while (i>0){
            printf("%d ", tabla[i-1]);
            i--;
        }
    }
    
    return 0;
}