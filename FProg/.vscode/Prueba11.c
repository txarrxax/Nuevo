#include <stdio.h>

#define STR 4

typedef struct {
    char cadena[STR];
    int suma;
} Palabra;

int main () {
    Palabra palabra;

    printf("Intrduce una palabra de 4 caracteres: ");
    scanf("%s", &palabra.cadena);

    palabra.suma = palabra.cadena[0] + palabra.cadena[1] + palabra.cadena[2] + palabra.cadena[3];

    printf("La palabra %s esta formada por los caracteres %c, %c, %c, %c y la suma de sus codigos ASCII es %d.", palabra.cadena, palabra.cadena[0], palabra.cadena[1], palabra.cadena[2], palabra.cadena[3], palabra.suma);

    return 0;
}