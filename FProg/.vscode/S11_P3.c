#include <stdio.h>
#include <string.h>

#define STR_MAX 64

void numeroDePalabras (char *s, long *nPalabras){
    int i;

    for (i=0; i<strlen(s); i++){
        if (s[i] == ' ' && s[i-1] != ' '){
            *nPalabras = *nPalabras + 1;
        }
    }

    if (s[strlen(s)-1] != ' '){
        *nPalabras = *nPalabras + 1;
    }
}

int main (){
    long num=0;
    char cadena[STR_MAX];

    printf("Escribe una cadena de caracteres: ");
    gets(cadena);

    numeroDePalabras (cadena, &num);

    printf("El numero de palabras es: %ld", num);

    return 0;
}