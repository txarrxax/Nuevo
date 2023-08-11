#include <stdio.h>

int main() {
    int num1, num2, i;

    i = 0;
    num2 = 0;

    printf("Introduce un numero entre 1 y 99: ");
    scanf("%d", &num1);

    while (i<25){
        printf("\n");
        i++;
    }

    do{
        printf("Adivina el numero: ");
        scanf("%d", &num2);
    } while (num1!=num2);
    
    printf("Acertaste, el numero era el %d.", num1);

    return 0;
}