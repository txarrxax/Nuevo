#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX 128

char *sinVocales (char *palabra){
    char *nueva;
    int i, j, dim=0;

    for (i=0; i<strlen(palabra); i++){
        if (!(palabra[i] == 'a' || palabra[i] == 'e' || palabra[i] == 'i' || palabra[i] == 'o' || palabra[i] == 'u')){
            dim++;
        }
    }

    if ((nueva = (char*) calloc(dim, sizeof(char))) == NULL){
        return NULL;
    }

    for (i=0, j=0; i<strlen(palabra); i++){
        if (!(palabra[i] == 'a' || palabra[i] == 'e' || palabra[i] == 'i' || palabra[i] == 'o' || palabra[i] == 'u')){
            nueva[j] = palabra[i];
            j++;
        }
    }
    
    return nueva;
    free(nueva);
}

int main (){
    char cadena[STR_MAX];

    printf("Introduce una palabra en minusculas (solo letras): ");
    scanf("%s", cadena);

    if (sinVocales(cadena) == NULL){
        printf("Error ejecutando el programa");
    }
    else{
        printf("La palabra %s sin vocales es %s", cadena, sinVocales(cadena));
    }

    return 0;
}