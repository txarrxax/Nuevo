#include <stdio.h>

#define STR_LEN 64

typedef struct{
    char nombre[STR_LEN];
    int num1;
    int num2;
} Entrada;

int generar (char *entrada, char *salida, int limite){
    FILE *f, *g;
    Entrada a;

    f = fopen(entrada, "r");
    if (f == NULL)
        return 1;
    g = fopen(salida, "w");
    if (g == NULL)
        return 1;

    for (; fscanf(f, "%s %d %d", a.nombre, &a.num1, &a.num2) == 3;){
        if (a.num1 + a.num2 < limite)
            fprintf(g, "%s\n", a.nombre);
    }

    fclose(f);
    fclose(g);
    return 0;
}

int main (){
    char entrada[STR_LEN], salida[STR_LEN];
    int limite;

    printf("Introduce el nombre del archivo de entrada: ");
    scanf("%s", entrada);
    printf("Introduce el nombre del archivo de salida: ");
    scanf("%s", salida);
    printf("Introduce el valor del limite: ");
    scanf("%d", &limite);

    if (generar(entrada, salida, limite))
        printf("Error: no se pudo abrir un fichero");
    else
        printf("Se ha creado correctamente el fichero %s con los resultados", salida);

    return 0;
}