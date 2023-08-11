#include <stdio.h>
#include <stdlib.h>

#define DIM 10

typedef struct{
    char dni[DIM];
    int modelo;
    int aciertos;
    int fallos;
    int blanco;
    double nota;
} Estudiante;

int main (){
    FILE *f, *g;
    Estudiante a;

    f = fopen("notas.txt", "r");

    if (f == NULL){
        printf("Error abriendo el archivo\n");
        return 1;
    }

    g = fopen("listado.txt", "w");

    if (g == NULL){
        printf("Error creando el archivo\n");
        fclose(f);
        return 1;
    }

    for (; fscanf(f, "%s %d %d %d %d %lf", a.dni, &a.modelo, &a.aciertos, &a.fallos, &a.blanco, &a.nota) == 6;){
        if (a.nota < 5.0)
          fprintf(g, "%s %.2lf SUSPENSO\n", a.dni, a.nota);
        else if (a.nota < 7.0)
          fprintf(g, "%s %.2lf APROBADO\n", a.dni, a.nota);
        else if (a.nota < 9.0)
          fprintf(g, "%s %.2lf NOTABLE\n", a.dni, a.nota);
        else if (a.nota < 10.0)
          fprintf(g, "%s %.2lf SOBRESALIENTE\n", a.dni, a.nota);
        else
          fprintf(g, "%s %.2lf MATRICULA\n", a.dni, a.nota);
    }

    fclose(f);
    fclose(g);
    return 0;
}