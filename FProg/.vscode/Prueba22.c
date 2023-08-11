#include <stdio.h>
#include <string.h>

#define STR_MAX 64

int mayus (char *cadena, int *len){
    int i, test=1;

    for (i=0; i<strlen(cadena); i++){
        if (cadena[i] < 'a' || cadena[i] > 'z'){
            test = 0;
        }
    }

    *len = strlen(cadena);

    for (i=0; i<strlen(cadena); i++){
        cadena[i] += 'A'-'a';
    }

    return test;
}

int main (){
    char cadena[STR_MAX];
    int len, test;

    do{
        printf("Introduce una cadena de caracteres en minusculas: ");
        scanf("%s", cadena);

        test = mayus(cadena, &len);

        if (test == 0){
            printf("ERROR. La cadena solo debe contener letras minusculas.\n");
        }
    } while (test == 0);

    printf("Cadena: %s | Tamano: %d", cadena, len);

    return 0;
}