#include <stdio.h>
#include <stdlib.h>

double *mayorQueUmbral (double *x, long n, double umbral, long *m){
    double *tabla;
    int i, j=0;
    *m = 0;
    for (i=0; i<n; i++){
        if (x[i] > umbral){
            *m = *m +1;
        }
    }

    if ((tabla = (double*) calloc(*m, sizeof(double))) == NULL){
        return NULL;
    }

    for (i=0; i<n; i++){
        if (x[i] > umbral){
            tabla[j] = x[i];
            j++;
        }
    }

    return tabla;
}

int main (){
    double *datos, *mayores, umbral;
    int i;
    long dim, num; 

    printf("Escribe el numero de numeros a leer: ");
    scanf("%ld", &dim);

    if ((datos = (double*) calloc(dim, sizeof(double))) == NULL){
        printf("No se ha podido generar la tabla");
        return 1;
    }

    for (i=0; i<dim; i++){
        printf("Numero %d de %ld: ", i+1, dim);
        scanf("%lf", &datos[i]);
    }

    printf("Escribe el umbral: ");
    scanf("%lf", &umbral);

    mayores = mayorQueUmbral(datos, dim, umbral, &num);

    printf("Los numeros mayores que el umbral (%.2lf) son: ", umbral);
    for (i=0; i<num; i++){
        printf("%.2lf ", mayores[i]);
    }

    return 0;
}