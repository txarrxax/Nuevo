#include <stdio.h>
#include <string.h>

#define MAX_INT 5
#define STR_LEN 128

int main () {
    char cadena[STR_LEN];
    int intentos = 0, test, j;

    do{
        test = 0;
        if (intentos > MAX_INT){
            printf("Escribe una palabra (intento numero: %d): ", intentos);
        }
        else{
            printf("Escribe una palabra: ");
        }
        scanf("%s", cadena);

        for (j=0; j<strlen(cadena); j++){
            if ((cadena[j] < 'a' || cadena[j] > 'z') && (cadena[j] < 'A' || cadena[j] > 'Z') && (cadena[j] != '_')){
                printf("El caracter %c de la cadena %s es el primero no valido\n", cadena[j], cadena);
                test = 1;
                break;
            }
        }

        intentos++;
    } while (test == 1);

    printf("Cadena valida");

    return 0;
}
