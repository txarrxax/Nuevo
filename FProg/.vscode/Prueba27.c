#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX 64

int contar_palabras (char *archivo){
    FILE *f;
    char palabra[STR_MAX];
    int i;

    f = fopen(archivo, "r");

    if (f == NULL){
        printf("Error abriendo el archivo\n");
        return -1;
    }

    for (i=0; fscanf(f, "%s", palabra) == 1;){
        i++;
    }

    fclose(f);
    return i;
}

int contar_caracter (char *archivo, char car){
    FILE *f;
    char palabra[STR_MAX];
    int i, num;

    f = fopen(archivo, "r");

    if (f == NULL){
        printf("Error abriendo el archivo\n");
        return -1;
    }

    for (num=0; fscanf(f, "%s", palabra) == 1;){
        for (i=0; i<strlen(palabra); i++){
            if (palabra[i] == car){
                num++;
            }
        }
    }

    fclose(f);
    return num;
}

int main (){
    char archivo[STR_MAX], c;
    int palabras, caracter;

    printf("Introduce el nombre del archivo: ");
    scanf("%s", archivo);
    printf("Introduce un caracter: ");
    scanf("\n%c", &c);

    palabras = contar_palabras(archivo);
    caracter = contar_caracter(archivo, c);

    printf("El archivo %s tiene %d palabras; y el caracter %c aparece %d veces", archivo, palabras, c, caracter);

    return 0;
}