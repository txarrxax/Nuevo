#include <stdio.h>

#define TAM 64

//Función que lee los nombres de un fichero y lo edita
int procesaFichero (char *fichero, char *nombreBuscado){
    FILE *f;
    int num, repe;
    char nombre[TAM];

    //Comprobar los argumentos
    if (fichero == NULL || nombreBuscado == NULL)
        return 0;
    
    //Abrir y comprobar el fichero (lectura)
    f = fopen(fichero, "r");
    if (f == NULL)
        return 0;
    
    for (num=0, repe=0; fscanf(f, "%s", nombre) == 1; num++){
        if (nombre == nombreBuscado)
            repe = 1;
    }

    //Cerrar el fichero
    fclose(f);

    //Abrir y comprobar el fichero (edición)
    f = fopen(fichero, "a");
    if (f == NULL)
        return 0;

    //Escribir la información en el fichero
    if (repe == 0)
        fprintf(f, "El fichero tiene %d nombre(s) y %s se encuentra entre ellos", num, nombreBuscado);
    else   
        fprintf(f, "El fichero tiene %d nombre(s) y %s NO se encuentra entre ellos", num, nombreBuscado);

    //Cerrar el fichero
    fclose(f);
    return 1;
}

int main (){
    char fichero[TAM], nombre[TAM];

    //Solicitar los argumentos
    printf("Introduce el nombre del fichero con los nombres: ");
    scanf("%s", fichero);
    printf("Introduce el nombre de la persona que quieres buscar: ");
    scanf("%s", nombre);

    //LLamar a la función y comprobar el valor devuelto
    if (procesaFichero(fichero, nombre) == 0){
        printf("Error en la ejecución del programa");
        return 1;
    }
    else{
        printf("Informacion guardada correctamente en el fichero %s. Abrelo para verla.", fichero);
        return 1;
    }

}