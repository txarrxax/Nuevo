#include <stdio.h>

int factorial (int num) {
    int i, fact;

    fact = 1;

    for (i=num; i>0; i--){
        fact = fact*i;
    }
    return fact;
}

int main () {
    int num, i, res, total;

    do{
        printf("Introduce un numero positivo: ");
        scanf("%d", &num);

        if (num < 1){
            printf("Error, debes introducir un numero positivo.");
        }
    } while (num < 1);

    total = 0;

    for (i=1; i<=num; i++){
        res = factorial(i);
        total = total + res;
        printf("%d\n", res);
    }

    printf("Total: %d", total);

    return 0;
}