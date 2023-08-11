#include <stdio.h>

#define TAM 15

typedef struct{
    char titulo[TAM]; //título de la canción
    char artista[TAM]; //artista de la canción
    int duracion; //duracion de la canción en segundos
} Cancion;

typedef struct{
    Cancion cancion[TAM];
} Playlist;

int guardar_playlist (Playlist lista, int num){
    FILE *f;
    Cancion a;
    int i;

    //comprobar argumentos
    if (num == 0)
        return 0;

    //abrir y comprobar fichero
    f = fopen("canciones.txt", "a");
    if (f == NULL)
        return 0;
    
    //leer todos las lineas del fichero
    for (; fscanf(f, "%s#%s#%d", a.titulo, a.artista, &a.duracion) == 3;)

    //escribir los datos de la estructura Playlist
    for (i=0; i<num; i++){
        fprintf(f, "%s#%s#%d\n", lista.cancion[i].titulo, lista.cancion[i].artista, lista.cancion[i].duracion);
    }

    //cerrar fichero
    fclose(f);
    return 1;
}

int contarCanciones_playlist (int *num){
    FILE *f;
    Cancion a;

    //comprobar argumentos
    if (num == NULL)
        return 0;
    
    //abrir y comprobar el fichero
    f = fopen("canciones.txt", "a");
    if (f == NULL)
        return 0;
    
    //leer los datos del fichero y contar el numero de canciones
    for (num=0; fscanf(f, "%s#%s#%d", a.titulo, a.artista, &a.duracion) == 3; (*num)++)

    //cerrar fichero
    fclose(f);
    return 1;
}

int main (){
    int num, i, total=0;
    Playlist playlist;

    //solicitar el numero de canciones a leer
    printf("Numero de canciones: ");
    scanf("%d", &num);

    //solicitar los datos de las canciones
    for (i=0; i<num; i++){
        printf("Titulo de la cancion %d: ", i+1);
        scanf("%s", playlist.cancion[i].titulo);
        printf("Artista de la cancion %d: ", i+1);
        scanf("%s", playlist.cancion[i].artista);
        printf("Duracion de la cancion %d: ", i+1);
        scanf("%d", &playlist.cancion[i].duracion);
    }

    //llamar a la primera función y comprobar el valor devuelto
    if (guardar_playlist(playlist, num) == 0){
        printf("Error en la ejecucion del programa");
        return 1;
    }

    //llamar a la segunda función y comprobar el valor devuelto
    if (contarCanciones_playlist(&total) == 0){
        printf("Error en la ejecucion del programa");
        return 1;
    }
    else{
        printf("El fichero tiene ahora %d canciones", total);
        return 0;
    }
}