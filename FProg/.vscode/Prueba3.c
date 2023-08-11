#include <stdio.h>

int main (){
    char x;
    printf("Introduce un caracter: ");
    scanf("%c", &x);

    if (64<x<91 || 96<x<123){
        if (x==65 || x==69 || x==73 || x==79 || x==85 || x==97 || x==101 || x==105 || x==111 || x==117){
            printf("El caracter '%c' es una vocal", x);
        }
        else{
            printf("El caracter '%c' es una consonante", x);
        }
    }
    else{
        printf("El caracter '%c' no es una letra", x);
    }

    return 0;
}