#include <stdio.h>

#define MAX_STR 128
#define INFO 5

typedef struct {
	char campeon[MAX_STR];
    int kda[INFO];
} juego;

typedef struct {
    char nombre[MAX_STR];
    juego partida;
} invocador;

int main() {    
    invocador usuario;
    double ratio;

    printf("DATOS JUGADOR 1\n")
    printf("¿Cuál es tu nombre de invocador? ");
    scanf("%s", usuario.nombre);
    printf("¿Con qué campeón has jugado tu última partida? ");
    scanf("%s", usuario.partida.campeon);
    printf("¿Cuántos asesinatos has hecho? ");
    scanf("%d", &usuario.partida.kda[0]);
    printf("¿Cuántas veces has muerto? ");
    scanf("%d", &usuario.partida.kda[1]);
    printf("¿Y cuántas asistencias has hecho? ");
    scanf("%d", &usuario.partida.kda[2]);

    ratio = (double)(usuario.partida.kda[0]+usuario.partida.kda[2])/usuario.partida.kda[1]; // Fórmula: (K+A)/D
   
    printf("%s, de nivel %d y experiencia %d, tu KDA ratio con %s ha sido %.2lf.\n", usuario.nombre, usuario.nivel, usuario.experiencia, usuario.partida.campeon, ratio);  

    return 0;
}