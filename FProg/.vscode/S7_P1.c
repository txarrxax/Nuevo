#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VOCABULARIO 8
#define MAX_CADENA 32

int aleatorio (int a, int b){
    return (int) (a+(double)rand()/(RAND_MAX-1)*(b-a+1));
}

int main () {
    const char VOCABULARIO[TAM_VOCABULARIO][MAX_CADENA] = {"vehiculo", "edificio", "camiseta", "boligrafo", "murcielago", "dromedario", "melocoton", "mermelada"};
    char palabra[MAX_CADENA], x[MAX_CADENA]="________", intento[MAX_CADENA], letras[MAX_CADENA] = "";
    int i, j = 0;
    int aciertos = 0, fallos = 0;
    char letra;

    srand((unsigned)time(NULL));

    i = aleatorio(0, TAM_VOCABULARIO-1);
    strcpy(palabra, VOCABULARIO[i]);

    do{
        printf("Tus letras introducidas son: %s\n", letras);
        printf("Tus letras encontradas son: %s\n", x);
        printf("Palabra de 8 letra. %d fallos de 6. Introduce una letra: ", fallos);
        scanf("\n%c", &letra);

        letras[j] = letra;
        j++;

        aciertos = 0;

        for (i=0; i<MAX_CADENA; i++){
            if (letra == palabra[i]){
                x[i] = letra;
                aciertos++;
            }
        }

        if (aciertos == 0){
            fallos++;
        }

        printf("Tus letras introducidas son: %s\n", letras);
        printf("Tus letras encontradas son: %s\n", x);

        printf("¿Cual es la palabra a adivinar? ");
        scanf("%s", intento);

        if (strcmp(intento, palabra) == 0){
            printf("¡¡Enhorabuena, has acertado la palabra %s!!", palabra);
            break;
        }
        else{
            printf("Esa no es la palabra. Sigue intentandolo.\n");
        }

    } while (fallos < 6);

    return 0;
}