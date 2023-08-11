#include <stdio.h>
#include <stdlib.h>

void menorQue (double *x, long n, double umbral, long *l){
    int i;

    for (i=0; i<n; i++){
        if (x[i] < umbral){
            *l += 1;
        }
    }
}

int main (){
    double *datos, umbral;
    long dim, num=0;
    int i;

    printf("Escribe el numero de elementos: ");
    scanf("%ld", &dim);

    datos = (double*) calloc(dim, sizeof(double));

    for (i=0; i<dim; i++){
        printf("Numero %d: ", i+1);
        scanf("%lf", &datos[i]);
    }

    printf("Escribe el umbral: ");
    scanf("%lf", &umbral);

    menorQue(datos, dim, umbral, &num);

    printf("Hay %ld numeros por debajo del umbral: %.2lf", num, umbral);

    free(datos);

    return 0;
}