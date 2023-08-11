#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    long base;
    char *x;
} number;

// liberacion de la memoria
void freeNumber (number *num){
    if (num){
        if (num->x){
            free(num->x);
            num->x = NULL;
        }
        free(num);
    }
}

// reserva dinámica de memoria
number *allocNumber (long n){
    number *numero;

    if (n <= 0){
        return NULL;
    }

    if (!(numero = (number*) calloc(1, sizeof(number)))){
        return NULL;
    }

    if (!(numero->x = (char*) calloc(n+1, sizeof(char)))){
        freeNumber(numero);
        return NULL;
    }

    return numero;
}

// numero de digitos de un numero al convertirlo a decimal
long numberDigits (long x, long b){
    return (log(x)/log(b) + 1);
}

// funcion que convierte un numero a decimal
long convert2Decimal (number *n){
    int i, j;
    long decimal;

    for (i=strlen(n->x)-1, j=1, decimal=0; i>=0; i--, j*=n->base){
        if (n->x[i] > 'a' && n->x[i] < 'z'){
            decimal += (n->x[i] - 'a' + 10)*j;
        }
        else if (n->x[i] > 'A' && n->x[i] < 'Z'){
            decimal += (n->x[i] - 'A' + 10)*j;
        }
        else{
            decimal += (n->x[i] - '0')*j;
        }
    }
    return decimal;
}

// convertir un numero de decimal a otra base
number *convertDecimal2Base (long x, long base){
    int i, j;
    char *aux = NULL;
    number *num = NULL;

    if (x < 0 || base < 1){
        return NULL;
    }

    if (!(aux = (char*) calloc (numberDigits(x, base) + 1, sizeof(char)))){
        return NULL;
    }

    if (!(num = allocNumber(numberDigits(x, base)))){
        free(aux);
        return NULL;
    }

    num->base = base;

    for (i=0; x>0; x/=num->base, i++){
        aux[i] = x%num->base + '0';
        if (aux[i] > 'a' && aux[i] < 'z'){
            aux[i] += 'a' - '9' + 10;
        }
        else if (aux[i] > 'A' && aux[i] < 'Z'){
            aux[i] += 'A' -'9' + 10;
        }
    }

    aux[i] = '\0';

    for (i=strlen(aux)-1, j=0; i>=0; i--, j++){
        num->x[j] = aux[i];
    }

    num->x[j] = '\0';

    free(aux);
    aux = NULL;

    return num;
}

//convertir un numero de una base a otra
number *convertB1_2_B2 (number *origin, long base){
    number *destination = NULL;

    if (!origin  || base <= 1){
        return NULL;
    }

    if (!(destination = convertDecimal2Base(convert2Decimal(origin), base))){
        return NULL;
    }

    return destination;
}

int main (){
    number *origin = NULL, *destination = NULL;
    long base;

    if (!(origin = allocNumber(100))){
        printf("Error reservando la memoria\n");
        return 1;
    }

    printf("Introduce la base de origen: ");
    scanf("%ld", &origin->base);
    printf("Introduce un numero en base %ld: ", origin->base);
    scanf("%s", origin->x);
    
    printf("Introduce la base de destino: ");
    scanf("%ld", &base);

    if (!(destination = convertB1_2_B2(origin, base))){
        printf("Error conviertiendo.\n");
        return 1;
    }

    printf("%s en base %ld es %s en base %ld", origin->x, origin->base, destination->x, destination->base);

    return 0;
}