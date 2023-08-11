#include <stdio.h>

#define DIM 1000

int main () {
    int lista[DIM], divisores[DIM], min, tamano, primos, comunes, i, j;

    do{
        printf("Escribe el tamano del conjunto: ");
        scanf("%d", &tamano);

        if (tamano < 2 || tamano > 1000){
            printf("El tamano del conjunto, %d, esta fuera del rango permitido [2,1000], escribelo otra vez: ", tamano);
            scanf("%d", &tamano);
        }
    }while (tamano <2 || tamano > 1000);

    for (i=0; i<tamano; i++){
        printf("Ecribe el elemento %d del conjunto: ", i+1);
        scanf("%d", &lista[i]);
    }
    
    min = lista[0];

    for (i=0; i<tamano; i++){
        if (lista[i]<min){
            min = lista[i];
        }
    }

    j = 0;
    for (i=2; i<=min; i++){
        if (min%i == 0){
            divisores[j] = i;
            j++;
        }
    }
    
    primos = 0;
    for (j=0; j<min; j++){
        comunes = 0;
        for (i=0; i<tamano; i++){
            if (lista[i]%divisores[j] == 0){
                comunes++;
            }
        }
        if (comunes == tamano){
            printf("Los numeros del conjunto tienen como divisor comun al %d\n", divisores[j]);
            primos = 1;
        }
    }
    
    if (primos == 0){
        printf("Los numeros del conjunto son todos primos relativos");
    }
}