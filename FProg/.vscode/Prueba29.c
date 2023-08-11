#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 64

/*Estructura que guarda un nombre de asignatura y la calificacion en esa asignatura*/
typedef struct{
    char asignatura[STR_LEN];
    float nota;
} Calificacion;

/*Estructura que guarda un numero de calificaciones y un puntero donde habra una tabla de Calificacion
(depues de haber reservado memoria dinamica)*/
typedef struct{
    int num_calificaciones;
    Calificacion *notas;
} Calificaciones;

Calificaciones *leerCalificaciones (char *archivo){
    FILE *f;
    Calificaciones *calificaciones;
    Calificacion a;
    char nombre[STR_LEN];
    int i;

    if (archivo == NULL){
        printf("Error abriendo el archivo");
        return NULL;
    }

    calificaciones = (Calificaciones*) malloc(1*sizeof(calificaciones));
    if (calificaciones == NULL){
        printf("Error en la reserva de memoria dinámica");
        return NULL;
    }

    f = fopen(archivo, "r");
    if (f == NULL){
        printf("Error abriendo el archivo");
        return NULL;
    }

    for (calificaciones->num_calificaciones=0; fscanf(f, "%s %s %f", nombre, a.asignatura, &a.nota) == 3; calificaciones->num_calificaciones++);

    calificaciones->notas = (Calificacion*) malloc(calificaciones->num_calificaciones*sizeof(Calificacion));
    if (calificaciones->notas == NULL){
        printf("Error en la reserva de memoria dinámica");
        return NULL;
    }

    fclose(f);

    f = fopen(archivo, "r");
    if (f == NULL){
        printf("Error abriendo el archivo");
        return NULL;
    }

    for (i=0; i<calificaciones->num_calificaciones; i++){
        fscanf(f, "%s %s %f", nombre, calificaciones->notas[i].asignatura, &calificaciones->notas[i].nota);
    }

    fclose(f);
    return calificaciones;
}

int main (){
    char archivo[STR_LEN], asignatura[STR_LEN];
    Calificaciones *calificaciones;
    float total;
    int i, j;

    printf("Introduce el nombre del archivo: ");
    scanf("%s", archivo);

    calificaciones = leerCalificaciones(archivo);

    printf("Introduce el nombre de una asignatura: ");
    scanf("%s", asignatura);

    for (i=0, j=0, total = 0.0; i<calificaciones->num_calificaciones; i++){
        if (strcmp(calificaciones->notas[i].asignatura, asignatura) == 0){
            total += calificaciones->notas[i].nota;
            j++;
        }
    }

    if (j==0)
        printf("No se ha encontrado ninguna coincidencia");
    else
        printf("La media de las calificaciones de la asignatura %s es %.2f", asignatura, total/j);

    free(calificaciones);
    return 0;
}
