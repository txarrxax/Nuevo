#include <stdio.h>

#define STR_LEN 64

typedef struct{
    char nombre[STR_LEN];
    int num1;
    int num2;
} Entrada;

int buscarInicial (char *archivo, char inicial){
    FILE *f;
    Entrada a;
    int recuento;

    //Comprobar argumentos
    if (archivo == NULL)
        return 1;

    f = fopen(archivo, "r");
    if (f == NULL)
        return 1;

    for (recuento = 0; fscanf(f, "%s %d %d", a.nombre, &a.num1, &a.num2) == 3;){
        if (a.nombre[0] == inicial){
            recuento++;
        }
    }

    fclose(f);

    f = fopen(archivo, "a");
    if (f == NULL)
        return 1;

    fprintf(f, "\nHay: %d nombre(s) que empieza(n) por la incial %c", recuento, inicial);

    fclose(f);
    return 0;
}

int main (){
    char archivo[STR_LEN];
    char inicial;

    printf("Introduce el nombre del archivo: ");
    scanf("%s", archivo);
    printf("Introduce una inicial: ");
    scanf("\n%c", &inicial);

    if (buscarInicial(archivo, inicial) == 1)
        printf("Error: no se pudo abrir el fichero %s", archivo);
    else
        printf("El resultado se ha guardado correctamente al final del fichero %s", archivo);
    
    return 0;
}