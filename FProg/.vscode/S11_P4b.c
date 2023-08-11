#include <stdio.h>
#include <string.h>

#define DIM 64

short conversor (long x, long base, char *s){
    int i=0, j;
    char a[DIM];

    if (x == 0 || base == 0 || s == NULL){
        return 0;
    }
    else{
        while (x > 0){
            a[i] = x%base;
            x = x/base;
            i++;
        }

        for (i--, j=0; i>=0; i--, j++){
            s[j] = a[i];
        }

        return 1;
    }
}

int main (){
    long num, base;
    char cadena[DIM]={};
    int i;

    printf("Introduce un numero en base decimal: ");
    scanf("%ld", &num);

    printf("A que base lo quieres convertir? ");
    scanf("%ld", &base);

    if (conversor (num, base, cadena) == 1){
        printf("El numero decimal %ld en base %ld es: ", num, base);
        for (i=0; i<strlen(cadena); i++){
            printf("%d ", cadena[i]);
        }
    }
    else{
        printf("Ha ocurrido un error.\n");
    }

    return 0;
}