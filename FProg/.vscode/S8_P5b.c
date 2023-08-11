#include <stdio.h>
#include <math.h>

int esPrimo (int num) {
    int i;

    for (i=2; i<=sqrt(num); i++){
        if (num%i == 0){
            return 0;
        }
    }
    
    return 1;
}

int sumaDePrimos (int valor) {
    int suma = 0, i;

    for (i=2; i<=valor; i++){
        if (esPrimo(i) == 1){
            suma = suma + i;
        }
    }

    return suma;
}

int main () {
    int num, suma;

    do{
        printf("Introduce un numero mayor o igual que dos: ");
        scanf("%d", &num);

        if (num < 2){
            printf("Error, tiene que introducir un numero mayor o igual que dos\n");
        }
    } while (num < 2);

    suma = sumaDePrimos(num);

    printf("La suma de los numeros primos desde 2 hasta %d es %d", num, suma);

    return 0;
}