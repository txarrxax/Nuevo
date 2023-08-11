#include <stdio.h>

#define STR_LEN 64

typedef struct{
    int a;
    int b;
    float c;
    int d;
    int e;
} Entrada;

int leer (char *nombre, double *resultado, int limite){
    FILE *f;
    Entrada x;
    int i;

    f = fopen(nombre, "r");
    if (f == NULL)
        return 1;
    
    for (i=0, *resultado=0.0; fscanf(f, "%d %d %f %d %d", &x.a, &x.b, &x.c, &x.d, &x.e) == 5;){
        if (x.d > limite){
            *resultado += x.b;
            i++;
        }
    }

    if (*resultado > 0)
        *resultado /= i;

    fclose(f);
    return 0;
}

int main (){
    char archivo[STR_LEN];
    double resultado;
    int limite;

    printf("Introduce el nombre del archivo: ");
    scanf("%s", archivo);
    printf("Introduce un numero entero: ");
    scanf("%d", &limite);

    if (leer(archivo, &resultado, limite))
        printf("Error: no se pudo abrir el fichero %s", archivo);
    else
        printf("La media de la segunda columna con el limite igual a %d es: %.2lf", limite, resultado);

    return 0;
}