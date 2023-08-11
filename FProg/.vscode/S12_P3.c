#include <stdio.h>
#include <stdlib.h>

void buscarMinMax (double *x, long d, double *min, double *max){
    int i;

    *min = x[0];
    *max = x[0];

    for (i=0; i<d; i++){
        if (x[i] < *min){
            *min = x[i];
        }
        if (x[i] > *max){
            *max = x[i];
        }
    }
}

int main (){
    int i;
    long dim;
    double *datos, min, max;

    printf("Numero de datos: ");
    scanf("%ld", &dim);

    datos = (double*) calloc(dim, sizeof(double));

    for (i=0; i<dim; i++){
        printf("Dato %d: ", i+1);
        scanf("%lf", &datos[i]);
    }

    buscarMinMax(datos, dim, &min, &max);

    printf("El minimo y maximo son: %.2lf y %.2lf, respectivamente", min, max);

    free(datos);
    
    return 0;
}