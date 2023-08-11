#include <stdio.h>
#include <string.h>

#define MIN 2
#define MAX 10
#define STR 64

typedef struct{
    char nombre[STR];
    char apellido[STR];
}Persona;

int intercambiar (Persona *a, Persona *b){
    Persona x;

    if (a == NULL || b == NULL){
        return 0;
    }
    else{
        strcpy(x.nombre, a->nombre);
        strcpy(a->nombre, b->nombre);
        strcpy(b->nombre, x.nombre);

        strcpy(x.apellido, a->apellido);
        strcpy(a->apellido, b->apellido);
        strcpy(b->apellido, x.apellido);
        return 1;
    }
}

int main (){
    Persona tabla[MAX];
    int i, num, test;

    do{
        printf("Cuantas personas vas a introducir? ");
        scanf("%d", &num);

        if (num < MIN || num > MAX){
            printf("Debes introducir un numero entre %d y %d.\n", MIN, MAX);
        }
    } while (num < MIN || num > MAX);

    for (i=0; i<num; i++){
        printf("Introduce el nombre de la persona %d: ", i+1);
        scanf("%s", tabla[i].nombre);
        printf("Introduce el apellido de la persona %d: ", i+1);
        scanf("%s", tabla[i].apellido);
    }

    test = intercambiar (&tabla[0], &tabla[num-1]);

    if (test == 1){
        for (i=0; i<num; i++){
            printf("Persona %d: %s %s\n", i+1, tabla[i].nombre, tabla[i].apellido);
        }
    }
    else{
        printf("ERROR.");
    }

    return 0;
}