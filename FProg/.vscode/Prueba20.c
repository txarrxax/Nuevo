#include <stdio.h>

#define DIM 64

int main (){
    char cadena[DIM];
    char *p;
    int i;

    printf("Introduce una cadena de caracteres: ");
    scanf("%s", cadena);

    for (i=0, p=&cadena[0]; *p; i++, p++){
    }

    printf("La cadena '%s' tiene %d caracteres", cadena, i);

    return 0;
}