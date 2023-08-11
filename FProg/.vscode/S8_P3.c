#include <stdio.h>

int suma(int num) {
    int i, suma;

    suma = 0;
    i = num;
    while (i>0){
        suma = suma + i;
        i = i-2;
    }

    return suma;
}

int main () {
    int num, i, res, total;

    do{
        printf("Introduce un numero positivo: ");
        scanf("%d", &num);

        if (num<0){
            printf("Error, debes introducir un numero positivo.");
        }
    } while (num<0);

    total = 0;
    for (i=1; i<=num; i++){
        res = suma(i);
        printf("%d\n", res);
        total = total + res;
    }

    printf("Total: %d", total);

    return 0;
}