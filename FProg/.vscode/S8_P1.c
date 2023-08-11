#include <stdio.h>

int minimoDivisor (long x) {
    int divisor, i;
    for (i=2; i<=x; i++) {
        if (x%i == 0) {
            divisor = i;
            break;
        }
    }
    return divisor;
}

int main () {
    long num, i, res;

    do{
        printf("Escribe un numero mayor que 2: ");
        scanf("%ld", &num);
    } while (num < 2);

    res = minimoDivisor(num);

    for (i=2; i<=num; i++){
        res = minimoDivisor(i);
        printf("El divisor mas pequeñi de %ld es: %ld\n", i, res);
    }

    return 0;
}