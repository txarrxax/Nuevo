#include <stdio.h>

#define MIN 1
#define MAX 10

typedef struct{
    int tabla[MAX];
    int tamano;
}Almacen;

void obtenPares (Almacen a, Almacen *b){
    int i;
    b->tamano = 0;

    for (i=0; i<a.tamano; i++){
        if (a.tabla[i]%2 == 0){
            b->tabla[b->tamano]=a.tabla[i];
            b->tamano++;
        }
    }
}

int main (){
    int i, x;
    Almacen almacen;

    do{
        printf("¿Cuantos numeros quieres leer (entre 1 y 10)? ");
        scanf("%d", &almacen.tamano);

        if (almacen.tamano < MIN || almacen.tamano > MAX){
            printf("Error, el numero tiene que estar comprendido entre %d y %d\n", MIN, MAX);
        }
    } while (almacen.tamano < MIN || almacen.tamano > MAX);

    for (i=0; i<almacen.tamano; i++){
        printf("Introduce el numero %d de %d: ", i+1, almacen.tamano);
        scanf("%d", &almacen.tabla[i]);
    }

    x = almacen.tamano;
    obtenPares(almacen, &almacen);

    if (almacen.tamano == 0){
        printf("No has introducido ningun numero par");
    }
    else{
        printf("Has introducido %d numeros, de los cuales %d son pares. Estos son: ", x, almacen.tamano);
        for (i=0; i<almacen.tamano; i++){
            printf("%d ", almacen.tabla[i]);
        }
    }

    return 0;
}