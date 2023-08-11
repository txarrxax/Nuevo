#include <stdio.h>
#include <stdlib.h>

int main (){
    int n, i, *tabla, *datos_nuevo;
    double suma=0;

    printf("Cuantos numeros quieres leer? ");
    scanf("%d", &n);

    tabla = (int*) calloc(n, sizeof(int));
    if (tabla == NULL){
        printf("La reserva de memoria ha fallado.");
        return 1;
    }

    for (i=0; i<n; i++){
        printf("Introduce el numero %d de la tabla: ", i+1);
        scanf("%d", &tabla[i]);
        suma += tabla[i];
    }

    printf("La media de los numeros introducidos es: %.2lf\n", suma/n);

    datos_nuevo = (int*) calloc(n+1, sizeof(int));

    for (i=0; i<n; i++){
        datos_nuevo[i] = tabla[i];
    }
    free(tabla);

    tabla = datos_nuevo;

    printf("Introduce un nuevo numero: ");
    scanf("%d", &tabla[n+1]);

    suma += tabla[n+1];

    printf("La media de los numeros introducidos es: %.2lf", suma/(n+1));

    return 0;
}