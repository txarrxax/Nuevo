#include <stdio.h>

#define DIM 10
#define MIN 2
#define MAX 10

// Creamos la función que nos permite calcular las potencias utilizando un bucle for
int elevado (int base, int exponente){
    int res=1, i;

    for (i=1; i<=exponente; i++){
        res = res*base;
    }

    // Devolvemos el valor obtenido
    return res;
}

// Creamos la función principal
int main (){
    int tabla[DIM];
    int num, res, i,j;

    // Solicitamos el numero de valores a introducir haciendo las comprobaciones pertinentes
    do{
        printf("Introduce cuantos numeros quieres leer (entre 2 y 10): ");
        scanf("%d", &num);

        if (num < MIN || num > MAX){
            printf("Error, el numero tiene que estar comprendido entre 2 y 10\n");
        }
    } while (num < MIN || num > MAX);

    // Solicitamos por teclado los numeros necesarios
    for (i=0; i<num; i++){
        printf("Introduce el numero %d: ", i+1);
        scanf("%d", &tabla[i]);
    }

    // Calculamos las potencias de todos los numeros utilizando dos bucles for anidados
    for (i=0; i<num; i++){
        for (j=i+1; j<num; j++){
            res = elevado(tabla[i], tabla[j]);
            printf("%d elevado a %d es %d\n", tabla[i], tabla[j], res);
        }
    }

    return 0;
}