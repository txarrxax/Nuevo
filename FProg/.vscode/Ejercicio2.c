#include <stdio.h>

#define MAX_PRI 5

int main () {
    int numero, i = 0, j, test;
    int primos[MAX_PRI];

    do{
        test = 0;

        printf("Escribe un numero: ");
        scanf("%d", &numero);
        
        if (numero > 0){
            for (j=2; j<numero; j++){
                if (numero % j == 0){
                    test = 1;
                }
            }

            if (test==0){
                primos[i] = numero;
                i++;
            }
        }
    } while (numero > 0 && i < MAX_PRI);

    printf("Los primos introducidos en orden inverso a como se escribieron son: ");

    for (i=i-1; i>=0; i--){
        printf("%d ", primos[i]);
    }

    return 0;
}