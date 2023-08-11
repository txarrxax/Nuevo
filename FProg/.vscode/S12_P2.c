#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int concatenar (char *cadena1, char *cadena2, char *nueva){
    int i, j;

    for (i=0; i<strlen(cadena1); i++){
        nueva[i] = cadena1[i];
    }
    for (i=0, j=strlen(cadena1); i<strlen(cadena2); i++, j++){
        nueva[j] = cadena2[i];
    }

    return strlen(nueva);
}

int main (){
    char *cadena1, *cadena2, *nueva;
    int dim, len;

    printf("Introduce el tamano maximo de las cadenas de caracteres: ");
    scanf("%d", &dim);

    if ((cadena1 = (char*) calloc(dim, sizeof(char))) == NULL){
        printf("Error, no se puede reservar memoria para la primera cadena");
        return 1;
    }

    if ((cadena2 = (char*) calloc(dim, sizeof(char))) == NULL){
        printf("Error, no se puede reservar memoria para la segunda cadena");
        return 1;
    }

    if ((nueva = (char*) calloc(dim, sizeof(char))) == NULL){
        printf("Error, no se puede reservar memoria para la nueva cadena");
        return 1;
    }

    printf("Introduce una cadena: ");
    scanf("%s", cadena1);

    printf("Introduce otra cadena: ");
    scanf("%s", cadena2);

    len = concatenar(cadena1, cadena2, nueva);

    printf("Cadena concatenada: %s,\nlongitud: %d", nueva, len);

    return 0;
}