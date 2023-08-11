#include <stdio.h>
#include <string.h>
#define DIM 64

char codificar (char a, int x) {
    char b;
    b = a + x;

    return b;
}

char decodificar (char b, int x) {
    char a;
    a = b - x;

    return a;
}

int main () {
    char cadena[DIM];
    int num, i;
    char a;

    printf("Introduce la clave de cifrado: ");
    scanf("%d", &num);

    printf("Introduce una cadena de cracteres: ");
    scanf("\n%s", cadena);

    for (i=0; i<strlen(cadena); i++){
        a = codificar(cadena[i], num);
        cadena[i] = a;
    }

    printf("Cadena codificada: %s\n", cadena);

    for (i=0; i<strlen(cadena); i++){
        a = decodificar(cadena[i], num);
        cadena[i] = a;
    }

    printf("Cadena decodificada: %s", cadena);

    return 0;
}