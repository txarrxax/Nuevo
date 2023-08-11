#include <stdio.h>
#include <stdlib.h>

#define STR_MAX 64

typedef struct{
    int dni;
    int modelo;
    int aciertos;
    int fallos;
    int blanco;
    double nota;
} Estudiante;

int contar_estudiantes (char *archivo){
    FILE *f;
    int i;
    Estudiante a;

    f = fopen(archivo, "r");

    if (f == NULL){
        printf("Error abriendo el archivo\n");
        return -1;
    }

    for (i=0; fscanf(f, "%d %d %d %d %d %lf", &a.dni, &a.modelo, &a.aciertos, &a.fallos, &a.blanco, &a.nota) == 6;){
        i++;
    }

    fclose(f);
    return i;
}

int main (){
    FILE *f;
    char archivo[STR_MAX];
    int num, i;
    double media;
    Estudiante a;
    Estudiante *tabla;

    printf("Introduce el nombre del archivo: ");
    scanf("%s", archivo);

    num = contar_estudiantes(archivo);

    tabla = (Estudiante*) calloc(num, sizeof(Estudiante));

    f = fopen(archivo, "r");

    if (f == NULL){
        printf("Error abriendo el archivo\n");
        return 1;
    }

    for (i=0, media=0.0; fscanf(f, "%d %d %d %d %d %lf", &a.dni, &a.modelo, &a.aciertos, &a.fallos, &a.blanco, &a.nota) == 6; i++){
        tabla[i].dni = a.dni;
        tabla[i].modelo = a.modelo;
        tabla[i].aciertos = a.aciertos;
        tabla[i].fallos = a.fallos;
        tabla[i].blanco = a.blanco;
        tabla[i].nota = a.nota;

        media += a.nota;
    }

    printf("La nota media de los estudiantes es: %.2lf", media/i);

    fclose(f);
    return 0;
}