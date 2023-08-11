#include <stdio.h>

int DecimalABinario (int x, int *a){
    int i=0, y=1;
    if (x+1 > 0){
        while (x+1>=y){
            y = y*2;
            i++;
        }

        (*a) = i;
        return 1;
    }
    else{
        return 0;
    }
}

int main () {
    int num, d;

    do{
        printf("Introduce un numero entero positivo: ");
        scanf("%d", &num);

        if (num < 0){
            printf("El numero %d no es correcto\n", num);
        }
    } while (num < 0);

    if (DecimalABinario(num, &d) == 1){
        printf("El numero %d en decimal ocupa %d digitos en binario", num, d);
    }

    return 0;
}
