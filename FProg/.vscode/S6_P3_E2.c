#include <stdio.h>
#include <string.h>

#define STR_LEN 32

int main () {
    char cadena1[STR_LEN], cadena2[STR_LEN]; 
    char longitud, test, n, i, j;

    printf("Introduce una palabra: ");
    scanf("%s", cadena1);
    printf("Introduce otra palabra: ");
    scanf("%s", cadena2);

    longitud = strlen(cadena1);

    for (i=0; i<longitud; i++){
        n = 0;
        test = 0;
        for (j=0; j<i; j++){
           if (cadena1[i] == cadena1[j]){
               test = 1;
            }
        }
        if (test == 0){
            for (j=0; j<longitud; j++){
                if (cadena1[i] == cadena2[j]){
                    n++;
                }
            }
            printf("El caracter %c aparece %d veces en la palabra %s.\n", cadena1[i], n, cadena2);
        }
        else if (test == 1){
            printf("El caracter %c ya ha aparecido. Mira mas arriba.\n");
        }
    }

    return 0;
}