#include <stdio.h>

#define MIN 2
#define MAX 10

short numerosDistintos (int *x, int n, int *u, int *nDistintos){
    int i, j, test;

    for (i=0; i<n; i++){
        test = 0;
        for (j=0; j<i; j++){
            if (x[i] == x[j]){
                test = 1;
            }
        }
        if (test == 0){
            u[*nDistintos] = x[i];
            (*nDistintos)++;
        }

    }

    return 1;
}

int main (){
    int numeros[MAX], distintos[MAX], num, numdist = 0;
    int i;
    
    do{
        printf("Introduce cuantos numeros quieres leer: ");
        scanf("%d", &num);

        if (num < MIN || num > MAX){
            printf("ERROR. Tienes que introducir un numero entre %d y %d.\n", MIN, MAX);
        }
    } while (num < MIN || num > MAX);

    for (i=0; i<num; i++){
        printf("Introduce el numero %d de %d: ", i+1, num);
        scanf("%d", &numeros[i]);
    }

    if (numerosDistintos(numeros, num, distintos, &numdist)){
        printf("Has introducido %d numeros distintos: ", numdist);
        for (i=0; i<numdist; i++){
            printf("%d ", distintos[i]);
        }
    }
    else{
        printf("Ha ocurrido un error.\n");
    }

    return 0;
}