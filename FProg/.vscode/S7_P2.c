#include <stdio.h>
#include <stdlib.h>

#define AS 1
#define DOS 2
#define TRES 3
#define CUATRO 4
#define CINCO 5
#define SEIS 6
#define SIETE 7
#define SOTA 0.5
#define CABALLO 0.5
#define REY 0.5

#define DIM 4

int aleatorio(int a, int b) {
	return (int) (a + (double) rand()/(RAND_MAX-1) * (b - a + 1));
}

int main () {
    double cartas[40] = {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY, AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY, AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY, AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY};
    int i, j, k;
    int jugadores, test;
    float c1, c2, suma[DIM];
    char sn;

    for (i=0; i<100; i++){
        j = aleatorio(0,39);
        k = aleatorio(0,39);
        c1 = cartas[j];
        c2 = cartas[k];
        cartas[j] = c2;
        cartas[k] = c1;
    }

    do{
        printf("Cuantos jugadores (maximo 4)? ");
        scanf("%d", &jugadores);
    } while (jugadores < 0 && jugadores > 5);

    j=0;

    for (i=0; i<jugadores; i++){
        printf("Jugador %d ==========\n", i+1);
        test = 0;
        do{
            suma[i] += cartas[j];
            j++;

            printf("Tu puntuacion parcial es %.1f.\n", suma[i]);
            if (suma[i] > 7.5){
                test = 1;
                break;
            }
            printf("Quieres carta (s/n)? ");
            scanf("\n%c", &sn);
            
            if (sn == 'n'){
                test = 1;
            }

        } while (test == 0);

        if (suma[i] > 7.5){
            printf("¡¡Te has pasado!!¡Te quedas con %.1f puntos!\n", suma[i]);
        }
        else if (suma[i] <= 7.5){
            printf("¡¡Te has plantado!!¡Te quedas con %.1f puntos!\n", suma[i]);
        }
    }

    return 0;
}