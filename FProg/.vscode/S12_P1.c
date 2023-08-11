#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void coincidencia (char *cadena1, char *cadena2){
    int test, i, j;
    for (i=0; i<strlen(cadena1); i++){
        test = 0;
        for (j=0; j<strlen(cadena2); j++){
            if (cadena1[i] == cadena2[j]){
                test = 1;
            }
        }
        if (test){
            printf("El caracter %c aparece en la cadena %s\n", cadena1[i], cadena2);
        }
        else{
            printf("El caracter %c NO aparece en la cadena %s\n", cadena1[i], cadena2);
        }
    }
}

int main (){
    char *cadena1, *cadena2;
    int dim;

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

    printf("Introduce una cadena: ");
    scanf("%s", cadena1);

    printf("Introduce otra cadena: ");
    scanf("%s", cadena2);

    coincidencia(cadena1, cadena2);

    free(cadena1);
    free(cadena2);

    return 0;
}