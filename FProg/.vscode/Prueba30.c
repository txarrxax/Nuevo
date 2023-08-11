#include <stdio.h>

#define STR_MAX 64

int leer (char *nombre, double *resultado, int limite){
    FILE *f;
    int a, b, d, e, i=0;
    double c, total;

    //abrir y comprobar el fichero
    f = fopen(nombre, "r");
    if (!f)
        return 1;

    //seleccionar y operar con los datos
    for (; fscanf(f, "%d %d %lf %d %d", &a, &b, &c, &d, &e) == 5;){
        if (d > limite){
            total += b;
            i++;
        }
    }

    if (i != 0)
        *resultado = total/i;
    else
        *resultado = 0.0;

    //cerrar el fichero
    fclose(f);
    return 0;
}

int main (){
    char fichero[STR_MAX];
    int limite;
    double media;

    //solicitar los argumentos para la funcion
    printf("Introduce el nombre del archivo: ");
    scanf("%s", fichero);
    printf("Introduce un numero entero: ");
    scanf("%d", &limite);

    //llamar a la funcion y comprobar el valor devuelto
    if (!leer(fichero, &media, limite)){
        printf("La media de la segunda columna con el limite igual a %d es: %.2lf", limite, media);
        return 0;
    }
    else{
        printf("Error. No se pudo abrir el fichero %s", fichero);
        return 1;
    }
}