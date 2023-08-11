#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 64

//estructura que define el tipo de dato "number"
typedef struct{
    long base;
    char x[DIM];
} number;

//funcion que convierte un numero a decimal
long convert2Decimal (number *n){
    int i, j;
    long decimal;

    for (i=(strlen(n->x)-1), j=1, decimal =0; i>=0; i--, j*=n->base){
        if (n->x[i] > '9'){
            decimal += (n->x[i] - 'A'+10)*j;
        }
        else{
            decimal += (n->x[i]-'0')*j;
        }
    }

    return decimal;
}

//funcion que convierte un numero decimal a otra base
short convertDecimal2B (long x, number *n){
    int i, j;
    char aux[DIM];

    if (x == 0 || n == NULL){
        return 1;
    }

    for (i=0; x > 0; i++){
        aux[i] = x%n->base + '0';
        if (aux[i] > '9'){
            aux[i] += 'A' - '9' + 10;
        }
        x /= n->base;
    }

    for (j=0; i>0; i--, j++){
        n->x[j] = aux[i-1];
    }

    if (j>DIM){
        return 2;
    }

    return 0;
}

//funcion que convierte un numero de una base a otra
short convertB1_2_B2 (number *origin, number *destination){
    long decimal;

    if (origin == NULL || destination == NULL){
        return 1;
    }

    decimal = convert2Decimal(origin);

    if (convertDecimal2B(decimal, destination) != 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main (){
    number no, nd;

    printf("Introduce la base de origen: ");
    scanf("%ld", &no.base);
    printf("Escribe un numero en base %ld: ", no.base);
    scanf("%s", no.x);
    printf("Introduce la base de destino: ");
    scanf("%ld", &nd.base);

    if (convertB1_2_B2(&no, &nd) == 0){
        printf("%s en base %ld es %s en base %ld", no.x, no.base, nd.x, nd.base);
    }
    else{
        printf("Se ha producido un error");
    }

    return 0;
}