#include <stdio.h>
#include <string.h>

#define STR_MAX 64

void intercambiar (char *car1, char *car2){
    char aux;

    aux = *car1;
    *car1 = *car2;
    *car2 = aux;
}

int main (){
    char palabra[STR_MAX];
    int i;

    printf("Introduce una palabra: ");
    scanf("%s", palabra);

    printf("La palabra %s con las letras intercambiadas es ", palabra);

    for (i=0; i<strlen(palabra)/2; i++){
        intercambiar (&palabra[i], &palabra[strlen(palabra)-1-i]);
    }

    printf("%s", palabra);

    return 0;
}