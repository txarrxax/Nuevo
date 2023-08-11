#include <stdio.h>
#include <stdlib.h>

//definir macros para las dimensiones del tablero
#define FILAS_MIN 10
#define FILAS_MAX 20
#define COLUMNAS_MIN 10
#define COLUMNAS_MAX 20

typedef enum {AGUA, NO_TOCADO, TOCADO, HUNDIDO};

//definir la estructura de tipo Tablero
typedef struct{
    int **casillas;
    int numeroFilas;
    int numeroColumnas;
} Tablero;

//función para crea un tablero
Tablero *crear_tablero (int numFilas, int numColumnas){
    Tablero *tablero;
    int i;

    if (!(tablero->casillas = (int**) calloc(numColumnas, sizeof(int*))))
        return NULL;
    for (i=0; i<numColumnas; i++){
        if(!(tablero->casillas[i] = (int*) calloc(numFilas, sizeof(int))))
            return NULL;
    }

    tablero->numeroFilas = numFilas;
    tablero->numeroColumnas = numColumnas;

    return tablero;
}

//función que libera un tablero
void liberar_tablero (Tablero *tablero){
    int i;

    for (i=0; i<tablero->numeroColumnas; i++){
        free (tablero->casillas[i]);
    }
    free (tablero->casillas);
}

//función que muestra el tablero por pantalla
void visualizar_tablero (Tablero *tablero, int soloDisparos){
    int i, j;

    for (i=0; i<tablero->numeroFilas; i++){
        for (j=0; j<tablero->numeroColumnas; j++){
            printf("")
        }
    }
}