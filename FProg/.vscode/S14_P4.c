#include <stdio.h>
#include <string.h>

#define STR_LEN 64

int leerCadenas (char *archivo, char *cadena1, char *cadena2){
    FILE *f;

    f = fopen(archivo, "r");
    if (f == NULL)
        return 0;

    fscanf(f, "%s", cadena1);
    fscanf(f, "%s", cadena2);

    fclose(f);
    return 1;
}

int comparaCadenas (char *archivo, char *cadena1, char *cadena2){
    FILE *f;
    int i, j, k, test, num;

    f = fopen(archivo, "a");
    if (f == NULL)
        return 0;
    
    for (i=0; i<strlen(cadena1); i++){
        test = 1;
        for (j=0; j<i; j++){
            if (cadena1[i] == cadena1[j])
                test = 0; 
        }

        if (test){
            for (k=0, num=0; k<strlen(cadena2); k++){
                if (cadena1[i] == cadena2[k])
                    num++;
            }
            
            if (num == 0)
                fprintf(f, "El caracter %c NO aparece en la cadena %s\n", cadena1[i], cadena2);
            else
                fprintf(f, "El caracter %c aparece %d veces en la cadena %s\n", cadena1[i], num, cadena2);
        }
    }

    fclose(f);
    return 1;
}

int main (){
    char cadena1[STR_LEN], cadena2[STR_LEN], archivo[STR_LEN];

    printf("Introduce el nombre del fichero que contiene las cadenas: ");
    scanf("%s", archivo);

    if (leerCadenas(archivo, cadena1, cadena2) == 0)
        printf("Error al leer los datos del fichero");
    else if (comparaCadenas(archivo, cadena1, cadena2) == 0)
        printf("Error al escribir los datos en el fichero");
    else
        printf("La informacion se ha guardado correctamente en el fichero %s", archivo);

    return 0;
}